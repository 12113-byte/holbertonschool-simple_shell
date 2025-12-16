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
	int i = 0;

	if (command == NULL || command[0] == '\0')
		return (NULL);

	argv = malloc(sizeof(char *) * MAX_TOKENS);
	if (argv == NULL)
		return (NULL);

	token = strtok(command, " \t");
	while (token != NULL && i < MAX_TOKENS - 1)
	{
		argv[i] = token;
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
	if (tokens == NULL)
		return;
	free(tokens);
}
