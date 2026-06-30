#include <stdio.h>

int main()
{
    int n, k;

    printf("Enter size of first array: ");
    scanf("%d", &n);
    int arr1[n];
    printf("Enter elements of first array (sorted): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &k);
    int arr2[k];
    printf("Enter elements of second array (sorted): ");
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &arr2[i]);
    }

    int arr3[n + k];
    int i = 0, j = 0, m = 0;

    while (i < n && j < k)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[m] = arr1[i];
            i++;
        }
        else
        {
            arr3[m] = arr2[j];
            j++;
        }
        m++;
    }

    while (i < n)
    {
        arr3[m] = arr1[i];
        i++;
        m++;
    }

    while (j < k)
    {
        arr3[m] = arr2[j];
        j++;
        m++;
    }

    printf("Merged sorted array: ");
    for (int i = 0; i < n + k; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    return 0;
}
