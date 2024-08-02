#include "shell.h"

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
        free(argv); // Free the array of pointers
    }
}