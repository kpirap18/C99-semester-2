#include <stdio.h>
#define N 10
#define OK 0
#define ERR -1

int read(int a[], int *n);
void print(int a[], int n);
void sortt(int a[], int n);
int main()
{
    int a[N];
    int n;
    setbuf(stdout, NULL);
    int fi = read(a, &n);
    if (fi)
    {
        sortt(a, n);
        print(a, n);
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
void sortt(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = (n - 1); j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                int t = a[j - 1];
                a[j - 1] = a[j];
                a[j] = t;
            }
        }
    }
}
void print(int a[], int n)
{
    printf("Sorted array ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
