

#include <tilemap/lib/TileConvolutionFilter.hpp>


TileConvolutionFilter::TileConvolutionFilter(const std::vector<ALLEGRO_BITMAP *> tile_set, const TileMap *source_tilemap, TileMap *destination_tilemap)
   : tile_set(tile_set)
   , source_tilemap(source_tilemap)
   , destination_tilemap(destination_tilemap)
{
}


TileConvolutionFilter::~TileConvolutionFilter()
{
}


void TileConvolutionFilter::process()
{
   //destination = 
}


