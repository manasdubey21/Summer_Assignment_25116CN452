
#include <stdio.h>

int main()
{
    int n, d;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter number of left rotations: ");
    scanf("%d", &d);

    d = d % n;

    for (int r = 0; r < d; r++)
    {
        int first = arr[0];
        for (int i = 0; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = first;
    }

    printf("Array after left rotation: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
