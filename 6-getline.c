#include "shell.h"

/**
  * displayPrompt - Dsplays the shell prompt for user
  * Return: void
  */

void displayPrompt(void)
{
	printf("simple_shell> ");
}

/**
  * readline - Reads all characters the user input
  * Return: line
  */

char *readline(void)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_size;
	static int buffer_index;

	if (buffer_index == 0)
	{
		buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (buffer_size <= 0)
			return (" ");
	}

	int end_index = buffer_index;

	while (end_index < buffer_index)
	{
		if (buffer[end_index] == '\n')
		{
			break;
		}
		end_index++;
	}

	char *line = malloc(sizeof(char) * (end_index - buffer_index + 1));

	strncpy(line, buffer + buffer_index, end_index - buffer_index);
	line[end_index - buffer_index] = '\0';

	buffer_index = end_index + 1;

	return (line);
}
