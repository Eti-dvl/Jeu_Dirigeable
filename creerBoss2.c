#include "statique.h"

///CREATION DU BOSS///

///meme principe que creerBoss///

t_perso creerBoss2()
{
    t_perso boss;

    boss.type='c';  ///c pour le boss n*2
    boss.x=2500;
    boss.y=150;
    boss.vie=400;
    boss.cmpt=0;
    boss.dx=1;
    boss.dy=1;

    boss.bmp = load_bitmap("boss2.bmp",NULL);
    if (!boss.bmp)
    {
        allegro_message("pas pu trouver/charger boss2.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    return boss;
}
