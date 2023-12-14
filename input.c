#include"myshell.h"

/**
 *input - receives user's input
 *@str: passing a command.
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
}
