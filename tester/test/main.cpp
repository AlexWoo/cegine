#include "ce_tester.h"

using namespace CETester;

CE_TESTCASE(Test) {
    std::cout << "Hello World" << std::endl;

    EXPECT_EQ(1, 1);
    EXPECT_EQ(20, 20.0);
}

CE_TESTCASE(Test2) {
    int i = 10, j = 20;

    std::cout << "Hello World 2" << std::endl;

    EXPECT_EQ("Hello", "World");
    EXPECT_EQ("Hello", "Hello");
    EXPECT_EQ(i, j);
}

int main() {
    RunAllTester();
}
