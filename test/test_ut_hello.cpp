#include <gtest/gtest.h>
#include <iostream>
#include "common.h"

TEST(Test, hello)
{
    EXPECT_EQ(1, 1);
#ifdef DEBUG_BUILD
    std::cout << "DEBUG_BUILD" << std::endl;
#else
    std::cout << "NO" << std::endl;
#endif
}