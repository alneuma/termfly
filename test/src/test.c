#include "unity.h"
#include "date.h"
#include "person.h"

#define TEST_DATE_H

void setUp(void) {
}

void tearDown(void) {
}

//// date.h ////
#ifdef TEST_DATE_H

void test_date_date_destroy_01_false_if_null(void) {
        Date d = NULL;
        TEST_ASSERT_FALSE(date_destroy(&d));
}

void test_date_date_destroy_02_true_if_not_null(void) {
        Date d = date_create();
        TEST_ASSERT_TRUE(date_destroy(&d));
}

void test_date_date_destroy_03_null_after_destroy(void) {
        Date d = date_create();
        date_destroy(&d);
        TEST_ASSERT_NULL(d);
}

void test_date_date_set_day__date_get_day_01_can_not_set_unallocated_date(void) {
        Date d = NULL;
        TEST_ASSERT_FALSE(date_set_day(7, d));
}

void test_date_date_set_day__date_get_day_02_setting_yields_true(void) {
        Date d = date_create();
        TEST_ASSERT_TRUE(date_set_day(7, d));
        date_destroy(&d);
}

void test_date_date_set_day__date_get_day_03_gett_from_null_yields_false(void) {
        Date d = NULL;
        day_t day;
        TEST_ASSERT_FALSE(date_get_day(&day, d));
        date_destroy(&d);
}

void test_date_date_set_day__date_get_day_04_default_value_is_0(void) {
        Date d = date_create();
        day_t day;
        date_get_day(&day, d);
        TEST_ASSERT(day == 0);
        date_destroy(&d);
}

void test_date_date_set_day__date_get_day_05_gets_what_was_set(void) {
        Date d = date_create();
        date_set_day(7, d);
        day_t day;
        date_get_day(&day, d);
        TEST_ASSERT(day == 7);
        date_destroy(&d);
}

void test_date_date_set_month__date_get_month_01_can_not_set_unallocated_date(void) {
        Date d = NULL;
        TEST_ASSERT_FALSE(date_set_month(7, d));
}

void test_date_date_set_month__date_get_month_02_setting_yields_true(void) {
        Date d = date_create();
        TEST_ASSERT_TRUE(date_set_month(7, d));
        date_destroy(&d);
}

void test_date_date_set_month__date_get_month_03_gett_from_null_yields_false(void) {
        Date d = NULL;
        month_t month;
        TEST_ASSERT_FALSE(date_get_month(&month, d));
        date_destroy(&d);
}

void test_date_date_set_month__date_get_month_04_default_value_is_0(void) {
        Date d = date_create();
        month_t month;
        date_get_month(&month, d);
        TEST_ASSERT(month == 0);
        date_destroy(&d);
}

void test_date_date_set_month__date_get_month_05_gets_what_was_set(void) {
        Date d = date_create();
        date_set_month(7, d);
        month_t month;
        date_get_month(&month, d);
        TEST_ASSERT(month == 7);
        date_destroy(&d);
}

void test_date_date_set_year__date_get_year_01_can_not_set_unallocated_date(void) {
        Date d = NULL;
        TEST_ASSERT_FALSE(date_set_year(7, d));
}

void test_date_date_set_year__date_get_year_02_setting_yields_true(void) {
        Date d = date_create();
        TEST_ASSERT_TRUE(date_set_year(7, d));
        date_destroy(&d);
}

void test_date_date_set_year__date_get_year_03_gett_from_null_yields_false(void) {
        Date d = NULL;
        year_t year;
        TEST_ASSERT_FALSE(date_get_year(&year, d));
        date_destroy(&d);
}

void test_date_date_set_year__date_get_year_04_default_value_is_0(void) {
        Date d = date_create();
        year_t year;
        date_get_year(&year, d);
        TEST_ASSERT(year == 0);
        date_destroy(&d);
}

void test_date_date_set_year__date_get_year_05_gets_what_was_set(void) {
        Date d = date_create();
        date_set_year(7, d);
        year_t year;
        date_get_year(&year, d);
        TEST_ASSERT(year == 7);
        date_destroy(&d);
}

#endif //TEST_DATE_H
int main(void) {
        UNITY_BEGIN();

#ifdef TEST_DATE_H
        RUN_TEST(test_date_date_destroy_01_false_if_null);
        RUN_TEST(test_date_date_destroy_02_true_if_not_null);
        RUN_TEST(test_date_date_destroy_03_null_after_destroy);
        RUN_TEST(test_date_date_set_day__date_get_day_01_can_not_set_unallocated_date);
        RUN_TEST(test_date_date_set_day__date_get_day_02_setting_yields_true);
        RUN_TEST(test_date_date_set_day__date_get_day_03_gett_from_null_yields_false);
        RUN_TEST(test_date_date_set_day__date_get_day_04_default_value_is_0);
        RUN_TEST(test_date_date_set_day__date_get_day_05_gets_what_was_set);
        RUN_TEST(test_date_date_set_month__date_get_month_01_can_not_set_unallocated_date);
        RUN_TEST(test_date_date_set_month__date_get_month_02_setting_yields_true);
        RUN_TEST(test_date_date_set_month__date_get_month_03_gett_from_null_yields_false);
        RUN_TEST(test_date_date_set_month__date_get_month_04_default_value_is_0);
        RUN_TEST(test_date_date_set_month__date_get_month_05_gets_what_was_set);
        RUN_TEST(test_date_date_set_year__date_get_year_01_can_not_set_unallocated_date);
        RUN_TEST(test_date_date_set_year__date_get_year_02_setting_yields_true);
        RUN_TEST(test_date_date_set_year__date_get_year_03_gett_from_null_yields_false);
        RUN_TEST(test_date_date_set_year__date_get_year_04_default_value_is_0);
        RUN_TEST(test_date_date_set_year__date_get_year_05_gets_what_was_set);
#endif //TEST_DATE_H
 
        return UNITY_END();
}
