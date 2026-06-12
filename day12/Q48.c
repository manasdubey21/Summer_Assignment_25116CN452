#include <stdio.h>

int isPerfect(int num)
{
    int sum = 0;
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    if (sum == num && num > 0)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (isPerfect(number))
    {
        printf("%d is a perfect number.\n", number);
    }
    else
    {
        printf("%d is not a perfect number.\n", number);
    }
    return 0;
}
