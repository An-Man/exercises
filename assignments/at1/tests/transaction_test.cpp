#include "../includes/doctest.h"
#include "../includes/transaction.h"
#include <vector>

TEST_CASE("Test transaction ") {
    Transaction test {0, 300};  // expenses 300
    Transaction test2 {0, 200}; // expenses 200
    std::vector<Transaction> testvector;
    testvector.push_back(test);
    testvector.push_back(test2);

    CHECK(calc_total_expenses(testvector) == 500);
}
