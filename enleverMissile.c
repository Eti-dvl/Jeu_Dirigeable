#include "statique.h"

void enleverMissile(t_liste*a,int i)
{
    /// V�rifier qu'il y a bien un acteur accroch� en indice i
    if (a->tab[i]!=NULL)
    {
        /// lib�rer la m�moire du acteur
        free(a->tab[i]);

        /// marquer l'emplacement comme libre
        a->tab[i]=NULL;
        a->n--;
    }
}
