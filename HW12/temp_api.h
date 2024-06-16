#include <stdio.h>
#include <stdint.h>

typedef struct _temperature_sensor {
    uint32_t year;
    uint32_t month;
    uint32_t day;
    uint32_t hour;
    uint32_t minute;
    int32_t temperature;
} temperature_sensor;

void print_average_temp(int year, int month);
void print_minimum_temp(int year, int month);
void print_maximum_temp(int year, int month);
void print_statistic(int year);
