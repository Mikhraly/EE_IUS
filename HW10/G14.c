#include <stdio.h>
#include <string.h>


int main()
{
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    char last_name[101] = {0};
    char first_name[101] = {0};
    char middle_name[101] = {0};

    fscanf(f_in, "%s", last_name);
    fscanf(f_in, "%s", first_name);
    fscanf(f_in, "%s", middle_name);
    
    fprintf(f_out, "Hello, %s %s!", first_name, last_name);

    fclose(f_in);
    fclose(f_out);
    return 0;
}