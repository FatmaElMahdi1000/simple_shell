#include "shell.h"

/**
 * tokenize_input - Tokenizes input buffer into arguments.
 * @buffer: The input buffer containing the command line string.
 * @buffer_copy: A copy of the input buffer used for tokenizing.
 * @argv: A pointer to an array of arguments (tokens) that will be populated.
 * @token_numbers: A pointer to an integer that will hold the number of tokens.
 *
 * This function tokenizes the given input
 * allocates memory for each token, and stores them in an argument array.
 * The total number of tokens is stored in token_numbers.
 */

void tokenize_input(char *buffer, char *buffer_copy,
char ***argv, int *token_numbers)
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
