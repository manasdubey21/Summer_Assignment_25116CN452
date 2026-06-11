#include <stdio.h>

int main()
{
    double x;
    int n;
    double result = 1.0;

    printf("Enter base (x): ");
    scanf("%lf", &x);
    printf("Enter exponent (n): ");
    scanf("%d", &n);

    int steps = (n < 0) ? -n : n;
    int i = 0;

    while (i < steps)
    {
        result *= x;
        i++;
    }

    if (n < 0)
    {
        result = 1.0 / result;
    }

    printf("%.2lf to the power of %d is %.6lf\n", x, n, result);

    return 0;
}
