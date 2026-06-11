#include <stdio.h>

int findMax(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    return num2;
}

int main()
{
    int a = 15;
    int b = 25;
    int max = findMax(a, b);
    printf("Maximum: %d\n", max);
    return 0;
}
