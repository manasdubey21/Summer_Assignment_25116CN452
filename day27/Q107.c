#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    int id;
    char name[50];
    float basic_salary;
    float allowances;
    float deductions;
    float net_salary;
};

int main()
{
    int n, i;

    printf("Enter the number of employees: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid number of employees.\n");
        return 1;
    }

    struct Employee *emp = (struct Employee *)malloc(n * sizeof(struct Employee));
    if (emp == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for Employee %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &emp[i].id);

        printf("Name: ");
        scanf(" %49[^\n]", emp[i].name);

        printf("Basic Salary: ");
        scanf("%f", &emp[i].basic_salary);

        printf("Allowances: ");
        scanf("%f", &emp[i].allowances);

        printf("Deductions: ");
        scanf("%f", &emp[i].deductions);

        emp[i].net_salary = emp[i].basic_salary + emp[i].allowances - emp[i].deductions;
    }

    printf("\n================ SALARY REPORT ================\n");
    printf("%-5s %-20s %-12s %-12s %-12s %-12s\n", "ID", "Name", "Basic", "Allowances", "Deductions", "Net Salary");
    printf("----------------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%-5d %-20s %-12.2f %-12.2f %-12.2f %-12.2f\n",
               emp[i].id,
               emp[i].name,
               emp[i].basic_salary,
               emp[i].allowances,
               emp[i].deductions,
               emp[i].net_salary);
    }
    printf("===============================================\n");

    free(emp);
    return 0;
}
