#include <stdio.h>
#include <string.h>

int is_palindrom(char str[]);
int get_index(char str[], char c);


int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    char str[1002] = {0};
    fscanf(f_in, "%s", str);

    if (is_palindrom(str)) {
        fprintf(f_out, "YES");
    } else {
        fprintf(f_out, "NO");
    }

    fclose(f_in);
    fclose(f_out);
    return 0;
}


int is_palindrom(char str[])
{
    int end_i = get_index(str, '\0') - 1;
    for (int i = 0; i < end_i; i++, end_i--) {
        if (str[i] != str[end_i]) {
            return 0;
        }
    }
    return 1;
}

int get_index(char str[], char c)
{
    int i = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return i;
        }
    }
    return str[i] == '\0' ? i : -1;
}