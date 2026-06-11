#include <stdio.h>

int main()
{
    int num;
    int factorial = 1;
    printf("Enter an integer: ");
    scanf("%d", &num);
    if (num < 0)
    {
        printf("Error! Factorial of a negative number does not exist.\n");
    }
    else
    {
        for (int i = 1; i <= num; ++i)
        {
            
            factorial *= i;
        }
        printf("Factorial of %d = %d \n", num, factorial);
    }

    return 0;
}