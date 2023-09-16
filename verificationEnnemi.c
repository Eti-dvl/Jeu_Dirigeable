#include "statique.h"

void verificationEnnemi(t_ennemi *avion,BITMAP*hitbox,t_perso *diri,int nbe)
{
    int i;

    for(i=0; i<nbe; i++)
    {
        detection_tir_allie(&avion[i],hitbox,diri);
    }
}
