#include <stdio.h>
#include <ctype.h>

int main()
{
    char *questions[] = {
        "1. What is the correct keyword to define a variable that cannot be changed in C?",
        "2. Which of the following is a logical OR operator in C?",
        "3. What is the size of an integer data type in C (typically, in bytes)?"};

    char *options[] = {
        "A) constant\nB) const\nC) #define\nD) variable",
        "A) &\nB) ||\nC) &&\nD) !",
        "A) 2\nB) 4\nC) 8\nD) 16"};

    char answers[] = {'B', 'B', 'B'};
    int score = 0;
    int num_questions = sizeof(answers) / sizeof(answers[0]);
    char user_guess;

    for (int i = 0; i < num_questions; i++)
    {
        printf("%s\n", questions[i]);
        printf("%s\n", options[i]);
        printf("Enter your answer (A, B, C, or D): ");

        scanf(" %c", &user_guess);
        user_guess = toupper(user_guess);

        if (user_guess == answers[i])
        {
            printf("Correct!\n\n");
            score++;
        }
        else
        {
            printf("Wrong! The correct answer was %c.\n\n", answers[i]);
        }
    }

    printf("Quiz Over! You scored %d out of %d.\n", score, num_questions);

    return 0;
}
