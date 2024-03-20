#include "date.h"
#include <stdio.h>
#include <stdlib.h>

// 3 for day+' '
// 10 for mont+' ' (September is the longest with 9 characters)
// 5 for year+' '
// 3 for AD/BC+'\0'
#define DATE_STRING_LENGTH (3 + 10 + 5 + 3) 

static uint8_t days_in_month(uint8_t month, int16_t year);
static bool is_leap_year(int16_t year);

struct date_type {
        uint8_t day;
        uint8_t month;
        int16_t year;
};

// implementation missing
bool date_init(Date date) {
        date = malloc(sizeof(*date));
        if (date == NULL)
                return false;
        date->day = 0;
        date->month = 0;
        date->year = 0;
        return true;
}

// implementation missing
bool date_destroy(Date date) {
        free(date);
        return true;
}

// implementation missing
bool date_validate(Date date) {
        if (date->month < 1 || date->month > 12)
                return false;
        return true;
}

static uint8_t days_in_month(uint8_t month, int16_t year) {
        if (month == 1 ||
                month == 3 ||
                month == 5 ||
                month == 7 ||
                month == 8 ||
                month == 10 ||
                month == 12) {
                return 31;
        } else if (month == 2) {
                return 28 + is_leap_year(year);
        } else if (month == 4 ||
                month == 6 ||
                month == 9 ||
                month == 11) {
                return 30;
        } else {
                return -1;
        }
}

static bool is_leap_year(int16_t year) {
        return false;
}

bool date_get_day(uint8_t *day, Date date) {
        *day = date->day;
        return true;
}

bool date_get_month(uint8_t *month, Date date) {
        *month = date->month;
        return true;
}

bool date_get_year(int16_t *year, Date date) {
        *year = date->year;
        return true;
}

// Returns NULL if argument is not a valid
// date or if memory allocation failed.
// Otherwise returns a pointer to a null terminated
// string of the following format:
// "<day> <month> <year> <AD|BC>"
char *date_get_string(Date date) {
        if (!date_validate(date))
                return NULL;

        char *date_string = malloc(DATE_STRING_LENGTH * sizeof(*date_string));
        if (date_string == NULL)
                return NULL;

        static char *months[] = { "January",
                                  "February",
                                  "March",
                                  "April",
                                  "May",
                                  "June",
                                  "July",
                                  "August",
                                  "September",
                                  "October",
                                  "November",
                                  "December" };

        snprintf(date_string, DATE_STRING_LENGTH, "%d %s %d %s",
                        date->day,
                        months[date->month],
                        abs(date->year),
                        (date->year < 0) ? "BC" : "AD");

        return date_string;
}

size_t date_get_size(Date date) {
        return sizeof(*date);
}
