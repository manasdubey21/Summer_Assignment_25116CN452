#include <stdio.h>
#include <string.h>

struct Student
{
    int roll_number;
    char name[50];
    float marks;
};

int main()
{
    int num_students;

    printf("Enter the number of students: ");
    if (scanf("%d", &num_students) != 1 || num_students <= 0)
    {
        printf("Invalid number of students.\n");
        return 1;
    }

    struct Student records[num_students];

    for (int i = 0; i < num_students; i++)
    {
        printf("\nEnter details for student %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &records[i].roll_number);

        getchar();

        printf("Enter Name: ");
        fgets(records[i].name, sizeof(records[i].name), stdin);
        records[i].name[strcspn(records[i].name, "\n")] = '\0';

        printf("Enter Marks: ");
        scanf("%f", &records[i].marks);
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < num_students; i++)
    {
        printf("ID: %d | Name: %s | Marks: %.2f\n",
               records[i].roll_number, records[i].name, records[i].marks);
    }

    return 0;
}
