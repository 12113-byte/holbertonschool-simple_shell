#include "shell.h"

/**
 * execute_command - Executes a command using fork and execve
 * @command: The command to execute
 * @prog_name: Name of the shell program (argv[0])
 */

extern char **environ;

int execute_command(char *command, char *prog_name)
{
	pid_t pid;
	char **argv, *full_path, *command_copy;
	int status;

/* Copy, because tokenize_command modifies the string*/
	command_copy = strdup(command);
	if (command_copy == NULL)
{
	return (0);
}
	argv = tokenize_command(command_copy);

	if (argv == NULL || argv[0] == NULL)
	{
		free(command_copy);
		return (0);
	}

	/* Check if command exists before forking */
	full_path = path_check(argv[0]);
	if (full_path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", prog_name, argv[0]);
		free_tokens(argv);
		free(command_copy);
		return (127); /* Return 127 for command not found */
	}

	/* creates a copy of the current process, returns -1 on error */
	pid = fork();
	if (pid == -1)
	{
		perror(prog_name);
		free(full_path);
		free_tokens(argv);
		free(command_copy);
		exit(EXIT_FAILURE);
	}

	/* only child enters this block */
	if (pid == 0)
	{
		execve(full_path, argv, environ);
		perror(argv[0]);
		free(full_path);
		free_tokens(argv);
		free(command_copy);
		exit(EXIT_FAILURE);
	}

	/* parent needs to wait() for the child to finish,
	   then display the prompt again */
	waitpid(pid, &status, 0);
	free(full_path);
	free_tokens(argv);
	free(command_copy);

	/* Return child's exit status */
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	return (1);
}
