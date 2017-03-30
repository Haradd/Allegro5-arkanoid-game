#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include "colors.h"


ALLEGRO_DISPLAY *window_menu;
ALLEGRO_FONT *font_caption; //= al_load_font("Aller_Bd.ttf", 60, 0);
ALLEGRO_FONT *font_header; //= al_load_font("seaside.ttf", 96, 0);


void init_window_menu();
void create_menu(int winWidth, int winHeight);
void pointer_on(float x, float y);
void pointer_off(float x, float y);


#endif // MENU_H_INCLUDED
