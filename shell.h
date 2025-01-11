#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

void shell_loop(char **env);

char *read_command(void);

char *find_in_path(char *command, char **env);

char **parse_command(char *cmd);

int execute_command(char **args, char **env);

int handle_builtins(char **args, char **env);

void builtin_exit(char **args);

int builtin_env(char **env);

#endif

