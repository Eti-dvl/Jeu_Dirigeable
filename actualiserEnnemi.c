#include "statique.h"

///ACTUALISE LES ENNEMIS///

///Ce programme actualise la position des ennemis///

void actualiserEnnemi(t_ennemi *avion, int nbe)
{
    int i;
    int aleax,aleay;

    for(i=0; i<nbe; i++)            ///On parcours le nombre d'ennemis du niveau
    {
        if(avion[i].vie>0)          ///Si l'ennemi est vivant alors on peut l'actualiser
        {
            aleax=rand()%2-1;           ///déplacement aléatoire des ennemis selon l'axe x des ennemis
            aleay=rand()%3-1;           ///déplacement aléatoire des ennemis selon l'axe y des ennemis

            if(avion[i].y<0)            ///On blinde pour que les ennemis ne dépassent pas le screen
            {
                avion[i].y = avion[i].y+3;
            }
            else if(avion[i].y>SCREEN_H-200)
            {
                avion[i].y = avion[i].y-3;
            }
            else                    ///Si les coordonées ne depassent pas le screen alors les ennemis se déplassent aléatoirement
            {
                avion[i].x = avion[i].x+aleax;
                avion[i].y = avion[i].y+aleay;
            }

        }
    }
}
