#include <stdio.h>
#include <string.h>

int main()
{
    int i, number;
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    fscanf(f_in, "%d", &number);
    char str[number + 1];
    char c = 'A';
    char c_num = '2';

    for (i = 0; i < number; ++i) {
        if (i % 2 == 0) {
            str[i] = c++;
        } else {
            str[i] = c_num;
            if (c_num == '8')
                c_num = '2';
            else
                c_num += 2;
        }
    }
    str[i] = '\0';

    fprintf(f_out, "%s", str);
    fclose(f_in);
    fclose(f_out);
    return 0;
}