

#include <gtest/gtest.h>

#include <tilemap/lib/TileMatrixMatcher.hpp>


TEST(TileMatrixMatcherTest, can_be_created_without_arguments)
{
   TileMatrixMatcher filter_matcher;
}


TEST(TileMatrixMatcherTest, match__returns_true_when_given_a_tile_context_and_a_filter_matches)
{
   TileMatrixMatcher filter_matcher;

   int my_tile_context_matrix[3][3] = { { 12, 32,  8 },
                                        { 32, 32, 11 },
                                        { 12,  7,  8 } };

   ASSERT_TRUE(filter_matcher.match(filter_matcher.bottom_right, 32, my_tile_context_matrix));
}


TEST(TileMatrixMatcherTest, match__returns_false_when_given_a_tile_context_and_a_filter_does_not_match)
{
   TileMatrixMatcher filter_matcher;

   int my_tile_context_matrix[3][3] = { { 12, 32,  8 },
                                        { 32, 32, 32 },
                                        { 12,  7,  8 } };

   ASSERT_FALSE(filter_matcher.match(filter_matcher.bottom_right, 32, my_tile_context_matrix));
}


int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}


