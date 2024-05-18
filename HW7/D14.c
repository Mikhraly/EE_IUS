#include <stdio.h>

void scan_odd_nums();

int main()
{
    scan_odd_nums();
    return 0;
}

void scan_odd_nums()
{
    int num;
    scanf("%d", &num);

    if (num == 0)
        return;
    
    if (num % 2 != 0)
        printf("%d ", num);

    scan_odd_nums();
}