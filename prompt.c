#include"myshell.h"
/**
 * promptt - display prompt
 * Description: creating the prompt
 * Return: void
*/
void promptt(void)
{
	if (isatty(fileno(stdin)))
	{
	prnt("Myshell$ ");
}
}
