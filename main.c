#include "shell.h"  

void read_input(char **buffer, char **buffer_copy, size_t *size, ssize_t *whattoread);
void tokenize_input(char *buffer, char *buffer_copy, char ***argv, int *token_numbers);
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
            free(buffer);        // Free only if buffer was allocated
            free(buffer_copy);  // Free only if buffer_copy was allocated
            return (-1);
        }

        tokenize_input(buffer, buffer_copy, &argv, &token_numbers);
        execution(argv);
        free_arguments(argv); // Free arguments

        free(buffer);        // Free buffer
        free(buffer_copy);  // Free buffer_copy

        // Reset buffer and buffer_copy to NULL to avoid double free
        buffer = NULL;
        buffer_copy = NULL;
    }

    // Ensure no memory leaks before exiting
    free(buffer);
    free(buffer_copy);
    return (0);
}