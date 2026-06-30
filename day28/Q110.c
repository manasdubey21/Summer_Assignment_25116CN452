#include <stdio.h>
#include <string.h>

struct BankAccount
{
    int accountNumber;
    char name[50];
    double balance;
};

int main()
{
    struct BankAccount account;
    int accountCreated = 0;
    int choice;
    int inputAccNo;
    double amount;

    while (1)
    {
        printf("\n=== BANK ACCOUNT SYSTEM ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Account Number: ");
            scanf("%d", &account.accountNumber);
            printf("Enter Account Holder Name: ");
            scanf(" %[^\n]s", account.name);
            printf("Enter Initial Deposit: ");
            scanf("%lf", &account.balance);
            accountCreated = 1;
            printf("\nAccount created successfully!\n");
            break;

        case 2:
            if (!accountCreated)
            {
                printf("\nError: Create an account first.\n");
                break;
            }
            printf("\nEnter Account Number: ");
            scanf("%d", &inputAccNo);
            if (inputAccNo != account.accountNumber)
            {
                printf("Error: Invalid account number.\n");
                break;
            }
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            if (amount <= 0)
            {
                printf("Error: Invalid deposit amount.\n");
            }
            else
            {
                account.balance += amount;
                printf("Deposited: $%.2f. New Balance: $%.2f\n", amount, account.balance);
            }
            break;

        case 3:
            if (!accountCreated)
            {
                printf("\nError: Create an account first.\n");
                break;
            }
            printf("\nEnter Account Number: ");
            scanf("%d", &inputAccNo);
            if (inputAccNo != account.accountNumber)
            {
                printf("Error: Invalid account number.\n");
                break;
            }
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (amount <= 0)
            {
                printf("Error: Invalid withdrawal amount.\n");
            }
            else if (amount > account.balance)
            {
                printf("Error: Insufficient balance.\n");
            }
            else
            {
                account.balance -= amount;
                printf("Withdrawn: $%.2f. Remaining Balance: $%.2f\n", amount, account.balance);
            }
            break;

        case 4:
            if (!accountCreated)
            {
                printf("\nError: Create an account first.\n");
                break;
            }
            printf("\nEnter Account Number: ");
            scanf("%d", &inputAccNo);
            if (inputAccNo != account.accountNumber)
            {
                printf("Error: Invalid account number.\n");
                break;
            }
            printf("\n--- Account Summary ---\n");
            printf("Account Number: %d\n", account.accountNumber);
            printf("Holder Name: %s\n", account.name);
            printf("Current Balance: $%.2f\n", account.balance);
            break;

        case 5:
            printf("\nThank you for using our banking system!\n");
            return 0;

        default:
            printf("\nError: Invalid option. Try again.\n");
        }
    }
    return 0;
}
