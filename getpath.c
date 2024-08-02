#include"shell.h"

char *getpath(char *command) /** Command here represents the path name, check execution.c file, path name was: command **/
{
    int directory_length, command_length;
    char *pathtoken; 
    char *Full_path; 
    char *path, *path_copy;
    const char *pathdelim = ":\n";
    struct stat buffer; 

    /**condition that checks whether the pointers is non-null, it means if path hold info instead of '0 */
    path = getenv("PATH");

    if(path)
    {
        path_copy = strdup(path);

    /***Tokenize the long path to get the path of only a command **/
    /**strlen(command) Get the length of the command given, that we insert or the user insert**/
    
        command_length = strlen(command);   /**output: length of commands**/
    
        pathtoken = strtok(path_copy, pathdelim);  /**output: Directories**/

     while (pathtoken != NULL)
     {
        directory_length = strlen(pathtoken); /**strlen function does not take the NULL terminator **/
        
        Full_path = malloc(directory_length + command_length + 2);
        
        strcpy(Full_path, pathtoken);
        strcat(Full_path, "/");
        strcat(Full_path, command);
        strcat(Full_path, "\0");

        
        if(stat(Full_path, &buffer) == 0)
        {
            free(path_copy); /**we're freeing it as the usage of str &) in the stat function call is used to pass the address of the buffer variable to the function. */ 
            
            return(Full_path);
            
        }
        else
        {
            free(Full_path);
            pathtoken = strtok(NULL, ":");
            
        }
     }
        free(path_copy);

        if (stat(command, &buffer) == 0)
        {
            return(command);
        }

        return(NULL);

    }
    return(NULL);
}