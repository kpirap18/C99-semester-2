#include <stdio.h>

int main()
{
    float h, t, m;
    float v, ind;
    setbuf(stdout, NULL);
    printf("Input integer or float height in cm, chest circumference in cm, weight in kg\n");
    scanf("%f%f%f", &h, &t, &m);
    v = h * t / 240;
    h = h / 100;
    ind = m / h / h;
    printf("The normal weight of a person %.5f\n", v);
    printf("The body mass index %.5f", ind);
    return 0;
}
