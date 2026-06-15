#include <stdio.h>
#include <limits.h>

int main()
{
    int size;
    int max1 = INT_MIN;
    int max2 = INT_MIN;

    printf("Enter size of the array: ");
    if (scanf("%d", &size) != 1 || size < 2)
    {
        printf("Invalid size. Array must have at least 2 elements.\n");
        return 1;
    }

    int arr[size];
    printf("Enter elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2 && arr[i] < max1)
        {
            max2 = arr[i];
        }
    }

    if (max2 == INT_MIN)
    {
        printf("There is no second largest element.\n");
    }
    else
    {
        printf("The second largest element is: %d\n", max2);
    }

    return 0;
}
