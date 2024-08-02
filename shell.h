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



#endif