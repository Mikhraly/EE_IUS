#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "temperature.h"
#include "dyn_array.h"

#define STR_LENGTH 25

int main(int argc, char *argv[])
{
    //todo обработка аргументов командной строки

    char *file_name = "temperature_small.csv";
    FILE *file;
    
    if ((file = fopen(file_name, "r")) == NULL) {
        perror("Can not open file\n");
        return 1;
    }
    Dyn_array *temp_arr = dyn_array_create(sizeof(Temperature));

    char str[STR_LENGTH] = {0};
    for (uint32_t i = 0; fgets(str, STR_LENGTH, file); i++) {
        Temperature temp = {0};
        int num = sscanf(
            str, "%d;%d;%d;%d;%d;%d",
            &temp.year, &temp.month, &temp.day,
            &temp.hour, &temp.minute, &temp.value
        );

        if (num == 6) {
            if (temp.year > 0 &&
                temp.month >= 1 && temp.month <= 12 &&
                temp.day >= 1 && temp.day <= 31 &&
                temp.hour >= 0 && temp.hour <= 23 &&
                temp.minute >= 0 && temp.minute <= 59
            ) {
                dyn_array_add(temp_arr, &temp);
                continue;
            } else {
                printf("Error! String %d: invalid date: %s\n", i + 1, str);
            }
        } else {
            printf("Error! String %d: invalid format: %s\n", i + 1, str);
        }

        memset(&temp, 0, sizeof(Temperature));
        dyn_array_add(temp_arr, &temp);
    }

    printf("\n\n");
    t_print_arr(temp_arr);
    t_print_all_statistic(temp_arr);

    dyn_array_free(temp_arr);
    fclose(file);
}