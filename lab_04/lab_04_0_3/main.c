#include <stdio.h>
#include <string.h>
#include "myfuncstr.h"

#define OK 0
#define ERRORLOGIC 1
#define ERRORINPUT 2

int main()
{
    char str[STRMAX];
    char symbols[] = " ;,:-.!?\n";
    char *pword_array[COUNTWORD];
    char word_array[COUNTWORD][WORDMAX] = { 0 };
    printf("Input string: ");
    char *p = fgets(str, STRMAX, stdin);
    if ((p == NULL) || (str[strlen(str) - 1] != '\n'))
    {
        printf("Input error");
        return ERRORINPUT;
    }
    else
    {
        int len_word_array = string_split(str, pword_array, word_array, symbols);
        if (len_word_array == 0)
        {
            printf("Input error");
            return ERRORINPUT;
        }
        else
        {
            len_word_array = clean(word_array, len_word_array);
            word_arr(word_array, len_word_array);
            char new_str[STRMAX] = { 0 };
            str_new(new_str, word_array, len_word_array);
            if (strlen(new_str) != 0)
            {
                printf("Result: %s", new_str);
                return OK;
            }
            else
            {
                printf("Invalid input");
                return ERRORLOGIC;
            }
        }
    }
}
