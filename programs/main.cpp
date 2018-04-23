

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
      , current_tile_map(tile_map_factory.create_zoria_tile_map())
   {
   }

   void render_scene()
   {
      ALLEGRO_BITMAP *bitmap = al_get_backbuffer(al_get_current_display());
      ALLEGRO_TRANSFORM trans;
      al_identity_transform(&trans);
      al_orthographic_transform(&trans, 0, 0, -1.0, al_get_bitmap_width(bitmap)/5,
            al_get_bitmap_height(bitmap)/5, 1.0);

      al_set_target_bitmap(bitmap);
      al_use_projection_transform(&trans);
      al_clear_to_color(color::pink);

      if (current_tile_map) current_tile_map->draw();

      al_flip_display();
   }

   void process_event(ALLEGRO_EVENT &event) override
   {
      switch(event.type)
      {
      case ALLEGRO_EVENT_TIMER:
         render_scene();
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


