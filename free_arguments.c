#include "shell.h"

/**
 * free_arguments - Frees memory allocated for argument array.
 * @argv: The array of arguments to be freed.
 *
 * This function iterates over the array of arguments and frees
 * each one.
 * Return: It then frees the array itself.
 */
void free_arguments(char **argv)
{
int i = 0;

if (argv != NULL)
{
while (argv[i] != NULL)
{
free(argv[i]);
i++;
}
free(argv);
}
}
