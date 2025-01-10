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

/**
 * find_in_path - search for commands in PATH
 * @env: enviorment
 * @command: command
 *
 * Return: NULL
 */

char *find_in_path(char *command, char **env)
{
	char *path = NULL, *path_copy, *token, full_path[1024];
	struct stat st;
	int i = 0;

	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i] + 5;
			break;
		}
	}
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (strdup(full_path));
		}
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

