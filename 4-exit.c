#include "shell.h"

/**
  * displayPrompt - Displays user prompt in the shell
  * Return: void
  */

void displayPrompt(void)
{
	printf("Simple_shell> ");
}

/**
  * executeCommand - Executes the shell loop
  * @command: Command by the user
  * @args: argument by the user
  * Return: void
  */

void executeCommand(char *command, char **args)
{
	if (strcmp(command, "exit") == 0)
		exit(EXIT_SUCCESS);
	char *path = getenv("PATH"), *paths[10], *token;
	int i = 0;

	token = strtok(path, ":");
	while (token != NULL && i < 10)
	{
		paths[i++] = token;
		token = strtok(NULL, ":");
	}
	path[i] = NULL;

	int foundCommand = 0, m;

	for (m = 0; paths[m] != NULL; m++)
	{
		char fullCommand[MAX_COMMAND_LENGTH];

		snprintf(fullCommand, sizeof(fullCommand), "%s/%s", paths[m]. command);
		if (access(fullCommand, X_OK) == 0)
		{
			foundCommand = 1;
			pid_t pid;

			pid = fork();

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
			fprintf(stderr, "Command not found: %s\n", command);
	}
}

/**
  * tokenizeInput - splits input into command and arguments
  * @input: what the user types into the shell
  * @command: the command the user gives
  * @arguments: the arguments the user provides
  */

void tokenizeInput(char *input, char **command, char **arguments)
{
	char *token;
	int i = 0;

	token = strtok(input, " ");
	*command = token;
	token = strtok(NULL, " ");
	while (token != NULL && i < 10)
	{
		(*arguments)[++] = token;
		token = strtok(NULL, " ");
	}
	(*arguments)[i] = NULL;
}

/**
  * main - Runs the loop
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

		userInput[strcpn(userInput, "\n")] = '\0';

		if (userInput[0] != '\0')
		{
			char *command;
			char **arguments = malloc(sizeof(char *) * 10);

			tokenizeInput(userInput, &command, &arguments);
			executeCommand(command, arguments);
			free(args);
	}
	return (0);
}
