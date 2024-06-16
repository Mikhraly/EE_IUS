#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temperature.h"
#include "dyn_array.h"


int main(int argc, char *argv[])
{
    printf("%d\n%s\n", argc, argv[0]);

    Dyn_array *arr = dyn_array_create(sizeof(int));
    for (int i = 0; i < 10; i += 2) {
        dyn_array_add(arr, &i);
    }

    for (int i = 0; i < arr->count; i++) {
        printf("%d\n", *(int*)dyn_array_get(arr, i));
    }


    Temperature t1 = {2024, 6, 16, 1, 44, 28};
    Temperature t2 = {2024, 6, 16, 1, 45, 28};
    Temperature t3 = {2024, 6, 16, 1, 50, 27};

    Dyn_array *t_arr = dyn_array_create(sizeof(Temperature));
    dyn_array_add(t_arr, &t1);
    dyn_array_add(t_arr, &t2);
    dyn_array_add(t_arr, &t3);

    t_print_arr(t_arr);
    t_print_year_statistic(t_arr);

    dyn_array_free(arr);
    dyn_array_free(t_arr);
}