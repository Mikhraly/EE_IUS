#include <stdio.h>
#include <string.h>

void sort_up(int* arr, int size);
void swap(int* a, int* b);


int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    int nums[1001] = {0};
    int nums_i = 0;
    int num = 0;

    for (char c = fgetc(f_in), prev_c = ' '; c != EOF; c = fgetc(f_in)) {
        if (c >= '0' && c <= '9') {
            if (prev_c >= '0' && prev_c <= '9') {
                num = num * 10 + (c - 48);
            } else {
                num = c - 48;
            }
        } else if (prev_c >= '0' && prev_c <= '9') {
            nums[nums_i++] = num;
            num = 0;
        }
        prev_c = c;
    }

    sort_up(nums, nums_i);
    for (int i = 0; i < nums_i; i++) {
        fprintf(f_out, "%d ", nums[i]);
    }

    fclose(f_in);
    fclose(f_out);
    return 0;
}


void sort_up(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}