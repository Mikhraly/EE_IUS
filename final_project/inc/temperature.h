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

void t_print_tittle();
void t_print_line();
void t_print_all_statistic(Dyn_array *t_arr);
void t_print_arr(Dyn_array *t_arr);
void t_print_year_statistic(Dyn_array *t_arr);
void t_print_month_statistic(Dyn_array *t_arr, int32_t month);

#endif