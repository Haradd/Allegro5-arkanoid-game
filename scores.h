#ifndef SCORES_H_INCLUDED
#define SCORES_H_INCLUDED
#define True 1
#define False 0

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>


#include "scores.h"
#include "keyboard.h"
#include "colors.h"

ALLEGRO_DISPLAY *window_scores;
ALLEGRO_FONT *font_caption; //= al_load_font("Aller_Bd.ttf", 60, 0);

int done;
FILE *file;
void game_scores(int winWidth, int winHeight);


#endif // SCORES_H_INCLUDED
