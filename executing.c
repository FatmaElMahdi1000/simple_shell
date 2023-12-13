#include"myshell.h"
/**
 *execution - executing process
 *@str: commands/arguments
 *Return: Null, zero
*/
void execution(char *str)
{
	pid_t childprocess = fork();
/**Handling exit command**/
	if (strcmp(str, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	if (childprocess == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (childprocess == 0)
	{ /**parsing**/
		char *args[300];/**storing memory for command**/
		int argcount = 0; /**counting no. of args in command**/
		char *token; /*for tokenization**/
		char *delim = " "; /**tokenize with space**/

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
