
#include <stdio.h>

int main()
{
    int arr[100], n, target, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &target);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            printf("Element found at index %d\n", i);
            break;
        }
    }

    if (i == n)
    {
        printf("Element not found\n");
    }

    return 0;
}
