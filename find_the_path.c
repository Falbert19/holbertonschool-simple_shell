#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * find_in_path - Searches for a command in the PATH.
 * @command: Command to search for.
 * @env: Environment variables.
 *
 * Return: Full path or NULL
 */

char *find_in_path(char *command, char **env)
{
	char *path = NULL, *path_copy = NULL, *token = NULL, full_path[1024];
	struct stat st;
	int i = 0;

	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i] + 5; /* Skip "PATH=" */
			break;
		}
		i++;
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
			return strdup(full_path); /* Found the command */
		}
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

