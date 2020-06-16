#include <stddef.h>
#include "mystr.h"

char *my_strpbrk(const char *str1, const char *str2)
{
    //if ((str1 == NULL) || (str2 == NULL))
        //return NULL;
    int i = 0, j = 0;
    while (str1[i])
    {
        while (str2[j])
        {
            if (str1[i] == str2[j])
                return (char *)&str1[i];
            j++;
        }
        i++;
        j = 0;
    }
    return NULL;
}
