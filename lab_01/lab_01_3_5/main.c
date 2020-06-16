#include <stdio.h>

int nod(int a, int b);

int main()
{
    int a, b;
    setbuf(stdout, NULL);
    printf("Input integer A and B:\n");
    int rc;
    rc = scanf("%d%d", &a, &b);
    if ((rc == 2) && (a > 0) && (b > 0))
    {
        int rez = nod(a, b);
        printf("NOD(a,b) = %d", rez);
        return 0;
    }
    else
    {
        printf("Input error");
        return -1;
    }
}

int nod(int a, int b)
{
    int x = a, y = b;
    while ((x != y))
    {
        if (x > y)
            x = x - y;
        else
            y = y - x;
    }
    return x;
}
