#include <stdio.h>

int main() {
    int num, count = 0;
    scanf("%d", &num);

    for(; num != 0; num /= 10) {
        count += num % 10 == 9 ? 1 : 0;
    }

    count == 1 ? printf("YES") : printf("NO");
    return 0;
}