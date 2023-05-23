#include "shell.h"

/**
  * displayPrompt - Display a prompt and wait for the user to type a command.
  * Returns: void
  */



/*Function that Display a prompt and wait for the user to type a command.*/
void displayPrompt(void)
{
	printf("simple_shell> ");
}

/**
  * execute_command - Executes command input by the user
  * @command: command word input
  * Return: void
  */

/*fork the child proces*/
int execute_command(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	pid_t pid = fork();
	int status;


	if (pid == 0)
	{
		if (execve(command, NULL, NULL) == -1)
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
			waitpid(pid, &status, 0);
	}
}

/**
  * main - Runs the shell loop
  * Return: EXIT_SUCCESS
  */

int main(void)
{
	while (1)
	{
		displayPrompt();

	char input[MAX_INPUT_SIZE];

	if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
		printf("\n");
	}

	input[strcspn(input, "\n")] = '\0';

	if (strlen(input) > 0)
	{
		execute_command(input);
	}
	return (EXIT_SUCCESS);
}
