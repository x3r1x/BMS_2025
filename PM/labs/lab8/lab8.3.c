//
// Created by x3r1x on 28.04.2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

constexpr int MAX_COMMAND_LENGTH = 10;
constexpr int COMMANDS_COUNT = 7;
constexpr char HELP_STRING[] = "help";
constexpr char STATUS_STRING[] = "status";
constexpr char MOVEROBOT_STRING[] = "moverobot";
constexpr char EXIT_STRING[] = "exit";
constexpr char RESET_STRING[] = "reset";
constexpr char TELEPORT_STRING[] = "teleport";
constexpr char HISTORY_STRING[] = "history";
constexpr char DIRECTION_UP_STRING[] = "up";
constexpr char DIRECTION_DOWN_STRING[] = "down";
constexpr char DIRECTION_RIGHT_STRING[] = "right";
constexpr char DIRECTION_LEFT_STRING[] = "left";
constexpr int SPACE = ' ';

typedef int (*CommandHandler)(void* context, int argc, char* argv[]);

typedef enum
{
	HELP,
	STATUS,
	MOVEROBOT,
	EXIT,
	UNKNOWN_ROBOT_COMMAND
} RobotCommands;

typedef enum
{
	ERROR = -100,
	HANDLER_EXIT = -1,
	OK = 0,
	WRONG_USAGE = 1,
	UNKNOWN_COMMAND = 2
} HandlerStatus;

typedef enum
{
	RIGHT,
	LEFT,
	UP,
	DOWN,
	UNKNOWN_DIRECTION
} RobotDirections;

typedef struct
{
	const char* name;
	CommandHandler handler;
	void* context; // контекст конкретной команды
	const char* help;
} Command;

typedef struct
{
	int x;
	int y;
} Robot;

typedef struct
{
	char** commandsList;
	int commandsAmount;
} History;

int HelpCommand(void* context, int argc, char* argv[])
{
	const Command* commands = (Command*)context;

	if (argc != 0)
	{
		printf("Wrong usage: %s\n", HELP_STRING);
		return WRONG_USAGE;
	}

	for (int i = 0; i < COMMANDS_COUNT; i++)
	{
		printf("%s - %s\n", commands[i].name, commands[i].help);
	}

	return OK;
}

int StatusCommand(void* context, int argc, char* argv[])
{
	const Robot* robot = (Robot*)context;

	if (argc != 0)
	{
		printf("Wrong usage: %s\n", STATUS_STRING);
		return WRONG_USAGE;
	}

	printf("Robot position: x=%d y=%d\n", robot->x, robot->y);

	return OK;
}

RobotDirections GetRobotDirection(const char* direction)
{
	if (strcmp(direction, DIRECTION_RIGHT_STRING) == 0)
	{
		return RIGHT;
	}
	if (strcmp(direction, DIRECTION_DOWN_STRING) == 0)
	{
		return DOWN;
	}
	if (strcmp(direction, DIRECTION_LEFT_STRING) == 0)
	{
		return LEFT;
	}
	if (strcmp(direction, DIRECTION_UP_STRING) == 0)
	{
		return UP;
	}

	return UNKNOWN_DIRECTION;
}

void MoveRobot(Robot* robot, const RobotDirections direction, const int step)
{
	switch (direction)
	{
	case RIGHT:
		robot->x += step;
		break;
	case LEFT:
		robot->x -= step;
		break;
	case UP:
		robot->y += step;
		break;
	case DOWN:
		robot->y -= step;
		break;
	case UNKNOWN_DIRECTION:
		break;
	}
}

int MoveRobotCommand(void* context, int argc, char* argv[])
{
	Robot* robot = (Robot*)context;

	if (argc != 2)
	{
		printf("Wrong usage: %s <direction> <positive integer>\nWhere <direction> is either %s, %s, %s or %s\n", MOVEROBOT_STRING, DIRECTION_DOWN_STRING, DIRECTION_LEFT_STRING, DIRECTION_RIGHT_STRING, DIRECTION_UP_STRING);
		return WRONG_USAGE;
	}

	const RobotDirections direction = GetRobotDirection(argv[0]);

	if (direction == UNKNOWN_DIRECTION)
	{
		printf("Wrong usage: in %s <direction> is either <right>, <left>, <up> or <down>\n", MOVEROBOT_STRING);
		return WRONG_USAGE;
	}

	const int robotStep = (int) strtol(argv[1], nullptr, 0);
	if (robotStep < 0)
	{
		printf("Wrong usage: in %s <positive integer> should be greater than 0!\n", MOVEROBOT_STRING);
		return WRONG_USAGE;
	}

	MoveRobot(robot, direction, robotStep);

	return OK;
}

int ExitCommand(void* context, int argc, char* argv[])
{
	printf("Bye!\n");

	return HANDLER_EXIT;
}

int ResetCommand(void* context, const int argc, char* argv[])
{
	Robot* robot = (Robot*) context;

	if (argc != 0)
	{
		printf("Wrong usage: %s\n", RESET_STRING);
		return WRONG_USAGE;
	}

	robot->x = 0;
	robot->y = 0;

	return OK;
}

int TeleportCommand(void* context, int argc, char* argv[])
{
	Robot* robot = (Robot*) context;

	if (argc != 2)
	{
		printf("Wrong usage: %s <x> <y> where <x> and <y> are integers!\n", TELEPORT_STRING);
		return WRONG_USAGE;
	}

	const int robotX = (int) strtol(argv[0], nullptr, 0);
	const int robotY = (int) strtol(argv[1], nullptr, 0);

	robot->x = robotX;
	robot->y = robotY;

	return OK;
}

int HistoryCommand(void* context, const int argc, char* argv[])
{
	const History* history = (History*) context;

	if (argc != 0)
	{
		printf("Wrong usage: %s\n", HISTORY_STRING);
		return WRONG_USAGE;
	}

	printf("History:\n");
	for (int i = 0; i < history->commandsAmount; i++)
	{
		printf("%s\n", history->commandsList[i]);
	}

	return OK;
}

void FreeArgv(const int argc, char** argv)
{
	for (int i = 0; i < argc; i++)
	{
		if (argv[i] != nullptr)
		{
			free(argv[i]);
		}
	}

	free(argv);
}

char* ReadString()
{
	char* string = nullptr;
	size_t len = 0;
	int ch;

	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		char* newString = realloc(string, len + 1);

		if (newString == nullptr)
		{
			goto error;
		}

		string = newString;
		newString[len++] = (char)ch;
	}

	char* newString = realloc(string, len + 1);

	if (newString == nullptr)
	{
		goto error;
	}

	string = newString;
	newString[len] = '\0';

	return string;

error:
	if (string != nullptr)
	{
		free(string);
	}
	return nullptr;
}

char* GetSubstringBeforeSymbol(const char* string, const char symbol)
{
	char* symbolPtr = strchr(string, symbol);

	if (symbolPtr == nullptr)
	{
		return strdup(string);
	}

	const size_t substringLen = symbolPtr - string;
	char* substring = malloc(substringLen + 1);

	if (substring == nullptr)
	{
		return nullptr;
	}

	memcpy(substring, string, substringLen);
	substring[substringLen] = '\0';

	return substring;
}

bool ParseString(int* argc, char*** argv)
{
	*argc = 0;
	*argv = nullptr;
	char* string = ReadString();
	char* spacePointer = string;
	bool isStart = true;

	if (string == nullptr)
	{
		return false;
	}

	while (spacePointer < string + strlen(string))
	{
		if (isStart)
		{
			isStart = false;
			spacePointer += 1;
		}

		char* substring = GetSubstringBeforeSymbol(spacePointer, SPACE);

		if (substring == nullptr)
		{
			free(string);
			return false;
		}

		char** tempArgv = realloc(*argv, (*argc + 1) * sizeof(char*));

		if (tempArgv == nullptr)
		{
			free(string);
			free(substring);
			return false;
		}

		*argv = tempArgv;
		(*argv)[(*argc)++] = substring;

		spacePointer += strlen(substring) + 1;
	}

	free(string);
	return true;
}

char* GetFullCommand(char command[MAX_COMMAND_LENGTH], const int argc, char** argv)
{
	size_t sizeOfFullCommand = strlen(command) + 1;

	for (int i = 0; i < argc; i++)
	{
		sizeOfFullCommand += strlen(argv[i]) + 1;
	}

	char* fullCommand = malloc(sizeOfFullCommand);

	if (fullCommand == nullptr)
	{
		return nullptr;
	}

	strcpy(fullCommand, command);

	for (int i = 0; i < argc; i++)
	{
		strcat(fullCommand, " ");
		strcat(fullCommand, argv[i]);
	}

	return fullCommand;
}

bool SaveCommandToHistory(char command[MAX_COMMAND_LENGTH], const int argc, char** argv, History* history)
{
	char* fullCommand = GetFullCommand(command, argc, argv);

	if (fullCommand == nullptr)
	{
		return false;
	}

	char** newHistory = realloc(history->commandsList, (history->commandsAmount + 1) * sizeof(char*));

	if (newHistory == nullptr)
	{
		free(fullCommand);
		return false;
	}

	history->commandsList = newHistory;
	history->commandsList[history->commandsAmount++] = fullCommand;
	return true;
}

void FreeHistoryArray(History* history)
{
	for (int i = 0; i < history->commandsAmount; i++)
	{
		free(history->commandsList[i]);
	}

	free(history->commandsList);
	history->commandsAmount = 0;
}

int HandleCommand(char unparsedCommand[MAX_COMMAND_LENGTH], const Command* commands, History* history)
{
	for (int i = 0; i < COMMANDS_COUNT; i++)
	{
		if (strcmp(unparsedCommand, commands[i].name) == 0)
		{
			int argc;
			char** argv;

			if (!ParseString(&argc, &argv))
			{
				return ERROR;
			}

			if (commands[i].handler(commands[i].context, argc, argv) == HANDLER_EXIT)
			{
				FreeArgv(argc, argv);
				return HANDLER_EXIT;
			}

			if (!SaveCommandToHistory(commands[i].name, argc, argv, history))
			{
				FreeArgv(argc, argv);
				return ERROR;
			}

			FreeArgv(argc, argv);
			return OK;
		}
	}

	return UNKNOWN_COMMAND;
}

int main()
{
	Robot robot = {
		.x = 0,
		.y = 0
	};

	History history = {0};

	Command commands[] = {
		{ HELP_STRING, HelpCommand, commands, "show available commands" },
		{ STATUS_STRING, StatusCommand, &robot, "show robot position" },
		{ MOVEROBOT_STRING, MoveRobotCommand, &robot, "move robot" },
		{ EXIT_STRING, ExitCommand, NULL, "exit interpreter" },
		{RESET_STRING, ResetCommand, &robot, "resets the robot to x=0 and y=0"},
		{TELEPORT_STRING, TeleportCommand, &robot, "teleports the robot"},
		{HISTORY_STRING, HistoryCommand, &history, "shows history of commands"}
	};

	int status = OK;

	while (status != HANDLER_EXIT)
	{
		char command[MAX_COMMAND_LENGTH];

		if (scanf("%s", command) != 1)
		{
			goto error;
		}

		if ((status = HandleCommand(command, commands, &history)) == ERROR)
		{
			goto error;
		}
	}

	FreeHistoryArray(&history);
	return 0;
error:
	fprintf(stderr, "Error!\n");
	FreeHistoryArray(&history);
	return 1;
}