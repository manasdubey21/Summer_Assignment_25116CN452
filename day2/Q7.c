#include <stdlib.h>

int main()
{
    int num, rem;
    long long prod = 1;

    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1)
    {
        return 1;
    }

    num = abs(num);

    if (num == 0)
    {
        prod = 0;
    }

    while (num > 0)
    {
        rem = num % 10;
        prod *= rem;
        num /= 10;
    }

    printf("Product of digits: %lld\n", prod);

    return 0;
}