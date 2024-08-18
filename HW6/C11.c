#include <stdio.h>

int nod(int a, int b);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    printf("%d", nod(a, b));
    return 0;
}

int nod(int a, int b)
{
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    return a;
}