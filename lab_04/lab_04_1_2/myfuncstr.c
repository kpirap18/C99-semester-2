#include <stdio.h>
#include "myfuncstr.h"
#include <string.h>

int clean_word_str(char word_str[COUNTWORD][WORDMAX], int n)
{
    for (int i = 0; i < (n - 1); i++)
        for (int j = i + 1; j <= (n - 1); j++)
            if ((strcmp(word_str[i], word_str[j]) == 0))
            {
                for (int k = i; k < (n - 1); k++)
                    change1(word_str, k);
                n--;
                i--;
                j--;
            }
    return n;
}
void sort(char word_str[COUNTWORD][WORDMAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = (n - 1); j > i; j--)
        {
            if (strcmp(word_str[j - 1], word_str[j]) > 0)
            {
                change2(word_str, j);
            }
        }
    }
}
void change1(char word_str[COUNTWORD][WORDMAX], int k)
{
    int m = WORDMAX;
    if (strlen(word_str[k]) > strlen(word_str[k + 1]))
        m = strlen(word_str[k]);
    else
        m = strlen(word_str[k + 1]);
    for (int l = 0; l < m; l++)
    {
        char buf = word_str[k][l];
        word_str[k][l] = word_str[k + 1][l];
        word_str[k + 1][l] = buf;
    }
}
void change2(char word_str[COUNTWORD][WORDMAX], int j)
{
    int m = WORDMAX;
    if (strlen(word_str[j]) > strlen(word_str[j - 1]))
        m = strlen(word_str[j]);
    else
        m = strlen(word_str[j - 1]);
    for (int l = 0; l < m; l++)
    {
        char buf = word_str[j][l];
        word_str[j][l] = word_str[j - 1][l];
        word_str[j - 1][l] = buf;
    }
}
