#include "statique.h"

///ACTUALISE LE DIRIGEABLE///

///Ce programme actualise la position du dirigeable///

void actualiserDiri(t_perso *diri)              ///le dirigeable va se déplacer se les touches utilisées
{
    if((key[KEY_DOWN])&&(diri->y<528))        ///blindage du déplacement du dirigeable pour qu'il ne dépasse pas le screen
    {
        diri->y=diri->y+2;          ///Si fleche du bas alors le dirigeable descend de 2 pixels
    }
    if ((key[KEY_UP])&&(diri->y>0))
    {
        diri->y=diri->y-2;      ///Si fleche du haut alors le dirigeable monte de 2 pixels
    }
    if((key[KEY_LEFT])&&((diri->x)>0))
    {
        diri->x=diri->x-2;          ///Si fleche de gauche alors le dirigeable se déplace de 2 pixels vers la gauche
    }
    if((key[KEY_RIGHT])&&((diri->x)<670))
    {
        diri->x=diri->x+2;        ///Si fleche de droite alors le dirigeable se déplace de 2 pixels vers la droite
    }
}
