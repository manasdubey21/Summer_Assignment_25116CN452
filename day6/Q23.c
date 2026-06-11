#include <stdio.h>

int countSetBits(int c) {
    int count = 0;
    while (c > 0) {
        c &= (c - 1);
        count++;
    }
    return count;
}

int main() {
    int c;
    if (scanf("%d", &c) == 1) {
        printf("%d\n", countSetBits(c));
    }
    return 0;
}
