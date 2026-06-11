#include <stdio.h>

int reverse(int n, int rev)
{
    if (n == 0)
        return rev;

    rev = rev * 10 + n % 10;
    return reverse(n / 10, rev);
}

int main()
{
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    int reversed_num = reverse(num, 0);
    printf("Reversed number: %d\n", reversed_num);

    return 0;
}
