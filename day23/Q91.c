#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkAnagram(char *str1, char *str2)
{
    int count1[256] = {0};
    int count2[256] = {0};
    int i = 0;

    if (strlen(str1) != strlen(str2))
    {
        return 0;
    }

    for (i = 0; str1[i] != '\0'; i++)
    {
        count1[(unsigned char)str1[i]]++;
        count2[(unsigned char)str2[i]]++;
    }

    for (i = 0; i < 256; i++)
    {
        if (count1[i] != count2[i])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char *str1 = malloc(100 * sizeof(char));
    char *str2 = malloc(100 * sizeof(char));

    if (str1 == NULL || str2 == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter first string: ");
    scanf("%99s", str1);

    printf("Enter second string: ");
    scanf("%99s", str2);

    if (checkAnagram(str1, str2))
    {
        printf("The strings are anagrams.\n");
    }
    else
    {
        printf("The strings are not anagrams.\n");
    }

    free(str1);
    free(str2);

    return 0;
}
