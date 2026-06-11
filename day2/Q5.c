#include <stdio.h>
#include <stdlib.h> 

int main() {
    int num, temp, remainder, sum = 0;
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }
    temp = abs(num);
    while (temp > 0) {
        remainder = temp % 10;  
        sum += remainder;       
        temp = temp / 10;       
    }
    printf("The sum of the digits of %d is: %d\n", num, sum);

    return 0;
}
