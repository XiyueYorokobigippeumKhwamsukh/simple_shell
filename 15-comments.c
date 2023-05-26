#include "shell.h"

int executeCommands(char *commands[])
{
	int previousCommandStatus = 0, i;

	for (i = 0; commands[i] != NULL; i++)
		char* command = strtok(commands[i], " \t\n\r");
		
		if (command != NULL)
			command = strtok(command, "#");
			if (strlen(command) == 0)
				continue;
			if (strstr(command, "&&") != NULL)
				//commands &&
			else if (strstr(command, "||") != NULL)
				//
			else
				int argCount = 0;
				char* args[MAX_COMMAND_LENGTH];

				args[argCount++] = command;
				while (argCount < MAX_COMMAND_LENGTH)
					args[argCount] = strtok(NULL, " \t\n\r");
					if (args[argCount] == NULL)
						break;
				argCount++;

				prevCommandStatus = executeCommands(args[0], args + 1);
	return (previousCommandStatus);
}

/**
  * main - Runs through the shell loop
  * Return: Always 0
  */

int main(void)
{
	int overallStatus;
	int commandCount;

	while (1)
	{
		displayPrompt();

		char input[MAX_COMMAND_LENGTH];

		if (fgets(input, sizeof(input), stdin) == NULL)
			break;

		userInput[strcspn(userInput, "\n")] = '\0';

		if (userInput[0] != '\0')
			char* commands[MAX_COMMAND_LENGTH];
			char* command = strtok(userInput, ";");

			commandCount = 0;
			while (command != NULL && commandCount < MAX_COMMAND_LENGTH)
				commands[commandCount++] = command;
				command = strtok(NULL, ";");

			 commands[commandCount] = NULL;

			 overallStatus = executeCommands(commands);
			 if (overallStatus != 0)
				 printf("Commands execution error");
	}
	return (0);
}
