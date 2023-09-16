#include "statique.h"

///CREATION DES ENNEMIS///

t_ennemi creerEnnemi()
{
    t_ennemi avion;
    int aleax=rand()%4000+500;      ///coordonées de départ aléatoires
    int aleay=rand()%400;
    avion.x=aleax;
    avion.y=aleay;
    avion.vie=25;       ///Vie d'un avion

    avion.bmp = load_bitmap("avion.bmp",NULL);  ///On charge la bitmap
    if (!avion.bmp)
    {
        allegro_message("pas pu trouver/charger avion.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    return avion;       ///On retourne l'avion qu'on a crée
}
