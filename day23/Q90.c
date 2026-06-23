#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    int count[256] = {0};
    int found = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL)
    {
        return 1;
    }

    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; str[i] != '\0'; i++)
    {
        unsigned char ch = (unsigned char)str[i];
        if (count[ch] == 1)
        {
            printf("First repeating character: %c\n", ch);
            found = 1;
            break;
        }
        count[ch]++;
    }

    if (!found)
    {
        printf("No repeating character found.\n");
    }

    return 0;
}
