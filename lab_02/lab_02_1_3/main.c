#include <stdio.h>
#define N 20
#define OK 0
#define ERR -1

int fib(int p);
int read(int a[], int *n);
void write(int n, int a[]);
int main()
{
    int p = 1;
    int a[N];
    int n;
    setbuf(stdout, NULL);
    int fi = read(a, &n);
    if (fi)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 3 == 0)
            {
                for (int j = n; j > i; j--)
                    a[j + 1] = a[j];
                a[i + 1] = fib(p);
                p++;
                n++;
                i++;
            }
        }
        write(n, a);
        return 0;
    }
    else
    {
        printf("Logic error");
        return 1;
    }
}
int fib(int p)
{
    if (p == 1)
        return 0;
    if (p == 2)
        return 1;
    return fib(p - 1) + fib(p - 2);
}
void write(int n, int a[])
{
    printf("New array ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
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
