#include "shell.h"

/**
 * env_built_in - prints current environment variables
 * @command: input command string
 * @env: environment variable array
 *
 * Implementation of "env" built-in. Iterates over global environ array
 * and prints each variable to standard output
 *
 * Return: 0 on success
 */

int env_built_in(char *command, char **env)
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
		while (env[i] != NULL)
		{
			printf("%s\n", env[i]);
			i++;
		}
		free_tokens(argv);
		free(command_copy);
		return (BUILTIN_ENV);
	}
	free_tokens(argv);
	free(command_copy);
	return (BUILTIN_NONE);
}

