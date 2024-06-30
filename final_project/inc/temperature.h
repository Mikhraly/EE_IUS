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

typedef struct statistic {
    int32_t year;
    int32_t month;
    int32_t values;
    int32_t min;
    int32_t max;
    int32_t average;
} Statistic;

void t_print_arr(Dyn_array *t_arr);
void t_print_statistic(Statistic temp_stat[], int32_t month);
void t_print_tittle();
void t_print_line();

int t_get_min(Dyn_array *t_arr, int month);
int t_get_max(Dyn_array *t_arr, int month);
int t_get_average(Dyn_array *t_arr, int month);
int t_get_count(Dyn_array *t_arr, int month);

int sort_arr_day(const void *a, const void *b);
int sort_arr_month(const void *a, const void *b);
int sort_arr_year(const void *a, const void *b);
int sort_arr_minute(const void *a, const void *b);
int sort_arr_hour(const void *a, const void *b);
int sort_arr_value(const void *a, const void *b);

void create_statistic(Statistic temp_stat[], Dyn_array *temp_arr);
int sort_stat_month(const void *a, const void *b);
int sort_stat_values(const void *a, const void *b);
int sort_stat_min(const void *a, const void *b);
int sort_stat_max(const void *a, const void *b);
int sort_stat_average(const void *a, const void *b);

#endif