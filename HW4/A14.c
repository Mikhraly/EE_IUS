#include <stdio.h>

int main () {
    int number;
    scanf("%d", &number);

    int d1 = number/100%10;
    int d2 = number/10%10;
    int d3 = number%10;

    int max = d1 > d2 ? d1 : d2;
    max = d3 > max ? d3 : max;

    printf("%d", max);
    return 0;
}
