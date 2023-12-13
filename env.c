#include"myshell.h"

/**
 *myenv - environment
*Return: 0 success, 1 failure
**/

int myenv(void)
{
	int exc = 0;
	char *executable_name;
	char buffer[100];
	FILE *file = fopen("envscript.txt", "r");

	if (file == NULL)
		return (1);

	if (fgets(buffer, sizeof(buffer), file) == NULL) /**read from the file**/
	{
		fclose(file);
		return (1);
	}

	executable_name = strrchr(buffer, '/');

	if (executable_name != NULL)
	{
/**move the pointer to the character after the last NULL**/
		executable_name++; /*incrementing to the next character**/
	}

	if (access(buffer, X_OK) != -1)
	{
		exc = system(buffer);
		fclose(file);

		if (exc == -1)
		{
		return (-1);
		}
		else
		{
		return (0);
	}

	}
	fclose(file);
	return (-1);
}

