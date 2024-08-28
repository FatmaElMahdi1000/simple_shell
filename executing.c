#include "myshell.h"
/**
 * execution - executing a single command
 * @str: command to execute
 * Return: Null, zero
 */

void execution(char *str)
{
    pid_t childprocess = fork();
    extern char **environ; /** Access to the environment **/

    /** Handling exit command **/
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
    {
        /** Dynamically allocate the args array **/
        char *args[2];
        args[0] = str;
        args[1] = NULL; /** Command without arguments **/

        if (execve(args[0], args, environ) == -1)
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

