#include "utility_numbers.h"

size_t count_digits_int64(int64_t n) {
        size_t digits = 1;
        while (n < -9 || n > 9) {
                ++digits;
                n /= 10;
        }
        return digits;
}

size_t count_digits_uint64(uint64_t n) {
        size_t digits = 1;
        while (n > 9) {
                ++digits;
                n /= 10;
        }
        return digits;
}
