#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    char str[1002];
    int lenght = 0;

    char c;
    while ((c = getc(f_in)) != EOF && c != '\n') {
        str[lenght++] = c;
    }

    for (int i = 0; i < lenght - 1; i++) {
        if (str[i] == str[lenght - 1]) {
            fprintf(f_out, "%d ", i);
        }
    }

    fclose(f_in);
    fclose(f_out);
    return 0;
}