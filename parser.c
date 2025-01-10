#include "shell.h"

/**
 * read_command -read a command form user
 *
 * Return: a command
 */

char *read_command(void)
{
	char *cmd = NULL;
	size_t len = 0;

	if (getline(&cmd, &len, stdin) == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(cmd);
		return (NULL);
	}

	return (cmd);
}

/**
 * parse_command - read individual arguments
 * @cmd: command
 *
 * Return: a string
 */

char **parse_command(char *cmd)
{
	char **args = malloc(64 * sizeof(char *));
	char *token;
	int index = 0;

	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(cmd, " \t\n");
	while (token != NULL)
	{
		args[index++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[index] = NULL;

	return (args);
}

