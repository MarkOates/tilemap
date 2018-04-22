#pragma once


#include <allegro5/allegro.h>
#include <framework/placement2d.hpp>


class Sprite
{
public:
   Placement2D placement;
   Placement2D velocity;
   ALLEGRO_BITMAP *bitmap;

   Sprite();
   ~Sprite();

   void draw();
};


