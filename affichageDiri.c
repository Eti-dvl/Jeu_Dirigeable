#include "statique.h"


///AFFICHAGE DU DIRIGEABLE AINSI QUE SA HITBOX///

void affichageDiri(t_perso *diri,BITMAP *page,BITMAP *hitbox,int xf)
{
    masked_blit(diri->bmp,page,0,0,diri->x+xf,diri->y,SCREEN_W,SCREEN_H);                ///Affichage du dirigeable
    rectfill(hitbox,diri->x+xf,diri->y,diri->x+xf+115,diri->y+60,makecol(0,255,0));             ///hitbox du dirigeable
    rect(page,diri->x+xf-1,diri->y-12,diri->x+xf+120,diri->y-5,makecol(0,0,0));                   ///rectangle autour de la vie du dirigeable
    rectfill(page,diri->x+xf,diri->y-11,diri->x+xf+diri->vie*0.6,diri->y-6,makecol(0,255,0));        /// vie du dirigeable
}
