#include <stdio.h>

int position(float x1, float y1, float x2, float y2, float xa, float ya);

int main(void)
{
    float x1, y1, x2, y2, xa, ya;
    int rc;
    
    printf("Input integer or float x1, y1, x2, y2, xA, yA\n");
    rc = scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &xa, &ya);
    if ((rc == 6) && ((x1 != x2) || (y1 != y2)))
    {
        int rez = position(x1, y1, x2, y2, xa, ya);
        printf("%d", rez);
        return 0;
    }
    else
    {
        printf("Input error");
        return -1;
    }
}

int position(float x1, float y1, float x2, float y2, float xa, float ya)
{
    float k, b;
    k = (y1 - y2) / (x1 - x2);
    b = y1 - x1 * k;
    if (ya > (k * xa + b))
        return 0;
    else if (ya < (k * xa + b))
        return 2;
    else
        return 1;
}