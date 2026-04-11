//
// Created by x3r1x on 10.04.2026.
//

#include <stdio.h>

typedef enum
{
	INT_TYPE = 1,
	VECTOR_TYPE = -1
} VariableType;

typedef enum
{
	UNKNOWN_TYPE = 1,
	COULD_NOT_READ_TYPE = 2,
	COULD_NOT_READ_INFO = 3
} ReadErrors;

typedef enum
{
	ADDITION = '+',
	SUBSTRACTION = '-',
	MULTIPLICATION = '*',
	EQUALITY = '='
} VariableOperations;

typedef enum
{
	UNKNOWN_OPERATION = 1,
	RESTRICTED_OPERATION = 2,
	UNKNOWN_ERROR = 3
} OperationErrors;

typedef struct
{
	int x;
	int y;
} Vec2;

typedef struct
{
	VariableType type;

	union
	{
		int i;
		Vec2 vector;
	};
} Variable;

constexpr int OK = 0;
constexpr char INT_TYPE_SYMBOL = 'i';
constexpr char VECTOR_TYPE_SYMBOL = 'v';

int ReadVariable(Variable* var);
void PrintVariable(Variable v);
int AddVariables(Variable a, Variable b, Variable* result);
int SubVariables(Variable a, Variable b, Variable* result);
int MulVariables(Variable a, Variable b, Variable* result);
bool EqualVariables(Variable a, Variable b);
bool IsOperateVariablesSuccessful(Variable a, Variable b, Variable* result, bool* isArithmetic);

void HandleReadError(int errorCode);
void HandleOperationError(int errorCode);

int main(void)
{
	Variable variable1, variable2, resultVariable;
	bool isOperationArithmetic;
	int status;

	if ((status = ReadVariable(&variable1)) != OK)
	{
		HandleReadError(status);
		return 1;
	}

	if ((status = ReadVariable(&variable2)) != OK)
	{
		HandleReadError(status);
		return 1;
	}

	if (!IsOperateVariablesSuccessful(variable1, variable2, &resultVariable, &isOperationArithmetic))
	{
		return 1;
	}

	if (isOperationArithmetic)
	{
		PrintVariable(resultVariable);
	}
}

int ReadVariable(Variable* var)
{
	char type;

	if (scanf("%c", &type) != 1)
	{
		return COULD_NOT_READ_TYPE;
	}

	switch (type)
	{
	case VECTOR_TYPE_SYMBOL:
		if (scanf("%d %d\n", &var->vector.x, &var->vector.y) != 2)
		{
			return COULD_NOT_READ_INFO;
		}
		var->type = VECTOR_TYPE;

		break;
	case INT_TYPE_SYMBOL:
		if (scanf("%d\n", &var->i) != 1)
		{
			return COULD_NOT_READ_INFO;
		}
		var->type = INT_TYPE;

		break;
	default:
		return UNKNOWN_TYPE;
	}

	return OK;
}

bool IsOperateVariablesSuccessful(Variable a, Variable b, Variable* result, bool* isArithmetic)
{
	int status;
	char operation;
	*isArithmetic = true;

	scanf("%c", &operation);

	switch (operation)
	{
	case ADDITION:
		if ((status = AddVariables(a, b, result)) != OK)
		{
			HandleOperationError(status);
			return false;
		}
		break;
	case SUBSTRACTION:
		if ((status = SubVariables(a, b, result)) != OK)
		{
			HandleOperationError(status);
			return false;
		}
		break;
	case MULTIPLICATION:
		if ((status = MulVariables(a, b, result)) != OK)
		{
			HandleOperationError(status);
			return false;
		}
		break;
	case EQUALITY:
		if (scanf("%c", &operation) != 1)
		{
			HandleOperationError(UNKNOWN_OPERATION);
			return false;
		}

		*isArithmetic = false;

		if (EqualVariables(a, b))
		{
			printf("Variables are equal!\n");
		}
		else
		{
			printf("Variables aren't equal!\n");
		}
		break;
	default:
		HandleOperationError(UNKNOWN_OPERATION);
		return false;
	}

	return true;
}

void PrintVariable(const Variable v)
{
	switch (v.type)
	{
	case INT_TYPE:
		printf("%d\n", v.i);
		break;
	case VECTOR_TYPE:
		printf("(%d, %d)\n", v.vector.x, v.vector.y);
		break;
	default:
		printf("Unknown variable type!\n");
	}
}

int AddVariables(const Variable a, const Variable b, Variable* result)
{
	if (a.type * b.type < 0)
	{
		return RESTRICTED_OPERATION;
	}

	switch (a.type)
	{
	case INT_TYPE:
		result->type = INT_TYPE;
		result->i = a.i + b.i;
		break;
	case VECTOR_TYPE:
		result->type = VECTOR_TYPE;
		result->vector.x = a.vector.x + b.vector.x;
		result->vector.y = a.vector.y + b.vector.y;
		break;
	default:
		return UNKNOWN_ERROR;
	}

	return OK;
}

int SubVariables(Variable a, Variable b, Variable* result)
{
	if (a.type * b.type < 0)
	{
		return RESTRICTED_OPERATION;
	}

	switch (a.type)
	{
	case INT_TYPE:
		result->type = INT_TYPE;
		result->i = a.i - b.i;
		break;
	case VECTOR_TYPE:
		result->type = VECTOR_TYPE;
		result->vector.x = a.vector.x - b.vector.x;
		result->vector.y = a.vector.y - b.vector.y;
		break;
	default:
		return UNKNOWN_ERROR;
	}

	return OK;
}

int MulVariables(Variable a, Variable b, Variable* result)
{
	switch (a.type)
	{
	case INT_TYPE:
		switch (b.type)
		{
		case INT_TYPE:
			result->type = INT_TYPE;
			result->i = a.i * b.i;
			break;
		case VECTOR_TYPE:
			result->type = VECTOR_TYPE;
			result->vector.x = a.i * b.vector.x;
			result->vector.y = a.i * b.vector.y;
			break;
		default:
			return UNKNOWN_ERROR;
		}

		break;
	case VECTOR_TYPE:
		switch (b.type)
		{
		case INT_TYPE:
			result->type = VECTOR_TYPE;
			result->vector.x = b.i * a.vector.x;
			result->vector.y = b.i * a.vector.y;
			break;
		case VECTOR_TYPE:
			result->type = VECTOR_TYPE;
			result->vector.x = a.vector.x * b.vector.x;
			result->vector.y = a.vector.y * b.vector.y;
			break;
		default:
			return UNKNOWN_ERROR;
		}
		break;
	default:
		return UNKNOWN_ERROR;
	}

	return OK;
}

bool EqualVariables(Variable a, Variable b)
{
	if (a.type * b.type < 0)
	{
		return false;
	}

	switch (a.type)
	{
	case INT_TYPE:
		return a.i == b.i;
	case VECTOR_TYPE:
		return a.vector.x == b.vector.x && a.vector.y == b.vector.y;
	default:
		return false;
	}
}

void HandleReadError(const int errorCode)
{
	switch (errorCode)
	{
	case UNKNOWN_TYPE:
		printf("Error: unknown type given!\n");
		break;
	case COULD_NOT_READ_INFO:
		printf("Error: wrong info format given!\n");
		break;
	case COULD_NOT_READ_TYPE:
		printf("Error: wrong type format given!\n");
		break;
	default:
		printf("Unknown error!\n");
	}
}

void HandleOperationError(const int errorCode)
{
	switch (errorCode)
	{
	case UNKNOWN_OPERATION:
		printf("Error: unknown operation!\n");
		break;
	case RESTRICTED_OPERATION:
		printf("Error: this operation is prohibited between these two variables.\n");
		break;
	default:
		printf("Unknown error!\n");
	}
}