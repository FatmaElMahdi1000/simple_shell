#include"myshell.h"

/**
 *input - receives user's input
 *@buffer: storing the input
 *@size: input size of memory
 *Return: 0
*/

void input(char *buffer, size_t size)
{
	while (1)
	{
		promptt();

	if (fgets(buffer, size, stdin) != NULL)
	{
		buffer[strcspn(buffer, "\n")] = '\0';
		execution(buffer);
	}
	else
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}
}
promptt();
}
