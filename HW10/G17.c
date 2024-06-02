#include <stdio.h>
#include <string.h>

void swap(char* a, char* b);


int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    char str[1001] = {0};

    char c = fgetc(f_in);
    for (int i = 0; c != EOF; c = fgetc(f_in)) {
        str[i++] = c;
    }

    int index_1 = -1, index_2 = -1;
    for (int i = 0; i < strlen(str); i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z')) {

            if (index_1 == -1) {
                index_1 = i;
            } else if (index_2 == -1) {
                index_2 = i;
                swap(str + index_1, str + index_2);
                index_1 = index_2 = -1;
            }
        }
    }

    fprintf(f_out, "%s", str);

    fclose(f_in);
    fclose(f_out);
    return 0;
}


void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}