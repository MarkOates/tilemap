

class Screen
{
public:
   ALLEGRO_EVENT_SOURCE event_source;

   Screen()
   {
      al_init_user_event_source(&event_source);
      al_register_event_source(master_event_queue, &event_source);
   }
   virtual ~Screen()
   {
      al_unregister_event_source(master_event_queue, &event_source);
   }

   void emit_event(int32_t event_type, intptr_t data1=0, intptr_t data2=0, intptr_t data3=0, intptr_t data4=0)
   {
      ALLEGRO_EVENT al_event;
      al_event.user.type = event_type;
      al_event.user.data1 = data1;
      al_event.user.data2 = data2;
      al_event.user.data3 = data3;
      al_event.user.data4 = data4;
      al_emit_user_event(&event_source, &al_event, NULL);
   }
   virtual void process_event(ALLEGRO_EVENT &event) {}
};



