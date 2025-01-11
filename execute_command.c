#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * execute_command - execute external command
 * @args: argument
 * @env: enviorment
 *
 * Return: a command
 */

int execute_command(char **args, char **env)
{
	pid_t pid;
	int status;
	char *command_path;

	command_path = find_in_path(args[0], env);
	if (!command_path)
	{
		fprintf(stderr, "hsh: %s: command not found\n", args[0]);
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("./hsh");
			free(command_path);
			exit(EXIT_FAILURE);
		}
	}

	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	free(command_path);
	return (1);
}

