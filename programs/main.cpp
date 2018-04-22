

#include <framework/color.hpp>
#include <framework/framework.hpp>
#include <framework/placement2d.hpp>
#include <tilemap/tile_map.hpp>
#include <tilemap/tile_map_factory.hpp>


class Project : public Screen
{
public:
   TileMapFactory tile_map_factory;
   TileMap *current_tile_map;

   Project()
      : tile_map_factory()
      , current_tile_map(tile_map_factory.create_tile_map())
   {
      //al_set_target_bitmap(al_get_backbuffer(al_get_current_display()));
      //Placement2D projection;
      //ALLEGRO_TRANSFORM projection_transform;
      //projection.scale = vec2d(1, 1);
      //projection.build_reverse_transform(&projection_transform);
      //al_use_projection_transform(&projection_transform);
   }

   void initializer()
   {
   }

   void process_event(ALLEGRO_EVENT &event) override
   {
      switch(event.type)
      {
      case ALLEGRO_EVENT_TIMER:
         al_clear_to_color(color::pink);
         if (current_tile_map) current_tile_map->draw();
         al_flip_display();
         break;
      default:
         std::cout << "Event << " << std::endl;
         break;
      }
   }
};


int main(int argc, char **argv)
{
   Framework framework;
   Project project;
   framework.add_screen(&project);
   framework.loop();

   return 0;
}


