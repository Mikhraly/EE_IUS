#include <stdio.h>
#include <string.h>

void make_palindrome(char str_in[], char str_out[]);
int char_quantity(char arr[], int size, char c);


int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    char str_in[1001] = {0};
    char str_out[1001] = {0};

    char c = fgetc(f_in);
    for (int i = 0; c != EOF; c = fgetc(f_in)) {
        str_in[i++] = c;
    }

    make_palindrome(str_in, str_out);
    fprintf(f_out, "%s", str_out);   

    fclose(f_in);
    fclose(f_out);
    return 0;
}


void make_palindrome(char str_in[], char str_out[])
{
    int index = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = 0; i < char_quantity(str_in, 1001, c) / 2; i++) {
            str_out[index++] = c;
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        if (char_quantity(str_in, 1001, c) % 2) {
            str_out[index++] = c;
            break;
        }
    }
    for (char c = 'z'; c >= 'a'; c--) {
        for (int i = 0; i < char_quantity(str_in, 1001, c) / 2; i++) {
            str_out[index++] = c;
        }
    }
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