#include <stdio.h>

const int str_length = 256;

int main(void)
{
    char* input_fn = "input.txt";
    char* output_fn = "output.txt";
    char str[str_length];
    FILE* file;
    
    if ((file = fopen(input_fn, "r")) == NULL) {
        perror("Error occured while opening input file!");
        return 1;
    }

    char c;
    int count = 0;
    while (((c = getc(file)) != EOF) && (c != '\n')) {
        str[count++] = c;
    }
    str[count] = '\0';
    fclose(file);

    if ((file = fopen(output_fn, "w")) == NULL) {
        perror("Error occured while opening output file!");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        if (i)
            fprintf(file, ", ");
        fprintf(file, "%s", str);
    }
    fprintf(file, " %d", count);
    fclose(file);
    
    return 0;
}