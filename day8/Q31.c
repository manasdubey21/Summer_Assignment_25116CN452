#include <stdio.h>

int main()
{
    char i = 'A';
    char j;

    while (i <= 'E')
    {
        j = 'A';
        while (j <= i)
        {
            printf("%c ", j);
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}
