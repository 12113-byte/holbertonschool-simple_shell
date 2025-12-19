#include "shell.h"

/**
 * read_command - Reads a command line from stdin
 * @buffer: Pointer to buffer pointer
 * @bufsize: Pointer to buffer size
 *
 * Return: Number of characters read, or -1 on EOF/error
 */
ssize_t read_command(char **buffer, size_t *bufsize)
{
	ssize_t nread;
	char *trimmed;

	nread = getline(buffer, bufsize, stdin);

	if (nread == -1)
		return (-1);

	/* remove new line */
	if (nread > 0 && (*buffer)[nread - 1] == '\n')
		(*buffer)[nread - 1] = '\0';

	trimmed = trim_whitespace(*buffer);
	/* if trimmed not equal to *buffer, it means space has been trimmed,*/
	/*   use memmove to copy bytes from trimmed location to buffer location */
	if (trimmed != *buffer)
		memmove(*buffer, trimmed, strlen(trimmed) + 1);

	return (nread);
}
