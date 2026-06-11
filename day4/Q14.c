#include <stdio.h>

int main()
{
    int n;
    printf("enetr number");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        return 1;
    }

    if (n == 0)
    {
        printf("0\n");
        return 0;
    }
    else if (n == 1)
    {
        printf("1\n");
        return 0;
    }

    long long prev2 = 0;
    long long prev1 = 1;
    long long current = 0;

    for (int i = 2; i <= n; i++)
    {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    printf("%lld\n", current);
    return 0;
}
