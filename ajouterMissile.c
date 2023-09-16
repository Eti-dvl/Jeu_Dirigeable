#include "statique.h"

///AJOUTE UN MISSILE A LA LISTE///

t_missile *ajouterMissile(t_liste *a,t_perso*b,int xf)
{
    int i;
    t_missile *missile;

    /// Liste pleine, on alloue rien et on retourne NULL...
    if (a->n >= a->maxi)
    {
        return NULL;
    }
    /// Allouer un acteur initialis�
    missile=creer(b,xf);

    /// Chercher un emplacement libre
    i=0;
    while (a->tab[i]!=NULL && i<a->maxi)
    {
        i++;
    }
    /// Si on a trouv� ...
    /// (normalement oui car on a v�rifi� n<max)
    if (i<a->maxi)
    {
        a->tab[i]=missile;
        a->n++;
    }
    /// Sinon c'est qu'il y a un probl�me de coh�rence
    else
    {
        allegro_message("Anomalie gestion ajouterActeur : liste corrompue");
    }

    return missile;
}
