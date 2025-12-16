#include "shell.h"

/**
 * trim_whitespace - Removes leading and trailing whitespace
 * @str: String to trim
 *
 * Return: Pointer to trimmed string
 */
char *trim_whitespace(char *str)
{
	char *end;

	/* remove leading whitespace */
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;

	if (*str == '\0')
		return (str);

	/* remove trailing whitespace */
	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n'))
		end--;

	*(end + 1) = '\0';

	return (str);
}
