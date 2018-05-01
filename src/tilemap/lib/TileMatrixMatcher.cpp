

#include <tilemap/lib/TileMatrixMatcher.hpp>


TileMatrixMatcher::TileMatrixMatcher()
{
}


TileMatrixMatcher::~TileMatrixMatcher()
{
}


bool TileMatrixMatcher::match(const int matrix[3][3], int test_tile, const int context_matrix[3][3])
{
   for (unsigned y=0; y<3; y++)
      for (unsigned x=0; x<3; x++)
      {
         switch (matrix[y][x])
         {
         case 0: break;
         case 1: if (test_tile != context_matrix[y][x]) return false; break;
         case 2: if (test_tile == context_matrix[y][x]) return false; break;
         default: std::runtime_error("TileMatrixMatcher::match error: unrecognized value in matrix"); break;
         }
      }
   return true;
}


