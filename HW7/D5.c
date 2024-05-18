#include <stdio.h>

void dec_to_bin(int dec);

int main()
{
    int num;
    scanf("%d", &num);
    
    dec_to_bin(num);
    return 0;
}

void dec_to_bin(int dec)
{
    if (dec > 1)
        dec_to_bin(dec / 2);
        
    printf("%d", dec % 2);
}