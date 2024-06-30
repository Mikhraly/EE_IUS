#include <stdio.h>
#include <string.h>


int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    int count_a = 0;
    int count_A = 0;
    for (char c = fgetc(f_in); c != EOF; c = fgetc(f_in)) {
        if (c >= 'a' && c <= 'z')
            count_a++;
        if (c >= 'A' && c <= 'Z')
            count_A++;
    }
    fprintf(f_out, "%d %d", count_a, count_A);

    fclose(f_in);
    fclose(f_out);
    return 0;
}