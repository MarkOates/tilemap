

#include <tilemap/tile_map_factory.hpp>

#include <tilemap/tile_map.hpp>


TileMapFactory::TileMapFactory()
   : tiles_sprite_sheet(al_load_bitmap("bitmaps/tiles/foresttiles.gif")) // note, this foresttiles bitmap dangles
{
}


TileMapFactory::~TileMapFactory()
{
}


TileMap *TileMapFactory::create_tile_map()
{
   const int MAP_HEIGHT = 9;
   const int MAP_WIDTH = 16;
   TileMap *tile_map = new TileMap(MAP_WIDTH, MAP_HEIGHT, 16);

   for (int y=0; y<MAP_HEIGHT; y++)
      for (int x=0; x<MAP_WIDTH; x++)
         tile_map->set_tile(x, y, tiles_sprite_sheet.get_sprite((x+y) % tiles_sprite_sheet.get_num_sprites()));

   return tile_map;
}
