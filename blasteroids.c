#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include "calc.h"
#include "spaceship.h"

int main(void)
{
    al_init();
    al_init_primitives_addon();
    al_init_font_addon();
    al_install_keyboard();
    al_install_mouse();
    al_install_joystick();

    ALLEGRO_DISPLAY* display = al_create_display(WIDTH, HEIGHT);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
    //ALLEGRO_FONT* font = al_load_font("Arial", 20, 0);
    al_set_window_title(display, "Blasteroids");

    //register events
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());    

    ALLEGRO_COLOR background = al_map_rgb(0, 0, 0);
    Spaceship* ship = spaceship_create(400, 400);
    Rotated rotated = STOP;

    int running = true;
    al_start_timer(timer);
    while (running) {
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) running = false;

        if (event.type == ALLEGRO_EVENT_TIMER) {
            al_clear_to_color(background);

            spaceship_draw(ship);
            spaceship_rotated(ship, rotated);
            spaceship_update(ship);
            rotated = STOP;
            
            al_flip_display();
        }

        ALLEGRO_KEYBOARD_STATE keyState;
        al_get_keyboard_state(&keyState);
        if (al_key_down(&keyState, ALLEGRO_KEY_UP)) {
            spaceship_speedup(ship, per_second(15.0f));
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_DOWN)) {
            spaceship_speedup(ship, per_second(-15.0f));
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT)) {
            rotated = LEFT;
        }
        else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT)) {
            rotated = RIGHT;
        }
    }

    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_display(display);

    al_uninstall_joystick();
    al_uninstall_mouse();
    al_uninstall_keyboard();

    return 0;
}
