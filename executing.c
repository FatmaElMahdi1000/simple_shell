#include"myshell.h"
/**
 *execution - executing process
 *@str: commands/arguments
 *Return: Null, zero
*/
void execution(char *str)
{
	pid_t childprocess = fork();
	char *status_str, int status, char *endptr;

	if (strncmp(str, "exit", 4) == 0)
	{
		status_str = strtok(str + 5, " ");
		status = EXIT_SUCCESS;

		if (status_str != NULL)
		{
			status = strtol(status_str, &endptr, 10);

			if (*endptr != '\0')
			{
				fprintf(stderr, "Invalid exit status: %s\n", status_str);
				return;
			}
		}
		exit(status);
	}

	if (childprocess == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (childprocess == 0)
	{
		char *args[300], int argcount = 0, char *token, char *delim = " ";
		
		token = strtok(str, delim);
		
		while (token != NULL && argcount < 299)
		{
			args[argcount++] = token;
			token = strtok(NULL, delim);
		}
		args[argcount] = NULL;

		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(childprocess, NULL, 0);
	}
}
