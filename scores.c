#include "scores.h"

int count_lines(FILE **file)
{
    char line[100];
    int i=0;
    while ( fgets ( line, sizeof line, file ) != NULL )
    {
        i++;
    }
    return i;
}

int show(FILE **file, int i, int winWidth) //show the newest scores using recursion
{
    char line[100];
    if (fgets ( line, sizeof line, file ) != NULL)
    {
        i--;
        show(file, i, winWidth);
    }
    else return 0;
    al_draw_text(font_caption, white, winWidth/10, 80 + i*45, ALLEGRO_ALIGN_LEFT, line);
}

void game_scores(int winWidth, int winHeight)
{
    al_init();
    al_set_new_window_position(100, 100);
    al_set_new_display_flags(ALLEGRO_RESIZABLE | ALLEGRO_WINDOWED );
    al_set_window_title(window_scores, "Arkanoid");

    al_init_font_addon();
    al_init_ttf_addon();


    window_scores = al_create_display(winWidth, winHeight);
    font_caption = al_load_font("fonts/raleway.ttf", 35, 0);


    al_set_target_bitmap(al_get_backbuffer(window_scores));
    al_clear_to_color(grey);


    al_draw_text(font_caption, red, winWidth/10, 20, ALLEGRO_ALIGN_LEFT, "Nick         Score         Time");
    al_flip_display();


    file = fopen ("saves.txt", "r" );
    int i = count_lines(file);
    fclose(file);

    file = fopen ("saves.txt", "r" );
    show(file, i, winWidth); // show scores
    fclose(file);

    al_flip_display();

    done = False;
    while (!done)
        if (keyboard_state() == ALLEGRO_KEY_ESCAPE)
            done = True;




    al_destroy_display(window_scores);

    main();

}
