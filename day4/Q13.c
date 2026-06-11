#include <stdio.h>

int main() {
    int n = 0;
    int t1 = 0;
    int t2 = 1;
    int nextTerm;

    printf("Enter the number of terms: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0; 
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    return 0;
}
