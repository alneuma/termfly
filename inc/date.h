#ifndef DATE_H
#define DATE_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct date_type *Date;
typedef uint8_t day_t;
typedef uint8_t month_t;
typedef int16_t year_t;

Date date_create(void);
// returns dynamically allocated Date struct and sets it's day, month and year to 0
// returns NULL if memory allocation failed

bool date_destroy(Date *date);
// false if date == NULL
// otherwise disallocates date's memory from date
// sets date to NULL
// and returns true

int date_validate(Date date);
// -2 if date == NULL
// -1 for impossible combination of
// day, month and year
// 0 if everything is fine

bool date_get_day(day_t *day, Date date);
// false if date == NULL
// otherwise true and as expected

bool date_get_month(month_t *month, Date date);
// false if date == NULL
// otherwise true and as expected

bool date_get_year(year_t *year, Date date);
// false if date == NULL
// otherwise true and as expected

bool date_set_day(day_t day, Date date);
// false if date == NULL
// otherwise true and as expected

bool date_set_month(month_t month, Date date);
// false if date == NULL
// otherwise true and as expected

bool date_set_year(year_t year, Date date);
// false if date == NULL
// otherwise true and as expected

size_t date_get_string_length(Date date);
// returns length of the null terminated string
// as would be written by date_get_string()
// when provided with date as argument
// returns 0 if date is not valid

size_t date_get_string_max_length(void);
// returns a fixed size a date string could maximally have
// assuming the year, does not take more than six digits.
// Use this instead of date_get_string_length for (slightly)
// improved performance or if variable length arrays are not
// supported (i.e. __STDC_NO_VLA__ is defined)

int date_get_string(char target_string[], Date date);
// If provided with correct arguments
// writes the date of the following format to target_string[]
// "<day> <month> <year> <AD|BC>"
//
// target_string[] should be of the length returned by
// date_get_string(date)
//
// -3 if target_string[] is too small
// -2 if date == NULL
// -1 for impossible combination of
// day, month and year
// 0 if everything is fine
//
// Only does the writing if return value is 0.

size_t date_get_size(Date date);
// returns memory size of the given date

#endif // DATE_H
