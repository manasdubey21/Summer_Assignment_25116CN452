#include <stdio.h>

int main()
{
    int n, target, found = 0;

    printf("Enter array size: ");
    if (scanf("%d", &n) != 1 || n < 2)
    {
        printf("Invalid size.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }
    }

    printf("Enter target sum: ");
    if (scanf("%d", &target) != 1)
    {
        printf("Invalid target.\n");
        return 1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                printf("Pair found: %d and %d\n", arr[i], arr[j]);
                found = 1;
                break;
            }
        }
        if (found)
        {
            break;
        }
    }

    if (!found)
    {
        printf("No pair found with the given sum.\n");
    }

    return 0;
}
