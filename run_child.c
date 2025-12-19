#include "shell.h"
/**
 * run_child - executes command in child process
 * @full_path: full path to executable
 * @argv: array of command arguments
 * @env: environment variables array
 * @command_copy: copy of original command string
 */
void run_child(char *full_path, char **argv, char **env, char *command_copy)
{
	execve(full_path, argv, env);
	perror(argv[0]);
	free(full_path);
	free_tokens(argv);
	free(command_copy);
	exit(EXIT_FAILURE);
}

