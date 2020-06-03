#include <stdio.h>
#include <allegro5/allegro.h>

int main(void)
{

    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_install_joystick();

    ALLEGRO_DISPLAY* display = al_create_display(640, 480);
    al_set_window_title(display, "Test");
    
    
    while (1) {
        al_draw_pixel(10, 10, al_map_rgb(255, 255, 255));
        al_flip_display();
    }

    al_destroy_display(display);

    al_uninstall_joystick();
    al_uninstall_mouse();
    al_uninstall_keyboard();

    return 0;
}
