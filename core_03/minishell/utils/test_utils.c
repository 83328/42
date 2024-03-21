#include "../minishell.h"

void    printStringArray(char **strArray)
{
    int i;

    i = 0;
    while (strArray[i] != NULL)
    {
        printf("\nstrArr[%d] #%s#", i ,strArray[i]);
        i++;
    }
    printf("\n");
}

void    printIntArray(int *intArray)
{
    int i;

    i = 0;
    while (intArray[i] != -1)
    {
        printf("\nintArr[%d] %i", i ,intArray[i]);
        i++;
    }
    printf("\n");
}

void printFileContent(int fd)
{
    char buffer[4096];  // Adjust the buffer size as needed
    ssize_t bytesRead;

    // Read and print the content of the file until the end
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    if (bytesRead == -1) {
        // Handle error
        perror("Error reading file");
    }
	close(fd);
}