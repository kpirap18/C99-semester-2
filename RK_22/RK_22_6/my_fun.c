#include "my_utils.h"

int from_file_to_array(FILE *const f, char str[MAX_STR][STR_LEN])
{
    char s[STR_LEN] = { 0 };
    int i = 0;

    while (fgets(s, STR_LEN, f) != NULL)
    {
        for(int j = 0; j < STR_LEN; j++)
            str[i][j] = s[j];
        i++;
    }

    if (i)
        return i;
    else
        return INVALID_ARG;
}
void trasform(char **a, char *buf, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = buf + n * i;
    }
}
void print_array_to_file_txt(FILE *const f, char str[MAX_STR][STR_LEN], int n)
{
    for (int i = 0; i < n; i++)
        fprintf(f, "%s", str[i]);
}
void print_file_to_cons(FILE *f, int n)
{
    char s[STR_LEN];
    for (int i = 0; i < n; i++)
    {
        fgets(s, STR_LEN, f);
        printf("%s", s);
    }
}
