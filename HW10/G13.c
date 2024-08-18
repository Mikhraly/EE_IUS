#include <stdio.h>
#include <string.h>

int get_index_revers(char str[], int size, char c);


int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    char path[1000] = {0};
    fscanf(f_in, "%s", path);

    int last_slash = get_index_revers(path, 1000, '/');
    for (int i = 0; i <= last_slash; i++) {
        fprintf(f_out, "%c", path[i]);
    }
    for (int i = last_slash + 1; path[i] != '.' && path[i] != '\0'; i++) {
        fprintf(f_out, "%c", path[i]);
    }
    fprintf(f_out, "%s", ".html");

    fclose(f_in);
    fclose(f_out);
    return 0;
}


int get_index_revers(char str[], int size, char c)
{
    int i = size - 1;
    for (; i >= 0; i--) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}