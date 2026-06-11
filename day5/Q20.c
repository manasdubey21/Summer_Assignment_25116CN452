#include <stdio.h>

long long get_largest_prime_factor(long long n)
{
    long long max_prime = -1;

    while (n % 2 == 0)
    {
        max_prime = 2;
        n /= 2;
    }

    for (long long i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            max_prime = i;
            n /= i;
        }
    }

    if (n > 2)
    {
        max_prime = n;
    }

    return max_prime;
}

int main()
{
    long long num;

    if (scanf("%lld", &num) != 1 || num < 2)
    {
        return 1;
    }

    printf("%lld\n", get_largest_prime_factor(num));

    return 0;
}
