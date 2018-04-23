

#include <framework/framework.hpp>

#include <allegro5/allegro_image.h>


ALLEGRO_EVENT_QUEUE *master_event_queue = nullptr;


Framework::Framework()
   : display(nullptr)
   , event_source()
   , timer_event_source(nullptr)
   , keyboard_event_source(nullptr)
   , timer(nullptr)
   , screens()
{
   al_init();

   if (!al_init_image_addon()) throw std::runtime_error("al_init_image_addon() failed");

   ALLEGRO_PATH *resource_path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
   al_change_directory(al_path_cstr(resource_path, ALLEGRO_NATIVE_PATH_SEP));
   al_destroy_path(resource_path);

   if (master_event_queue) throw std::runtime_error("duplicate calling of Framework");
   master_event_queue = al_create_event_queue();
   display = al_create_display(1280 / 5 * 7, 720 / 5 * 7);
   timer = al_create_timer(ALLEGRO_BPS_TO_SECS(60));

   if (!al_install_keyboard()) throw std::runtime_error("al_install_keyboard() failed.");

   al_init_user_event_source(&event_source);
   keyboard_event_source = al_get_keyboard_event_source();
   timer_event_source = al_get_timer_event_source(timer);
   al_register_event_source(master_event_queue, &event_source);
   al_register_event_source(master_event_queue, timer_event_source);
   al_register_event_source(master_event_queue, keyboard_event_source);
}


void Framework::add_screen(Screen *screen)
{
   screens.push_back(screen); 
}


void Framework::loop()
{
   ALLEGRO_EVENT event;
   al_start_timer(timer);
   while (event.type != EVENT_ABORT_PROGRAM)
   {
      al_wait_for_event(master_event_queue, &event);
      for (auto &screen : screens) screen->process_event(event);
   }
}


