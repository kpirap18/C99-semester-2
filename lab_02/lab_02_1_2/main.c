#include <stdio.h>
#define N 10
#define OK 0
#define ERR -1

int read(int a[], int *n);
void print(int b[], int n);
int simple_arr(int);
int main()
{
    int a[N], b[N];
    int n;
    setbuf(stdout, NULL);
    int fi = read(a, &n);
    if (fi)
    {
        int j = 0;
        int k;
        for (int i = 0; i < n; i++)
        {
            k = simple_arr(a[i]);
            if (k)
            {
                b[j] = k;
                j++;
            }
        }
        if (j)
        {
            print(b, j);
            return OK;
        }
        else
        {
            printf("Input error");
            return ERR;
        }
    }
    else
    {
        printf("Input error");
        return ERR;
    }
}
int read(int a[], int *n)
{
    printf("Inpur size of array(intrger) ");
    int fi;
    int rc = scanf("%d", n);
    if (rc == 1)
    {
        fi = 1;
        if ((*n > 0) && (*n <= 10))
        {
            fi = 1;
            int s;
            for (int i = 0; i < *n; i++)
            {
                printf("Element of array ");
                rc = scanf("%d", &s);
                if (rc == 1)
                    a[i] = s;
                else
                {
                    fi = 0;
                    break;
                }
            }
        }
        else
        {
            fi = 0;
        }
    }
    else
    {
        fi = 0;
    }
    return fi;
}
int simple_arr(int a)
{
    if (a == 1)
        return OK;
    if (a > 1)
    {
        for (int p = 2; p * p <= a; p++)
        {
            if (a % p == 0)
                return OK;
        }
        return a;
    }
    else
        return OK;
}
void print(int b[], int n)
{
    printf("Simple elements ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
}
