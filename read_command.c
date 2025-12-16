#include "shell.h"

/**
 *
 */
ssize_t read_command(char **buffer, size_t *bufsize)
{
	ssize_t nread;

	nread = getline(buffer, bufsize, stdin);

	if (nread == -1)
		return (-1);

	/* remove new line */
	if (nread > 0 && (*buffer)[nread - 1] == '\n')
		(*buffer)[nread - 1] = '\0';

	return (nread);
}
