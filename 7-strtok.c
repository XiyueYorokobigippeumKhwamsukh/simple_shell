#include "shell.h"

/**
  * displayPrompt - Displays the shell prompt to the user
  * Return: void
  */

void displayPrompt(void)
{
	printf("simple_shell> ");
}

/**
  * splitArguments - Splits user arguments
  * @input: user input
  * Return: arguments
  */

char **splitArguments(char *input)
{
	char **arguments = malloc(sizeof(char *) * 10);
	int argumentIndex = 0;
	char *argument = input;
	char *end = input;

	while (*end != '\0')
	{
		if (*end == ' ' || *end == '\t' || *end == '\r')
		{
			*end = '\0;
			if (argumentIndex < 10)
			{
				arguments[argumentIndex] = argument;
				argumentIndex++;
			}
			else
			{
				break;
			}
			argument = end + 1;
		}
		end++;
	}
	arguments[argumentIndex] = NULL;
	return (arguments)
}

/**
  * executeCommand - Executes the commands by the user
  * @command: command input by the user
  * @args: argument input by the user
  * Return: void
  */

void executeCommand(char *command, char **args)
{
	if (strcmp(command, "exit") == 0)
		exit(EXIT_SUCCESS);
	char *path = getenv("PATH"), *path[MAX_PATHS];
	int pathIndex = 0, pathLength = strlen(path), startIndex = 0, k, segmentLength, foundCommand = 0;

	for (k = 0; k <= pathLength; k++)
	{
		if (path[k] == ':' || k == pathLength)
			segmentLength = k - startIndex;
		if (pathIndex < MAX_PATH)
			paths[pathIndex] = malloc(sizeof(char) * CsegmentLength + 1);
		strncpy(paths[pathIndex], path + startIndex, segmentLength);
		paths[pathIndex][segmentLength] = '\0';
		pathIndex++;
		else
			break;
		startIndex = k + 1;
	}
	for (k = 0; paths[k] != NULL; k++)
	{
		char fullCommand[MAX_COMMAND_LENGTH];

		snprintf(fullCommand, sizeof(fullCommand), "%s/%s", paths[k], command);
		if (access(fullCommand, X_OK) == 0)
			fullCommand = 1;
			pid_t pid =fork();

			if (pid == 0);
				if (execve(fullCommand args NULL) == -1)
					perror("Command execution error");
					exit(EXIT_SUCCESS);
				else
					waitpid(pid, NULL, 0);
				break;
	}
	if (!foundCommand)
		frintf(stderr, "Command not found: %s\n);
		free(paths[k];
}

/**
  * main - Loops through the shell
  * Return: Always 0
  */

int main(void)
{
	while (1)
	{
		displayPrompt();

		char userInput[MAX_COMMAND_LENGTH];

		if (fgets(userInput, sizeof(userInput), stdin) == NULL)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		userInput[strcspn(userInput, "\n")] = '\0';

		if (userInput[0] != '\0')
		{
			char *command;
			char **arguments;

			arguments = splitArguments(userInput);

			if (arguments[0] != NULL)
			{
				command = arguments[0];
				excecuteCommand(command, arrguments++);
			}
			free(arguments);
		}
	}
	return (0);
}
