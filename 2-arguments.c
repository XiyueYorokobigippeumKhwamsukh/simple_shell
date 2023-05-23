#include "shell.h"

/**
  * displayPrompt - Displays command line prompt to the user
  * Return: void
  */

void displayPrompt(void)
{
	printf("simple_shell> ");
}

/**
  * execute_command - Executes user command input
  * @command: user input
  * Return: void
  */

void execute_command(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	char *args[MAX_COMMAND_LENGHT];
	int args_count = 0;

	/*Tokenize the command*/
	char *token = strtok(command, " ");

	while (token != NULL)
	{
		args[args_count++] = token;
		token = strtok(NULL, " ");
	}
	args[args_count] = NULL;

	/*Create child process*/
	pid_t pid = fork();
	int status;

	if (pid == 0)
	{
		if (execve(args[0],  args, NULL) == -1)
		{
			perror("Command execution error");
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("Forking error");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
}

/**
  * main - Runs the shell loop
  * Return: EXIT_SUCCESS
  */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (fgets(command, MAX_COMMAND_LENGTH, stdin) != NULL)
	{
		command[strcspn(command, "\n")] = '\0';
		displayPrompt();

		execute_command(command);
	}

	printf("\n");
	return (EXIT_SUCCESS);
}
