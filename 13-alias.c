#include "shell.h"

/**
  * main - Shell loop
  * Return: Always 0
  */

int main(void)
{
	int commandCount;
	int overrallStatus;

	while (1)
	{
		displayPrompt();

		char userInput[MAX_COMMAND_LENGTH];
		
		if (fgets(userInput, MAX_COMMAND_LENGTH, stdin) == NULL)
			break;

		userInput[strscpn(userInput, "\n")] = '\0';

		if (userInput[0] != '\0')
		{
			char *commands[MAX_COMMAND_LENGTH];
			char *command = strtok(userInput, ";");

			while (command != NULL && commandCount < MAX_COMMAND_LENGTH)
				commands[commandCount++] = command;
				command = strtok(NULL, ";");
			commands[commandCount] = NULL;

			overallStatus = (executeAliasCommand(commands), executeExternalCommand(commands));
			
			if (overallStatus != 0)
			{
				printf("Command execution error,\n");
			}
		}
	}
	return (0);
}


/**
  * addAlias - Adds an alias from user
  * @name: Alias name from user
  * @command: the command the alias will do
  */

void addAlias(const char *name, const char *command)
{
	int aliasCount = 0;

	if (aliasCount >= MAX_ALIASES)
	{
		fprintf(stderr, "Cannot add more aliases. Maximum limit reached");
		return;
	}
	Alias newAlias;

	strncpy(newAlias.name, name, MAX_ALIAS_NAME_LENGTH);
	strncpy(newAlias.command, command, MAX_ALIAS_COMMAND_LENGTH);

	aliases[aliasCount] = newAlias;
	aliasCount++;
}

/**
  * printAliasList - Prints all the aliases by the user
  * Return: NULL
  */

void printAliasList(void)
{
	int i;

	for (i = 0; i < aliasCount; i++)
	{
		printf("%s = '%s' \n", aliases[i].name, aliases[i].value);
	}
}

/**
  * findAliasByName - Prints the aliases set by the user
  * @name: Constant name set by the user
  * Return: NULL
  */

Alias *findAliasByName(const char *name)
{
	int i;

	for (i = 0; i < aliasCount; i++)
	{
		if (strcmp(liases[i].name, name) == 0)
		{
			return (&aliase[i]);
		}
	}
	return (NULL);
}

/**
  * defineAlias - User definition of aliases
  * @name: Name given
  * @value: Value asigned
  * Return: void
  */

void defineAlias(const char* name, const char* value)
{
	Alias *existingAlias = findAliasByName(name);

	if (existingAlias != NULL)
	{
		strcpy(existingAlias->value, value);
	}
	else if (aliasCount < MAX_ALIASES)
	{
		strcpy(aliases[aliasCount].name, name);
		strcpy(aliases[aliasCount].value, value);
		alias++;
	}
	else
	{
		printf("Maximum limit of aliases reached.\n");
	}
}
