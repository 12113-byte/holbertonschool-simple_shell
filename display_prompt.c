#include "shell.h"

/**
 * display_prompt - displays prompt
 * Return: 0 on success, otherwise -1
*/
void display_prompt(void)
{
	write(STDOUT_FILENO, ":) ", 3);
}

