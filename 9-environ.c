#include "shell.h"

/**
  * main - Runs the shell loop
  * Return: Always 0
  */

int main(void)
{
	while (1)
	{
		diplayPrompt();

		char userInput[MAX_COMMAND_LENGTH];

		if (fgets(userInput, sizeof(userInput), stdin) == NULL)
		{
			break;
		}

		userInput[strcspn(userInput, "\n")] = '\0';

		if (strlen(userInput) > 0)
		{
			char *command = strtok(userInput, " ");
			char *args[MAX_PATHS];
			int argIndex = 0;

			while (command != NULL)
			{
				args[argIndex] = command;
				argIndex++;

				if (argIndex >= MAX_PATHS - 1)
				{
					break;
				}

				command == strtok(NULL, " ");
			}

			args[argIndex] = NULL;
			executeCommand(args[0], args);
		}
	}
	return (0);
}

/**
  * executeCommand - Executes the command from the user
  * @command: command from the user
  * @args: arguments from the user
  */

void executeCommand(char *command, char **args)
{
	int status, result;

	if (strcmp(command, "exit") == 0)
		if (args[0] == NULL)
			exit(EXIT_SUCCESS);
		else
			status = atoi(args[0]);
			exit(status);
		else if (strcmp(command, "env") == 0)
			printEnvironment();
		else if (strcmp(command, "setenv") == 0)
			if (args[0] == NULL || args[1] == NULL || args[2] != NULL)
				fprintf(stderr, "Invalid: Correct syntax; setenv variable");
			else
				result = setEnvironmentVariable(args[0], args[1]);
				if (result == -1)
					fprintf(stderr, "Failed to set environment variable\n");
		else if (strcmp(command, "unsetenv") == 0)
			if (args[0] == NULL || args[1] != NULL)
				fprintf(stderr, "Invalid: Correct syntax: unsetenv variable");
				else
					result = unsetEnvironmentVariable(args[0]);
					if (result == -1)
						fprintf(stderr, "Failed to uset environment variable");
		else
			executeCommandWithPath(command, arguments);
}

/**
  * printEnvironment - Prints the environment the user is using
  * Return: void
  */

void printEnvironment(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

/**
  * setEnvironmentVariable - sets or modify an environment variable
  * @variable: Variable being set
  * @value: Variable name
  * Return: 0 if successfully set -1 if not
  */

int setEnvironmentVariable(char *variable, char *value)
{
	if (setenv(variable, value, 1) == -1)
	{
		return (-1);
	}
	return (0);
}

/**
  * unsetEnvironmentVariable - unset or remove an environment variable
  * @variable: Variable to unset
  * Return: 0 on success -1 if not
  */

int unsetEnvironmentVariable(char *variable)
{
	if (unsetenv(variable) == -1)
	{
		return (-1);
	}
	return (0);
}
