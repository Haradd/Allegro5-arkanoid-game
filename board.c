#include "board.h"


void make_blocks_easy(struct Block block[13][10])
{
    srand(time(NULL));
    int i = 0;
    for(i; i<13; i++)
    {
        int j = 0;
        for(j; j<7; j++)
        {
            block[i][j].x = 20 + (i*76);
            block[i][j].y = 50 + (j*30);
            block[i][j].exists = True;
            block[i][j].strong = False;

            block[i][j].color = (rand()%4) +1;
        }
    }

}

void make_blocks_medium(struct Block block[13][10])
{
    srand(time(NULL));
    int i = 0;
    for(i; i<13; i++)
    {
        int j = 0;
        for(j; j<7; j++)
        {
            block[i][j].x = 20 + (i*76);
            block[i][j].y = 50 + (j*30);
            block[i][j].exists = True;
            block[i][j].strong = False;

            block[i][j].color = (rand()%4) +1;
        }
    }
    i = 0;
    for(i; i<13; i+=4)
    {
        int j = 0;
        for(j; j<7; j+=3)
        {
            block[i][j].strong = True;
            block[i][j].color = 0;
        }

    }
}

void make_blocks_hard(struct Block block[13][10])
{
    srand(time(NULL));
    int i = 0;
    for(i; i<13; i++)
    {
        int j = 0;
        for(j; j<7; j++)
        {
            block[i][j].x = 20 + (i*76);
            block[i][j].y = 50 + (j*30);
            block[i][j].exists = True;
            block[i][j].strong = True;

            block[i][j].color = 0;
        }
    }
    i = 0;
    for(i; i<13; i+=4)
    {
        int j = 0;
        for(j; j<7; j+=3)
        {
            block[i][j].strong = False;
            block[i][j].color = (rand()%4) +1;
        }

    }
}
void draw_blocks(struct Block block[13][10])
{
    int i = 0;
    for(i; i<13; i++)
    {
        int j = 0;
        for(j; j<7; j++)
        {
            if (block[i][j].exists)
            {
                switch (block[i][j].color)
                {
                    case 0: al_draw_bitmap(block_strong_bitmap, block[i][j].x, block[i][j].y, 0); break;
                    case 1: al_draw_bitmap(block_red_bitmap, block[i][j].x, block[i][j].y, 0); break;
                    case 2: al_draw_bitmap(block_green_bitmap, block[i][j].x, block[i][j].y, 0); break;
                    case 3: al_draw_bitmap(block_blue_bitmap, block[i][j].x, block[i][j].y, 0); break;
                    case 4: al_draw_bitmap(block_orange_bitmap, block[i][j].x, block[i][j].y, 0); break;


                }
            }

        }
    }

}
