#include "shell.h"

/**
 * path_check -
 *
 */

extern char **environ;

char *path_check(char *command)
{
	char *path, *path_copy, *dir, *full_path;

	if (command == NULL)
	{
		return (NULL);
	}

	/* If command contains '/', it's a path - check if executable */
	if (strchr(command, '/'))
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		return (NULL);
	}

	/* Try to get PATH */
	path = get_path();
	if (!path || path[0] == '\0')  /* PATH doesn't exist or is empty */
	{
		return (NULL);
	}

	path_copy = strdup(path);
	if (!path_copy)
	{
		return (NULL);
	}

	dir = strtok(path_copy, ":"); /* tokenisation */

	/* loop through different directories */
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return(full_path);
		}
		free(full_path);
		/* proceed to next directory */
		dir = strtok(NULL, ":");
	}
	/* if no executable found, free the copy and return NULL */
	free(path_copy);
	return (NULL);
}
