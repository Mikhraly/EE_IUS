#include <stdio.h>
#include <string.h>


int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    int count = 0;
    char c_prev = 0;
    for (char c = fgetc(f_in); c != EOF; c = fgetc(f_in)) {
        if ((c == ' ' || c == '\n') && c_prev == 'a')
            count++;
        c_prev = c;
    }
    if (c_prev == 'a')
        count++;

    fprintf(f_out, "%d", count);

    fclose(f_in);
    fclose(f_out);
    return 0;
}