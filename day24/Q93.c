#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str1[256];
    char str2[256];

    printf("Enter the first string: ");
    if (fgets(str1, sizeof(str1), stdin) == NULL)
        return 1;
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the second string: ");
    if (fgets(str2, sizeof(str2), stdin) == NULL)
        return 1;
    str2[strcspn(str2, "\n")] = '\0';

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2)
    {
        printf("The strings are not rotations of each other.\n");
        return 0;
    }

    char *temp = (char *)malloc(sizeof(char) * (len1 * 2 + 1));
    if (temp == NULL)
        return 1;

    strcpy(temp, str1);
    strcat(temp, str1);

    if (strstr(temp, str2) != NULL)
    {
        printf("The strings are rotations of each other.\n");
    }
    else
    {
        printf("The strings are not rotations of each other.\n");
    }

    free(temp);
    return 0;
}
