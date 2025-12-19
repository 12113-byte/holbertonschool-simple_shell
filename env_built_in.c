#include "shell.h"

/**
 * env_built_in -
 *
 */
extern char **environ;

int env_built_in(char *command)
{
	char **argv, *command_copy;
	int i = 0;

	command_copy = strdup(command);

	if (command_copy == NULL)
	{
		return (BUILTIN_NONE);
	}
	argv = tokenize_command(command_copy);
	if (argv == NULL || argv[0] == NULL)
	{
		free(command_copy);
		return (BUILTIN_NONE);
	}

	if (strcmp(argv[0], "env") == 0)
	{
		while (environ[i] != NULL)
		{
			printf("%s\n", environ[i]);
			i++;
		}
		free_tokens(argv);
		free(command_copy);
		return(BUILTIN_ENV);
	}
	free_tokens(argv);
	free(command_copy);
	return (BUILTIN_NONE);
}

