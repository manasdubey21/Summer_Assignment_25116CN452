// diagonal sum of a matrix
#include <stdio.h>

int main()
{
    int size;
    int sum = 0;

    printf("Enter the size of the square matrix: ");
    if (scanf("%d", &size) != 1 || size <= 0)
    {
        printf("Invalid size.\n");
        return 1;
    }

    int matrix[size][size];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < size; i++)
    {
        sum += matrix[i][i];
    }

    printf("Sum of the main diagonal elements: %d\n", sum);

    return 0;
}
