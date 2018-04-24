#pragma once


class TileMapCollisionResponse
{
public:
   TileMapCollisionResponse(TileMap *tile_map, Sprite *sprite);
   ~TileMapCollisionResponse();

   void process();
};


