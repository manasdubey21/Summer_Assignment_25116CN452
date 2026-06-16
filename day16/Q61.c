#include <stdio.h>

int main()
{
    int n;

    printf("Enter the value of N (total numbers in sequence): ");
    if (scanf("%d", &n) != 1 || n <= 1)
    {
        printf("Invalid sequence size.\n");
        return 1;
    }

    int arr[n - 1];
    int current_sum = 0;

    printf("Enter %d elements: ", n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &arr[i]);
        current_sum += arr[i];
    }

    int total_sum = (n * (n + 1)) / 2;
    int missing_number = total_sum - current_sum;

    printf("The missing number is: %d\n", missing_number);

    return 0;
}
