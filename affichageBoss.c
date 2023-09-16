#include "statique.h"


///AFFICHAGE DU BOSS AINSI QUE SA HITBOX///

void affichageBoss(t_perso *boss,BITMAP *page,BITMAP *hitbox,int xf)
{
    masked_blit(boss->bmp,page,0,0,boss->x,boss->y,SCREEN_W,SCREEN_H);                ///Affichage du boss
    rectfill(hitbox,boss->x,boss->y,boss->x+96,boss->y+41,makecol(255,0,0));             ///hitbox du boss
    rect(page,boss->x-1,boss->y-12,boss->x+120,boss->y-5,makecol(0,0,0));                   ///rectangle autour de la vie du boss
    rectfill(page,boss->x,boss->y-11,boss->x+boss->vie*0.6,boss->y-6,makecol(255,0,0));        /// vie du boss
}
