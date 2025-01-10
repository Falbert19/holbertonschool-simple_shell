#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * execute_command - execute external command
 * @args: argument
 * @env: enviorment
 * Return: a command
 */

int execute_command(char **args, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("./hsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (1);
}

/**
 * find_in_path - search for commands in PATH
 * @env: enviorment
 * @command: command
 *
 * Return: NULL
 */

char *find_in_path(char *command, char **env)
{
	(void)command;
	(void)env;

	return (NULL);
}

