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
            // ((Temperature*)(temp_arr->data))[i].value
        );
    }
    printf("\n");
}

// 1..12 - for month; 0 - for year; >12 for all
void t_print_statistic(Dyn_array *t_arr, int32_t month) {
    if (t_arr == NULL)
        return;

    t_print_tittle();

    if (month > 0) {
        t_print_line();
        for (int32_t m = 1; m <= 12; m++) {
            if (month <= 12 && month != m)
                continue;

            if (t_get_count(t_arr, m)) {
                printf(
                    "%4d\t%3d\t%3d\t%3d\t%3d\t%3d\n",
                    ((Temperature*)dyn_array_get(t_arr, 0))->year,
                    m,
                    t_get_count(t_arr, m),
                    t_get_min(t_arr, m),
                    t_get_max(t_arr, m),
                    t_get_average(t_arr, m)
                );
            }
        }
    }

    if (month == 0 || month > 12) {
        if (t_get_count(t_arr, 0)) {
            t_print_line();
            printf(
                "%4d\t%s\t%3d\t%3d\t%3d\t%3d\n",
                ((Temperature*)dyn_array_get(t_arr, 0))->year,
                "all",
                t_get_count(t_arr, 0),
                t_get_min(t_arr, 0),
                t_get_max(t_arr, 0),
                t_get_average(t_arr, 0)
            );
        }
    }
    printf("\n");
}

void t_print_tittle() {
    printf("\nYear\tMonth\tValues\tMin\tMax\tAverage\n");
}

void t_print_line() {
    printf("-----------------------------------------------\n");
}

// 1..12 - for month; 0 - for year
int t_get_min(Dyn_array *t_arr, int month) {
    int32_t min = INT32_MAX;
    for (int32_t i = 0; i < t_arr->count; i++) {
        if (month && month != ((Temperature*)dyn_array_get(t_arr, i))->month)
            continue;
        
        if (((Temperature*)dyn_array_get(t_arr, i))->year) {
            int32_t temp = ((Temperature*)dyn_array_get(t_arr, i))->value;
            min = temp < min ? temp : min;
        }
    }
    return min;
}

// 1..12 - for month; 0 - for year
int t_get_max(Dyn_array *t_arr, int month) {
    int32_t max = INT32_MIN;
    for (int32_t i = 0; i < t_arr->count; i++) {
        if (month && month != ((Temperature*)dyn_array_get(t_arr, i))->month)
            continue;
        
        if (((Temperature*)dyn_array_get(t_arr, i))->year) {
            int32_t temp = ((Temperature*)dyn_array_get(t_arr, i))->value;
            max = temp > max ? temp : max;
        }
    }
    return max;
}

// 1..12 - for month; 0 - for year
int t_get_average(Dyn_array *t_arr, int month) {
    int32_t sum = 0;
    int32_t count = 0;
    for (int32_t i = 0; i < t_arr->count; i++) {
        if (month && month != ((Temperature*)dyn_array_get(t_arr, i))->month)
            continue;
        
        if (((Temperature*)dyn_array_get(t_arr, i))->year) {
            sum += ((Temperature*)dyn_array_get(t_arr, i))->value;
            count++;
        }
    }
    return count ? sum / count : INT32_MIN;
}

// 1..12 - for month; 0 - for year
int t_get_count(Dyn_array *t_arr, int month) {
    int32_t count = 0;
    for (int32_t i = 0; i < t_arr->count; i++) {
        if (month && month != ((Temperature*)dyn_array_get(t_arr, i))->month)
            continue;
        if (((Temperature*)dyn_array_get(t_arr, i))->year)
            count++;
    }
    return count;
}

int sort_arr_temp_up(const void *a, const void *b) {
    return ((Temperature*)a)->value - ((Temperature*)b)->value;
}

int sort_arr_temp_down(const void *a, const void *b) {
    return ((Temperature*)b)->value - ((Temperature*)a)->value;
}