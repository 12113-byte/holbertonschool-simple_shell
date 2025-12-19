#include "shell.h"

/**
 * get_path - gets the PATH environment variable
 * @env: environment variables array
 *
 * Return: Pointer to PATH string, or NULL if not set;
 * used by path_check to search for executable commands
 */

char *get_path(char **env)
{
	int i = 0, j;
	char path_array[] = "PATH=";
	char *path;

	while (env[i] != NULL)
	{
		/* do the first 5 characters match PATH= */
		for (j = 0; j < 5; j++)
		{
			if (env[i][j] != path_array[j])
			{
				/* no match found */
				break;
			}
		}
		if (j == 5)
		{
			/* PATH= matched, return pointer after '=' */
			path = env[i] + 5;
			return (path);
		}
		i++; /* move to next environ variable */
	}
	return (NULL);
}

