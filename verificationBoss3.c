#include "statique.h"

void verificationBoss3(t_perso *boss,BITMAP*hitbox,t_perso *diri)
{
    int i,j,c;
    int touche=0;

    for(j=boss->x; j<boss->x+93; j++)
    {
        for(i=boss->y; i<boss->y+55; i++)         	///vérification de la hitbox du missile
        {
            c=getpixel(hitbox,j,i);
            if(c==makecol(0,0,255))
            {
                touche=1;                               ///s'il détecte une couleur bleue alors touche =1
            }
        }
    }

    if(boss->vie>0 && touche==1)                    	///si l'boss est touché alors on retire de la vie et on augmente le score
    {
        boss->vie=boss->vie-diri->degat;
        diri->score=diri->score+15;
    }
}
