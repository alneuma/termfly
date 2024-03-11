#include "date.h"
#include <stdio.h>
#include <stdlib.h>

// 3 for day+' '
// 10 for mont+' ' (September is the longest with 9 characters)
// 5 for year+' '
// 3 for AD/BC+'\0'
#define DATE_STRING_LENGTH (3 + 10 + 5 + 3) 

struct date_type {
        uint8_t day;
        uint8_t month;
        int16_t year;
};

// implementation missing
bool date_init() {
        return true;
}

// implementation missing
bool date_destroy(Date date) {
        return true;
}

// implementation missing
bool date_validate(Date date) {
        return true;
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

        static char **months = { "January",
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

        sprintf_s(date_string, DATE_STRING_LENGTH, "%d %s %d %s",
                        date_get_day(date),
                        months[date_get_month(date)],
                        abs(date_get_year(date)),
                        (date_get_year(date) < 0) ? "BC" : "AD");

        return date_string;
}

