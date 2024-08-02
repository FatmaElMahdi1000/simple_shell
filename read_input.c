#include "shell.h"

void read_input(char **buffer, char **buffer_copy, size_t *size,
ssize_t *whattoread)
{
*whattoread = getline(buffer, size, stdin);

if (*whattoread != -1)
{
*buffer_copy = malloc(sizeof(char) * (*whattoread));
if (*buffer_copy == NULL)
{
perror("Memory Allocation Error");
exit(EXIT_FAILURE);
}
strcpy(*buffer_copy, *buffer);
}
}
