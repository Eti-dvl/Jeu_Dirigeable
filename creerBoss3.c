#include "statique.h"

///CREATION DU BOSS///

///meme principe que creerBoss///

t_perso creerBoss3()
{
    t_perso boss;

    boss.type='b';
    boss.x=3000;
    boss.y=250;
    boss.vie=600;
    boss.cmpt=0;
    boss.dx=1;
    boss.dy=1;

    boss.bmp = load_bitmap("boss3.bmp",NULL);
    if (!boss.bmp)
    {
        allegro_message("pas pu trouver/charger boss3.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    return boss;
}
