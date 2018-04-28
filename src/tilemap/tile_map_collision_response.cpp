

#include <tilemap/tile_map_collision_response.hpp>

#include <tilemap/lib/NextCollidingTilesCalculator.hpp>
#include <tilemap/tile_map.hpp>
#include <tilemap/sprite.hpp>


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
   NextCollidingTilesCalculator horizontal_calculator(
         NextCollidingTilesCalculator::X_AXIS,
         sprite->placement.position.x,
         sprite->placement.position.y,
         sprite->placement.size.x,
         sprite->placement.size.y,
         sprite->velocity.position.x,
         sprite->velocity.position.y
      );

   std::vector<vec2i> horizontal_colliding_tiles = horizontal_calculator.next_colliding_tiles();
   sprite->placement.x += sprite->velocity.x;

   NextCollidingTilesCalculator vertical_calculator(
         NextCollidingTilesCalculator::Y_AXIS,
         sprite->placement.position.x,
         sprite->placement.position.y,
         sprite->placement.size.x,
         sprite->placement.size.y,
         sprite->velocity.position.x,
         sprite->velocity.position.y
      );

   std::vector<vec2i> vertically_colliding_tiles = vertical_calculator.next_colliding_tiles();
   sprite->placement.y += sprite->velocity.y;

   for (auto &tile : horizontal_colliding_tiles) tile_map->set_tile(tile.x, tile.y, fire_tile);
   for (auto &tile : vertically_colliding_tiles) tile_map->set_tile(tile.x, tile.y, fire_tile);
}


