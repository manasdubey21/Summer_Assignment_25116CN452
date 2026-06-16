#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    bool visited[n];

    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        visited[i] = false;
    }

    int max_count = 0;
    int max_element = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == true)
        {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                visited[j] = true;
            }
        }

        if (count > max_count)
        {
            max_count = count;
            max_element = arr[i];
        }
    }

    printf("The most frequent element is %d with a frequency of %d\n", max_element, max_count);

    return 0;
}
