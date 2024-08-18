#include <stdio.h>

int main() {
    unsigned char a, b, c;
    
    printf("A\tB\tC\t(!b||a)&&!(a||b)&&(!a||c))\t!a&&!b\n\n");
    
    for (unsigned char i = 0; i < 8; i++) {
        a = (i & 0b00000100) >> 2;
        b = (i & 0b00000010) >> 1;
        c = (i & 0b00000001) >> 0;
        
        printf("%d\t%d\t%d\t%d\t\t\t\t%d\n\n", a , b, c,
                (!b||a) && !(a||b) && (!a||c), !a&&!b);
    }
}
