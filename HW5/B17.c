#include <stdio.h>

int main() {
    int number, sum = 0, prod = 1;
    scanf("%d", &number);
    
    for (int i = 10; i <= number; i++) {
        for (int j = i; j != 0; j /= 10) {
            int digit = j % 10;
            sum += digit;
            prod *= digit;
        }

        if (sum == prod) {
            printf("%d ", i);
        }

        sum = 0;
        prod = 1;
    }

    return 0;
}