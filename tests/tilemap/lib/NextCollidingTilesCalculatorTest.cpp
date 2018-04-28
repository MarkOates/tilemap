

#include <gtest/gtest.h>

#include <tilemap/lib/NextCollidingTileCalculator.hpp>


TEST(NextCollidingTileCalculatorTest, can_be_created)
{
   NextCollidingTileCalculator calculator;
}


TEST(NextCollidingTileCalculatorTest, get_ordered_item__returns_the_expected_sorted_item)
{
   NextCollidingTileCalculator calculator;
}


int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}


