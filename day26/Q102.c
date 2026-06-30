
#include <stdio.h>

int main()
{
    int age;

    printf("Enter your age: ");
    if (scanf("%d", &age) != 1)
    {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    if (age >= 18)
    {
        printf("You are eligible to vote.\n");
    }
    else if (age >= 0)
    {
        printf("You are not eligible to vote. You must wait %d more year(s).\n", 18 - age);
    }
    else
    {
        printf("Invalid age entered.\n");
    }

    return 0;
}
