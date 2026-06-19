#include <stdio.h>
#include <stdlib.h>

void sortDescending(int *arr, int n) {
    int i;
    int j;
    int temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (*(arr + i) < *(arr + j)) {
                temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

int main() {
    int n;
    int i;
    int *arr;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", arr + i) != 1) {
            free(arr);
            return 1;
        }
    }

    sortDescending(arr, n);

    printf("Array in descending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    free(arr);
    return 0;
}
