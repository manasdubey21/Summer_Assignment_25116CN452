#include <stdio.h>

int main()
{
    int choice;
    double num1, num2, result;

    do
    {
        printf("\n--- Menu-Driven Calculator ---\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (choice >= 1 && choice <= 4)
        {
            printf("Enter two numbers: ");
            if (scanf("%lf %lf", &num1, &num2) != 2)
            {
                printf("Invalid numbers entered!\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
        }

        switch (choice)
        {
        case 1:
            result = num1 + num2;
            printf("Result: %.2lf\n", result);
            break;
        case 2:
            result = num1 - num2;
            printf("Result: %.2lf\n", result);
            break;
        case 3:
            result = num1 * num2;
            printf("Result: %.2lf\n", result);
            break;
        case 4:
            if (num2 != 0)
            {
                result = num1 / num2;
                printf("Result: %.2lf\n", result);
            }
            else
            {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice! Please select an option between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}
