#include "main.h"

int main()
{
    winWidth = 1024;
    winHeight = 668;
    done = False;
    menu_option = 1;

    //menu pointer
    pointer_x = winWidth/20;
    pointer_y = 335;


    init_window_menu();
    create_menu(winWidth, winHeight);

    while (!done)
    {
        pointer_on(pointer_x, pointer_y);
        al_flip_display();
        switch (keyboard_state())
        {

        case ALLEGRO_KEY_ESCAPE:
            done = True; break;

        case ALLEGRO_KEY_UP:
            if (pointer_y>335)
            {
            pointer_off(pointer_x, pointer_y);
            pointer_y -= 75;
            menu_option--; break;
            }
            else break;


        case ALLEGRO_KEY_DOWN:
            if (pointer_y<635)
            {
            pointer_off(pointer_x, pointer_y);
            pointer_y += 75;
            menu_option++; break;
            }
            else break;

        case ALLEGRO_KEY_ENTER:
            switch (menu_option)
                {
                case 1:
                    al_destroy_display(window_menu);
                    game(easy, winWidth, winHeight, al_current_time()); break;
                case 2:
                    al_destroy_display(window_menu);
                    game(medium, winWidth, winHeight, al_current_time()); break;
                case 3:
                    al_destroy_display(window_menu);
                    game(hard, winWidth, winHeight, al_current_time()); break;
                case 4:
                    al_destroy_display(window_menu);
                    game_scores(winWidth, winHeight);
                case 5:
                    done = True; break;
                }
        }
    }
    al_destroy_display(window_menu);
}
