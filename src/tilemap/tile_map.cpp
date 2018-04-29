

#include <tilemap/tile_map.hpp>


TileMap::TileMap(int width, int height, int tile_width)
   : width(width)
   , height(height)
   , tile_width(tile_width)
   , tiles()
{
   set_width_and_height(width, height);
}


TileMap::~TileMap()
{
}


void TileMap::set_tile(int x, int y, ALLEGRO_BITMAP *tile)
{
   if (x < 0 || x >= width) throw std::runtime_error("cannot assign tile outsize x boundaries");
   if (y < 0 || y >= height) throw std::runtime_error("cannot assign tile outsize y boundaries");
   tiles[y*width+x] = tile;
}


void TileMap::set_width_and_height(int width, int height)
{
   tiles.clear();
   tiles.resize(width * height, nullptr);
}


void TileMap::draw()
{
   for (int y=0; y<height; y++)
      for (int x=0; x<width; x++)
      {
         ALLEGRO_BITMAP *tile = tiles[y * width + x];
         if (tile) al_draw_bitmap(tile, x*tile_width, y*tile_width, 0);
      }
}


