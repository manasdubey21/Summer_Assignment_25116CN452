#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols;
    int i, j;
    int is_symmetric = 1;

    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2)
    {
        printf("Invalid input.\n");
        return 1;
    }

    if (rows != cols)
    {
        printf("The matrix must be square to be symmetric.\n");
        return 0;
    }

    int matrix[rows][cols];

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                printf("Invalid input.\n");
                return 1;
            }
        }
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                is_symmetric = 0;
                break;
            }
        }
        if (!is_symmetric)
        {
            break;
        }
    }

    if (is_symmetric)
    {
        printf("The matrix is symmetric.\n");
    }
    else
    {
        printf("The matrix is not symmetric.\n");
    }

    return 0;
}
