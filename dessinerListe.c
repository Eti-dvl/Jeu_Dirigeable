#include "statique.h"

///AFFICHE LES MISSILES///

void dessinerListe(BITMAP *bmp,t_liste *a,BITMAP*hitbox,t_perso*b)
{
    int i;

    for (i=0; i<a->maxi; i++)       ///On parcours la liste des missiles
    {
        if (a->tab[i]!=NULL)        ///On verifie si le missile existe
        {
            afficherMissile(bmp,a->tab[i],hitbox,b);    ///On affiche le missile
        }
    }
}
