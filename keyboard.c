#include "keyboard.h"

int keyboard_state()
{
    al_install_keyboard();
    ALLEGRO_KEYBOARD_STATE keyboard;
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_wait_for_event(event_queue, &event);
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
        return event.keyboard.keycode;
    return 0;
}

int game_keyboard_state()
{
        al_install_keyboard();
    ALLEGRO_KEYBOARD_STATE keyboard;
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_wait_for_event(event_queue, &event);
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
        return event.keyboard.keycode;
    return 0;

}
