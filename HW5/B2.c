#include <stdio.h>

int main() {
    int start_number, end_number;
    scanf("%d%d", &start_number, &end_number);
    
    for (int i = start_number; i <= end_number; i++) {
        printf("%d ", i*i);
    }
    
    return 0;
}