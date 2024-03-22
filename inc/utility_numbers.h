#ifndef UTILITY_NUMBERS_H
#define UTILITY_NUMBERS_H

#include <stdint.h>
#include <stddef.h>

#define COUNT_DIGITS_INT(n) (((n) < 0) ? count_digits_int64((int64_t)(n)) : count_digits_uint64((uint64_t)(n)))

size_t count_digits_int64(int64_t n);
size_t count_digits_uint64(uint64_t n);

#endif //UTILITY_NUMBERS_H
