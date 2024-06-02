#include <stdio.h>
#include <string.h>

int do_contain(char* str, char c);


int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    char str[1001] = {0};
    int str_i = 0;

    for (char c = fgetc(f_in), prev_c = 0; c != EOF; c = fgetc(f_in)) {
        if (c == ' ')
            continue;

        if (do_contain(str, c))
            continue;

        str[str_i++] = c;
        prev_c = c;
    }

    fprintf(f_out, "%s", str);

    fclose(f_in);
    fclose(f_out);
    return 0;
}


int do_contain(char* str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return 1;
        }
    }
    return 0;
}