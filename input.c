#include"myshell.h"

/**
 *input - receives user's input
 *@buffer: storing the input
 *@size: input size of memory
 *Return: 0
*/

void input(char *buffer, size_t size)
{
	promptt();

	while (fgets(buffer, size, stdin))
	{
		buffer[strcspn(buffer, "\n")] = '\0';
		execution(buffer);
		promptt();
	}
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}
