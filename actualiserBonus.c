#include "statique.h"

///ACTUALISE LE BONUS///

///Ce programme actualise la position du bonus///

void actualiserBonus(t_bonus *bonus)
{
    int i;

    for(i=0; i<5; i++)          ///On vérifie les 5 bonus
    {
        if(bonus[i].visible==1)     ///On verifie que les bonus sont visible
        {
            bonus[i].x=bonus[i].cx+(100*cos(bonus[i].angle));       ///Si oui on actualise leur déplacement
            bonus[i].y=bonus[i].cy-(100*sin(bonus[i].angle));
            bonus[i].angle=bonus[i].angle+0.03;                     ///On augmente l'angle pour la trajectoire circulaire
        }
    }
}
