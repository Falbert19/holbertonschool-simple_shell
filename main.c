#include "shell.h"

/**
 * main - entry point
 * @argv: argument variable
 * @argc: argument char
 * @env: enviorment
 *
 * Return: 0
 */

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;

	shell_loop(env);

	return (0);
}

