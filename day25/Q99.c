#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j;
    char names[100][50];
    char temp[50];

    printf("Enter the number of names: ");
    if (scanf("%d", &n) != 1)
    {
        return 1;
    }

    printf("Enter %d names:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", names[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(names[i], names[j]) > 0)
            {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("\nSorted names:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", names[i]);
    }

    return 0;
}
