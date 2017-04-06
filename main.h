#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "menu.h"
#include "game.h"
#include "keyboard.h"
#include "colors.h"
#include "scores.h"

enum level{easy, medium, hard};
int  winWidth;
int winHeight;
int done;
int menu_option;
int pointer_x;
int pointer_y;

int main();

#endif // MAIN_H_INCLUDED
