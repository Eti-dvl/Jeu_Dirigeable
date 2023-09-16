#include "statique.h"

void enleverMissile(t_liste*a,int i)
{
    /// Vérifier qu'il y a bien un acteur accroché en indice i
    if (a->tab[i]!=NULL)
    {
        /// libérer la mémoire du acteur
        free(a->tab[i]);

        /// marquer l'emplacement comme libre
        a->tab[i]=NULL;
        a->n--;
    }
}
