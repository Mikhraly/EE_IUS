#include <stdio.h>

int main () {
    int number;
    scanf("%d", &number);

    int max = number/100%10 > number/10%10 ? number/100%10 : number/10%10;
    max = number%10 > max ? number%10 : max;

    printf("%d", max);
    return 0;
}
