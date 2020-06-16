#include <stdio.h>
#include <math.h>

int main(void)
{
    float a, b, h;
    float c, p;
    setbuf(stdout, NULL);
    printf("Input integer or float a, b and h\n");
    scanf("%f%f%f", &a, &b, &h);
    c = sqrt((b - a) * (b - a) / 4 + h * h);
    p = c + c + a + b;
    printf("The perimeter of the trapeziod %.5f", p);
    return 0;
}
