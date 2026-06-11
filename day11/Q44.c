#include <stdio.h>

long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Error: Factorial of a negative number does not exist.\n");
    } else {
        printf("Factorial of %d = %lld\n", num, factorial(num));
    }
    
    return 0;
}
