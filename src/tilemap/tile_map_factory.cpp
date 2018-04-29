

#include <tilemap/tile_map_factory.hpp>

#include <tilemap/tile_map.hpp>


TileMapFactory::TileMapFactory()
   : forest_tiles_sprite_sheet(al_load_bitmap("bitmaps/tiles/foresttiles.gif")) // note, this foresttiles bitmap dangles
   , zoria_tiles_sprite_sheet(al_load_bitmap("bitmaps/tiles/tiles.png")) // note, this foresttiles bitmap dangles
{
}


TileMapFactory::~TileMapFactory()
{
}


TileMap *TileMapFactory::create_forest_tile_map()
{
   const int MAP_HEIGHT = 9;
   const int MAP_WIDTH = 16;
   TileMap *tile_map = new TileMap(MAP_WIDTH, MAP_HEIGHT, 16);

   for (int y=0; y<MAP_HEIGHT; y++)
      for (int x=0; x<MAP_WIDTH; x++)
         tile_map->set_tile(x, y, forest_tiles_sprite_sheet.get_sprite((x+y) % forest_tiles_sprite_sheet.get_num_sprites()));

   return tile_map;
}


TileMap *TileMapFactory::create_zoria_tile_map()
{
   const int MAP_HEIGHT = 9*2;
   const int MAP_WIDTH = 16*2;
   TileMap *tile_map = new TileMap(MAP_WIDTH, MAP_HEIGHT, 16);

   for (int y=0; y<MAP_HEIGHT; y++)
      for (int x=0; x<MAP_WIDTH; x++)
         tile_map->set_tile(x, y, zoria_tiles_sprite_sheet.get_sprite((x+y) % zoria_tiles_sprite_sheet.get_num_sprites()));

   return tile_map;
}


void draw_barrier(TileMap *tile_map, SpriteSheet *sprite_sheet, int x, int y, int x2, int y2)
{
   for (int xx=x; xx<=x2; xx++) tile_map->set_tile(xx, y, sprite_sheet->get_sprite(4*32+1)); // top
   for (int xx=x; xx<=x2; xx++) tile_map->set_tile(xx, y2, sprite_sheet->get_sprite(4*32+1)); // bottom
   for (int yy=y; yy<=y2; yy++) tile_map->set_tile(x, yy, sprite_sheet->get_sprite(3*32+3)); // left
   for (int yy=y; yy<=y2; yy++) tile_map->set_tile(x2, yy, sprite_sheet->get_sprite(3*32+3)); // right

   tile_map->set_tile(x, y, sprite_sheet->get_sprite(2*32)); // top left
   tile_map->set_tile(x2, y, sprite_sheet->get_sprite(2*32+1)); // top right
   tile_map->set_tile(x, y2, sprite_sheet->get_sprite(3*32)); // bottom left
   tile_map->set_tile(x2, y2, sprite_sheet->get_sprite(3*32+1)); // bottom right
}


TileMap *TileMapFactory::create_zoria_grass_map()
{
   const int MAP_HEIGHT = 9*2;
   const int MAP_WIDTH = 16*2;
   TileMap *tile_map = new TileMap(MAP_WIDTH, MAP_HEIGHT, 16);

   std::vector<int> possible_tiles = { 0, 0, 0, 0, 32+5, 5, 6, 32+7, 32+8, 32*2+9 };

   for (int y=0; y<MAP_HEIGHT; y++)
      for (int x=0; x<MAP_WIDTH; x++)
      {
         int selected_tile_index = possible_tiles[rand() * 250 % possible_tiles.size()];
         tile_map->set_tile(x, y, zoria_tiles_sprite_sheet.get_sprite(selected_tile_index));
      }

   draw_barrier(tile_map, &zoria_tiles_sprite_sheet, 2, 2, 10, 5);

   draw_barrier(tile_map, &zoria_tiles_sprite_sheet, 0, 0, 16*2-1, 9*2-1);

   return tile_map;
}


std::set<ALLEGRO_BITMAP *> TileMapFactory::get_zoria_solids()
{
   std::set<int> solid_tile_indexes = { 4*32+1, 4*32+1, 3*32+3, 3*32+3, 2*32, 2*32+1, 3*32, 3*32+1 };
   std::set<ALLEGRO_BITMAP *> solid_bitmaps;

   for (auto &solid_tile_index : solid_tile_indexes)
      solid_bitmaps.insert(zoria_tiles_sprite_sheet.get_sprite(solid_tile_index));

   return solid_bitmaps;
}


