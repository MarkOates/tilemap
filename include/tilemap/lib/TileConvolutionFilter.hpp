#pragma once


#include <allegro5/allegro.h>
#include <tilemap/tile_map.hpp>


class TileConvolutionFilter
{
private:
   const std::vector<ALLEGRO_BITMAP *> tile_set;
   const TileMap *source_tilemap;
   TileMap *destination_tilemap;

public:
   TileConvolutionFilter(const std::vector<ALLEGRO_BITMAP *> tile_set, const TileMap *source_tilemap, TileMap *destination_tilemap);
   ~TileConvolutionFilter();

   void process();
};


