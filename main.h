#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void parse_command(char *command, char **args, char *delim);
int execute_command(char **args, char **env);

int return_exe(char **args, char **env);

void exit_shell(char *ciao, int exit_status);
char *_getenv(const char *name, char **env);
void print_env(char **env);
int handle_env(char **args, char **env, int *exit_status);

#endif
