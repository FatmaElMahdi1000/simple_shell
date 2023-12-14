#include"myshell.h"
/**
 *prnt - function that prints
 *@str: what the user,will type in.
 * Return: the output.
*/
void prnt(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}

