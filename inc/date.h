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
// false if date or *date is NULL
// otherwise disallocates date's memory from date
// sets date to NULL
// and returns true

bool date_copy(Date target, const Date source);
// Copies all date data from source to target
// overwriting everything, that has been there.
// Retruns true on success, otherwise false.

int date_validate(const Date date);
// -2 if date == NULL
// -1 for impossible combination of
// day, month and year
// 0 if everything is fine

int date_compare(const Date date_1, const Date date_2);
// -1 if date_1 is before date_2
// 0 if both dates are equal or either argument is NULL
// 1 if date_1 is after date_2

bool date_get_day(day_t *day, const Date date);
// false if date == NULL
// otherwise true and as expected

bool date_get_month(month_t *month, const Date date);
// false if date == NULL
// otherwise true and as expected

bool date_get_year(year_t *year, const Date date);
// false if date == NULL
// otherwise true and as expected

bool date_set_day(const day_t day, Date date);
// false if date == NULL
// otherwise true and as expected

bool date_set_month(const month_t month, Date date);
// false if date == NULL
// otherwise true and as expected

bool date_set_year(const year_t year, Date date);
// false if date == NULL
// otherwise true and as expected

int32_t date_get_delta_day(const Date first, const Date second);
// Returns the number of full days between first and second.
// Can be negative if first is later than second.

int32_t date_get_delta_month(const Date first, const Date second);
// Returns the number of full months between first and second.
// Can be negative if first is later than second.

year_t date_get_delta_year(const Date first, const Date second);
// Returns the number of full years between first and second.
// Can be negative if first is later than second.

size_t date_get_string_length(const Date date);
// returns length of the null terminated string
// as would be written by date_get_string()
// when provided with date as argument
// returns 0 if date is not valid

size_t date_get_string_max_length(void);
// returns the fixed size a date string could maximally have
// assuming the year, does not take more than six digits.
// Use this instead of date_get_string_length if variable
// length arrays are not supported (i.e. __STDC_NO_VLA__ is defined).

int date_get_string(char target_string[], const size_t target_string_length, const Date date);
// If provided with correct arguments a null
// terminated string showing the date in the format:
// "<day> <month> <year> <AD|BC>"
//
// Writes a maximum of target_string_length
// cahracters to target_string[].
// -3 if target_string_length is too small
// -2 if date == NULL
// -1 for impossible combination of
// day, month and year
// 0 if everything is fine
//
// Only does the writing if return value is -3 or 0.
//
// The correct value for target_string_length should be
// determined by calling date_get_string_length(date)
// if variable length arrays are supported
// (i.e. __STDC_NO_VLA__ is defined)
// Otherwise it should be determined by calling
// date_get_max_string_length()

size_t date_get_size(const Date date);
// returns memory size of the given date

#endif // DATE_H
