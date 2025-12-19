#include "shell.h"
/**
 * path_check - finds full path of command in PATH
 * @command: to search for
 * @env: environment variable array
 * If command contains '/', returns a copy of command. Otherwise, searches dire
 * ctories in PATH env variable and retuns full path of first executable found
 * Return: full path string, if executable found, otherwise NULL
 */
char *path_check(char *command, char **env)
{
	char *path, *path_copy, *dir, *full_path;

	if (command == NULL)
		return (NULL);
	/* If command contains '/', it's a path - check if executable */
	if (strchr(command, '/'))
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		return (NULL);
	}
	path = get_path(env); /*get PATH from env*/
	if (!path || path[0] == '\0')  /* PATH doesn't exist or is empty */
		return (NULL);
	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);
	dir = strtok(path_copy, ":"); /* tokenisation */
	while (dir != NULL) /* loop through different directories*/
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
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":"); /* procees to next directory */
	}
	/* if no executable found, free the copy and return NULL */
	free(path_copy);
	return (NULL);
}

