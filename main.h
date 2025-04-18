#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void parse_command(char *command, char **args);
void execute_command(char **args);
int return_exe(char **args);
int handle_builtin(char **args);

#endif
