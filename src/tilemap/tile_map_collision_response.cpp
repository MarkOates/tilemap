

#include <tilemap/tile_map_collision_response.hpp>

#include <tilemap/tile_map.hpp>
#include <tilemap/sprite.hpp>


#include <iostream>
#include <cmath>

class TileAndObjectCollision
{
public:
   float x;
   float y;
   float w;
   float h;
   float velocity_x;
   float velocity_y;

   bool collides(const TileAndObjectCollision &other)
   {
      if (other.x > (x+w)) return false;
      if (other.y > (y+h)) return false;
      if (other.x+other.w < x) return false;
      if (other.y+other.h < y) return false;
      return true;
   }
   float get_left() { return x; }
   float get_right() { return x+w; }
   float get_bottom() { return y+h; }
   float get_top() { return y; }

   void set_left(float x) { this->x = x; }
   void set_right(float x) { this->x = x - w; }
   void set_bottom(float y) { this->y = y - h; }
   void set_top(float y) { this->y = y; }
};


class int2
{
public:
   int2(int x, int y)
      : x(x)
      , y(y)
   {}
   int x, y;
   void print(std::ostream& os)const
   {
      os << "(" << x << ", " << y << ")";
   }
};

static int2 world_to_tile_coordinates(float world_x, float world_y)
{
   return int2(world_x/16, world_y/16);
}


template<class T>
auto operator<<(std::ostream& os, const T& t) -> decltype(t.print(os), os)
{
    t.print(os);
    return os;
}


enum AXIS
{
   X_AXIS,
   Y_AXIS,
};



//#define GAMEPLAY_FRAME_DURATION_PER_SEC (1.0/60.0)
#define GAMEPLAY_FRAME_DURATION_PER_SEC 1.0



static std::vector<int2> test_tile_map_collision_axis(AXIS axis, TileAndObjectCollision element, float timestep = GAMEPLAY_FRAME_DURATION_PER_SEC)
{
   float velocity_amt = element.velocity_x * timestep;
   float now_x = element.x;
   float next_x = element.x + velocity_amt;
   float next_y = element.y;
   float size_of_body = element.w;
   float length_of_edge = element.h;
   float cursor_step_amt = 16;






   if (axis == Y_AXIS)
   {
      velocity_amt = element.velocity_y * timestep;
      now_x = element.y;
      next_x = element.y + velocity_amt;
      next_y = element.x;
      size_of_body = element.h;
      length_of_edge = element.w;
   }







   // if moving right, test along the right edge
   if (velocity_amt > 0.0) // moving right
   {
      now_x += size_of_body;
      next_x += size_of_body;
   }

   int column_x_now = now_x / 16;
   int column_x_next = next_x / 16;
   std::vector<int2> collided_tiles;

   if (now_x != next_x)
   {
      std::cout << "---" << std::endl;
      std::cout << "now_x: " << now_x << std::endl;
      std::cout << "next_x: " << next_x << std::endl;
      std::cout << "column_x_now: " << column_x_now << std::endl;
      std::cout << "column_x_next: " << column_x_next << std::endl;
   }

   float remainder_y = fmod(next_y, 16.0);

   if (column_x_now != column_x_next)
   {
      std::cout << "PASS" << " was: " << column_x_now << " now: " << column_x_next << std::endl;
      // the player has passed from one row of tiles into the next
      // collect the tiles along the "next" left edge
      int num_passes = std::ceil((length_of_edge + remainder_y) / 16);
      float step_cursor = 0;

      //std::cout << "NUMPAS " << num_passes << std::endl;

      collided_tiles.reserve(num_passes);
      for (unsigned i=0; i<num_passes; i++)
      {
         //if (i==(num_passes-1)) step_cursor = length_of_edge;

         int2 collided_tile(0, 0);

         if (axis == X_AXIS) collided_tile = world_to_tile_coordinates(next_x, next_y + step_cursor);
         else if (axis == Y_AXIS) collided_tile = world_to_tile_coordinates(next_y + step_cursor, next_x);

         collided_tiles.push_back(collided_tile);

         std::cout << "   passed tiles:" << collided_tile << std::endl;

         step_cursor += cursor_step_amt;
      }
   }

   return collided_tiles;
}




TileMapCollisionResponse::TileMapCollisionResponse(TileMap *tile_map, Sprite *sprite)
   : tile_map(tile_map)
   , sprite(sprite)
{
}


TileMapCollisionResponse::~TileMapCollisionResponse()
{
}


void TileMapCollisionResponse::process(ALLEGRO_BITMAP *fire_tile)
{
   TileAndObjectCollision element;
   element.x = sprite->placement.position.x;
   element.y = sprite->placement.position.y;
   element.w = sprite->placement.size.x;
   element.h = sprite->placement.size.y;
   element.velocity_x = sprite->velocity.x;
   element.velocity_y = sprite->velocity.y;

   std::vector<int2> horizontal_colliding_tiles = test_tile_map_collision_axis(X_AXIS, element);
   sprite->placement.x += sprite->velocity.x;

   std::vector<int2> vertically_colliding_tiles = test_tile_map_collision_axis(Y_AXIS, element);
   sprite->placement.y += sprite->velocity.y;

   for (auto &tile : horizontal_colliding_tiles) tile_map->set_tile(tile.x, tile.y, fire_tile);
   for (auto &tile : vertically_colliding_tiles) tile_map->set_tile(tile.x, tile.y, fire_tile);
}


