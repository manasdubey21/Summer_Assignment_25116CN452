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

    printf("Enter number of right rotations: ");
    scanf("%d", &d);

    d = d % n;

    for (int r = 0; r < d; r++)
    {
        int last = arr[n - 1];
        for (int i = n - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    }

    printf("Array after right rotation: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}