#include <stdio.h>
#include <string.h>


int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    char str_in[2000] = {0};
    char str_out[2000] = {0};

    char c = fgetc(f_in);
    for (int i = 0; c != EOF; c = fgetc(f_in)) {
        str_in[i++] = c;
    }

    for(int i = 0, j = 0; i < strlen(str_in); i++, j++) {
        if (!memcmp(str_in + i, "Cao", 3)) {
            strcat(str_out, "Ling");
            j += 4;
            i += 3;
        }
        str_out[j] = str_in[i];
    }

    fprintf(f_out, "%s", str_out);

    fclose(f_in);
    fclose(f_out);
    return 0;
}