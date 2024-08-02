#include <stdio.h>

int main(int argc, char *argv)
{
    int n;
    scanf("%d", &n);

    if (n < 1)
        return 1;

    int max;
    int count = 1;
    scanf("%d", &max);

    for (int i = 1; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (num > max) {
            max = num;
            count = 1;
        } else if (num == max) {
            count++;
        }

    }

    printf("%d", count);
    return 0;
}