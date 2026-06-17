#include <stdio.h>

int main()
{
    int n1, n2;

    printf("Enter size of first array: ");
    if (scanf("%d", &n1) != 1 || n1 <= 0)
        return 1;
    int arr1[n1];
    printf("Enter elements of first array: ");
    for (int i = 0; i < n1; i++)
    {
        if (scanf("%d", &arr1[i]) != 1)
            return 1;
    }

    printf("Enter size of second array: ");
    if (scanf("%d", &n2) != 1 || n2 <= 0)
        return 1;
    int arr2[n2];
    printf("Enter elements of second array: ");
    for (int i = 0; i < n2; i++)
    {
        if (scanf("%d", &arr2[i]) != 1)
            return 1;
    }

    printf("Common elements: ");
    int found = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                printf("%d ", arr1[i]);
                found = 1;
                break;
            }
        }
    }

    if (!found)
    {
        printf("None");
    }
    printf("\n");

    return 0;
}
