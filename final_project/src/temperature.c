#include "temperature.h"

void t_print_arr(Dyn_array *t_arr) {
    printf("#\tdate\t\ttime\tvalue\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < t_arr->count; i++) {
        printf("%d\t%.4d.%.2d.%.2d\t%.2d:%.2d\t%.2d\n",
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
void t_print_statistic(Statistic temp_stat[], int32_t month) {
    t_print_tittle();

    if (month > 0) {
        t_print_line();
        for (int32_t m = 1; m <= 12; m++) {
            if (month <= 12 && month != m)
                continue;

            if (temp_stat[m].values > 0) {
                printf(
                    "%4d\t%3d\t%3d\t%3d\t%3d\t%3d\n",
                    temp_stat[m].year,
                    temp_stat[m].month,
                    temp_stat[m].values,
                    temp_stat[m].min,
                    temp_stat[m].max,
                    temp_stat[m].average
                );
            }
        }
    }

    if (month == 0 || month > 12) {
        if (temp_stat[0].values > 0) {
            t_print_line();
            printf(
                "%4d\t%s\t%3d\t%3d\t%3d\t%3d\n",
                temp_stat[0].year,
                "all",
                temp_stat[0].values,
                temp_stat[0].min,
                temp_stat[0].max,
                temp_stat[0].average
            );
        }
    }
    printf("\n");
}

void t_print_tittle() {
    printf("\nyear\tmonth\tvalues\tmin\tmax\taverage\n");
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

int sort_arr_date(const void *a, const void *b) {
    return
        (((Temperature*)a)->year * 10000 +
        ((Temperature*)a)->month * 100 +
        ((Temperature*)a)->day) - 
        (((Temperature*)b)->year * 10000 +
        ((Temperature*)b)->month * 100 +
        ((Temperature*)b)->day);
}

int sort_arr_time(const void *a, const void *b) {
    return
        (((Temperature*)a)->hour * 100 +
        ((Temperature*)a)->minute) - 
        (((Temperature*)b)->hour * 100 +
        ((Temperature*)b)->minute);
}

int sort_arr_date_time(const void *a, const void *b) {
    return
        (((Temperature*)a)->year * 100000000 +
        ((Temperature*)a)->month * 1000000 +
        ((Temperature*)a)->day * 10000 +
        ((Temperature*)a)->hour * 100 +
        ((Temperature*)a)->minute) - 
        (((Temperature*)b)->year * 100000000 +
        ((Temperature*)b)->month * 1000000 +
        ((Temperature*)b)->day * 10000 +
        ((Temperature*)b)->hour * 100 +
        ((Temperature*)b)->minute);
}

int sort_arr_value(const void *a, const void *b) {
    return ((Temperature*)a)->value - ((Temperature*)b)->value;
}


void create_statistic(Statistic temp_stat[], Dyn_array *temp_arr) {
    if (temp_arr == NULL)
        return;

    for (int32_t i = 0; i < 13; i++) {
        temp_stat[i].year = ((Temperature*)(temp_arr->data))[0].year;
        temp_stat[i].month = i;
        temp_stat[i].values = t_get_count(temp_arr, i);
        temp_stat[i].min = t_get_min(temp_arr, i);
        temp_stat[i].max = t_get_max(temp_arr, i);
        temp_stat[i].average = t_get_average(temp_arr, i);
    }
}

int sort_stat_month(const void *a, const void *b) {
    return ((Statistic*)a)->month - ((Statistic*)b)->month;
}

int sort_stat_values(const void *a, const void *b) {
    return ((Statistic*)a)->values - ((Statistic*)b)->values;
}

int sort_stat_min(const void *a, const void *b) {
    return ((Statistic*)a)->min - ((Statistic*)b)->min;
}

int sort_stat_max(const void *a, const void *b) {
    return ((Statistic*)a)->max - ((Statistic*)b)->max;
}

int sort_stat_average(const void *a, const void *b) {
    return ((Statistic*)a)->average - ((Statistic*)b)->average;
}