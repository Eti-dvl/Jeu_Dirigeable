#include "statique.h"

///CREER UNE LISTE DE MISSILES///

t_liste * creerListe(int maxi)
{
    t_liste *nouv;
    int i;

    nouv=(t_liste*)malloc(sizeof(t_liste));

    nouv->maxi=maxi;
    nouv->n=0;
    nouv->tab=(t_missile**)malloc(maxi*sizeof(t_missile*));

    for (i=0; i<maxi; i++)
    {
        nouv->tab[i]=NULL;
    }

    return nouv;
}
