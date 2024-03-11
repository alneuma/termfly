#ifndef DATE_H
#define DATE_H

#include <stdbool.h>
#include <stdint.h>

typedef struct date_type *Date;

bool date_init();
bool date_destroy(Date date);
bool date_get_day(uint8_t *day, Date date);
bool date_get_month(uint8_t *month, Date date);
bool date_get_year(int16_t *year, Date date);
char *date_get_string(Date date);

#define // DATE_H
