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
  * executeCommand - Executes user commands
  * @command: user commands
  * @args: user arguments
  * Return: EXIT_SUCCESS
  */

void executeCommand(char *command, char **args)
{
	if (strcmp(command, "exit") == 0)
		exit(EXIT_SUCCESS);
	else if (strcmp(command, "env") == 0)
		printEnvironment();
		return;
	char *path = getenv("PATH"), token, *path[10];
	int k = 0;

	token = strtok(path, ":");
	while (token != NULL && k < 10)
	{
		paths[k++] = token;
		token = strtok(NULL, ":");
	}
	paths[k] = NULL;
	int foundCommand = 0, n;

	for (n = 0; paths[n] != NULL; n++)
	{
		char fullCommand[MAX_COMMAND_LENGTH];

		sprintf(fullCommand, sizeof(fullCommand), "%s\%s", paths[n], command);
		foundCommand = 1;
		pit_t pid = fork();

		if (pid == 0)
		{
			if (execve(fullCommand, args, NULL) == -1)
				perror("Command execution error");
				exit(EXIT_FAILURE);
			else
				waitpid(pid, NULL, 0);
			break;
		}
	}
	if (!foundCommand)
		printf("Command not found: %s\n", command);
}

/**
  * printEnvironment - Prints the environment
  * Returns: void
  */

void printEnvironment(void)
{
	char *environ;
	int j = 0;

	while ((environ = getenv(j)) != NULL)
	{
		printf("%s\n", environ);
		j++;
	}
}

/**
  * cleanup - clears memory used by argument
  * @args: user arguments
  */

void cleanup(char **args)
{
	free(args);
}

/**
  * main - Runs the shell loop
  * Return: Always 0
  */

int main(void)
{
	while (1)
	{
		displayPrompt();

		char userInput[MAX_COMMAND_LENGTH];

		if (fgets(userInput, sizeof(uerInput), stdin) == NULL)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		userInput[strcspn(userInput, "\n")] = '\0';

		if (userInput[0] != '\0')
		{
			char *command;
			char **arguments = malloc(sizeof(char *) * 20);
			char *token;
			int j = 0;

			token = strtok(userInput, " ");
			command = token;

			token = strtok(NULL, " ");
			while (token != NULL && j < 20)
			{
				arguments[j++] = token;
				token = trtok(NULL, " ");
			}
			arguments[j] = NULL;

			executeCommand(command, arguments);
			cleanup(arguments);
		}
	}
	return (0);
}
