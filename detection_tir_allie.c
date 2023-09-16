#include "statique.h"

void detection_tir_allie(t_ennemi*avion,BITMAP*hitbox,t_perso *diri)
{
    int i,j,c;
    int touche=0;

    for(j=avion->x; j<avion->x+46; j++)
    {
        for(i=avion->y; i<avion->y+33; i++)         	///vérification de la hitbox du missile
        {
            c=getpixel(hitbox,j,i);
            if(c==makecol(0,0,255))
            {
                touche=1;                               ///s'il détecte une couleur bleue alors touche =1
            }
        }
    }

    if(avion->vie>0 && touche==1)                    	///si l'avion est touché alors on retire de la vie et on augmente le score
    {
        avion->vie=avion->vie-diri->degat;
        diri->score=diri->score+15;
    }

    touche=0;
}
