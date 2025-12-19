#include "shell.h"
/**
 * handle_fork_error - handles fork() failure
 * @pid: return value of fork()
 * @prog_name: name of shell program (for perror)
 * @full_path: full path to command
 * @argv: array of command arguments
 * @command_copy: copy of original command string
 */
void fork_error_handling(char *prog_name, char *full_path, char **argv, char *command_copy)
{
	perror(prog_name);
	free(full_path);
	free_tokens(argv);
	free(command_copy);
	exit(EXIT_FAILURE);
}

