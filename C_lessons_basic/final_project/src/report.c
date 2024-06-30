#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "temperature.h"
#include "dyn_array.h"

enum {FALSE, TRUE};
#define STR_LENGTH 25

int main(int argc, char *argv[])
{
    struct {
        _Bool help    :1;
        _Bool file    :1;
        _Bool month   :1;
        _Bool year    :1;
        _Bool list    :1;
        _Bool sort    :1;
        char *file_arg;
        char *month_arg;
        char *sort_arg;
    } options = {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL, NULL, NULL};

    for (int opt; (opt = getopt(argc, argv, "hf:m:yls:")) != -1;) {
        switch (opt) {
        case 'h':
            options.help = TRUE;
            break;
        case 'f':
            options.file = TRUE;
            options.file_arg = optarg;
            break;
        case 'm':
            options.month = TRUE;
            options.month_arg = optarg;
            break;
        case 'y':
            options.year = TRUE;
            break;
        case 'l':
            options.list = TRUE;
            break;
        case 's':
            options.sort = TRUE;
            options.sort_arg = optarg;
            break;
        default:
            break;
        }
    }

    if (argc == 1 || options.help) {
        printf("\nThe program reads data from a file and prints the "
            "temperature sensor statistics. Use these flags:\n");
        printf("-h -- Print detailed help\n");
        if (options.help)
            printf("\tExample: ./out/report -h\n");
        printf("-f -- The name of the input file\n");
        if (options.help)
            printf("\tExample: ./out/report -f temperature_small.csv\n");
        printf("-m -- Number of month. Use with '-f' flag\n");
        if (options.help)
            printf("\tExample: ./out/report -f temperature_small.csv -m [1..12]\n");
        printf("-y -- Year. Use with '-f' flag\n");
        if (options.help)
            printf("\tExample: ./out/report -f temperature_small.csv -y\n");
        printf("-l -- Print the list of data. Use with '-f' flag\n");
        if (options.help)
            printf("\tExample: ./out/report -f temperature_small.csv -l\n");
        printf("-s -- Sort data. Use with '-f' and '-l' (optional) flags \n");
        if (options.help) {
            printf("\tExample: ./out/report -f temperature_small.csv -s [month, values, min, max, average]\n");
            printf("\tExample: ./out/report -f temperature_small.csv -l -s [date, time, date+time, value]\n");
        }
        printf("\n");
        return 0;
    }

    if (options.file) {
        char *file_name = options.file_arg;
        FILE *file;

        if ((file = fopen(file_name, "r")) == NULL) {
            perror("Can not open file\n");
            return 1;
        }
        Dyn_array *temp_arr = dyn_array_create(sizeof(Temperature));

        char str[STR_LENGTH] = {0};
        for (uint32_t i = 0; fgets(str, STR_LENGTH, file); i++) {
            Temperature temp = {0};
            int num = sscanf(
                str, "%d;%d;%d;%d;%d;%d",
                &temp.year, &temp.month, &temp.day,
                &temp.hour, &temp.minute, &temp.value
            );

            if (num == 6) {
                if (temp.year > 0 &&
                    temp.month >= 1 && temp.month <= 12 &&
                    temp.day >= 1 && temp.day <= 31 &&
                    temp.hour >= 0 && temp.hour <= 23 &&
                    temp.minute >= 0 && temp.minute <= 59
                ) {
                    dyn_array_add(temp_arr, &temp);
                    continue;
                } else {
                    printf("Error! String %d: invalid date: %s\n", i + 1, str);
                }
            } else {
                printf("Error! String %d: invalid format: %s\n", i + 1, str);
            }

            memset(&temp, 0, sizeof(Temperature));
            dyn_array_add(temp_arr, &temp);
        }

        Statistic temp_stat[13] = {};
        create_statistic(temp_stat, temp_arr);

        if (options.list) {
            if (options.sort) {
                if (!strcmp(options.sort_arg, "date")) {
                    qsort(temp_arr->data, temp_arr->count,
                        sizeof(Temperature), sort_arr_date);
                } else if (!strcmp(options.sort_arg, "time")) {
                    qsort(temp_arr->data, temp_arr->count,
                        sizeof(Temperature), sort_arr_time);
                } else if (!strcmp(options.sort_arg, "date+time")) {
                    qsort(temp_arr->data, temp_arr->count,
                        sizeof(Temperature), sort_arr_date_time);
                } else if (!strcmp(options.sort_arg, "value")) {
                    qsort(temp_arr->data, temp_arr->count,
                        sizeof(Temperature), sort_arr_value);
                }
            }
            t_print_arr(temp_arr);
        } else if (options.month) {
            t_print_statistic(temp_stat, atoi(options.month_arg));
        } else if (options.year) {
            t_print_statistic(temp_stat, 0);
        } else {
            if (options.sort) {
                if (!strcmp(options.sort_arg, "month")) {
                    qsort(&temp_stat[1], 12, sizeof(Statistic), sort_stat_month);
                } else if (!strcmp(options.sort_arg, "values")) {
                    qsort(&temp_stat[1], 12, sizeof(Statistic), sort_stat_values);
                } else if (!strcmp(options.sort_arg, "min")) {
                    qsort(&temp_stat[1], 12, sizeof(Statistic), sort_stat_min);
                } else if (!strcmp(options.sort_arg, "max")) {
                    qsort(&temp_stat[1], 12, sizeof(Statistic), sort_stat_max);
                } else if (!strcmp(options.sort_arg, "average")) {
                    qsort(&temp_stat[1], 12, sizeof(Statistic), sort_stat_average);
                }
            }
            t_print_statistic(temp_stat, 13);
        }

        dyn_array_free(temp_arr);
        fclose(file);
    }

    return 0;
}