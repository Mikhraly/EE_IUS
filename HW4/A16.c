#include <stdio.h>

int main () {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    printf(b > a && c > b ? "YES" : "NO"); 
    return 0;
}
