#include "save.h"

void save_file(char nick[], int score, int time)
{

        fp = fopen("saves.txt", "a");
        fprintf(fp, "%s    %d in %d seconds\n", nick, score, time);

        fclose(fp);

}

