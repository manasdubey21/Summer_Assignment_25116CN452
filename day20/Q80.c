#include <stdio.h>

int main()
{
    int rows, cols;

    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2)
    {
        return 1;
    }

    int matrix[rows][cols];

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                return 1;
            }
        }
    }

    for (int j = 0; j < cols; j++)
    {
        int col_sum = 0;
        for (int i = 0; i < rows; i++)
        {
            col_sum += matrix[i][j];
        }
        printf("Sum of column %d = %d\n", j + 1, col_sum);
    }

    return 0;
}
