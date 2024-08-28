#include"myshell.h"
/**
 * execution - Executes a command parsed from input.
 * @str: The command to execute.
 *
* Return: Nothing.
 */
void execution(char *str)
{
	pid_t childprocess;
	char *args[MAX_ARGS]; /* Array to hold command and NULL */
	char *token;
	char *delim = " ";

	if (strcmp(str, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	token = strtok(str, delim);

	if (token != NULL)
	{
		args[0] = token; /* Command to execute */
		args[1] = NULL;
		childprocess = fork();

		if (childprocess == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (childprocess == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(childprocess, NULL, 0);
		}
	}
	else
	{
		fprintf(stderr, "No command entered\n");
	}
}
