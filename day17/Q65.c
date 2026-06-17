#include <stdio.h>

int main()
{
    int n1, n2, n3;

    printf("Enter the size of the first array: ");
    scanf("%d", &n1);

    int arr1[n1];
    printf("Enter %d elements for the first array:\n", n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &n2);

    int arr2[n2];
    printf("Enter %d elements for the second array:\n", n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    n3 = n1 + n2;
    int merged[n3];

    for (int i = 0; i < n1; i++)
    {
        merged[i] = arr1[i];
    }

    for (int i = 0; i < n2; i++)
    {
        merged[n1 + i] = arr2[i];
    }

    printf("The merged array is:\n");
    for (int i = 0; i < n3; i++)
    {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
