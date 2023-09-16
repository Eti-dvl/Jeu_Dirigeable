#include "statique.h"

///CREATION DU BOSS///

///Il y a 3 boss différents donc un programme par boss///

t_perso creerBoss()
{
    t_perso boss;

    boss.type='b';      ///Type de personnage b pour boss
    boss.x=2000;        ///Coordonées de départ
    boss.y=250;
    boss.vie=200;       ///Vie du boss
    boss.cmpt=0;        ///compteur de tir du boss
    boss.dx=1;          ///Direction du boss
    boss.dy=1;

    boss.bmp = load_bitmap("boss.bmp",NULL);        ///On charge la bitmap du boss
    if (!boss.bmp)
    {
        allegro_message("pas pu trouver/charger boss.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    return boss;
}
