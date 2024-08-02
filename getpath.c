#include "shell.h"

/**
 * getpath - Retrieves the system path for a given command.
 * @command: The command whose path is to be found.
 *
 * This function searches through the system's PATH environment
 * variable to find the full path of the specified command.
 * Return: the full path if found, or NULL if not found.
 */
char *getpath(char *command)
{
int directory_length, command_length;
char *pathtoken;
char *Full_path;
char *path, *path_copy;
const char *pathdelim = ":\n";
struct stat buffer;

path = getenv("PATH");

if (path)
{
path_copy = strdup(path);
command_length = strlen(command);
pathtoken = strtok(path_copy, pathdelim);
while (pathtoken != NULL)
{directory_length = strlen(pathtoken);
Full_path = malloc(directory_length + command_length + 2);
strcpy(Full_path, pathtoken);
strcat(Full_path, "/");
strcat(Full_path, command);
strcat(Full_path, "\0");
if (stat(Full_path, &buffer) == 0)
{
free(path_copy);
return (Full_path);
}
else
{free(Full_path);
pathtoken = strtok(NULL, ":");
}
}
free(path_copy);
if (stat(command, &buffer) == 0)
{
return (command);
}
return (NULL);
}
return (NULL);
}
