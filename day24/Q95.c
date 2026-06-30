#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000];
    char longest[100] = "";
    int max_len = 0;

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL)
    {
        return 1;
    }

    sentence[strcspn(sentence, "\n")] = '\0';

    char *word = strtok(sentence, " ");
    while (word != NULL)
    {
        int current_len = strlen(word);
        if (current_len > max_len)
        {
            max_len = current_len;
            strcpy(longest, word);
        }
        word = strtok(NULL, " ");
    }

    if (max_len > 0)
    {
        printf("Longest word: %s\n", longest);
        printf("Length: %d\n", max_len);
    }
    else
    {
        printf("No words found.\n");
    }

    return 0;
}
