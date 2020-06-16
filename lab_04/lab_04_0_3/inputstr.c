#include <string.h>
#include "myfuncstr.h"

#define FALSE 0

int string_split(char *str, char *pword_array[], char word_array[COUNTWORD][WORDMAX], const char *const symbols)
{
    char *pword = strtok(str, symbols);
    int i = 0, j;
    while (pword)
    {
        pword_array[i++] = pword;
        pword = strtok(NULL, symbols);
        int n = strlen(pword_array[i - 1]);
        for (j = 0; j < n; j++)
            word_array[i - 1][j] = pword_array[i - 1][j];
        word_array[i - 1][j] = '\0';
        if (strlen(word_array[i - 1]) > WORDMAX)
            return FALSE;
    }
    return i;
}


