#include <stdio.h>
#define N 10
#define M 10
#define NN 100
#define OK 0
#define ERR_INPUT 1
#define ERR_LOGIC 2

int read_n_m(int *n, int *m);
int read_matrix(int n, int m, int a[N][M]);
void write_matrix(int a[N][M], int n, int m);
void arr(int b[NN], int a[N][M], int n, int m, int *k);
int sum(int a1);
void left_arr(int b[NN], int k);
void new_matrix(int a[N][M], int b[NN], int n, int m);

int main()
{
    setbuf(stdout, NULL);
    int a[N][M];
    int b[NN];
    int n, m;
    int err = read_n_m(&n, &m);
    if (err != OK)
    {
        printf("Input error");
        return err;
    }
    else
    {
        err = read_matrix(n, m, a);
        if (err != 0)
        {
            printf("Error input element");
            return err;
        }
        else
        {
            int k = 0;
            arr(b, a, n, m, &k);
            if (k == 0)
            {
                printf("Input error");
                return ERR_LOGIC;
            }
            else
            {
                //write_matrix(a, n, m);
                left_arr(b, k);
                new_matrix(a, b, n, m);
                write_matrix(a, n, m);
            }
        }
    }
    return OK;
}
int read_n_m(int *n, int *m)
{
    setbuf(stdout, NULL);
    printf("Input (integer) N and M: ");
    int rc = scanf("%d%d", n, m);
    if (rc == 2)
    {
        if ((*n > 0) && (*n < 11) && (*m > 0) && (*m < 11))
            return OK;
        else
            return ERR_LOGIC;
    }
    else
        return ERR_INPUT;
}
int read_matrix(int n, int m, int a[N][M])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int rc = scanf("%d", &a[i][j]);
            if (rc != 1)
                return ERR_INPUT;
        }
    return OK;
}
void arr(int b[NN], int a[N][M], int n, int m, int *k)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (sum(a[i][j]) > 10)
            {
                b[*k] = a[i][j];
                *k = *k + 1;
            }
        }
}
int sum(int a1)
{
    int s = 0;
    if (a1 < 0)
        a1 = (-1) * a1;
    while (a1)
    {
        s += (a1 % 10);
        a1 /= 10;
    }
    return s;
}
void left_arr(int b[NN], int k)
{
    for (int i = 0; i < 3; i++)
    {
        int c = b[0];
        for (int j = 1; j < k; j++)
            b[j - 1] = b[j];
        b[k - 1] = c;
    }
}
void new_matrix(int a[N][M], int b[NN], int n, int m)
{
    int p = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (sum(a[i][j]) > 10)
            {
                a[i][j] = b[p];
                p++;
            }
        }
}
void write_matrix(int a[N][M], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}
