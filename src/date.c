#include "date.h"
#include <stdio.h>
#include <stdlib.h>

// 3 for day+' '
// 10 for mont+' ' (September is the longest with 9 characters)
// 5 for year+' '
// 3 for AD/BC+'\0'
#define DATE_STRING_LENGTH (3 + 10 + 5 + 3) 

static day_t days_in_month(month_t month, year_t year);
static int is_leap_year(year_t year);

struct date_type {
        day_t day;
        month_t month;
        year_t year;
};

Date date_create(void) {
        Date date = malloc(sizeof(*date));
        if (date != NULL) {
                date->day = 0;
                date->month = 0;
                date->year = 0;
        }
        return date;
}

bool date_destroy(Date *date) {
        if (*date == NULL)
                return false;
        free(*date);
        *date = NULL;
        return true;
}

int date_validate(Date date) {
        if (date == NULL)
                return -1;
        if (date->month < 1 || date->month > 12)
                return -2;
        if (date->day > days_in_month(date->month, date->year))
                return -2;
        return 0;
}

static day_t days_in_month(month_t month, year_t year) {
        if (month == 1 ||
                month == 3 ||
                month == 5 ||
                month == 7 ||
                month == 8 ||
                month == 10 ||
                month == 12) {
                return 31;
        } else if (month == 2) {
                return 28 + (day_t)is_leap_year(year);
        } else if (month == 4 ||
                month == 6 ||
                month == 9 ||
                month == 11) {
                return 30;
        } else {
                return -1;
        }
}

static int is_leap_year(year_t year) {
        if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
                return 0;
        else
                return 1;
}

bool date_get_day(day_t *day, Date date) {
        if (date == NULL)
                return false;
        *day = date->day;
        return true;
}

bool date_get_month(month_t *month, Date date) {
        if (date == NULL)
                return false;
        *month = date->month;
        return true;
}

bool date_get_year(year_t *year, Date date) {
        if (date == NULL)
                return false;
        *year = date->year;
        return true;
}

bool date_set_day(day_t day, Date date) {
        if (!date)
                return false;
        date->day = day;
        return true;
}

bool date_set_month(month_t month, Date date) {
        if (!date)
                return false;
        date->month = month;
        return true;
}

bool date_set_year(year_t year, Date date) {
        if (!date)
                return false;
        date->year = year;
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

// returns memory size of the given date
size_t date_get_size(Date date) {
        return sizeof(*date);
}
