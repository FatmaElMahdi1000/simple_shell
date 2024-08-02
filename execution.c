/**
 * execution - Executes a command with given arguments.
 * @argv: An array of arguments passed to the command.
 *
 * This function forks a child process and executes the command
 * specified by argv[0] with the given arguments. It waits for the
 * child process to terminate before returning.
 */
#include "shell.h"

void execution(char **argv)

{
pid_t pid;
int status;
char *command = NULL, *actualcommand = NULL;

if (argv && argv[0])
{
command = argv[0];
actualcommand = getpath(command);

pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{

if (execve(actualcommand, argv, NULL) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
else
{
if (waitpid(pid, &status, WUNTRACED) == -1)
{
perror("waitpid");
exit(EXIT_FAILURE);
}
}
free(actualcommand);
}
}
