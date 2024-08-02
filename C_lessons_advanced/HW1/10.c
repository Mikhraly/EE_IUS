#include <stdio.h>
#include <stdint.h>

struct pack_array {
    uint32_t array;         // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8;    // счетчик нулей в array
    uint32_t count1 : 8;    // счетчик единиц в array
};

void array2struct(int arr[], struct pack_array *pack);

int main(int argc, char *argv)
{
    int arr[32];
    for (int i = 0; i < 32; i++) {
        scanf("%d", arr + i);
    }

    struct pack_array pack;
    array2struct(arr, &pack);

    printf("%x\n%d\n%d\n", pack.array, pack.count0, pack.count1);
    return 0;
}


void array2struct(int arr[], struct pack_array *pack) {
    pack->array = 0;
    pack->count0 = 0;
    pack->count1 = 0;

    for (int i = 0; i < 32; i++) {
        pack->array = pack->array << 1 | arr[i];
        arr[i] ? pack->count1++ : pack->count0++;
    }
}