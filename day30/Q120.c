// tic tac toe game
#include <stdio.h>

void initializeBoard(char board[])
{
    for (int i = 0; i < 9; i++)
    {
        board[i] = '1' + i;
    }
}

void displayBoard(char board[])
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

int checkWin(char board[])
{
    int winPositions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

    for (int i = 0; i < 8; i++)
    {
        if (board[winPositions[i][0]] == board[winPositions[i][1]] &&
            board[winPositions[i][1]] == board[winPositions[i][2]])
        {
            return 1;
        }
    }
    return 0;
}

int checkDraw(char board[])
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] != 'X' && board[i] != 'O')
        {
            return 0;
        }
    }
    return 1;
}

void makeMove(char board[], int choice, char mark)
{
    board[choice - 1] = mark;
}

int main()
{
    char board[9];
    char players[2][20];
    int currentPlayer = 0;
    int choice;
    char mark;
    int gameStatus = 0;

    printf("Enter Name for Player 1 (X): ");
    scanf("%s", players[0]);
    printf("Enter Name for Player 2 (O): ");
    scanf("%s", players[1]);

    initializeBoard(board);

    do
    {
        displayBoard(board);
        mark = (currentPlayer == 0) ? 'X' : 'O';

        printf("%s (%c), enter a cell number (1-9): ", players[currentPlayer], mark);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9 || board[choice - 1] == 'X' || board[choice - 1] == 'O')
        {
            printf("Invalid move! Try again.\n");
            continue;
        }

        makeMove(board, choice, mark);

        if (checkWin(board))
        {
            displayBoard(board);
            printf("Congratulations! %s wins!\n", players[currentPlayer]);
            gameStatus = 1;
        }
        else if (checkDraw(board))
        {
            displayBoard(board);
            printf("It's a draw!\n");
            gameStatus = 1;
        }
        else
        {
            currentPlayer = 1 - currentPlayer;
        }

    } while (gameStatus == 0);

    return 0;
}
