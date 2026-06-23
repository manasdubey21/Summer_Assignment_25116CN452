#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int freq[256] = {0};
    int found = 0;

    if (fgets(str, sizeof(str), stdin) == NULL)
    {
        return 1;
    }

    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; str[i] != '\0'; i++)
    {
        freq[(unsigned char)str[i]]++;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (freq[(unsigned char)str[i]] == 1)
        {
            printf("%c\n", str[i]);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("No non-repeating character found\n");
    }

    return 0;
}
