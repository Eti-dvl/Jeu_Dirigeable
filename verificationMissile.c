#include "statique.h"

void verificationMissile(t_liste *a,int xf,BITMAP*hitbox,t_perso *b)
{
    int i,j,k;

    for (i=0; i<a->maxi; i++)
    {
        if (a->tab[i]!=NULL)
        {
            if(b->type=='d')        ///si c'est un missile du dirigeable
            {
                for(k=a->tab[i]->x ; k<a->tab[i]->x+21 ; k++)
                {
                    for(j=a->tab[i]->y ; j<a->tab[i]->y+13; j++)
                    {
                        if((getpixel(hitbox,k,j)==makecol(255,0,0)))
                        {
                            a->tab[i]->visible=0;
                        }
                    }
                }

                if (a->tab[i]->x+27>SCREEN_W+xf || a->tab[i]->y>SCREEN_H )  ///Il disparait s'il dépasse les bords
                {
                    a->tab[i]->visible=0;
                }

                if (a->tab[i]->visible==0)
                {
                    enleverMissile(a,i);
                }
            }
            else if(b->type=='b')       ///Si c'est un missile du boss
            {
                for(k=a->tab[i]->x+6; k<a->tab[i]->x+21 ; k++)
                {
                    for(j=a->tab[i]->y ; j<a->tab[i]->y+13; j++)
                    {
                        if((getpixel(hitbox,k,j)==makecol(0,255,0)))
                        {
                            a->tab[i]->visible=0;
                        }
                    }
                }

                if (a->tab[i]->x<xf || a->tab[i]->y>SCREEN_H )      ///Il disparait s'il dépasse les bords
                {
                    a->tab[i]->visible=0;
                }

                if (a->tab[i]->visible==0)
                {
                    enleverMissile(a,i);
                }
            }
            else if(b->type=='c')       ///Si c'est un missile du boss2
            {
                for(k=a->tab[i]->x+6; k<a->tab[i]->x+17 ; k++)
                {
                    for(j=a->tab[i]->y ; j<a->tab[i]->y+29; j++)
                    {
                        if((getpixel(hitbox,k,j)==makecol(0,255,0)))
                        {
                            a->tab[i]->visible=0;
                        }
                    }
                }

                if (a->tab[i]->x<xf || a->tab[i]->y>SCREEN_H )      ///Il disparait s'il dépasse les bords
                {
                    a->tab[i]->visible=0;
                }

                if (a->tab[i]->visible==0)
                {
                    enleverMissile(a,i);
                }
            }
        }
    }
}
