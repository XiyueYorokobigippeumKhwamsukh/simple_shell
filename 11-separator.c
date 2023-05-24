#include "shell.h"

/**
  * executeCommands - Executes the users commands
  * @commands: Users commands
  * Return: void
  */

void executeCommands(char *commands)
{
	char *command = strtok(commands, ";");

	while (command != NULL)
	{
		if (strlen(command) > 0)
		{
			char *args[MAX_ARGS];
			int argIndex = 0;

			char *token = strtok(command, " ");

			while (token != NULL)
			{
				args[argIndex] = token;
				argIndex++;

				if (argIndex >= MAX_ARGS - 1)
				{
					break;
				}
				token = trtok(NULL, " ");
			}
			args[argIndex] = NULL;
			executeCommand(args[0], args);
		}
		command = strtok(NULL, ";");
	}
}

/**
  * main - Executes the loop
  * Return: Always 0
  */

int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		displayPrompt();

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if (strlen(input) > 0)
		{
			executeCommands(input);
		}
	}
	return (0);
}
