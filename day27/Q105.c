#include <stdio.h>
#include <string.h>

struct Student
{
    int roll;
    char name[50];
    float gpa;
};

void addStudent(struct Student s[], int *count)
{
    printf("Enter Roll Number: ");
    scanf("%d", &s[*count].roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", s[*count].name);
    printf("Enter GPA: ");
    scanf("%f", &s[*count].gpa);
    (*count)++;
    printf("Record added successfully!\n");
}

void displayStudents(struct Student s[], int count)
{
    if (count == 0)
    {
        printf("No records found.\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++)
    {
        printf("Roll: %d | Name: %s | GPA: %.2f\n", s[i].roll, s[i].name, s[i].gpa);
    }
}

void searchStudent(struct Student s[], int count)
{
    if (count == 0)
    {
        printf("No records to search.\n");
        return;
    }
    int roll, found = 0;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            printf("Record Found: Roll: %d | Name: %s | GPA: %.2f\n", s[i].roll, s[i].name, s[i].gpa);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Record not found.\n");
    }
}

void deleteStudent(struct Student s[], int *count)
{
    if (*count == 0)
    {
        printf("No records to delete.\n");
        return;
    }
    int roll, found = 0;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);
    for (int i = 0; i < *count; i++)
    {
        if (s[i].roll == roll)
        {
            found = 1;
            for (int j = i; j < *count - 1; j++)
            {
                s[j] = s[j + 1];
            }
            (*count)--;
            printf("Record deleted successfully!\n");
            break;
        }
    }
    if (!found)
    {
        printf("Record not found.\n");
    }
}

int main()
{
    struct Student students[100];
    int count = 0;
    int choice;

    do
    {
        printf("\n1. Add Student\n2. Display All\n3. Search Student\n4. Delete Student\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent(students, &count);
            break;
        case 2:
            displayStudents(students, count);
            break;
        case 3:
            searchStudent(students, count);
            break;
        case 4:
            deleteStudent(students, &count);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
