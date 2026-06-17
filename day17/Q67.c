#include <stdio.h>

int main()
{
    int n1, n2, i, j, k;
    int arr1[100], arr2[100], inter[100];
    int size = 0;

    printf("Enter number of elements for first array: ");
    scanf("%d", &n1);
    printf("Enter elements for first array:\n");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter number of elements for second array: ");
    scanf("%d", &n2);
    printf("Enter elements for second array:\n");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                int isDuplicate = 0;
                for (k = 0; k < size; k++)
                {
                    if (inter[k] == arr1[i])
                    {
                        isDuplicate = 1;
                        break;
                    }
                }
                if (!isDuplicate)
                {
                    inter[size] = arr1[i];
                    size++;
                }
                break;
            }
        }
    }

    printf("Intersection of the two arrays:\n");
    if (size == 0)
    {
        printf("No common elements found.\n");
    }
    else
    {
        for (i = 0; i < size; i++)
        {
            printf("%d ", inter[i]);
        }
        printf("\n");
    }

    return 0;
}
