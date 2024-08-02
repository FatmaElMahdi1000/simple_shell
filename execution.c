#include "shell.h"

void execution(char **argv)

{
  pid_t pid;
  int status;
  char *command = NULL, *actualcommand = NULL;

  if (argv && argv[0])

  { /** Check if argv is not NULL and has at least one element**/
    command = argv[0];

    /**Get the full path of the command **/
    actualcommand = getpath(command);

    pid = fork();

    if (pid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      /**Child process**/
      if (execve(actualcommand, argv, NULL) == -1) {
        perror("execve");
        exit(EXIT_FAILURE);
      }
    } else {
      /** Parent process **/
      /** Wait for the child process to finish**/
      if (waitpid(pid, &status, WUNTRACED) == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
      }
    }

    /** Free the memory allocated by getpath if necessary**/
    free(actualcommand);
  }
}