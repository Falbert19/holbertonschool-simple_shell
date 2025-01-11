#include "shell.h"

/**
 * handle_builtins - executes
 * @args: argument
 * @env: enviorment
 *
 * return: exit
 */

int handle_builtins(char **args, char **env)
{
	if (strcmp(args[0], "exit") == 0)
		builtin_exit(args);
	else if (strcmp(args[0], "env") == 0)
		return (builtin_env(env));

	return (0);
}

/**
 * builtin_exit - cleans resources
 * @args: argument
 *
 * Return: exit
 */

void builtin_exit(char **args)
{
	int exit_status = 0;

	if (args[1] != NULL)
	{
		exit_status = atoi(args[1]);
		if (exit_status < 0)
		{
		fprintf(stderr, "exit: Invalid exit status\n");
		return 2;
		}
	}

	exit(exit_status);
}

/**
 * builtin_env - prints current env
 * @env: enviorment
 *
 * Return: 1
 */

int builtin_env(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}

	return (1);
}

