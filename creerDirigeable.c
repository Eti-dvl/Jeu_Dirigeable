#include "statique.h"

///CREATION DU DIRIGEABLE///

t_perso creerDirigeable()
{
    t_perso diri;

    diri.type='d';      /// On indique le type du perso
    diri.x=20;          /// Coordonées de départ
    diri.y=280;
    diri.vie=200;       ///Vie du dirigeable
    diri.degat=5;       ///Dégats de base du dirigeable
    diri.score=0;       ///On initialise le score à 0

    diri.bmp=load_bitmap("dirigeable.bmp",NULL);        ///On charge la bitmap
    if (!diri.bmp)
    {
        allegro_message("pas pu trouver/charger dirigeable.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    return diri;
}
