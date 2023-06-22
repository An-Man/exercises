#include "../includes/doctest.h"
#include "../includes/fileop.h"
#include <vector>

TEST_CASE("Test transaction ") {
    std::vector<Transaction> testvector;

    CHECK(write_to_file("test.txt", testvector) == "File writing succeeded.\n");
}