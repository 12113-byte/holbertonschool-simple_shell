#include "shell.h"

/**
 * execute_command - Executes a command using fork and execve
 * @command: The command to execute
 * @prog_name: Name of the shell program (argv[0])
 */

extern char **environ;

void execute_command(char *command, char *prog_name)
{
	pid_t pid;
	char **argv;
	char *full_path;

	argv = tokenize_command(command);
	if (argv == NULL || argv[0] == NULL)
	{
		return;
	}

	/* creates a copy of the current process, returns -1 on error */
	pid = fork();
	if (pid == -1)
	{
		perror(prog_name);
		free_tokens(argv);
		exit(EXIT_FAILURE);
	}

	/* only child enters this block */
	if (pid == 0)
	{
		full_path = path_check(argv);
		if (full_path == NULL)
		{
			perror("Command not found");
			free_tokens(argv);
			/* status code 127 = "command not found" */
			exit(127);
		}
		execve(full_path, argv, environ);
		perror("Failed to execute program");
		free(full_path);
		free_tokens(argv);
		exit(EXIT_FAILURE);
	}

	/* parent needs to wait() for the child to finish,
	   then display the prompt again */
	waitpid(pid, NULL, 0);
	free_tokens(argv);
}

