#include <stdio.h>

int main()
{
    int choice;
    char str1[100], str2[100], result[200];
    int i, j;

    do
    {
        printf("\n1.Len 2.Rev 3.Concat 4.Comp 5.Exit: ");
        scanf("%d", &choice);
        while (getchar() != '\n')
            ;

        switch (choice)
        {
        case 1:
            printf("String: ");
            scanf("%99[^\n]", str1);
            for (i = 0; str1[i] != '\0'; i++)
                ;
            printf("Len: %d\n", i);
            break;
        case 2:
            printf("String: ");
            scanf("%99[^\n]", str1);
            for (i = 0; str1[i] != '\0'; i++)
                ;
            for (j = i - 1; j >= 0; j--)
                putchar(str1[j]);
            printf("\n");
            break;
        case 3:
            printf("Str1: ");
            scanf("%99[^\n]", str1);
            while (getchar() != '\n')
                ;
            printf("Str2: ");
            scanf("%99[^\n]", str2);
            for (i = 0; str1[i] != '\0'; i++)
                result[i] = str1[i];
            for (j = 0; str2[j] != '\0'; j++)
                result[i + j] = str2[j];
            result[i + j] = '\0';
            printf("Result: %s\n", result);
            break;
        case 4:
            printf("Str1: ");
            scanf("%99[^\n]", str1);
            while (getchar() != '\n')
                ;
            printf("Str2: ");
            scanf("%99[^\n]", str2);
            for (i = 0; str1[i] == str2[i] && str1[i] != '\0'; i++)
                ;
            printf("%s\n", (str1[i] == str2[i]) ? "Equal" : "Different");
            break;
        }
    } while (choice != 5);
    return 0;
}
