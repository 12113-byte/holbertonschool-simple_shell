#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void display_prompt(void);
ssize_t read_command(char **buffer, size_t *bufsize);
void execute_command(char *command, char *prog_name);

#endif
