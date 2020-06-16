/*В одномерном массиве найти сумму максимального
и минимального элементов и, если она четная –
записать ее в начало массива (перед первым элементом),
а если нечетная – то в конец (после последнего элемента).
Дополнительных массивов не использовать.*/

#include <stdio.h>

#define N 10
#define OK 0
#define INPUT_ERROR 1
#define LOGIC_ERROR 2

int read_arr(int a[], int n);
int read_n(int *n);
int max_el(int a[], int n);
int min_el(int a[], int n);
void array(int a[], int n, int a_new);
void print(int b[], int n);

int main(void)
{
    setbuf(stdout, NULL);
    int a[N + 1];
    int n;
    printf("Input N (integer and 1 <= N <= 10) ");
    int rc = read_n(&n);
    if (rc == INPUT_ERROR)
    {
        printf("Input error");
        return INPUT_ERROR;
    }
    else
    {
        if (rc == LOGIC_ERROR)
        {
            printf("Logic error");
            return LOGIC_ERROR;
        }
        else
        {
            rc = read_arr(a, n);
            if (rc)
            {
                printf("Input error");
                return INPUT_ERROR;
            }
            else
            {
                int max_ell = max_el(a, n);
                int min_ell = min_el(a, n);
                int a_new = max_ell + min_ell;
                if (a_new % 2 == 1)
                    a[n++] = a_new;
                else
                    array(a, n++, a_new);
                print(a, n);
            }
        }
    }
    return OK;
}
int read_n(int *n)
{
    int rc = scanf("%d", n);
    if (rc == 1)
    {
        if ((*n > 0) && (*n <= 10))
            return OK;
        else
            return LOGIC_ERROR;
    }
    else
    {
        return INPUT_ERROR;
    }
}
int read_arr(int a[], int n)
{
    int s, fi = OK;
        for (int i = 0; i < n; i++)
        {
            printf("Input element of array (integer) ");
            int rc = scanf("%d", &s);
            if (rc == 1)
                a[i] = s;
            else
            {
                fi = INPUT_ERROR;
                break;
            }
        }
    return fi;
}
int max_el(int a[], int n)
{
    int max_ell = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max_ell)
            max_ell = a[i];
    }
    return max_ell;
}
int min_el(int a[], int n)
{
    int min_ell = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min_ell)
            min_ell = a[i];
    }
    return min_ell;
}
void array(int a[], int n, int a_new)
{
    for (int i = n; i > 0; i--)
        a[i] = a[i - 1];
    a[0] = a_new;
}
void print(int b[], int n)
{
    printf("New array ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
}
