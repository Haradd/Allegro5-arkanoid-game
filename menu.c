#include "menu.h"

void init_window_menu()
{
    al_init();
    al_set_new_window_position(100, 100);
    al_set_new_display_flags(ALLEGRO_RESIZABLE | ALLEGRO_WINDOWED );
    al_set_window_title(window_menu, "Arkanoid");

    al_init_font_addon();
    al_init_ttf_addon();

}
void create_menu(int winWidth, int winHeight)
{
    window_menu = al_create_display(winWidth, winHeight);
    font_caption = al_load_font("fonts/FFF_Tusj.ttf", 60, 0);
    font_header = al_load_font("fonts/seaside.ttf", 96, 0);


    al_set_target_bitmap(al_get_backbuffer(window_menu));
    al_clear_to_color(grey);

    al_draw_text(font_header, white, winWidth/2, winHeight/50, ALLEGRO_ALIGN_CENTRE, "Arkanoid");
    al_draw_text(font_caption, white, winWidth/10, 300, ALLEGRO_ALIGN_LEFT, "Easy");
    al_draw_text(font_caption, white, winWidth/10, 375, ALLEGRO_ALIGN_LEFT, "Medium");
    al_draw_text(font_caption, white, winWidth/10, 450, ALLEGRO_ALIGN_LEFT, "Hard");
    al_draw_text(font_caption, white, winWidth/10, 525, ALLEGRO_ALIGN_LEFT, "Scores");
    al_draw_text(font_caption, red, winWidth/10, 600, ALLEGRO_ALIGN_LEFT, "Exit");

    al_flip_display();


}
void pointer_on(float x, float y)
{
    al_init_primitives_addon();

    al_draw_filled_circle(x, y, 15, red);
}
void pointer_off(float x, float y)
{
    al_init_primitives_addon();

    al_draw_filled_circle(x, y, 15, grey);
}

