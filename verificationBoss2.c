#include "statique.h"

void verificationBoss2(t_perso *boss,BITMAP*hitbox,t_perso *diri)
{
    int i,j,c;
    int touche=0;

    for(j=boss->x; j<boss->x+71; j++)
    {
        for(i=boss->y; i<boss->y+128; i++)         	///v�rification de la hitbox du missile
        {
            c=getpixel(hitbox,j,i);
            if(c==makecol(0,0,255))
            {
                touche=1;                               ///s'il d�tecte une couleur bleue alors touche =1
            }
        }
    }

    if(boss->vie>0 && touche==1)                    	///si l'boss est touch� alors on retire de la vie et on augmente le score
    {
        boss->vie=boss->vie-diri->degat;
        diri->score=diri->score+15;
    }
}
