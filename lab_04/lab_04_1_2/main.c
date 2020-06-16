#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "myfuncstr.h"

#define OK 0
#define ERROR 1

int main()
{
    char str[STRMAX + 1];
    char word_str[COUNTWORD][WORDMAX] = { 0 };
    char symbols[] = " ;,:-.!?\n";
    printf("Input string: ");
    char *p = fgets(str, STRMAX + 1, stdin);
    if ((p == NULL) || (str[strlen(str) - 1] != '\n'))
    {
        printf("Input error");
        return ERROR;
    }
    else
    {
        int n = string_split(str, word_str, symbols);
        if (n == 0)
        {
            printf("Invalid input");
            return ERROR;
        }
        else
        {
            n = check(word_str, n);
            if (n == 0)
            {
                printf("Invalid input");
                return ERROR;
            }
            else
            {
                n = clean_word_str(word_str, n);
                sort(word_str, n);
                print(word_str, n);
                return OK;
            }
        }
    }
}

