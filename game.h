#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#define True  1
#define False 0
#define COLS  13
#define ROWS  7

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "keyboard.h"
#include "save.h"
#include "colors.h"

ALLEGRO_DISPLAY *window_game;
ALLEGRO_EVENT_QUEUE *eventQueue_game;
ALLEGRO_EVENT event_game;
ALLEGRO_TIMER *move_timer, *draw_timer;
ALLEGRO_BITMAP *ball_bitmap;
ALLEGRO_BITMAP *bar_bitmap;
ALLEGRO_BITMAP *block_strong_bitmap;
ALLEGRO_BITMAP *block_red_bitmap;
ALLEGRO_BITMAP *block_green_bitmap;
ALLEGRO_BITMAP *block_blue_bitmap;
ALLEGRO_BITMAP *block_orange_bitmap;
ALLEGRO_FONT *font_caption;
ALLEGRO_FONT *font_time;

enum key {left, right};
enum colision{none, horizontal, vertical};
enum angle{no, angle_large, angle_normal};

struct Ball{
    int x;
    int y;
    int x_speed;
    int y_speed;
    int dimension;

};

struct Bar{
    int x;
    int y;
    int speed;
    int width;
    int height;

};

struct Block{
    int x;
    int y;
    int exists;
    int strong;
    int color;

};

int done;
int redraw;
int saving;
int score;
int destroyed_blocks;
int won;
char nick[25], *message;

void game(int level, int winWidth, int winHeight, float run_time);

#endif // GAME_H_INCLUDED
