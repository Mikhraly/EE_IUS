#include <stdio.h>

int main(int argc, char *argv)
{
    unsigned int max = 1000000;
    unsigned int mass;
    scanf("%u", &mass);

    if (mass > 1000000)
        return -1;

    // формирую массив доступных гирь
    unsigned int size = 0;
    for (int i = 1; i <= max; i *= 3) {
        size++;
    }
    unsigned int arr[size];
    for (int j = 0, i = 1; i <= max; i *= 3) {
        arr[j++] = i;
    }



    // for (int i = ) {
        
    // }




    for (int i = 0; i < size; i++) {
        printf("%u ", arr[i]); 
    }

    printf("%u", sizeof(arr)/sizeof(arr[0])); 
    return 0;
}