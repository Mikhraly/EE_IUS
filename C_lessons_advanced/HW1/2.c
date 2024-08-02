#include <stdio.h>

int main(int argc, char *argv)
{
    int n;
    scanf("%d", &n);

    char c;
    for (scanf("%c", &c); c == ' '; scanf("%c", &c)) {}

    for (; c != '.'; scanf("%c", &c)) {
        if (c == ' ') {
            printf(" ");
        } else if (c >= 'a' && c <= 'z') {
            printf("%c", ((c - 'a' + n) % ('z' - 'a' + 1)) + 'a');
        } else if (c >= 'A' && c <= 'Z') {
            printf("%c", ((c  - 'A' + n) % ('Z' - 'A' + 1)) + 'A');
        }
    }
    printf(".");

    return 0;
}