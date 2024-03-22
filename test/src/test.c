#include "unity.h"

//// comment or uncomment to test different headers ////
#define TEST_UTILITY_NUMBERS_H
//#define TEST_DATE_H
//#define TEST_PERSON_H


void setUp(void) {
}

void tearDown(void) {
}

//// utility_numbers.h ////
#ifdef TEST_UTILITY_NUMBERS_H
#include "utility_numbers.h"

// count_digits_int64()
void test_utility_numbers__count_digits_int64_01_int64_min(void) {
        TEST_ASSERT(19 == count_digits_int64(INT64_MIN));
}

void test_utility_numbers__count_digits_int64_02_int64_max(void) {
        TEST_ASSERT(19 == count_digits_int64(INT64_MAX));
}

void test_utility_numbers__count_digits_int64_03_zero(void) {
        TEST_ASSERT(1 == count_digits_int64(0));
}

void test_utility_numbers__count_digits_int64_04_negative_nine(void) {
        TEST_ASSERT(1 == count_digits_int64(-9));
}

void test_utility_numbers__count_digits_int64_05_nine(void) {
        TEST_ASSERT(1 == count_digits_int64(9));
}

void test_utility_numbers__count_digits_int64_06_negative_ten(void) {
        TEST_ASSERT(2 == count_digits_int64(-10));
}

void test_utility_numbers__count_digits_int64_07_ten(void) {
        TEST_ASSERT(2 == count_digits_int64(10));
}

// count_digits_uint64()
void test_utility_numbers__count_digits_uint64_01_int64_max(void) {
        TEST_ASSERT(20 == count_digits_uint64(UINT64_MAX));
}

void test_utility_numbers__count_digits_uint64_02_zero(void) {
        TEST_ASSERT(1 == count_digits_uint64(0));
}

void test_utility_numbers__count_digits_uint64_03_nine(void) {
        TEST_ASSERT(1 == count_digits_uint64(9));
}

void test_utility_numbers__count_digits_uint64_04_ten(void) {
        TEST_ASSERT(2 == count_digits_uint64(10));
}

// COUNT_DIGITS_INT()
void test_utility_numbers__count_digits_int_01_uint64_max(void) {
        TEST_ASSERT(20 == COUNT_DIGITS_INT(UINT64_MAX));
}

void test_utility_numbers__count_digits_int_02_int64_min(void) {
        TEST_ASSERT(19 == COUNT_DIGITS_INT(INT64_MIN));
}

void test_utility_numbers__count_digits_int_03_int64_max(void) {
        TEST_ASSERT(19 == COUNT_DIGITS_INT(INT64_MAX));
}

void test_utility_numbers__count_digits_int_04_zero(void) {
        TEST_ASSERT(1 == COUNT_DIGITS_INT(0));
}

void test_utility_numbers__count_digits_int_05_negative_nine(void) {
        TEST_ASSERT(1 == COUNT_DIGITS_INT(-9));
}

void test_utility_numbers__count_digits_int_06_nine(void) {
        TEST_ASSERT(1 == COUNT_DIGITS_INT(9));
}

void test_utility_numbers__count_digits_int_07_negative_ten(void) {
        TEST_ASSERT(2 == COUNT_DIGITS_INT(-10));
}

void test_utility_numbers__count_digits_int_08_ten(void) {
        TEST_ASSERT(2 == COUNT_DIGITS_INT(10));
}

#endif //TEST_UTILITY_NUMBERS_H

//// date.h ////
#ifdef TEST_DATE_H
#include "date.h"

// date_destroy()
void test_date__date_destroy_01_false_if_null(void) {
        Date d = NULL;
        TEST_ASSERT_FALSE(date_destroy(&d));
}

void test_date__date_destroy_02_true_if_not_null(void) {
        Date d = date_create();
        TEST_ASSERT_TRUE(date_destroy(&d));
}

void test_date__date_destroy_03_null_after_destroy(void) {
        Date d = date_create();
        date_destroy(&d);
        TEST_ASSERT_NULL(d);
}

// date_set_day() and date_get_day()
void test_date__date_set_day__date_get_day_01_can_not_set_unallocated_date(void) {
        Date d = NULL;
        TEST_ASSERT_FALSE(date_set_day(7, d));
}

void test_date__date_set_day__date_get_day_02_setting_yields_true(void) {
        Date d = date_create();
        TEST_ASSERT_TRUE(date_set_day(7, d));
        date_destroy(&d);
}

void test_date__date_set_day__date_get_day_03_gett_from_null_yields_false(void) {
        Date d = NULL;
        day_t day;
        TEST_ASSERT_FALSE(date_get_day(&day, d));
        date_destroy(&d);
}

void test_date__date_set_day__date_get_day_04_default_value_is_0(void) {
        Date d = date_create();
        day_t day;
        date_get_day(&day, d);
        TEST_ASSERT(day == 0);
        date_destroy(&d);
}

void test_date__date_set_day__date_get_day_05_gets_what_was_set(void) {
        Date d = date_create();
        date_set_day(7, d);
        day_t day;
        date_get_day(&day, d);
        TEST_ASSERT(day == 7);
        date_destroy(&d);
}

// date_set_month() and date_get_month()
void test_date__date_set_month__date_get_month_01_can_not_set_unallocated_date(void) {
        Date d = NULL;
        TEST_ASSERT_FALSE(date_set_month(7, d));
}

void test_date__date_set_month__date_get_month_02_setting_yields_true(void) {
        Date d = date_create();
        TEST_ASSERT_TRUE(date_set_month(7, d));
        date_destroy(&d);
}

void test_date__date_set_month__date_get_month_03_gett_from_null_yields_false(void) {
        Date d = NULL;
        month_t month;
        TEST_ASSERT_FALSE(date_get_month(&month, d));
        date_destroy(&d);
}

void test_date__date_set_month__date_get_month_04_default_value_is_0(void) {
        Date d = date_create();
        month_t month;
        date_get_month(&month, d);
        TEST_ASSERT(month == 0);
        date_destroy(&d);
}

void test_date__date_set_month__date_get_month_05_gets_what_was_set(void) {
        Date d = date_create();
        date_set_month(7, d);
        month_t month;
        date_get_month(&month, d);
        TEST_ASSERT(month == 7);
        date_destroy(&d);
}

// date_set_year() and date_get_year()
void test_date__date_set_year__date_get_year_01_can_not_set_unallocated_date(void) {
        Date d = NULL;
        TEST_ASSERT_FALSE(date_set_year(7, d));
}

void test_date__date_set_year__date_get_year_02_setting_yields_true(void) {
        Date d = date_create();
        TEST_ASSERT_TRUE(date_set_year(7, d));
        date_destroy(&d);
}

void test_date__date_set_year__date_get_year_03_gett_from_null_yields_false(void) {
        Date d = NULL;
        year_t year;
        TEST_ASSERT_FALSE(date_get_year(&year, d));
        date_destroy(&d);
}

void test_date__date_set_year__date_get_year_04_default_value_is_0(void) {
        Date d = date_create();
        year_t year;
        date_get_year(&year, d);
        TEST_ASSERT(year == 0);
        date_destroy(&d);
}

void test_date__date_set_year__date_get_year_05_gets_what_was_set(void) {
        Date d = date_create();
        date_set_year(7, d);
        year_t year;
        date_get_year(&year, d);
        TEST_ASSERT(year == 7);
        date_destroy(&d);
}

// date_validate()

void test_date__date_validate_01_null_yields_negative_two(void) {
        Date d = NULL;
        TEST_ASSERT(-2 == date_validate(d));
}

void test_date__date_validate_02_default_date_yields_negative_one(void) {
        Date d = date_create();
        TEST_ASSERT(-1 == date_validate(d));
}

void test_date__date_validate_03_month_thirteen_yields_negative_one(void) {
        Date d = date_create();
        date_set_day(1, d);
        date_set_month(13, d);
        TEST_ASSERT(-1 == date_validate(d));
}

void test_date__date_validate_04_month_twelve_day_thirytwo_yields_negateive_one(void) {
        Date d = date_create();
        date_set_day(32, d);
        date_set_month(12, d);
        TEST_ASSERT(-1 == date_validate(d));
}

void test_date__date_validate_05_non_leap_year_feb_twentynine_yields_negateive_one(void) {
        Date d = date_create();
        date_set_day(29, d);
        date_set_month(2, d);
        date_set_year(1991, d);
        TEST_ASSERT(-1 == date_validate(d));
}

void test_date__date_validate_06_leap_year_feb_twentynine_yields_zero(void) {
        Date d = date_create();
        date_set_day(29, d);
        date_set_month(2, d);
        date_set_year(1992, d);
        TEST_ASSERT(0 == date_validate(d));
}

void test_date__date_validate_07_random_valid_date_yields_zero(void) {
        Date d = date_create();
        date_set_day(13, d);
        date_set_month(8, d);
        date_set_year(2001, d);
        TEST_ASSERT(0 == date_validate(d));
}

// date_get_string_length()

void test_date__date_get_string_length_01(void) {

// date_get_string()

void test_date__date_get_string_01(void) {
        Date d = date_create();
        date_set_day(13, d);
        date_set_month(8, d);
        date_set_year(2001, d);
}

#endif //TEST_DATE_H

//// person.h ////
#ifdef TEST_PERSON_H
#include "person.h"

#endif //TEST_PERSON_H

int main(void) {
        UNITY_BEGIN();
        printf("\nRunning tests:\n");

#ifdef TEST_UTILITY_NUMBERS_H
        printf("\n### testing utility_numbers.h ###\n");
        printf("\nNow testing count_digits_int64():\n\n");
        RUN_TEST(test_utility_numbers__count_digits_int64_01_int64_min);
        RUN_TEST(test_utility_numbers__count_digits_int64_02_int64_max);
        RUN_TEST(test_utility_numbers__count_digits_int64_03_zero);
        RUN_TEST(test_utility_numbers__count_digits_int64_04_negative_nine);
        RUN_TEST(test_utility_numbers__count_digits_int64_05_nine);
        RUN_TEST(test_utility_numbers__count_digits_int64_06_negative_ten);
        RUN_TEST(test_utility_numbers__count_digits_int64_07_ten);
        printf("\nNow testing count_digits_uint64():\n\n");
        RUN_TEST(test_utility_numbers__count_digits_uint64_01_int64_max);
        RUN_TEST(test_utility_numbers__count_digits_uint64_02_zero);
        RUN_TEST(test_utility_numbers__count_digits_uint64_03_nine);
        RUN_TEST(test_utility_numbers__count_digits_uint64_04_ten);
        printf("\nNow testing COUNT_DIGITS_INT():\n\n");
        RUN_TEST(test_utility_numbers__count_digits_int_01_uint64_max);
        RUN_TEST(test_utility_numbers__count_digits_int_02_int64_min);
        RUN_TEST(test_utility_numbers__count_digits_int_03_int64_max);
        RUN_TEST(test_utility_numbers__count_digits_int_04_zero);
        RUN_TEST(test_utility_numbers__count_digits_int_05_negative_nine);
        RUN_TEST(test_utility_numbers__count_digits_int_06_nine);
        RUN_TEST(test_utility_numbers__count_digits_int_07_negative_ten);
        RUN_TEST(test_utility_numbers__count_digits_int_08_ten);
#endif //TEST_UTILITY_NUMBERS_H

#ifdef TEST_DATE_H
        printf("\n### testing date.h ###\n");
        printf("\nNow testing date_destroy():\n\n");
        RUN_TEST(test_date__date_destroy_01_false_if_null);
        RUN_TEST(test_date__date_destroy_02_true_if_not_null);
        RUN_TEST(test_date__date_destroy_03_null_after_destroy);
        printf("\nNow testing date_set_day() and date_get_day():\n\n");
        RUN_TEST(test_date__date_set_day__date_get_day_01_can_not_set_unallocated_date);
        RUN_TEST(test_date__date_set_day__date_get_day_02_setting_yields_true);
        RUN_TEST(test_date__date_set_day__date_get_day_03_gett_from_null_yields_false);
        RUN_TEST(test_date__date_set_day__date_get_day_04_default_value_is_0);
        RUN_TEST(test_date__date_set_day__date_get_day_05_gets_what_was_set);
        printf("\nNow testing date_set_month() and date_get_month():\n\n");
        RUN_TEST(test_date__date_set_month__date_get_month_01_can_not_set_unallocated_date);
        RUN_TEST(test_date__date_set_month__date_get_month_02_setting_yields_true);
        RUN_TEST(test_date__date_set_month__date_get_month_03_gett_from_null_yields_false);
        RUN_TEST(test_date__date_set_month__date_get_month_04_default_value_is_0);
        RUN_TEST(test_date__date_set_month__date_get_month_05_gets_what_was_set);
        printf("\nNow testing date_set_year() and date_get_year():\n\n");
        RUN_TEST(test_date__date_set_year__date_get_year_01_can_not_set_unallocated_date);
        RUN_TEST(test_date__date_set_year__date_get_year_02_setting_yields_true);
        RUN_TEST(test_date__date_set_year__date_get_year_03_gett_from_null_yields_false);
        RUN_TEST(test_date__date_set_year__date_get_year_04_default_value_is_0);
        RUN_TEST(test_date__date_set_year__date_get_year_05_gets_what_was_set);
        printf("\nNow testing date_validate():\n\n");
        RUN_TEST(test_date__date_validate_01_null_yields_negative_two);
        RUN_TEST(test_date__date_validate_02_default_date_yields_negative_one);
        RUN_TEST(test_date__date_validate_03_month_thirteen_yields_negative_one);
        RUN_TEST(test_date__date_validate_04_month_twelve_day_thirytwo_yields_negateive_one);
        RUN_TEST(test_date__date_validate_05_non_leap_year_feb_twentynine_yields_negateive_one);
        RUN_TEST(test_date__date_validate_06_leap_year_feb_twentynine_yields_zero);
        RUN_TEST(test_date__date_validate_07_random_valid_date_yields_zero);
        printf("\nNow testing date_get_string():\n\n");
#endif //TEST_DATE_H
 
        return UNITY_END();
}
