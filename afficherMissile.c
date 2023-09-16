#include "statique.h"

///AFFICHAGE DES MISSILES ET DE LEUR HITBOX

void afficherMissile(BITMAP*page,t_missile *missile,BITMAP*hitbox,t_perso *b)
{
    masked_blit(missile->bmp,page,0,0,missile->x,missile->y,SCREEN_W,SCREEN_H);
    if(b->type=='d')        ///Si c est un missile du dirigeable
    {
        rectfill(hitbox,missile->x,missile->y,missile->x+26,missile->y+13,makecol(0,0,255));  ///hitbox du missile
    }
    else if(b->type=='b')       ///Si c est un missile du boss 1 ou 3
    {
        rectfill(hitbox,missile->x,missile->y,missile->x+26,missile->y+13,makecol(0,200,0));  ///hitbox du missile
    }
    else if(b->type=='c')       ///Si c est un missile du boss 2
    {
        rectfill(hitbox,missile->x,missile->y,missile->x+17,missile->y+30,makecol(0,200,0));  ///hitbox du missile
    }
}
