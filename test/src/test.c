#include "unity.h"
#include "date.h"
#include "person.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_01(void) {
        TEST_IGNORE_MESSAGE("hello!\n");
}

int main(void) {
        UNITY_BEGIN();
        RUN_TEST(test_01);
        return UNITY_END();
}
