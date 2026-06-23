#include <stdio.h>

int main()
{
    int r, c;

    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &r, &c) != 2)
    {
        return 1;
    }

    int matrix[r][c];

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                return 1;
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        int row_sum = 0;
        for (int j = 0; j < c; j++)
        {
            row_sum += matrix[i][j];
        }
        printf("Sum of row %d = %d\n", i + 1, row_sum);
    }

    return 0;
}
