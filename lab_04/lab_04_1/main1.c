#include <stdio.h>
#include <string.h>
#include "mystr.h"

#define OK 0
#define ERROR 1
#define TEST 6
#define STR_LEN 256

int main()
{
    const char num[TEST][STR_LEN + 1] = { "one", "two", "three", "four", "five", "six" };
    const char test_str1[TEST][STR_LEN + 1] = { "Test for strpbrk", "Hello world!", "To be or not be?", "I am studying to be a programmer", "", "" };
    const char test_str2[TEST][STR_LEN] = { " oijlkf", "ppm!", "mnvc", "", "dfg", "" };
    printf("TESTS FOR my_strpbrk\n");
    for (int i = 0; i < TEST; i++)
    {
        printf("Test %s: ", num[i]);
        if (strpbrk(test_str1[i], test_str2[i]) == \
            my_strpbrk(test_str1[i], test_str2[i]))
            printf("TEST PASSED\n");
    }
    return OK;
}
