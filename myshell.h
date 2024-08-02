#ifndef MYSHELL_H
#define MYSHELL_H

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void prnt(const char *str);
void promptt(void);
void execution(char *str);
void input(char *buffer, size_t size);
int main(void);
int myenv(void);




#endif
