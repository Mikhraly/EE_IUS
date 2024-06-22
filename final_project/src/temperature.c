#include "temperature.h"

void t_print_arr(Dyn_array *t_arr) {
    for (int i = 0; i < t_arr->count; i++) {
        printf("%d\t%.4d.%.2d.%.2d %.2d:%.2d %.2d\n",
            i + 1,
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

void t_print_statistic(Dyn_array *t_arr, int32_t month) {
    t_print_tittle();
    t_print_line();
    if (month == 0) {
        for (int i = 1; i <= 12; i++) {
            t_print_month_statistic(t_arr, i);
        }
        t_print_line();
        t_print_year_statistic(t_arr);
    } else {
        t_print_month_statistic(t_arr, month);
    }
}

void t_print_tittle() {
    printf("Year\tMonth\tValues\tMin\tMax\tAverage\n");
}

void t_print_line() {
    printf("-----------------------------------------------\n");
}

void t_print_year_statistic(Dyn_array *t_arr) {
    if (t_arr == NULL)
        return;

    int32_t min = INT32_MAX;
    int32_t max = INT32_MIN;
    int32_t average;

    int32_t summ = 0;
    int32_t count = 0;
    for (int32_t temp, i = 0; i < t_arr->count; i++) {
        if (((Temperature*)dyn_array_get(t_arr, i))->month == 0)
            continue;

        temp = ((Temperature*)dyn_array_get(t_arr, i))->value;

        if (temp < min)
            min = temp;

        if (temp > max)
            max = temp;

        summ += temp;
        count++;
    }

    if (count != 0) {
        average = summ / count;
        
        printf(
            "%4.d\t%s\t%3.d\t%3.d\t%3.d\t%3.d\n",
            ((Temperature*)dyn_array_get(t_arr, 0))->year,
            "all", count, min, max, average
        );
    }
}

void t_print_month_statistic(Dyn_array *t_arr, int32_t month) {
    if (t_arr == NULL)
        return;

    int32_t min = INT32_MAX;
    int32_t max = INT32_MIN;
    int32_t average;

    int32_t summ = 0;
    int32_t count = 0;
    for (int32_t temp, i = 0; i < t_arr->count; i++) {
        if (((Temperature*)dyn_array_get(t_arr, i))->month != month)
            continue;
        
        temp = ((Temperature*)dyn_array_get(t_arr, i))->value;

        if (temp < min)
            min = temp;

        if (temp > max)
            max = temp;
        
        summ += temp;
        count++;
    }

    if (count != 0) {
        average = summ / count;

        printf(
            "%4.d\t%3.d\t%3.d\t%3.d\t%3.d\t%3.d\n",
            ((Temperature*)dyn_array_get(t_arr, 0))->year,
            month, count, min, max, average
        );
    }
}