#include "shell.h"

/**
 * get_path - 
 * Return:
 */

extern char **environ;

char *get_path(void)
{
	int i = 0, j;
	char path_array[] = "PATH=";
	char *path;

	while (environ[i] != NULL)
	{
		/* do the first 5 characters match PATH= */
		for (j = 0; j < 5; j++)
		{
			if (environ[i][j] != path_array[j])
			{
				/* no match found */
				break;
			}
		}
		if (j == 5)
		{
			/* PATH= matched, return pointer after '=' */
			path = environ[i] + 5;
			return(path);
		}
		i++; /* move to next environ variable */
	}
	return(NULL);
}

