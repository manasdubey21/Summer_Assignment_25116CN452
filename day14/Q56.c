
int main()
{
    int n, i, j;

    printf("Enter the size of the array: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        return 1;
    }

    int arr[n];
    int visited[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        visited[i] = 0;
    }

    printf("Duplicate elements: ");
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 1)
        {
            continue;
        }

        int count = 1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                visited[j] = 1;
            }
        }

        if (count > 1)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}
