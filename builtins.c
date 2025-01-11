#include "shell.h"

/**
 * handle_builtins - execute builtins commands
 * @args: argument
 * @env: enviorment
 *
 * Return: 0
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
	(void)args;
	exit(EXIT_SUCCESS);
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

