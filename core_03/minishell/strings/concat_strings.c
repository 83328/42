#include "../minishell.h"


char	*concat_strings(char** strings, int numStrings)
{
    // Check for valid input
    if (strings == NULL || numStrings <= 0) 
        return NULL;

    // Calculate total length of the concatenated string
    int totalLength = 0;
    int i = 0;

    // Calculate total length using a while loop
    while (i < numStrings) 
        totalLength += strlen(strings[i++]);

    // Add space for the spaces between strings
    totalLength += numStrings - 1;

    // Allocate memory for the concatenated string
    char* result = (char*)malloc(totalLength + 1); // +1 for the null terminator

    // Check for memory allocation failure
    if (result == NULL)
    	return NULL;

    // Copy the strings into the result buffer with spaces in between using a while loop
    int position = 0;
    i = 0;

    while (i < numStrings)
	{
        strcpy(result + position, strings[i]);
        position += strlen(strings[i]);
        if (i < numStrings - 1) {
            result[position++] = ' '; // Add space between strings
        }
        i++;
    }

    result[totalLength] = '\0'; // Null-terminate the result string
    return result;
}