#include <stdio.h>
#define N 10
#define OK 0
#define ERR -1

int found(int *pa, int *pb);
int read(int *pa, int *n);
int main()
{
    int a[N];
    int *pa = a;
    int n;
    setbuf(stdout, NULL);
    printf("Input N (integer) ");
    int rc = scanf("%d", &n);
    if (rc == 1)
    {
        int kol = -1;
        if ((n > 0) && (n < 11))
        {
            int *pb;
            pb = pa + n;
            int fi = read(pa, pb);
            if (fi)
                kol = found(pa, pb);
        }
        else
        {
            printf("Input error");
            return ERR;
        }
        if (kol != -1)
        {
            printf("Number of different elements %d", kol);
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
int read(int *pa, int *pb)
{
    int fi;
    int rc;
    fi = 1;
    int s;
    for (; pa < pb;)
    {
        printf("Element of array ");
        rc = scanf("%d", &s);
        if (rc == 1)
        {
            *pa = s;
            pa++;
        }
        else
        {
            fi = 0;
            break;
        }
    }
    return fi;
}
int found(int *pa, int *pb)
{
    int res = 0;
    for (; pa < pb; pa++)
    {
        int flag = 0;
        int *pa1 = pa;
        for (; pa1 < pb; pa1++)
        {
            if (*pa == *pa1)
                flag++;
        }
        if (flag == 1)
            res++;
    }
    return res;
}
