#include "shell.h"
/**
 * execute_command - Executes a command using fork and execve
 * @command: The command to execute
 * @prog_name: Name of the shell program (argv[0])
 * @env: environment variables array
 * Return: if command executed, child's exit status; otherwise 0 or 127
 */
int execute_command(char *command, char *prog_name, char **env)
{
	pid_t pid;
	char **argv, *full_path, *command_copy;
	int status;

	command_copy = strdup(command); /*copy, tokenization modigies string*/
	if (command_copy == NULL)
		return (0);
	argv = tokenize_command(command_copy);
	if (argv == NULL || argv[0] == NULL)
	{
		free(command_copy);
		return (0);
	}
	full_path = path_check(argv[0], env); /* check if command exits before forking*/
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
	if (pid == 0) /* only child enters this block */
	{
		execve(full_path, argv, env);
		perror(argv[0]);
		free(full_path);
		free_tokens(argv);
		free(command_copy);
		exit(EXIT_FAILURE);
	}
	/*parent needs to wait for child to finish, then display the prompt again*/
	waitpid(pid, &status, 0);
	free(full_path);
	free_tokens(argv);
	free(command_copy);
	if (WIFEXITED(status)) /* Return child's exit status */
		return (WEXITSTATUS(status));
	return (1);
}

