#include <stdio.h>

int main() {
    int num;

    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1 || num <= 1) {
        printf("Please enter an integer greater than 1.\n");
        return 1;
    }

    printf("Prime factors of %d are: ", num);

    while (num % 2 == 0) {
        printf("%d ", 2);
        num /= 2;
    }

    for (int i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            printf("%d ", i);
            num /= i;
        }
    }

    if (num > 2) {
        printf("%d", num);
    }
    
    printf("\n");
    return 0;
}
