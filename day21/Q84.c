// Write a program to Convert lowercase to uppercase#include <stdio.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;

    printf("Enter a lowercase character: ");
    scanf("%c", &ch);

    ch = toupper((unsigned char)ch);

    printf("Uppercase character: %c\n", ch);

    return 0;
}
