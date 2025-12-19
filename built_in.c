#include "shell.h"
#define BUILTIN_EXIT 1
#define BUILTIN_NONE 0

/**
 * exit_built_in -
 *
 */

int exit_built_in(char *command)
{
	char **argv;

	argv = tokenize_command(command);
	if (argv == NULL || argv[0] == NULL)
	{
		return (BUILTIN_NONE);
	}

	if (strcmp(argv[0], "exit") == 0)
	{
		free_tokens(argv);
		exit(BUILTIN_EXIT);
	}
	free_tokens(argv);
	return (BUILTIN_NONE);
}

