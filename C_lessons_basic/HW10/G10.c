#include <stdio.h>
#include <string.h>


int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    char str[1001] = {0};
    char str_long[1001] = {0};
    int str_len = 0;

    for (int i = 0; i < 1001; i++) {
        fscanf(f_in, "%s", str);
        if (strlen(str) > str_len) {
            for (int i = 0; i < strlen(str); i++) {
                str_long[i] = str[i];
                str_len = strlen(str);
            }
        }
        memset(str, 0, sizeof(char));
    }
    fprintf(f_out, "%s", str_long);

    fclose(f_in);
    fclose(f_out);
    return 0;
}