#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


#define MAX_INPUT_SIZE 100
#define MAX_COMMAND_LENGTH 100
#define MAX_PATH_SIZE 100

/*Prototypes*/
void displayPrompt(void);
void execute_command(char *command, char *args[]);
int splitPath(char *path, char *paths[]);
void runShellLoop(void);

#endif
