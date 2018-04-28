

#include <tilemap/lib/NextCollidingTilesCalculator.hpp>

#include <cmath>


static vec2i world_to_tile_coordinates(float world_x, float world_y)
{
   return vec2i(world_x/16, world_y/16);
}


NextCollidingTilesCalculator::NextCollidingTilesCalculator(axis_t axis, float element_x, float element_y, float element_w, float element_h, float element_velocity_x, float element_velocity_y)
   : axis(axis)
   , element_x(element_x)
   , element_y(element_y)
   , element_w(element_w)
   , element_h(element_h)
   , element_velocity_x(element_velocity_x)
   , element_velocity_y(element_velocity_y)
{
}


NextCollidingTilesCalculator::~NextCollidingTilesCalculator()
{
}


std::vector<vec2i> NextCollidingTilesCalculator::next_colliding_tiles()
{
   std::vector<vec2i> result_tiles;


   float velocity_amt = element_velocity_x; // * timestep;
   float now_x = element_x;
   float next_x = element_x + velocity_amt;
   float next_y = element_y;
   float size_of_body = element_w;
   float length_of_edge = element_h;
   float cursor_step_amt = 16;






   if (axis == Y_AXIS)
   {
      velocity_amt = element_velocity_y; // * timestep;
      now_x = element_y;
      next_x = element_y + velocity_amt;
      next_y = element_x;
      size_of_body = element_h;
      length_of_edge = element_w;
   }






   // if moving right, test along the right edge
   if (velocity_amt > 0.0) // moving right
   {
      now_x += size_of_body;
      next_x += size_of_body;
   }

   int column_x_now = now_x / 16;
   int column_x_next = next_x / 16;
   //std::vector<int2> collided_tiles;

   if (now_x != next_x)
   {
      //std::cout << "---" << std::endl;
      //std::cout << "now_x: " << now_x << std::endl;
      //std::cout << "next_x: " << next_x << std::endl;
      //std::cout << "column_x_now: " << column_x_now << std::endl;
      //std::cout << "column_x_next: " << column_x_next << std::endl;
   }

   float remainder_y = fmod(next_y, 16.0);

   if (column_x_now != column_x_next)
   {
      //std::cout << "PASS" << " was: " << column_x_now << " now: " << column_x_next << std::endl;
      // the player has passed from one row of tiles into the next
      // collect the tiles along the "next" left edge
      int num_passes = std::ceil((length_of_edge + remainder_y) / 16);
      float step_cursor = 0;

      //std::cout << "NUMPAS " << num_passes << std::endl;

      result_tiles.reserve(num_passes);
      for (unsigned i=0; i<num_passes; i++)
      {
         //if (i==(num_passes-1)) step_cursor = length_of_edge;

         vec2i collided_tile(0, 0);

         if (axis == X_AXIS) collided_tile = world_to_tile_coordinates(next_x, next_y + step_cursor);
         else if (axis == Y_AXIS) collided_tile = world_to_tile_coordinates(next_y + step_cursor, next_x);

         result_tiles.push_back(collided_tile);

         //std::cout << "   passed tiles:" << collided_tile << std::endl;

         step_cursor += cursor_step_amt;
      }
   }


   return result_tiles;
}


