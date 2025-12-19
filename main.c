#include "shell.h"

/**
 * main - Entry point for the simple shell
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t nread;
	int interactive;
	int exit_status = 0; /* Track exit status */

	(void)ac;
/**
 * isatty(STDIN_FILENO):
 * Returns 1 if STDIN is connected to a terminal;
 * Returns 0 if input comes from a pipe or file
 */
	interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
		{
			display_prompt();
		}

		nread = read_command(&buffer, &bufsize);

                /* EOF detected or Ctrl+D pressed */
		if (nread == -1)
		{
			if (interactive)
                          /* print a newline to make terminal look cleaner */
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (exit_built_in(buffer) == BUILTIN_EXIT)
		{
			free(buffer);
			break;
		}
		if (buffer[0] != '\0')
			exit_status = execute_command(buffer, av[0]);
	}

	free(buffer);
	return (exit_status);
}
