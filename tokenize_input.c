#include "shell.h"

void tokenize_input(char *buffer, char *buffer_copy, char ***argv, int *token_numbers)
{
    const char *delim = " \n";
    char *token;
    int i;

    *token_numbers = 0;
    token = strtok(buffer, delim);
    while (token != NULL)
    {
        (*token_numbers)++;
        token = strtok(NULL, delim);
    }
    (*token_numbers)++;
    
    *argv = malloc(sizeof(char *) * (*token_numbers));
    if (*argv == NULL)
    {
        perror("Memory Allocation Error");
        exit(EXIT_FAILURE);
    }

    token = strtok(buffer_copy, delim);
    for (i = 0; token != NULL; i++)
    {
        (*argv)[i] = malloc(sizeof(char) * (strlen(token) + 1));
        if ((*argv)[i] == NULL)
        {
            perror("Memory Allocation Error");
            exit(EXIT_FAILURE);
        }
        strcpy((*argv)[i], token);
        token = strtok(NULL, delim);
    }
    (*argv)[i] = NULL;
}