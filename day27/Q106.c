#include <stdio.h>
#include <string.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

int main()
{
    struct Employee emp[100];
    int count = 0;
    int choice;
    int searchId;
    int found;

    while (1)
    {
        printf("\n=== Employee Management System ===\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (count >= 100)
            {
                printf("System full.\n");
                break;
            }
            printf("Enter ID: ");
            scanf("%d", &emp[count].id);
            printf("Enter Name: ");
            scanf(" %[^\n]s", emp[count].name);
            printf("Enter Salary: ");
            scanf("%f", &emp[count].salary);
            count++;
            printf("Employee added successfully.\n");
            break;

        case 2:
            if (count == 0)
            {
                printf("No records found.\n");
                break;
            }
            printf("\n%-10s %-20s %-10s\n", "ID", "Name", "Salary");
            for (int i = 0; i < count; i++)
            {
                printf("%-10d %-20s %-10.2f\n", emp[i].id, emp[i].name, emp[i].salary);
            }
            break;

        case 3:
            if (count == 0)
            {
                printf("No records found.\n");
                break;
            }
            printf("Enter Employee ID to search: ");
            scanf("%d", &searchId);
            found = 0;
            for (int i = 0; i < count; i++)
            {
                if (emp[i].id == searchId)
                {
                    printf("\nRecord Found:\n");
                    printf("ID: %d\n", emp[i].id);
                    printf("Name: %s\n", emp[i].name);
                    printf("Salary: %.2f\n", emp[i].salary);
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                printf("Employee with ID %d not found.\n", searchId);
            }
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
