#include "shell.h"
#include <stdio.h>

/**
 * shell_loop - loop of the shell
 * @env: enviorment
 */

void shell_loop(char **env)
{
	char *command = NULL;
	size_t len = 0;
	char **args;
	int status = 1;

	while (status)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		if (getline(&command, &len, stdin) == -1)
		{
			free(command);
			break;
		}

		args = parse_command(command);
		if (args[0] != NULL)
			status = handle_builtins(args, env) || execute_command(args, env);

		free(command);
		free(args);
		command = NULL;
	}
}

