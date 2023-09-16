#include "statique.h"

///ACTUALISE LES MISSILES///

///Ce programme actualise la position des missiles///

void actualiserListe(t_liste *a)
{
    int i;
    /// actualiser chaque missile
    /// si un missile n'existe plus, l'enlever de la liste
    for (i=0; i<a->maxi; i++)
    {
        if (a->tab[i]!=NULL)
        {
            a->tab[i]->x = a->tab[i]->x+a->tab[i]->dx;      ///On applique les nouvelles coordonées
            a->tab[i]->y = a->tab[i]->y+a->tab[i]->dy;
        }
    }
}
