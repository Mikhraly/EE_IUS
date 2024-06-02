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

    char prev = ' ';
    for (int i = 0; i < strlen(str); prev = str[i++]) {
        if (str[i] == ' ' && prev == ' ')
            continue;
            
        fprintf(f_out, "%c", str[i]);   
    }

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