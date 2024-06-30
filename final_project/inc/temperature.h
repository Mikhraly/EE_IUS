#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <stdint.h>
#include <stdio.h>
#include "dyn_array.h"

typedef struct temperature {
    int32_t year;
    int32_t month;
    int32_t day;
    int32_t hour;
    int32_t minute;
    int32_t value;
} Temperature;

void t_print_arr(Dyn_array *t_arr);
void t_print_statistic(Dyn_array *t_arr, int32_t month);
void t_print_tittle();
void t_print_line();

int t_get_min(Dyn_array *t_arr, int month);
int t_get_max(Dyn_array *t_arr, int month);
int t_get_average(Dyn_array *t_arr, int month);
int t_get_count(Dyn_array *t_arr, int month);

int sort_arr_temp_up(const void *a, const void *b);
int sort_arr_temp_down(const void *a, const void *b);

#endif