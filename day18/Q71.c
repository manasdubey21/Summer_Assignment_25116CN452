#include <stdio.h>

int main()
{
    int n, search, first, last, middle;
    int array[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter value to find: ");
    scanf("%d", &search);

    first = 0;
    last = n - 1;
    middle = first + (last - first) / 2;

    while (first <= last)
    {
        if (array[middle] < search)
        {
            first = middle + 1;
        }
        else if (array[middle] == search)
        {
            printf("%d found at index %d.\n", search, middle);
            return 0;
        }
        else
        {
            last = middle - 1;
        }
        middle = first + (last - first) / 2;
    }

    printf("Not found! %d isn't present in the list.\n", search);
    return 0;
}
