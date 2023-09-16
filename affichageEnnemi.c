#include "statique.h"

///AFFICHAGE DES ENNEMIS AINSI QUE LEUR HITBOX///

void affichageEnnemi(t_ennemi *avion,BITMAP *page,BITMAP*hitbox,int nbe)
{
    int i;

    for(i=0; i<nbe; i++)        ///On parcours les ennemis du niveau
    {
        if(avion[i].vie>0)
        {
            masked_blit(avion[i].bmp,page,0,0,avion[i].x,avion[i].y,SCREEN_W,SCREEN_H);                ///On affiche l 'avion sur la page
            rectfill(hitbox,avion[i].x,avion[i].y,avion[i].x+47,avion[i].y+34,makecol(255,0,0));        ///On crée un rectangle rouge sur la hitbox pour les ennemis
            rect(page,avion[i].x,avion[i].y-11,avion[i].x+46,avion[i].y-5,makecol(0,0,0));              ///rectangle de vie au dessus de l avion
            rectfill(page,avion[i].x+1,avion[i].y-10,avion[i].x+avion[i].vie*1.8,avion[i].y-6,makecol(255,0,0));      ///vie de l'avion
        }
    }
}
