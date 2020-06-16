#include <stdio.h>
#define N 10
#define M 10
#define OK 0
#define ERR_INPUT 1
#define ERR_LOGIC 2

void write_matrix(int a[N][M], int n, int m);
int read_n_m(int *n, int *m);
int read_matrix(int *n, int *m, int a[N][M]);
void chek_matrix(int *n, int *m, int a[N][M], int b[N]);
void write_arr(int b[N], int n);

int main()
{
    setbuf(stdout, NULL);
    int a[N][M];
    int b[N];
    int n, m;
    int err = read_n_m(&n, &m);
    if (err != OK)
    {
        printf("Input error");
        return err;
    }
    else
    {
        err = read_matrix(&n, &m, a);
        if (err != 0)
        {
            printf("Error input element");
            return err;
        }
        else
        {
            //write_matrix(a, n, m);
            if (m == 1)
            {
                for (int i = 0; i < n; i++)
                    b[i] = 1;
            }
            else
                chek_matrix(&n, &m, a, b);
            write_arr(b, n);
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
int read_matrix(int *n, int *m, int a[N][M])
{
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
        {
            int rc = scanf("%d", &a[i][j]);
            if (rc != 1)
                return ERR_INPUT;
        }
    return OK;
}
void chek_matrix(int *n, int *m, int a[N][M], int b[N])
{
    for (int i = 0; i < *n; i++)
    {
        int p = 0;
        for (int j = 0; j < *m; j++)
        {
            if (a[i][j] == a[i][*m - j - 1])
                p++;
        }
        if (p == *m)
            b[i] = 1;
        else
            b[i] = 0;
    }
}
void write_arr(int b[N], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
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
