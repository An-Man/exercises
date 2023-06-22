#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/pascal_functions.h"

TEST_CASE("Test pascal function coefficient") {
    CHECK(calculate_coef(1, 5, 1) == 4);
    CHECK(calculate_coef(1, 4, 1) == 3);
    CHECK(calculate_coef(1, 3, 1) == 2);
    CHECK(calculate_coef(1, 2, 1) == 1);
    CHECK(calculate_coef(1, 1, 1) == 0);
}