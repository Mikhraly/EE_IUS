#include <stdio.h>

int main() {
    int number, flag = 0;
    scanf("%d", &number);
    
    int prev_number = number % 10;
    number /= 10;
    for(; number != 0; number /= 10) {
        int curr_number = number % 10;
        if (curr_number == prev_number)
            flag++;
        prev_number = curr_number;
    }

    flag > 0 ? printf("YES") : printf("NO");
    return 0;
}