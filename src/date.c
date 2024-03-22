#include "date.h"
#include "utility_numbers.h"
#include <stdio.h>
#include <stdlib.h>

///////////////
//// types ////
///////////////

struct date_type {
        day_t day;
        month_t month;
        year_t year;
};

///////////////////////////
//// private functions ////
///////////////////////////

static day_t days_in_month(month_t month, year_t year);
static day_t is_leap_year(year_t year);
static size_t date_get_characters_in_month(month_t month);
static year_t max_digit_value_year_t(void);

static day_t days_in_month(month_t month, year_t year) {
// 0 if not a valid month
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
                return 0;
        }
}

static day_t is_leap_year(year_t year) {
// 1 if leap_year
// 0 otherwise
        if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
                return 0;
        else
                return 1;
}

static size_t date_get_characters_in_month(month_t month) {
// 0 if not a valid month
// length of month string otherwise (e.g. May -> 3)
        static size_t number_characters[12] = {7,8,5,5,3,4,4,6,9,7,8,8};
        if (1 <= month && month <= 12)
                return number_characters[month-1];
        else
                return 0;
}

static year_t max_digit_value_year_t(void) {
// returns the value of year_t, that contains most digits
// works for signed and unsigned types for year_t
// implemented to make code resistant to modification of year_t
        if ((year_t)(-1) > 0)
        // year_t is unsigned
                return -1;
        else {
        // year_t is signed
                year_t max_digit_value = 2;
                while (max_digit_value > 1)
                        max_digit_value <<= 1;
                return max_digit_value;
        }
}

//////////////////////////
//// public functions ////
//////////////////////////

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
                return -2;
        if (date->month < 1 || date->month > 12)
                return -1;
        if (date->day > days_in_month(date->month, date->year))
                return -1;
        return 0;
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

size_t date_get_string_length(Date date) {
        if (date_validate(date))
                return 0;
        size_t length = (date->day < 10) ? 2 : 3; // +1 for ' '
        length += date_get_characters_in_month(date->month) + 1; // +1 for ' '
        length += COUNT_DIGITS_INT(date->year) + 1; // +1 for ' '
        length += 3; // AD/BC + '\0' 
        return length;
}

size_t date_get_string_max_length(void) {
        size_t length = 3; // '30 '
        length += 10; // 'September '
        length += COUNT_DIGITS_INT(max_digit_value_year_t()) + 1; // largest year + ' '
        length += 3; // AD/BC + '\0'
        return length;
}       

int date_get_string(char target_string[], Date date) {
//        if (date_validate(date) != 0)
//                return NULL;
//
//        char *date_string = malloc(date_get_string_length() * sizeof(*date_string));
//        if (date_string == NULL)
//                return NULL;
//
//        static char *months[] = { "January",
//                                  "February",
//                                  "March",
//                                  "April",
//                                  "May",
//                                  "June",
//                                  "July",
//                                  "August",
//                                  "September",
//                                  "October",
//                                  "November",
//                                  "December" };
//
//        snprintf(date_string, DATE_STRING_LENGTH, "%d %s %d %s",
//                        date->day,
//                        months[date->month],
//                        abs(date->year),
//                        (date->year < 0) ? "BC" : "AD");
//
//        return date_string;
}


// returns size in memory size of the given date
size_t date_get_size(Date date) {
        return sizeof(*date);
}
