#include <stdio.h>

int main() {
    int start_number, end_number, sum = 0;
    scanf("%d%d", &start_number, &end_number);
    
    for (int i = start_number; i <= end_number; i++) {
        sum += i*i;
    }

    printf("%d", sum);
    return 0;
}