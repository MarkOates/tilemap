

#include <framework/framework.hpp>


class Project : public Screen
{
public:
   Project() {}
   void process_event(ALLEGRO_EVENT &event) override
   {
      switch(event.type)
      {
      case ALLEGRO_EVENT_TIMER:
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


