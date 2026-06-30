#include <stdio.h>

int main()
{
    int pin, choice, attempts = 0;
    float balance = 5000.0, amount;
    int correct_pin = 1234;
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &pin);
    while (1)
    {
        printf("\n=== Welcome to the ATM ===\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw Cash\n");
        printf("3. Deposit Cash\n");
        printf("4. Exit\n");
        printf("Please enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nYour current balance is: $%.2f\n", balance);
            break;
        case 2:
            printf("\nEnter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > balance)
            {
                printf("Transaction failed! Insufficient funds.\n");
            }
            else if (amount <= 0)
            {
                printf("Transaction failed! Invalid amount.\n");
            }
            else
            {
                balance -= amount;
                printf("Please collect your cash.\n");
                printf("New balance: $%.2f\n", balance);
            }
            break;
        case 3:
            printf("\nEnter amount to deposit: ");
            scanf("%f", &amount);
            if (amount <= 0)
            {
                printf("Transaction failed! Invalid amount.\n");
            }
            else
            {
                balance += amount;
                printf("Successfully deposited $%.2f\n", amount);
                printf("New balance: $%.2f\n", balance);
            }
            break;
        case 4:
            printf("\nThank you for using our ATM. Goodbye!\n");
            return 0;
        default:
            printf("\nInvalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}
