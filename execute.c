#include "shell.h"

/**
  * executeCommandWithPath - Executes command using the paths
  * @command: command from user
  * @args: arguments from user
  * Return: void
  */

void executeCommandWithPath(char *command, char **args)
{
	char *path = getenv("PATH");
	char *paths[MAX_PATHS];
	int pathIndex = 0, segmentLength;
	int pathLength = strlen(path);
	int startIndex = 0, i, foundCommand;

	for (i = 0; i <= pathLength; i++)
		if (path[i] == ':' || i == pathLength)
			segmentLength = i - startIndex;
			if (pathIndex < MAX_PATHS)
				paths[pathIndex] = malloc((segmentLength + 1) * sizeof(char));
				strncpy(paths[pathIndex], path + startIndex, segmentLength);
				paths[pathIndex][segmentLength] = '\0';
				pathIndex++;
			else
				break;
			startIndex = i + 1;
	paths[pathIndex] = NULL;
	foundCommand = 0;

	for (i = 0; paths[i] != NULL; i++)
		char fullCommand[MAX_COMMAND_LENGTH];

		snprintf(fullCommand, sizeof(fullCommand), "%s/%s", paths[i], command);
		if (access(fullCommand, X_OK) == 0)
			foundCommand = 1;
			pid_t pid = fork();

			if (pid == 0)
				if (execve(fullCommand, args, NULL) == -1)
					fprintf(stderr, "Command execution failed.\n");
					exit(1);
		else
			waitpid(pid, NULL, 0);
		break;
	if (!foundCommand)
		fprintf(stderr, "Command not found: %s\n", command);
	for (i = 0; paths[i] != NULL; i++)
		free(paths[i]);
}
