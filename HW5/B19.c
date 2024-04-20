#include <stdio.h>

int main() {
    int num, sum = 0;
    scanf("%d", &num);

    for (; num != 0; num /= 10) {
        sum += num % 10;
    }

    sum == 10 ? printf("YES") : printf("NO");
    return 0;
}