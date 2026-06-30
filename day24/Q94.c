#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    printf("Enter a string: ");
    scanf("%999s", str);

    int len = strlen(str);
    printf("Compressed string: ");

    for (int i = 0; i < len; i++)
    {
        int count = 1;
        while (i < len - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        printf("%c%d", str[i], count);
    }
    printf("\n");

    return 0;
}
