#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void parse_command(char *command, char **args, char *delim);
void execute_command(char **args, char **env);

int return_exe(char **args, char **env);

void exit_shell (char *ciao);
char *_getenv(const char *name, char **env);
void print_env(char **env);

#endif
