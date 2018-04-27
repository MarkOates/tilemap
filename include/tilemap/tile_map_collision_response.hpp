#pragma once


class TileMap;
class Sprite;
class ALLEGRO_BITMAP;


class TileMapCollisionResponse
{
private:
   TileMap *tile_map;
   Sprite *sprite;

public:
   TileMapCollisionResponse(TileMap *tile_map, Sprite *sprite);
   ~TileMapCollisionResponse();

   void process(ALLEGRO_BITMAP *fire_tile);
};


