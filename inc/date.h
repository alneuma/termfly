#ifndef DATE_H
#define DATE_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct date_type *Date;
typedef uint8_t day_t;
typedef uint8_t month_t;
typedef int16_t year_t;

// returns dynamically allocated Date struct and sets it's day, month and year to 0
// returns NULL if memory allocation failed
Date date_create(void);

// false if date == NULL
// otherwise disallocates date's memory from date
// sets date to NULL
// and returns true
bool date_destroy(Date *date);

// 0 if everything is fine
// -1 if date == NULL
// -2 for impossible combination of
// day, month and year
int date_validate(Date date);

// false if date == NULL
// otherwise true and as expected
bool date_get_day(day_t *day, Date date);
bool date_get_month(month_t *month, Date date);
bool date_get_year(year_t *year, Date date);

// false if date == NULL
// otherwise true and as expected
bool date_set_day(day_t day, Date date);
bool date_set_month(month_t month, Date date);
bool date_set_year(year_t year, Date date);

char *date_get_string(Date date);

// returns memory size of the given date
size_t date_get_size(Date date);

#endif // DATE_H
