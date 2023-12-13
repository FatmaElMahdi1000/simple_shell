#ifndef MYSHELL_H
#define MYSHELL_H

/**Author of this: FatmaElMahdi
 * ALX project
 * myshell.h:is going to contain all the prototypes needed in this shell project
*/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void prnt(const char *str);
void promptt(void);
void execution(char *str);
void input(char *buffer, size_t size);
void exitshell();
int main(void);
int myenv();




#endif /**MYSHELL_H**/
