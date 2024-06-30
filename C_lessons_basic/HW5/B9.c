#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    for(; num != 0; num /= 10) {
        if (num % 10 % 2 != 0) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0;
}