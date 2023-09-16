#include "statique.h"

void verificationBonus(t_bonus *bonus,BITMAP*hitbox,t_perso *diri)
{
    int i,j,k;
    int touche=0;

    for(i=0; i<5; i++)
    {
        if(bonus[i].visible==1)
        {
            for(j=bonus[i].x ; j<bonus[i].x+36; j++)
            {
                for(k=bonus[i].y ; k<bonus[i].y+36 ; k++)
                {
                    if(getpixel(hitbox,j,k)==makecol(0,255,0))
                    {
                        touche=1;
                        //printf("%d",touche);
                    }
                }
            }
            if(touche==1)
            {
                printf("%d",touche);
                bonus[i].visible=0;
                touche=0;
            }
        }
    }
}
