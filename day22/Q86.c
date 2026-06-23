#include <stdio.h>
#include <ctype.h>

int main()
{
    char sentence[1000];
    int count = 0;
    int in_word = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (isspace((unsigned char)sentence[i]))
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            in_word = 1;
            count++;
        }
    }

    printf("Word count: %d\n", count);

    return 0;
}
