#include "shell.h"

#define MAX_TOKENS 64

/**
 * tokenize_command - Splits a command string into tokens
 * @command: The command string to tokenize
 *
 * Return: Array of strings (tokens), or NULL on failure
 */
char **tokenize_command(char *command)
{
	char **argv;
	char *token;
	int i = 0, j;

	if (command == NULL || command[0] == '\0')
		{
			return (NULL);
		}
	argv = malloc(sizeof(char *) * MAX_TOKENS);
	if (argv == NULL)
		{
			return (NULL);
		}
	token = strtok(command, " \t");
	while (token != NULL && i < MAX_TOKENS - 1)
	{
		argv[i] = strdup(token);
		if (argv[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(argv[j]);
			}
			free(argv);
			return (NULL);
		}
		i++;
		token = strtok(NULL, " \t");
	}
	argv[i] = NULL;

	return (argv);
}

/**
 * free_tokens - Frees the tokens array
 * @tokens: Array of tokens to free
 */
void free_tokens(char **tokens)
{
	int i;

	if (tokens == NULL)
		{
			return;
		}
		for (i = 0; tokens[i]; i++)
		{
			free(tokens[i]);
		}
	free(tokens);
}
