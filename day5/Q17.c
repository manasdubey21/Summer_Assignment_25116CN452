#include <stdio.h>

int main() {
    int num, sum = 0, i;

    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
        return 1;
    }

    if (num <= 0) {
        printf("%d is not a perfect number.\n", num);
        return 0;
    }

    for (i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    if (sum == num) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;
}
