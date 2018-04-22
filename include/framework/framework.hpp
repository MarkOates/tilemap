#pragma once


#include <allegro5/allegro.h>
#include <vector>
#include <iostream>




extern ALLEGRO_EVENT_QUEUE *master_event_queue;
#include <framework/screen.hpp>



#define EVENT_ABORT_PROGRAM ALLEGRO_GET_EVENT_TYPE('A','B','R','T')



class Framework
{
private:
   ALLEGRO_DISPLAY *display;
   ALLEGRO_EVENT_SOURCE event_source, *timer_event_source, *keyboard_event_source;
   ALLEGRO_TIMER *timer;
   std::vector<Screen *> screens;

public:
   Framework();

   void add_screen(Screen *screen);
   void loop();
};



