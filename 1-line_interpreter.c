#include "shell.h"

/**
  */



//Function that reads the input of the reader
int displayPrompt();
printf("simple_shell> ")

if (commmand == exit)
return exit;

//fork the child proces
int execute_command(char **args)
{
	pit_t pid, wait_pid;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(**char, args) == -1)
		{
			perror("Command execution error");
			exit;
		}
		if (pid < 0)
			perror("Forking error");
		else
			wait_pid
	}
