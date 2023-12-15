#include"myshell.h"
/**
 * main - Entry point
 * DescriptionL creating prompt
 * Return:0
*/

int main(void)
{
	char buffer[300];
	while (1)
	{
		promptt();
		input(buffer, sizeof(buffer));
		execution(buffer);
		promptt();
	}
	return (0);
}
