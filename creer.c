#include "statique.h"

///CREER UN MISSILE///

t_missile *creer(t_perso *b,int xf)   ///On crée un nouveau missile
{
    t_missile *nouv;
    nouv=(t_missile *)malloc(sizeof(t_missile));        ///On alloue dynamique de la place pour le missile


    if(b->type=='d')        ///On verifie le type -> d pour dirigeable
    {
        nouv->x=b->x+60+xf;     ///position de création
        nouv->y=b->y+30;
        nouv->dx=5;         ///direction du missile
        nouv->dy=0;
        nouv->bmp = load_bitmap("missile.bmp",NULL);        ///On charge la bitmap
        if (!nouv->bmp)
        {
            allegro_message("pas pu trouver/charger missile.bmp");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    if(b->type=='b')        ///On verifie le type -> b pour boss 1 ou 3
    {
        nouv->x=b->x+60+xf;
        nouv->y=b->y+30;
        nouv->dx=(-5);
        nouv->dy=0;
        nouv->bmp = load_bitmap("missile2.bmp",NULL);
        if (!nouv->bmp)
        {
            allegro_message("pas pu trouver/charger missile2.bmp");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    if(b->type=='c')        ///On verifie le type -> c pour boss 2
    {
        nouv->x=b->x+27+xf;
        nouv->y=b->y+50;
        nouv->dx=0;
        nouv->dy=3;
        nouv->bmp = load_bitmap("missile3.bmp",NULL);
        if (!nouv->bmp)
        {
            allegro_message("pas pu trouver/charger missile3.bmp");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }

    nouv->visible=1;

    return nouv;
}
