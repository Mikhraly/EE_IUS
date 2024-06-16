#include "temperature.h"

void t_print_arr(Dyn_array *t_arr) {
    for (int i = 0; i < t_arr->count; i++) {
        printf("%d.%d.%d %d:%d - %d\n",
            ((Temperature*)dyn_array_get(t_arr, i))->year,
            ((Temperature*)dyn_array_get(t_arr, i))->month,
            ((Temperature*)dyn_array_get(t_arr, i))->day,
            ((Temperature*)dyn_array_get(t_arr, i))->hour,
            ((Temperature*)dyn_array_get(t_arr, i))->minute,
            ((Temperature*)dyn_array_get(t_arr, i))->value
        );
    }
    printf("\n");
}

void t_print_year_statistic(Dyn_array *t_arr) {
    if (t_arr == NULL)
        return;

    int32_t min = ((Temperature*)dyn_array_get(t_arr, 0))->value;
    int32_t max = ((Temperature*)dyn_array_get(t_arr, 0))->value;
    int32_t average;

    int32_t summ = 0;
    for (int32_t temp, i = 0; i < t_arr->count; i++) {
        temp = ((Temperature*)dyn_array_get(t_arr, i))->value;
        summ += temp;

        if (temp < min)
            min = temp;

        if (temp > max)
            max = temp;
    }
    average = summ / t_arr->count;

    printf(
        "%d year statistic: min is %d, max is %d, average is %d\n\n",
        ((Temperature*)dyn_array_get(t_arr, 0))->year,
        min, max, average
    );
}

void t_print_month_statistic(Dyn_array *t_arr) {
    
}