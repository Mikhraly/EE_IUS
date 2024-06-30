#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);
    
    switch (number/100) {
    case 1: case 2: case 3: case 4: case 5:
    case 6: case 7: case 8: case 9:
        printf("YES");
        break;
    default:
        printf("NO");
        break;
    }

    return 0;
}