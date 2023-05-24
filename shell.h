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
#define BUFFER_SIZE 1024
#define MAX_PATHS 10
#define MAX_ARGS 10


/*Prototypes*/
void displayPrompt(void);
void execute_command(char *command, char *args[]);
int splitPath(char *path, char *paths[]);
void runShellLoop(void);
char *readline(void);
void executeCommand(char *command, char **args);
void tokenizeInput(char *input, char **command, char ***arguments);
void cleanup(char **args);
void processInput(void);
char **splitarguments(char *input);
void printEnvironmet(void);
void handleSetEnvCommand(char **args);
void handleUnsetEnvCommand(char **args);
void executeCommandWithPath(char *command, char **args);

#endif
