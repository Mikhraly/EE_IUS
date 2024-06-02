#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    char str[21] = {0};
    fscanf(f_in, "%s", str);

    char temp[21] = {0};
    int index = 0;

    temp[index++] = str[0];
    for (int i = 1; i < strlen(str); i++) {
        switch (str[i]) {
        case 'b': case 'f': case 'p': case 'v':
            temp[index++] = '1';
            break;
        case 'c': case 'g': case 'j': case 'k':
        case 'q': case 's': case 'x': case 'z':
            temp[index++] = '2';
            break;
        case 'd': case 't':
            temp[index++] = '3';
            break;
        case 'l':
            temp[index++] = '4';
            break;
        case 'm': case 'n':
            temp[index++] = '5';
            break;
        case 'r':
            temp[index++] = '6';
            break;
        default:
            break;
        }
    }

    memset(str, 0, 21);
    index = 0;
    str[index++] = temp[0];
    for (int i = 1; i < strlen(temp); i++) {
        if (temp[i] != temp[i - 1]) {
            str[index++] = temp[i];
        }
    }

    for (int i = 0; i < 4; i++) {
        if (str[i] == 0) {
            str[i] = '0';
        }
    }

    memset(str + 4, 0, 21 - 4);
    fprintf(f_out, "%s", str);

    fclose(f_in);
    fclose(f_out);
    return 0;
}