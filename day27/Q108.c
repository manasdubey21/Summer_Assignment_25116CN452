#include <stdio.h>

int main()
{
    char name[50];
    int roll;
    float math, science, english, total, average;

    printf("Enter Student Name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    printf("Enter Math marks: ");
    scanf("%f", &math);

    printf("Enter Science marks: ");
    scanf("%f", &science);

    printf("Enter English marks: ");
    scanf("%f", &english);

    total = math + science + english;
    average = total / 3.0;

    printf("\n=============================\n");
    printf("          MARKSHEET          \n");
    printf("=============================\n");
    printf("Name: %s", name);
    printf("Roll Number: %d\n", roll);
    printf("-----------------------------\n");
    printf("Math:    %.2f\n", math);
    printf("Science: %.2f\n", science);
    printf("English: %.2f\n", english);
    printf("-----------------------------\n");
    printf("Total Marks:   %.2f\n", total);
    printf("Average Marks: %.2f\n", average);

    if (average >= 90)
    {
        printf("Grade: A+\n");
    }
    else if (average >= 75)
    {
        printf("Grade: A\n");
    }
    else if (average >= 50)
    {
        printf("Grade: B\n");
    }
    else if (average >= 35)
    {
        printf("Grade: C\n");
    }
    else
    {
        printf("Grade: Fail\n");
    }
    printf("=============================\n");

    return 0;
}
