# holbertonschoolsimple_shell

Simple Shell is a simplified version of a Unix shell, supporting basic command execution and built-in commands like exit, and PATH resolution with ls and env.

## Installation
Clone the repo and compile:
```bash
git clone https://github.com/12113-byte/holbertonschool-simple_shell.git
cd holberton-simple_shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## File Structure

main.c - entry point of the shell
execute_command.c - executes commands using fork and execve
path_check.c - searches for the command in the directories listed in PATH
tokenize_command.c - splits a command string into arguments
built_in.c - implements the built-ins exit and env
shell.h - header file with the prototypes of the functions
display_prompt.c - displays the prompt ":) "
env_built_in.c - prints current environment variables
fork_error_handling - handles fork failure
get_path - gets the PATH environment variable
read_command - reads a command line from stdin
run_child - executes command in child process
trim_whitespace - removes leading and trailing whitespaces

## Exit Codes
0 - command executed successfully
127 - command not found
EXIT_FAILURE - fork or memory allocation error

## EXAMPLES

:) ls -la
total 136
drwxr-xr-x 3 root root  4096 Dec 19 06:37 .
drwx------ 1 root root  4096 Dec 19 06:19 ..
-rw-r--r-- 1 root root 12288 Dec 19 06:27 .README.md.swp
drwxr-xr-x 8 root root  4096 Dec 19 06:11 .git
-rw-r--r-- 1 root root 12288 Dec 19 06:17 .shell.h.swp
-rw-r--r-- 1 root root   145 Dec 19 06:11 AUTHORS
-rw-r--r-- 1 root root    31 Dec 19 05:36 README.md
-rw-r--r-- 1 root root   727 Dec 19 05:36 built_in.c
-rw-r--r-- 1 root root   165 Dec 19 05:36 display_prompt.c
-rw-r--r-- 1 root root   858 Dec 19 05:36 env_built_in.c
-rw-r--r-- 1 root root   516 Dec 19 05:36 env_built_in.c~
-rw-r--r-- 1 root root  1465 Dec 19 06:36 execute_command.c
-rw-r--r-- 1 root root   605 Dec 19 05:36 execute_command.c~
-rw-r--r-- 1 root root   475 Dec 19 06:35 fork_error_handling.c
-rw-r--r-- 1 root root   681 Dec 19 05:36 get_path.c
-rwxr-xr-x 1 root root 17792 Dec 19 06:37 hsh
-rw-r--r-- 1 root root  1179 Dec 19 05:36 main.c
-rw-r--r-- 1 root root  2268 Dec 19 06:11 man_1_simple_shell
-rw-r--r-- 1 root root  1418 Dec 19 05:36 path_check.c
-rw-r--r-- 1 root root   760 Dec 19 05:36 read_command.c
-rw-r--r-- 1 root root   450 Dec 19 06:34 run_child.c
-rw-r--r-- 1 root root   808 Dec 19 06:37 shell.h
-rw-r--r-- 1 root root    82 Dec 19 05:36 shell.h~
-rw-r--r-- 1 root root   994 Dec 19 05:36 tokenize_command.c
-rw-r--r-- 1 root root   616 Dec 19 05:36 tokenize_command.c~
-rw-r--r-- 1 root root   514 Dec 19 05:36 trim_whitespace.c

:) pwd
/root/holbertonschool-simple_shell

:) env
COLORTERM=truecolor
TERM_PROGRAM_VERSION=1.75.1
...

:) exit

