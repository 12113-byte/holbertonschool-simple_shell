#ifndef SHELL_H
#define SHELL_H

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

#endif
