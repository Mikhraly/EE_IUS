#include <stdio.h>

int one_quantity_in_bin(int dec);

int main()
{
    int num;
    scanf("%d", &num);

    printf("%d", one_quantity_in_bin(num));
    return 0;
}

int one_quantity_in_bin(int dec) {
    if (dec == 0)
        return 0;

    return dec % 2 + one_quantity_in_bin(dec / 2);
}
