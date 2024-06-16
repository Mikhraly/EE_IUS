#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <stdint.h>
#include <stdio.h>
#include "dyn_array.h"

typedef struct temperature {
    uint32_t year;
    uint32_t month;
    uint32_t day;
    uint32_t hour;
    uint32_t minute;
    int32_t value;
} Temperature;

void t_print_arr(Dyn_array *t_arr);
void t_print_year_statistic(Dyn_array *t_arr);
void t_print_month_statistic(Dyn_array *t_arr);

#endif