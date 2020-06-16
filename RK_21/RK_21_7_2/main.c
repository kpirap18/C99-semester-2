/*В квадратной матрице удалить строку и столбец,
  в которых находится максимальный элемент.*/

#include <stdio.h>

#define N 10
#define M 10
#define OK 0
#define INPUT_ERROR 1
#define LOGIC_ERROR 2

int read_n_m(int *n, int *m);
int read_matrix(int n, int m, int a[N][M]);
void max_el(int a[N][M], int n, int m, int *max_i, int *max_j);
void del_i_j(int a[N][M], int n, int m, int max_i, int max_j);
void write_matrix(int a[N][M], int n, int m);

int main(void)
{
    setbuf(stdout, NULL);
    int a[N][M];
    int n, m;
    printf("Input N and M (integer and 1 <= N,M <=10) ");
    int rc = read_n_m(&n, &m);
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
            printf("Input matrix(elements integer) \n");
            rc = read_matrix(n, m, a);
            if (rc)
            {
                printf("Input error");
                return INPUT_ERROR;
            }
            else
            {
                int max_i, max_j;
                max_el(a, n, m, &max_i, &max_j);
                del_i_j(a, n, m, max_i, max_j);
                printf("\nNew matrix \n");
                write_matrix(a, --n, --m);
            }
        }
    }
    return OK;
}
int read_n_m(int *n, int *m)
{
    int rc = scanf("%d%d", n, m);
    if (rc == 2)
    {
        if ((*n > 0) && (*n < 11) && (*m > 0) && (*m < 11) && (*n == *m))
            return OK;
        else
            return LOGIC_ERROR;
    }
    else
        return INPUT_ERROR;
}
int read_matrix(int n, int m, int a[N][M])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int rc = scanf("%d", &a[i][j]);
            if (rc != 1)
                return INPUT_ERROR;
        }
    return OK;
}
void max_el(int a[N][M], int n, int m, int *max_i, int *max_j)
{
    int max_e = a[0][0];
    *max_i = 0;
    *max_j = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] > max_e)
            {
                max_e = a[i][j];
                *max_i = i;
                *max_j = j;
            }
}
void del_i_j(int a[N][M], int n, int m, int max_i, int max_j)
{
    for (int i = max_i; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = a[i + 1][j];
    n--;
    for (int i = 0; i < n; i++)
        for (int j = max_j; j < m - 1; j++)
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
}
