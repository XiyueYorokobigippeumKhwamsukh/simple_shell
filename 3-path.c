#include "shell.h"

/**
  * main - Runs the loop
  * Return: EXIT_SUCCESS
  */

int main(void)
{
	runShellLoop();
	return (EXIT_SUCCESS);

/**
  * displayPrompt - Displays user input
  * Return: void
  */
void displayPrompt(void)
{
	printf("simple_shell> ");
}
/**
  * execute_command - Executes user input command
  * @command: user input commands
  * @args: user input arguments
  * Return: EXIT_SUCCESS
  */

void execute_command(char *command, char *args[])
{
	if (strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	char *path = getenv("PATH");

	if (path == NULL)
	{
		perror("PATH environment not found.\n");
		return;
	}
	char *paths[MAX_PATH_LENGTH];
	int path_count = splitPath(path, paths), i;

	char fullCommand(MAX_COMMAND_LENGTH + MAX_PATH_LENGTH);

	for (i = 0; i < path_count; i++)
	{
		snprintf(fullCommand, sizeof(fullCommand), "%s/%s", paths[i], command);
		if (access(fullCommand, X_OK) == 0)
		{
			pid_t pid = fork();
			int status;

			if (pid == 0)
			{
				if (execve(command, args, NULL) == -1)
			{
				perror("Command execution error");
				exit(EXIT_FAILURE);
			}
			else if (pid > 0)
				waitpid(pid, &status, 0);
			return;
			}
		}
	}
	fprintf(stderr, "Command '%s' not found\n", command);
}

/**
  * splitPath - Splits PATH in an array
  * @path: pointer to PATH environment variable
  * @paths: array that PATH splits into
  * Return: path_count
  */

int splitPath(char *path, char *paths[])
{
	int path_count = 0;
	char *token = strtok(path, ":");

	while (token != NULL && path_count < MAX_PATH_LENGTH)
	{
		paths[path_count++] = token;
		token = strtok(NULL, ":");
	}
	return (path_count);
}


/**
  * runShellLoop - Loops through the shell
  * Return: void
  */
void runShellLoop(void)
{
	while (1)
	{
		displayPrompt();

		char input[MAX_INPUT_SIZE];

		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		input[strcspn(input, "\n")] = '\0';

		if (strlen(input) > 0)
		{
			char *command = strtok(input, " ");
			char *arguments = strtok(NULL, " ");
			char *args[MAX_COMMAND_LENGTH];
			int args_count = 0;

			while (arguments != NULL && args_count < MAX_COMMAND_LENGTH)
			{
				args[args_count++] = arguments;
				arguments = strtok(NULL. " ");
			}

			args[args_count] = NULL;

			execute_command(command, args);
		}
	}
	return (EXIT_SUCCESS);
}
