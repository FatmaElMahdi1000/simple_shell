#include"myshell.h"
/**
 * main - Entry point
 * DescriptionL creating prompt
 * Return:0
*/

int main(void)
{
	char str[300];
	char buffer[300];

	while (1)
	{
		input(buffer, sizeof(buffer));
		execution(str);
	}
	return (0);
}
