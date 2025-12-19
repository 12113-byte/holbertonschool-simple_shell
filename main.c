#include "shell.h"
/**
 * main - Entry point for the simple shell
 * @ac: Argument count
 * @av: Argument vector
 * @env: environment variables
 * Return: Always 0
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL, *command_copy;
	size_t bufsize = 0;
	ssize_t nread;
	int interactive, exit_status = 0; /* Track exit status */
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
			display_prompt();
		nread = read_command(&buffer, &bufsize);
		if (nread == -1) /*EOF detected or Ctrl+D pressed*/
		{
			if (interactive) /* print a newline to make terminal look cleaner */
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (buffer[0] != '\0')
		{
			command_copy = strdup(buffer);
			if (exit_built_in(buffer) == BUILTIN_EXIT)
			{
				free(command_copy);
				break;
			}
			if (env_built_in(buffer, env) == BUILTIN_ENV)
			{
				free(command_copy);
				continue;
			}
			exit_status = execute_command(buffer, av[0], env);
			free(command_copy);
		}
	}
	free(buffer);
	return (exit_status);
}

