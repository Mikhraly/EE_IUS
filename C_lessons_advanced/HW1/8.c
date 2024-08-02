#include <stdio.h>

int main(int argc, char *argv)
{
    unsigned int n;
    scanf("%u", &n);

    unsigned int res = 0;
    for (unsigned int i = 0; i < n; i++) {
        unsigned int temp;
        scanf("%u", &temp);
        res ^= temp;
    }

    printf("%u", res); 
    return 0;
}