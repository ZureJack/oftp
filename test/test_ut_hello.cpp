#include <gtest/gtest.h>
#include <iostream>
#include "common.h"

TEST(Test, hello)
{
    EXPECT_EQ(1, 1);
#ifdef TEST_BUILD
    std::cout << "TEST_BUILD" << std::endl;
#else
    std::cout << "NO" << std::endl;
#endif
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}