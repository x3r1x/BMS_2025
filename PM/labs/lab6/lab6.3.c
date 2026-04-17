//
// Created by x3r1x on 13.04.2026.
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

constexpr double EPSILON = 1e-9;

enum
{
	UNKNOWN_ERROR = -1,
	OK = 0,
	MEMORY_ERROR = 1,
	WRONG_INPUT = 2,
	PROHIBITED_OPERATION = 3,
	NO_INVERSE_MATRIX = 4,
	MATRIX_IS_SINGULAR = 5,
} MatrixCodes;

typedef struct
{
	int numRows;
	int numColumns;
	double* items; // указатель на данные (в куче)
} Matrix;

int CreateMatrix(int numRows, int numColumns, Matrix* m);
int CreateUnitMatrix(int numRows, int numColumns, Matrix* m);
void DestroyMatrix(Matrix* m);

int ReadMatrix(Matrix* m);
void WriteMatrix(Matrix* m);

double GetMatrixItemValue(Matrix* m, int row, int column);
void SetMatrixItemValue(Matrix* m, int row, int column, double value);

int CopyMatrix(Matrix* inMatrix, Matrix* outMatrix);
int MultiplyMatrix(Matrix* m1, Matrix* m2, Matrix* result);
bool AreMatrixEqual(Matrix* m1, Matrix* m2);

int UnfoldGaussMethod(Matrix* inMatrix, Matrix* inverseMatrix);
int GetResultMatrix(Matrix* originalMatrix, Matrix* inverseMatrix, Matrix* resultMatrix);
bool IsPrintResultSuccessful(Matrix* resultMatrix);

int main()
{
	int N;
	int errorStatus = 0;
	Matrix m = { 0 };
	Matrix inverseM = { 0 };
	Matrix resultM = { 0 };

	if (scanf("%d", &N) != 1 || N < 1)
	{
		printf("Error: wrong input!\n");
		return 1;
	}

	if (CreateMatrix(N, N, &m) != OK)
	{
		DestroyMatrix(&m);
		printf("Error: not enough memory!\n");
		return 1;
	}

	if (ReadMatrix(&m) != OK)
	{
		DestroyMatrix(&m);
		printf("Error: wrong input!\n");
		return 1;
	}

	if ((errorStatus = UnfoldGaussMethod(&m, &inverseM)) != OK)
	{
		if (errorStatus == MATRIX_IS_SINGULAR)
		{
			printf("Matrix is singular!");
		}
		else
		{
			DestroyMatrix(&m);
			printf("There appears to be an error!\n");
			return 1;
		}
	}
	else
	{
		printf("Inverse matrix:\n");
		WriteMatrix(&inverseM);

		GetResultMatrix(&m, &inverseM, &resultM);
		if (!IsPrintResultSuccessful(&resultM))
		{
			DestroyMatrix(&m);
			DestroyMatrix(&inverseM);
			DestroyMatrix(&resultM);
			return 1;
		}
	}

	DestroyMatrix(&m);
	DestroyMatrix(&inverseM);
	DestroyMatrix(&resultM);
}

int CreateMatrix(const int numRows, const int numColumns, Matrix* m)
{
	double* newItems = malloc(numColumns * numRows * sizeof(double));

	if (newItems == nullptr)
	{
		return MEMORY_ERROR;
	}

	m->numRows = numRows;
	m->numColumns = numColumns;
	m->items = newItems;

	return OK;
}

int CreateUnitMatrix(const int numRows, const int numColumns, Matrix* m)
{
	if (CreateMatrix(numRows, numColumns, m) != OK)
	{
		return MEMORY_ERROR;
	}

	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numColumns; j++)
		{
			if (i == j)
			{
				SetMatrixItemValue(m, i, j, 1);
			}
			else
			{
				SetMatrixItemValue(m, i, j, 0);
			}
		}
	}

	return OK;
}

int ReadMatrix(Matrix* m)
{
	for (int i = 0; i < m->numRows; i++)
	{
		for (int j = 0; j < m->numColumns; j++)
		{
			double value;

			if (scanf("%lf", &value) != 1)
			{
				return WRONG_INPUT;
			}

			SetMatrixItemValue(m, i, j, value);
		}
	}

	return OK;
}

void WriteMatrix(Matrix* m)
{
	for (int i = 0; i < m->numRows; i++)
	{
		for (int j = 0; j < m->numColumns; j++)
		{
			printf("%lf ", GetMatrixItemValue(m, i, j));
		}

		printf("\n");
	}
}

void DestroyMatrix(Matrix* m)
{
	if (m->items != nullptr)
	{
		free(m->items);
	}

	m->numColumns = 0;
	m->numRows = 0;
	m->items = nullptr;
}

double GetMatrixItemValue(Matrix* m, const int row, const int column)
{
	if (row > m->numRows || column > m->numColumns || m->items == nullptr)
	{
		DestroyMatrix(m);
		abort();
	}

	return m->items[row * m->numColumns + column];
}

void SetMatrixItemValue(Matrix* m, const int row, const int column, const double value)
{
	if (row > m->numRows || column > m->numColumns || m->items == nullptr)
	{
		DestroyMatrix(m);
		abort();
	}

	m->items[row * m->numColumns + column] = value;
}

bool AreMatrixEqual(Matrix* m1, Matrix* m2)
{
	if (m1->numColumns != m2->numColumns || m1->numRows != m2->numRows)
	{
		return false;
	}

	for (int i = 0; i < m1->numRows; i++)
	{
		for (int j = 0; j < m2->numColumns; j++)
		{
			if (fabs(GetMatrixItemValue(m1, i, j) - GetMatrixItemValue(m2, i, j)) > EPSILON)
			{
				return false;
			}
		}
	}

	return true;
}

int MultiplyMatrix(Matrix* m1, Matrix* m2, Matrix* result)
{
	if (m1->numColumns != m2->numRows)
	{
		return PROHIBITED_OPERATION;
	}

	for (int i = 0; i < result->numRows; i++)
	{
		for (int j = 0; j < result->numColumns; j++)
		{
			double resultMatrixElement = 0;

			for (int k = 0; k < m1->numColumns; k++)
			{
				resultMatrixElement += GetMatrixItemValue(m1, i, k) * GetMatrixItemValue(m2, k, j);
			}

			SetMatrixItemValue(result, i, j, resultMatrixElement);
		}
	}

	return OK;
}

int CopyMatrix(Matrix* inMatrix, Matrix* outMatrix)
{
	if (inMatrix->numColumns != outMatrix->numColumns || inMatrix->numRows != outMatrix->numRows)
	{
		return PROHIBITED_OPERATION;
	}

	for (int i = 0; i < inMatrix->numRows; i++)
	{
		for (int j = 0; j < inMatrix->numColumns; j++)
		{
			SetMatrixItemValue(outMatrix, i, j, GetMatrixItemValue(inMatrix, i, j));
		}
	}

	return OK;
}

void MakeGaussLineCalculations(Matrix* originalMatrix, Matrix* inverseMatrix, const int originalRow, const int originalColumn, const int calculationRow)
{
	const double multiplicationIndex = GetMatrixItemValue(originalMatrix, calculationRow, originalColumn) / GetMatrixItemValue(originalMatrix, originalRow, originalColumn);

	for (int j = 0; j < originalMatrix->numColumns; j++)
	{
		const double newOriginalMatrixElement = GetMatrixItemValue(originalMatrix, calculationRow, j) - multiplicationIndex * GetMatrixItemValue(originalMatrix, originalRow, j);
		const double newInverseMatrixElement = GetMatrixItemValue(inverseMatrix, calculationRow, j) - multiplicationIndex * GetMatrixItemValue(inverseMatrix, originalRow, j);

		SetMatrixItemValue(originalMatrix, calculationRow, j, newOriginalMatrixElement);
		SetMatrixItemValue(inverseMatrix, calculationRow, j, newInverseMatrixElement);
	}
}

bool isTriangularMatrixSingular(Matrix* triangularMatrix)
{
	for (int i = 0; i < triangularMatrix->numRows; i++)
	{
		if (GetMatrixItemValue(triangularMatrix, i, i) == 0)
		{
			return true;
		}
	}

	return false;
}

void NormalizePseudoTransformedUnitMatrix(Matrix* transformedMatrix, Matrix* inverseMatrix)
{
	double divisionCoefficient;

	for (int i = 0; i < transformedMatrix->numRows; i++)
	{
		if ((divisionCoefficient = GetMatrixItemValue(transformedMatrix, i, i)) != 1)
		{
			for (int k = 0; k < inverseMatrix->numColumns; k++)
			{
				SetMatrixItemValue(inverseMatrix, i, k, GetMatrixItemValue(inverseMatrix, i, k) / divisionCoefficient);
			}

			SetMatrixItemValue(transformedMatrix, i, i, 1);
		}
	}
}

int UnfoldGaussMethod(Matrix* inMatrix, Matrix* inverseMatrix)
{
	if (inMatrix->numColumns != inMatrix->numRows)
	{
		return NO_INVERSE_MATRIX;
	}

	Matrix transformingMatrix;
	CreateMatrix(inMatrix->numRows, inMatrix->numColumns, &transformingMatrix);

	if (CopyMatrix(inMatrix, &transformingMatrix) != OK || CreateUnitMatrix(inMatrix->numRows, inMatrix->numColumns, inverseMatrix) != OK)
	{
		return MEMORY_ERROR;
	}

	for (int i = 0; i < transformingMatrix.numColumns - 1; i++)
	{
		for (int k = i + 1; k < transformingMatrix.numRows; k++)
		{
			MakeGaussLineCalculations(&transformingMatrix, inverseMatrix, i, i, k);
		}
	}

	if (isTriangularMatrixSingular(&transformingMatrix))
	{
		DestroyMatrix(&transformingMatrix);
		return MATRIX_IS_SINGULAR;
	}

	for (int i = transformingMatrix.numColumns - 1; i >= 0; i--)
	{
		for (int k = i - 1; k >= 0; k--)
		{
			MakeGaussLineCalculations(&transformingMatrix, inverseMatrix, i, i, k);
		}
	}

	NormalizePseudoTransformedUnitMatrix(&transformingMatrix, inverseMatrix);

	DestroyMatrix(&transformingMatrix);
	return OK;
}

int GetResultMatrix(Matrix* originalMatrix, Matrix* inverseMatrix, Matrix* resultMatrix)
{
	if (originalMatrix->numRows != inverseMatrix->numRows && originalMatrix->numColumns != inverseMatrix->numColumns)
	{
		return PROHIBITED_OPERATION;
	}

	if (CreateMatrix(originalMatrix->numRows, originalMatrix->numColumns, resultMatrix) != OK)
	{
		return MEMORY_ERROR;
	}

	if (MultiplyMatrix(originalMatrix, inverseMatrix, resultMatrix) != OK)
	{
		return UNKNOWN_ERROR;
	}

	return OK;
}

bool IsPrintResultSuccessful(Matrix* resultMatrix)
{
	Matrix unitMatrix;

	if (CreateUnitMatrix(resultMatrix->numRows, resultMatrix->numColumns, &unitMatrix) != OK)
	{
		printf("\nError: memory exceeded!\n");
		return false;
	}

	if (AreMatrixEqual(resultMatrix, &unitMatrix))
	{
		printf("\nMultiplication did create a unit matrix!\n");
	}
	else
	{
		printf("\nEpic fail :(\n");
	}

	DestroyMatrix(&unitMatrix);
	return true;
}