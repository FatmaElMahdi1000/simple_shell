#include "shell.h"

/**
 * main - Entry point of the shell program.
 * @buffer: storing
 * @buffer_copy: storing
 * @size: storing
 * @whattoread: reading input
 * This function implements a simple shell loop that reads input
 * from the user, tokenizes it, and executes commands until
 * the user exits. It handles memory allocation and command
 * execution within the loop.
 * Return: Always returns 0 on success, or -1 on failure.
 */
void read_input(char **buffer, char **buffer_copy,
size_t *size, ssize_t *whattoread);
void tokenize_input(char *buffer, char *buffer_copy,
char ***argv, int *token_numbers);
void free_arguments(char **argv);

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
char *myprompt = "(MyShell) $";
char *buffer = NULL, *buffer_copy = NULL;
size_t size = 0;
ssize_t whattoread = 0;
char **argv = NULL;
int token_numbers = 0;

while (1)
{
printf("%s", myprompt);
read_input(&buffer, &buffer_copy, &size, &whattoread);

if (whattoread == -1)
{
printf("Exit from myshell\n");
free(buffer);
free(buffer_copy);
return (-1);
}

tokenize_input(buffer, buffer_copy, &argv, &token_numbers);
execution(argv);
free_arguments(argv);

free(buffer);
free(buffer_copy);

buffer = NULL;
buffer_copy = NULL;
}

free(buffer);
free(buffer_copy);
return (0);
}
