#include "shell.h"

/**
  * executeCommands - Executes a single command and handles
  * built-in commands and external commands
  * @command: Command from the user
  * @args: Arguments from the user
  */

int executeCommands(char *command, char *args[])
{
	int status, result;

	if (strcmp(command, "exit") == 0)
		if (args[0] == NULL)
			exit(0);
		else
			status = atoi(args[0]);
			exit(status);
		else if ((strcmp(command, "env") == 0)
			char* const env[] = (NULL);

			execve("/usr/bin/env", args, env);
			perror("execve");
			exit(1);
		else if (strcmp(command, "setenv") == 0)
			if (args[0] != NULL && args[1] == NULL)
				result = unsetenv(args[0]);
				if (result != 0)
					printf("unsetting environment variable error\n");
				else
					printf("Use: unsetenv<variable>\n");
		else if ((strcmp(command, "cd") == 0)
			if (args[0] == NULL)
				char* homeDir = getenv("HOME");

				if (homeDir != NULL)
					chdir(homeDir);
		else if (args[1] == NULL)
			if (strcmp(args[0], "-") == 0)
				char* oldPwd = getenv("OLDPWD");

				if (oldPwd != NULL)
					chdir(oldPwd);
			else
				result = chdir(args[0]);
				if (result != 0)
					printf("Changing directory error\n");
			else
				printf("Use: cd [directory]\n");
		else
			executeExternalcommand(commands);
}
