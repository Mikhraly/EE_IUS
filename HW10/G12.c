#include <stdio.h>
#include <string.h>


int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    int first_word = 1;
    for (char c = fgetc(f_in), c_prev = ' '; c != EOF; c = fgetc(f_in)) {
        if (c == ' ' && c_prev != ' ') {
            fprintf(f_out, "\n");
        } else if (c != ' ') {
            fprintf(f_out, "%c", c);
        }
        c_prev = c;
    }

    fclose(f_in);
    fclose(f_out);
    return 0;
}