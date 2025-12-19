#ifndef SHELL_H
#define SHELL_H
#define BUILTIN_EXIT 1
#define BUILTIN_NONE 0
#define BUILTIN_ENV -1

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void display_prompt(void);
ssize_t read_command(char **buffer, size_t *bufsize);
int execute_command(char *command, char *prog_name);
char *trim_whitespace(char *str);
char **tokenize_command(char *command);
void free_tokens(char **tokens);
char *get_path(void);
char *path_check(char *command);
int exit_built_in(char *command);
int env_built_in(char *command);

#endif
