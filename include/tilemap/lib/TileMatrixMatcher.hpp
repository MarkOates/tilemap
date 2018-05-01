#pragma once


#include <stdexcept>


class TileMatrixMatcher
{
private:
   // 0 == does not matter
   // 1 == must be same
   // 2 == must be different
   // the center tile is the tile being evaluated question
   const int _ = 0;

public:

   TileMatrixMatcher();
   ~TileMatrixMatcher();

   const int top_left[3][3] =     { { _, 2, _ },
                                    { 2, 1, 1 },
                                    { _, 1, _ } };

   const int top_right[3][3] =    { { _, 2, _ },
                                    { 1, 1, 2 },
                                    { _, 1, _ } };

   const int bottom_left[3][3] =  { { _, 1, _ },
                                    { 2, 1, 1 },
                                    { _, 2, _ } };

   const int bottom_right[3][3] = { { _, 1, _ },
                                    { 1, 1, 2 },
                                    { _, 2, _ } };

   const int top[3][3] =          { { _, 2, _ },
                                    { 1, 1, 1 },
                                    { _, 1, _ } };

   const int bottom[3][3] =       { { _, 1, _ },
                                    { 1, 1, 1 },
                                    { _, 2, _ } };

   const int left[3][3] =         { { _, 1, _ },
                                    { 2, 1, 1 },
                                    { _, 1, _ } };

   const int right[3][3] =        { { _, 1, _ },
                                    { 1, 1, 2 },
                                    { _, 1, _ } };

   const int full[3][3] =         { { _, 1, _ },
                                    { 1, 1, 1 },
                                    { _, 1, _ } };

   bool match(const int truth_matrix[3][3], int test_tile, const int context_matrix[3][3]);
};


