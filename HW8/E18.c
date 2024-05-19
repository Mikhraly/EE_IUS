#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int count[10] = {0};

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= 9; j++) {
            if (i % j == 0) {
                count[j]++;
            }
        }
    }

    for (int i = 2; i <= 9; i++) {
        printf("%d %d\n", i, count[i]);
    }

    return 0;
}