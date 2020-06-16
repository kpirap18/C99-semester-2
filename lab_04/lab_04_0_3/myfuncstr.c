#include <string.h>
#include "myfuncstr.h"

int clean(char word_array[COUNTWORD][WORDMAX], int n)
{
    for (int i = 0; i < (n - 1); i++)
        if ((strcmp(word_array[i], word_array[n - 1]) == 0))
        {
            for (int k = i; k < (n - 1); k++)
            {
                int m = WORDMAX;
                if (strlen(word_array[k]) > strlen(word_array[k + 1]))
                    m = strlen(word_array[k]);
                else
                    m = strlen(word_array[k + 1]);
                for (int l = 0; l < m; l++)
                {
                    char buf = word_array[k][l];
                    word_array[k][l] = word_array[k + 1][l];
                    word_array[k + 1][l] = buf;
                }
            }
            n--;
            i--;
        }
    return --n;
}
void word_arr(char word_array[COUNTWORD][WORDMAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        int col = 0;
        int n = strlen(word_array[i]);
        char *p = word_array[i];
        word_array[i][col++] = word_array[i][0];
        for (int j = 1; j < n; j++)
            if (p[j] != p[0])
                word_array[i][col++] = p[j];
        word_array[i][col] = '\0';
    }
}
void str_new(char new_str[STRMAX], char word_array[COUNTWORD][WORDMAX], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        strcat(new_str, word_array[i]);
        if (i != 0)
            strcat(new_str, " ");
    }
}
