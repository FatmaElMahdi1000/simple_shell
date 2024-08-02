#include "shell.h"

/**ac arg count, av arguments strings  **/
/**for String tokenization: strtok (char *str, const char *delim)**/
int main(int ac __attribute__ ((unused)) ,  char** av __attribute__((unused)))
{
    char *myprompt = "(MyShell) $";
    /**TODO: In C, NULL, It is used to indicate that a pointer does not currently point to any valid memory location. Essentially, it is a way to signify that the pointer is empty or uninitialized**/ 
    char *buffer = NULL, *buffer_copy = NULL;  
    size_t size = 0;
    ssize_t whattoread = 0;
    const char *delim = " \n"; 
    char *token;
    int token_numbers = 0;
    char **argv; /* Pointer that holds a memory address that leads to another pointer that points to and hold a memory address that leads to an array of character pointers */ 
    int i;


    while (1)
    {
        printf("%s", myprompt);
        whattoread = getline(&buffer, &size, stdin);

        if (whattoread == -1 )
        {
            printf("Exit from myshell\n");
            return (-1);
        }

        /**Memory allocation for the copy of the buffer which is: buffer_copy**/
        buffer_copy = malloc(sizeof(char) * whattoread);

        if (buffer_copy == NULL)
        {
            perror("Memory Allocation Error");
            return(-1);
        }
        /* copy buffer to buffer_copy */
        strcpy(buffer_copy, buffer);

        /***splitting the string /TOKENIZATION ***/ 

        token = strtok(buffer, delim); /**LOOK FOR THE REASON WHY I AM TOKENIZING USING THE BUFFER AND NOT THE BUFFER COPY**/


        while (token != NULL)
        {
            token_numbers++;
            token = strtok(NULL, delim);

        }
        token_numbers++; /**LOOK FOR THE REASON WHY THIS HAS BEEN ADDED OUTSIDE OF WHILE LOOP**/
        
        /**TODO: Allocating space to hold first the pointer that has another pointer that includes the address to the string of tokens/or the array of characters**/ 
        argv = malloc(sizeof(char*) * token_numbers); /**alloction of memory space of the first pointer only that points to the address of the array of strings**/
       /**this first allocation is: to know what space to allocate for the number of token we've 
        we'll repeat the process to start copying and store each token in its created space, using tokenization for: buffer_copy as it has the string in its original state without being corrupted.**/
        
        token = strtok(buffer_copy, delim);
        /**first call: i (the counter is 0)
        condition token != NULL '\0'
        as long as token is not equal to Null, you'll allocate space for that token your passing through and store it in the space 
        once you reach the end of the string marked by: NULL, break out of the loop**/
        
        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token)); /**pass by the token using strlen, allocate it in its space using the correct data type Char**/
            strcpy(argv[i], token);
            token = strtok(NULL, delim);
        }

        argv[i] = NULL;

        execution(argv);
    }
       
       free(buffer);
       free(buffer_copy);
    
    return(0);
}