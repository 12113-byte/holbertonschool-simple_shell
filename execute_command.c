#include "shell.h"

void execute_command(char *command, char *prog_name)
{
	pid_t pid;
	char *argv[2];

        /* creates a copy of the current process, returns -1 on error */
	pid = fork();
	if (pid == -1)
	{
		perror(prog_name);
		exit(EXIT_FAILURE);
	}

        /* only child enters this block */
	if (pid == 0)
	{
		argv[0] = command;
		argv[1] = NULL;
        /* child needs to run execve() to become the new program */
		execve(command, argv, environ);
		perror(prog_name);
        /* Status code 127 = "command not found" */
		exit(127);
	}

        /* parent needs to wait() for the child to finish,
        then display the prompt again */
	wait(NULL);
}
