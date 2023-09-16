#include "statique.h"

///CREER UN BONUS///

t_bonus creerBonus()
{
    t_bonus bonus;
    int aleax=rand()%2000+500;      ///On cree des coordonnées aléatoires
    int aleay=rand()%350+100;

    bonus.cx=aleax;         ///coordonnées du centre du bonus
    bonus.cy=aleay;
    bonus.angle=0;          ///Angle de la trajectoire du bonus
    bonus.visible=1;        ///le bonus est visible

    bonus.bmp = load_bitmap("bonus.bmp",NULL);      ///On charge la bitmap du bonus
    if (!bonus.bmp)
    {
        allegro_message("pas pu trouver/charger bonus.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    return bonus;
}
