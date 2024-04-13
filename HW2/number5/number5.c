#include <stdio.h>

int main() {
    printf("A\tB\tA^B\t(!A&&B)||(A&&!B)\n");
    printf("0\t0\t0\t0\n");
    printf("0\t1\t1\t1\n");
    printf("1\t0\t1\t1\n");
    printf("1\t1\t0\t0\n");
}
