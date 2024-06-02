#include <stdio.h>
#include <string.h>

int is_palindrom(char str[]);
int char_quantity(char str[], char c);


int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    f_in = fopen(name_in, "r");

    char str[1001] = {0};
    char c = fgetc(f_in);
    for (int i = 0; c != EOF; c = fgetc(f_in)) {
        str[i++] = c;
    }

    if (is_palindrom(str))
        printf("%s", "YES");
    else
        printf("%s", "NO");

    fclose(f_in);
    return 0;
}


int is_palindrom(char str[])
{
    int odd_count = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        odd_count += char_quantity(str, c) % 2;
    }

    return odd_count <= 1 ? 1 : 0;
}

int char_quantity(char str[], char c)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}