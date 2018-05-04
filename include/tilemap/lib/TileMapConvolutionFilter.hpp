#pragma once


#include <allegro5/allegro.h>
#include <tilemap/tile_map.hpp>


class TileMapConvolutionFilter
{
private:
   const std::vector<ALLEGRO_BITMAP *> tile_set;
   const TileMap *source_tilemap;
   TileMap *destination_tilemap;

public:
   TileMapConvolutionFilter(const std::vector<ALLEGRO_BITMAP *> tile_set, const TileMap *source_tilemap, TileMap *destination_tilemap);
   ~TileMapConvolutionFilter();

   void process(ALLEGRO_BITMAP *source_comparison_tile);
};


