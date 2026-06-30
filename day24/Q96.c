#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str)
{
    int len = strlen(str);
    if (len < 2)
    {
        return;
    }

    int index = 0;
    for (int i = 0; i < len; i++)
    {
        int j;
        for (j = 0; j < index; j++)
        {
            if (str[i] == str[j])
            {
                break;
            }
        }
        if (j == index)
        {
            str[index++] = str[i];
        }
    }
    str[index] = '\0';
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin))
    {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n')
        {
            str[len - 1] = '\0';
        }

        removeDuplicates(str);

        printf("Result: %s\n", str);
    }

    return 0;
}
