#ifndef SHELL_H
#define SHELL_H

/**Library**/
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**prototypes**/ 
void execution(char **argv);
char *getpath(char *command);
void free_arguments(char **argv);
void read_input(char **buffer, char **buffer_copy, size_t *size,ssize_t *whattoread);
void tokenize_input(char *buffer, char *buffer_copy, char ***argv, int *token_numbers);

#endif