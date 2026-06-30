#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int size)
{
    int i;
    if (size == 0)
    {
        printf("\nArray is empty.\n");
        return;
    }
    printf("\nArray elements: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insert(int arr[], int size, int capacity)
{
    int element, position, i;
    if (size >= capacity)
    {
        printf("\nError: Array Overflow. Cannot insert more elements.\n");
        return size;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position (0 to %d): ", size);
    scanf("%d", &position);
    if (position < 0 || position > size)
    {
        printf("Invalid position!\n");
        return size;
    }
    for (i = size; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    printf("Element inserted successfully.\n");
    return size + 1;
}

int deleteElement(int arr[], int size)
{
    int position, i;
    if (size == 0)
    {
        printf("\nError: Array Underflow. Nothing to delete.\n");
        return size;
    }
    printf("Enter the position to delete (0 to %d): ", size - 1);
    scanf("%d", &position);
    if (position < 0 || position >= size)
    {
        printf("Invalid position!\n");
        return size;
    }
    printf("Deleted element: %d\n", arr[position]);
    for (i = position; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

void search(int arr[], int size)
{
    int element, i, found = 0;
    if (size == 0)
    {
        printf("\nArray is empty. Search operation aborted.\n");
        return;
    }
    printf("Enter the element to search: ");
    scanf("%d", &element);
    for (i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("Element %d found at index %d.\n", element, i);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Element %d not found in the array.\n", element);
    }
}

int main()
{
    int arr[100];
    int capacity = 100;
    int size = 0;
    int choice;
    int i;

    printf("Enter initial number of elements: ");
    scanf("%d", &size);
    if (size > capacity || size < 0)
    {
        printf("Invalid initial size. Setting size to 0.\n");
        size = 0;
    }
    else if (size > 0)
    {
        printf("Enter %d elements:\n", size);
        for (i = 0; i < size; i++)
        {
            scanf("%d", &arr[i]);
        }
    }

    while (1)
    {
        printf("\n--- ARRAY OPERATIONS MENU ---");
        printf("\n1. Insert Element");
        printf("\n2. Delete Element");
        printf("\n3. Search Element");
        printf("\n4. Display Array");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            size = insert(arr, size, capacity);
            break;
        case 2:
            size = deleteElement(arr, size);
            break;
        case 3:
            search(arr, size);
            break;
        case 4:
            display(arr, size);
            break;
        case 5:
            printf("\nExiting program.\n");
            exit(0);
        default:
            printf("\nInvalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}
