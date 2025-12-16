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

	argv = tokenize_command(command);
	if (argv == NULL)
		return;


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
        /* child needs to run execve() to become the new program */
		execve(argv[0], argv, environ);
		perror(prog_name);
		free_tokens(argv);
        /* Status code 127 = "command not found" */
		exit(127);
	}

        /* parent needs to wait() for the child to finish,
        then display the prompt again */
	wait(NULL);
	free_tokens(argv);
}
