#include <stdio.h>

int main() {
    long long num;
    int count = 0;

    // Prompt user for input
    printf("Enter an integer: ");
    if (scanf("%lld", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    long long temp = num; 
    do {
        count++;
        temp /= 10; 
    } while (temp != 0);

    printf("The number of digits in %lld is: %d\n", num, count);

    return 0;
}