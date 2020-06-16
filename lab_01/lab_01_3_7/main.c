#include <stdio.h>
#include <math.h>

float arctg(float, float);

int main()
{
    float x, eps;
    int rc;
    printf("Input integer or float X and float EPS\n");
    rc = scanf("%f%f", &x, &eps);
    if ((rc == 2) && (x >= -1) && (x <= 1) && (eps < 1) && (eps > 0))
    {
        float rezs = arctg(x, eps);
        printf("S(x) = %.6f\n", rezs);
        float rezf = atan(x);
        printf("F(x) = %.6f\n", rezf);
        float erro, errp;
        erro = rezf - rezs;
        if (rezf == 0)
            errp = 0;
        else
            errp = erro / rezf;
        printf("F(x)-S(x) = %.6f\n", fabs(erro));
        printf("(F(x)-S(x))/F(x) = %f.6\n", fabs(errp));
        return 0;
    }
    else
    {
        printf("Input error");
        return -1;
    }
}

float arctg(float x, float eps)
{
    float t, s, t1;
    int n = 0;
    t = x;
    s = x;
    t1 = t / (2 * n + 1);
    while (fabs(t1) > eps)
    {
        n += 1;
        t = (-1) * t * x * x;
        t1 = t / (2 * n + 1);
        s = s + t1;
    }
    return s;
}
