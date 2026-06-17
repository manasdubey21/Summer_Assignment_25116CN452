#include <stdio.h>

int main()
{
    int n1, n2;
    int arr1[100], arr2[100], unionArr[200];
    int k = 0;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    printf("Enter elements of first array:\n");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    printf("Enter elements of second array:\n");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    for (int i = 0; i < n1; i++)
    {
        int duplicate = 0;
        for (int j = 0; j < k; j++)
        {
            if (arr1[i] == unionArr[j])
            {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate)
        {
            unionArr[k] = arr1[i];
            k++;
        }
    }

    for (int i = 0; i < n2; i++)
    {
        int duplicate = 0;
        for (int j = 0; j < k; j++)
        {
            if (arr2[i] == unionArr[j])
            {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate)
        {
            unionArr[k] = arr2[i];
            k++;
        }
    }

    printf("Union of the arrays:\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}
