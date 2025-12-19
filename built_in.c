#include "shell.h"

/**
 * exit_built_in -
 *
 */

int exit_built_in(char *command)
{
	char **argv, *command_copy;

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

	if (strcmp(argv[0], "exit") == 0)
	{
		free_tokens(argv);
		free(command_copy);
		return(BUILTIN_EXIT);
	}
	free_tokens(argv);
	free(command_copy);
	return (BUILTIN_NONE);
}

