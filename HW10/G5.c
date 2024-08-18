#include <stdio.h>
#include <string.h>


int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    char str[1002] = {0};

    for (char c = getc(f_in); c != EOF; c = getc(f_in)) {
        switch (c) {
        case 'a':
            fprintf(f_out, "%c", 'b');
            break;
        case 'b':
            fprintf(f_out, "%c", 'a');
            break;
        case 'A':
            fprintf(f_out, "%c", 'B');
            break;
        case 'B':
            fprintf(f_out, "%c", 'A');
            break;
        default:
            fprintf(f_out, "%c", c);
            break;
        }
    }

    fclose(f_in);
    fclose(f_out);
    return 0;
}