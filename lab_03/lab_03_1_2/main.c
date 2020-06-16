#include <stdio.h>
#define N 10
#define M 10
#define OK 0
#define ERR_INPUT 1
#define ERR_LOGIC 2

int read_n_m(int *n, int *m);
int read_matrix(int n, int m, int a[N][M]);
void chek_matrix(int n, int m, int a[N][M], int mini, int minj);
void write_matrix(int a[N][M], int n, int m);
void min_el(int n, int m, int a[N][M], int *mini, int *minj);
int sum(int a1);

int main()
{
    setbuf(stdout, NULL);
    int a[N][M];
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
            //write_matrix(a, n, m);
            int mini = 0, minj = 0;
            min_el(n, m, a, &mini, &minj);
            chek_matrix(n, m, a, mini, minj);
            write_matrix(a, n - 1, m - 1);
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
        if ((*n > 1) && (*n < 11) && (*m > 1) && (*m < 11))
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
void min_el(int n, int m, int a[N][M], int *mini, int *minj)
{
    int s_min = sum(a[0][0]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s_min > sum(a[i][j]))
            {
                *mini = i;
                *minj = j;
                s_min = sum(a[i][j]);
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
void chek_matrix(int n, int m, int a[N][M], int mini, int minj)
{
    for (int i = mini; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = a[i + 1][j];
    for (int j = minj; j < m - 1; j++)
        for (int i = 0; i < n; i++)
            a[i][j] = a[i][j + 1];
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
