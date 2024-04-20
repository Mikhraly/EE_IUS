#include <stdio.h>

int main() {
    int number, flag = 0;
    scanf("%d", &number);

    int nums = number % 10;
    number /= 10;

    for(; number != 0; number /= 10) {
        int digit = number % 10;
        
        for(int i = nums; i != 0; i /= 10) {
            flag += i % 10 == digit ? 1 : 0;
        }

        nums = nums * 10 + digit;
    }

    flag > 0 ? printf("YES") : printf("NO");
    return 0;
}