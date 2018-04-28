

#include <gtest/gtest.h>

#include <tilemap/lib/NextCollidingTilesCalculatorTest.hpp>


TEST(NextCollidingTilesCalculatorTest, can_be_created)
{
   NextCollidingTilesCalculator calculator;
}


TEST(NextCollidingTilesCalculatorTest, next_colliding_tiles__returns_a_list_of_tiles_that_are_expected_to_collide_in_the_next_step)
{
   NextCollidingTilesCalculator calculator;
}


int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}


