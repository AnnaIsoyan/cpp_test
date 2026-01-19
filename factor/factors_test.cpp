#include <gtest/gtest.h>
#include "factors.h"

// TDD - Test Driven Development

// Red - Failing test (write tests first)
// Green - Make it pass
// Refactor - Clean up code

bool arraysEqual(const int* arr1, const int* arr2, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}

TEST(FactorTests, FactorsOf0)
{
    EXPECT_TRUE(arraysEqual(getFactors(0), {}, 0));
}

TEST(FactorTests, FactorsOf1)
{
    EXPECT_TRUE(arraysEqual(getFactors(1), {}, 0));
}

TEST(FactorTests, FactorsOf2)
{
    EXPECT_TRUE(arraysEqual(getFactors(2), ((int[]){2}), 1));
}

TEST(FactorTests, FactorsOf3)
{
    EXPECT_TRUE(arraysEqual(getFactors(3), ((int[]){3}), 1));
}

TEST(FactorTests, FactorsOf4)
{
    EXPECT_TRUE(arraysEqual(getFactors(4), ((int[]){2, 2}), 2));
}

// run like this
// clang++ factors_test.cpp factors.cpp  -o factors_test -lgtest -lgtest_main