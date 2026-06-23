#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    int freq[256] = {0};
    int max_count = 0;
    char max_char = '\0';

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        freq[(unsigned char)str[i]]++;
    }

    for (int i = 0; i < len; i++)
    {
        if (freq[(unsigned char)str[i]] > max_count)
        {
            max_count = freq[(unsigned char)str[i]];
            max_char = str[i];
        }
    }

    if (max_count > 0)
    {
        printf("Maximum occurring character: '%c' (appears %d times)\n", max_char, max_count);
    }
    else
    {
        printf("The string is empty.\n");
    }

    return 0;
}
