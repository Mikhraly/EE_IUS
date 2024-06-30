#include <stdio.h>
#include <string.h>

int char_quantity(char *arr, int size, char c);


int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    char str1[102] = {0};
    char str2[102] = {0};

    fscanf(f_in, "%s", str1);
    fscanf(f_in, "%s", str2);

    for (char c = 'a'; c <= 'z'; c++) {
        int count1 = char_quantity(str1, sizeof(str1)/sizeof(str1[0]), c);
        int count2 = char_quantity(str2, sizeof(str2)/sizeof(str2[0]), c);

        if (count1 == 1 && count2 == 1) {
            fprintf(f_out, "%c ", c);
        }
    }

    fclose(f_in);
    fclose(f_out);
    return 0;
}


int char_quantity(char arr[], int size, char c)
{
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == c) {
            count++;
        }
    }
    return count;
}