#include "game.h"

int check_block_collision(int ball_x, int ball_y, int ball_dim, int obj_x, int obj_y, int obj_width, int obj_height)
{

    if ( !( (ball_x >= obj_x + obj_width) || (obj_x >= ball_x + ball_dim) || (ball_y >= obj_y + obj_height) || (obj_y >= ball_y + ball_dim) ) )
    {
        //center point
        int ball_mid_x = ball_x + (ball_dim/2), ball_mid_y = ball_y + (ball_dim/2);
        int obj_mid_x = obj_x + (obj_width/2), obj_mid_y = obj_y + (obj_height/2);

        int distance_x = abs(ball_mid_x - obj_mid_x);
        int distance_y = abs(ball_mid_y - obj_mid_y);

        //collides at the top or bottom
        if (distance_x <= ((ball_dim/2) + (obj_width/2) - 1))
        {
            return horizontal;
        }

        //left or right
        if (distance_y <= ((ball_dim/2) + (obj_height/2) - 1))
        {
            return vertical;
        }
    }

    return 0;
}

int check_bar_collision(int ball_x, int ball_y, int ball_dim, int bar_x, int bar_y, int bar_width, int bar_height)
{
    if (ball_y  + ball_dim >= bar_y)
    {
        //left and right side parts of bar bounces off with larger angle
        if ( (ball_x + ball_dim >= bar_x && ball_x + ball_dim < bar_x + bar_width/5) ||
                (ball_x + ball_dim > bar_x + (bar_width - bar_width/5)) && (ball_x + ball_dim <= bar_x+bar_width) )
                return angle_large;

        else if ( ball_x + ball_dim >= bar_x + bar_width/5 && ball_x + ball_dim <= bar_x +(bar_width - bar_width/5) )
            return angle_normal;
    }

    return 0;
}

void game(int level, int winWidth, int winHeight, float run_time)
{
    al_init();
    window_game = al_create_display(winWidth,winHeight);


    al_install_keyboard();
    int keys[2] = {0, 0}; //keys array left, right

    al_init_image_addon();
    ball_bitmap = al_load_bitmap("images/Ball.png");
    bar_bitmap = al_load_bitmap("images/Bar.png");
    block_strong_bitmap = al_load_bitmap("images/Block-strong.png");
    block_red_bitmap = al_load_bitmap("images/Block-red.png");
    block_blue_bitmap = al_load_bitmap("images/Block-blue.png");
    block_green_bitmap = al_load_bitmap("images/Block-green.png");
    block_orange_bitmap = al_load_bitmap("images/Block-orange.png");


    // events and timing
    eventQueue_game = al_create_event_queue();
    move_timer = al_create_timer(1.0 / (200 + level*50)); // depend on level
    draw_timer = al_create_timer(1.0 / 120);

    al_register_event_source(eventQueue_game, al_get_display_event_source(window_game));
    al_register_event_source(eventQueue_game, al_get_timer_event_source(move_timer));
    al_register_event_source(eventQueue_game, al_get_timer_event_source(draw_timer));
    al_register_event_source(eventQueue_game, al_get_keyboard_event_source());


    al_start_timer(move_timer);
    al_start_timer(draw_timer);
    font_time = al_load_font("fonts/raleway.ttf", 30, 0);

    struct Ball ball;
    ball.x = winWidth/2;
    ball.y = winHeight/2;
    ball.x_speed = 1;
    ball.y_speed = 1;
    ball.dimension = 24;


    struct Bar bar;
    bar.x = winWidth/2;
    bar.y = winHeight - 40;
    bar.speed = 1 + level;
    bar.width = 200;
    bar.height = 20;

    al_draw_bitmap(bar_bitmap, winWidth/2, winHeight + 50, 0);

    struct Block block[COLS][ROWS];

    switch( level )
    {
    case 0:
        make_blocks_easy(block); break;
    case 1:
        make_blocks_medium(block); break;
    case 2:
        make_blocks_hard(block); break;
    }
    destroyed_blocks = 0;


    score = 0;
    redraw = False;
    done = False;
    won = False;
    srand(time(NULL));
    while(!done)
    {
        al_wait_for_event(eventQueue_game, &event_game);

        if (event_game.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = True;
        }
        if (event_game.type == ALLEGRO_EVENT_KEY_DOWN) //bar controller
        {
            switch(event_game.keyboard.keycode)
            {
            case ALLEGRO_KEY_LEFT:
                keys[left] = True; break;
            case ALLEGRO_KEY_RIGHT:
                keys[right] = True; break;
            }
        }
        else if (event_game.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (event_game.keyboard.keycode)
			{

				case ALLEGRO_KEY_LEFT:
					keys[left] = False; break;
                case ALLEGRO_KEY_RIGHT:
					keys[right] = False; break;
				case ALLEGRO_KEY_ESCAPE:
					done = True; break;
			}
		}
        if (event_game.type == ALLEGRO_EVENT_TIMER)
        {
            if (event_game.timer.source == move_timer)
            {

                ball.x += ball.x_speed;
                ball.y += ball.y_speed;

                int change_dir = True;
                int i = 0;
                for(i; i<COLS; i++)
                {
                    int j = 0;
                    for(j; j<ROWS; j++)
                    {
                        if (block[i][j].exists)
                        {
                            int collision = check_block_collision(ball.x, ball.y, ball.dimension, block[i][j].x, block[i][j].y, 76, 30);
                            if (collision == horizontal)
                            {
                                if (change_dir)
                                   {
                                        ball.y_speed *= -1;
                                   }
                                if (!block[i][j].strong)
                                    {
                                        block[i][j].exists = False;
                                        score += 20 + level*5;
                                        destroyed_blocks++;
                                        change_dir = False;
                                    }
                                else
                                {
                                    block[i][j].strong = False;
                                    block[i][j].color = (rand() % 4) + 1;
                                    change_dir = False;
                                }

                            }
                            else if (collision == vertical)
                            {
                                if (change_dir)
                                {
                                    ball.x_speed *= -1;
                                }


                                if (!block[i][j].strong)
                                    {
                                        block[i][j].exists =False;
                                        score += 20 + level*5;
                                        destroyed_blocks++;
                                        change_dir = False;
                                    }
                                else
                                {
                                    block[i][j].strong = False;
                                    block[i][j].color = (rand()%4) +1;
                                }
                            }
                        }
                    }
                }
                if (destroyed_blocks == COLS * ROWS)
                {
                    won = True;
                    done = True;
                }
                int bar_collision = check_bar_collision(ball.x, ball.y, ball.dimension, bar.x, bar.y, bar.width, bar.height );
                if (bar_collision == angle_normal)
                {
                   ball.y_speed *= -1;
                   if (abs(ball.y_speed) != 2)  ball.y_speed *= 2;
                   if( abs(ball.x_speed) != 1) ball.x_speed /= 2;
                }
                else if (bar_collision == angle_large)
                {

                    if (abs(ball.y_speed) != 1)
                    {
                        if( ball.y_speed > 1) ball.y_speed = 1;
                        else ball.y_speed = -1;
                    }
                    ball.y_speed *= -1;

                    if (abs(ball.x_speed) != 2) ball.x_speed *= 2;

                }

                if (ball.x <= 0) //left edge
                {
                    ball.x_speed *= -1;
                }
                else if (ball.x+ball.dimension >= winWidth) //right edge
                {
                    ball.x_speed *= -1;
                }
                else if (ball.y <= 50) // top edge (under timer)
                    ball.y_speed *= -1;

                else if (ball.y+ball.dimension >= winHeight) //bottom edge
                    done = True;
            }

            if (event_game.timer.source == draw_timer)
                redraw = True;
        }

		if (bar.x + bar.width < winWidth)
            bar.x += keys[right] * 1;
        if (bar.x > 0 )
            bar.x -= keys[left] *1;

        if ((redraw) && (al_is_event_queue_empty(eventQueue_game)))
        {
            redraw = False;

            al_clear_to_color(grey);
            al_draw_textf(font_time, white, 20, 10, ALLEGRO_ALIGN_LEFT, "Time : %i", (int)al_current_time() - (int)run_time);
            al_draw_bitmap(ball_bitmap, ball.x, ball.y, 0);
            al_draw_bitmap(bar_bitmap, bar.x, bar.y, 0);
            draw_blocks(block);
            al_flip_display();
        }



    }

    font_caption = al_load_font("fonts/FFF_Tusj.ttf", 60, 0);
    if (won)
        message = "Congratulations, You won!";
    else
        message = "Game Over";


        al_clear_to_color(grey);

        al_draw_text(font_caption, white, winWidth/2, winHeight/3, ALLEGRO_ALIGN_CENTER, message);
        al_draw_textf(font_caption, white, winWidth/2, winHeight/2, ALLEGRO_ALIGN_CENTER, "Your score : %i in %i seconds", score, (int)al_current_time() - (int)run_time);

        al_flip_display();

        printf("What's your nick? \n");
        scanf("%s", nick);
        al_rest(1.5);


        save_file(nick, score, (int)al_current_time() - (int)run_time);


        al_clear_to_color(grey);
        al_draw_text(font_caption, white, winWidth/2, winHeight/3, ALLEGRO_ALIGN_CENTER, "Score saved!");
        al_flip_display();
        al_rest(1.5);


    al_destroy_display(window_game);

    main();

}
