#include <stdio.h>

int main()
{
    int n;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        return 1;
    }

    int arr[n];
    int even_count = 0;
    int odd_count = 0;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even_count++;
        }
        else
        {
            odd_count++;
        }
    }

    printf("Even elements: %d\n", even_count);
    printf("Odd elements: %d\n", odd_count);

    return 0;
}
