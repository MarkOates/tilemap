#pragma once


#include <tilemap/sprite_sheet.hpp>
#include <set>


class TileMap;


class TileMapFactory
{
private:
   SpriteSheet forest_tiles_sprite_sheet;
   SpriteSheet zoria_tiles_sprite_sheet;

public:
   TileMapFactory();
   ~TileMapFactory();

   TileMap *create_forest_tile_map();
   TileMap *create_zoria_tile_map();
   TileMap *create_zoria_grass_map();

   std::set<ALLEGRO_BITMAP *> get_zoria_solids();
};


