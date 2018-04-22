

#include <allegro5/allegro_primitives.h>
#include <framework/color.hpp>
#include <tilemap/sprite.hpp>


Sprite::Sprite()
   : placement()
   , velocity()
   , bitmap(nullptr)
{
}


Sprite::~Sprite()
{
}


void Sprite::draw()
{
   placement.start_transform();
   al_draw_filled_rectangle(0, 0, placement.size.x, placement.size.y, color::yellow);
   placement.restore_transform();
}


