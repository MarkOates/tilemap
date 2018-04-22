#pragma once


#include <tilemap/sprite_sheet.hpp>


class TileMap;


class TileMapFactory
{
private:
   SpriteSheet tiles_sprite_sheet;

public:
   TileMapFactory();
   ~TileMapFactory();

   TileMap *create_tile_map();
};


