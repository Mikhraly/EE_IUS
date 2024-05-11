#include <stdio.h>

int main()
{
    int res = 0;
    char c = getchar();
    if (c != '(' || c == '.') {
        printf("NO");
        return 0;
    } else {
        res++;
    }

    for (; (c = getchar()) != '.';) {
        if (c == '(') {
            res++;
        } else {
            res--;
        }
    }

    res == 0 ? printf("YES") : printf("NO");
    return 0;
}