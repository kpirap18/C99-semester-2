#include <string.h>
#include <stdio.h>
#include "myfuncstr.h"

#define TRUE 1
#define FALSE 0

int string_split(const char *const str, char word_str[COUNTWORD][WORDMAX], const char *const symbols)
{
    int i = 0, j = 0, r = 0, col = 0;
    int flag = TRUE;
    while (str[i])
    {
        while (symbols[j])
        {
            if (str[i] == symbols[j])
            {
                flag = FALSE;
                break;
            }
            j++;
        }
        if (flag)
            word_str[r][col++] = str[i];
        else
        {
            if (col > 0)
            {
                r++;
                col = 0;
            }
        }
        i++;
        j = 0;
        flag = TRUE;
    }
    word_str[r][col] = '\0';
    return r;
}
int check(char word_str[COUNTWORD][WORDMAX], int n)
{
    for (int i = 0; i < n; i++)
        if (strlen(word_str[i]) > WORDMAX)
        {
            n = 0;
            break;
        }
    return n;
}
void print(char word_str[COUNTWORD][WORDMAX], int n)
{
    printf("Result: ");
    for (int i = 0; i < n; i++)
        printf("%s ", word_str[i]);
}
