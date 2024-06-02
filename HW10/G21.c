#include <stdio.h>
#include <string.h>

int char_quantity(char str[], char c);


int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    char str[3000] = {0};
    char c = fgetc(f_in);
    for (int i = 0; c != EOF; c = fgetc(f_in)) {
        str[i++] = c;
    }

    int count_stone = char_quantity(str, '*');
    int is_count_stone_ok = 0;
    int i = 3, k = 3;
    for (; i <= strlen(str); i += k++) {
        if (count_stone == i) {
            is_count_stone_ok = 1;
            break;
        }
    }

    if (is_count_stone_ok) {
        for (int str = k - 2, count = 1; str >= 0; str--, count++) {
            for (int i = 0; i < str; i++) {
                fprintf(f_out, "%c", ' ');
            }
            for (int i = 0; i < count; i++) {
                fprintf(f_out, "%c ", '*');
            }
            fprintf(f_out, "%c", '\n');
        }
    } else {
        fprintf(f_out, "%s", "NO");
    }

    fclose(f_in);
    fclose(f_out);
    return 0;
}


int char_quantity(char str[], char c)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}