#include <stdio.h>
#define N 10
#define M 10
#define OK 0
#define ERR_INPUT 1
#define ERR_LOGIC 2

int read_n_m(int *n, int *m);
int read_matrix(int n, int m, int a[N][M]);
void write_matrix(int a[N][M], int n, int m);
void min_el(int n, int m, int a[N][M]);
int max_el(int a[N][M], int jmax, int m);

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
            min_el(n, m, a);
            write_matrix(a, n, m);
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
void min_el(int n, int m, int a[N][M])
{
    for (int i = 0; i < n; i++)
    {
        int jmax = i;
        for (int j = i + 1; j < n; j++)
        {
            if (max_el(a, j, m) > max_el(a, jmax, m))
                jmax = j;
        }
        for (int j = 0; j < m; j++)
        {
            int buf = a[jmax][j];
            for (int k = jmax; k > i; k--)
                a[k][j] = a[k - 1][j];
            a[i][j] = buf;
        }
    }
}
int max_el(int a[N][M], int jmax, int m)
{
    int max_a = a[jmax][0];
    for (int i = 0; i < m; i++)
        if (a[jmax][i] > max_a)
            max_a = a[jmax][i];
    return max_a;
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
