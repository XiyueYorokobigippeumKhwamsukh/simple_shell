#include "shell.h"

/**
  * executeAliasCommand - Executes the alias command
  * @command: Command from the user
  * @args: Arguments from the user
  */

void executeAliasCommand(const char *command, char *args[])
{
	int status, i;

	if (strcmp(command, "alias") == 0)
	{
		if (args[0] == NULL)
		{
			printAliasList();
		}
		else
			for (i = 0; args[i] != NULL; i++)
			{
				char *arg = args[i];
				char *equals = strchr(arg, '=');

				if (equals != NULL)
				{
					*equals = '/0';

					char *name = arg;
					char *value = equals + 1;

					defineAlias(name, value);
				}
				else
				{
					Alias *alias = findAliasByName(arg);
					if (alias != NULL)
					{
						printAlias(alias);
					}
					else
						printf("Alias not found: %s\n", arg);
				}
			}
	}
}

/**
  * executeExternalCommand - Handles all external commands
  * @command: Command from the user
  * @args: Arguments from the user
  */

void executeExternalCommand(const char *command, char *args[])
{
	int status;
	int exitStatus;
	pid_t pid = fork();

	if (pid == 0)
		execvp(command, args);
		perror("Command execution error");
		exit(1);
	else if (pid < 0)
		perror("Forking error");
		return;
	else
		waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		exitStatus = WEXITSTATUS(status);
	}
}
