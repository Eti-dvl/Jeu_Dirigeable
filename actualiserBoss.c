#include "statique.h"

///ACTUALISE LE BOSS///

///Ce programme actualise la position du boss///

void actualiserBoss(t_perso *boss,t_liste* a)
{
    int xf=0;
    if(boss->vie>0)         ///On vérifie si le boss est en vie
    {
        if(boss->cmpt<100)      ///Le boss se déplace de maniere homogene tous les 100 pixels
        {
            if(boss->x>2200)        ///On determine des limites que le boss ne doit pas dépasser
            {
                boss->dx=-1;
            }
            if(boss->x<1800)
            {
                boss->dx=1;
            }
            if(boss->y<50)
            {
                boss->dy=1;
            }
            if(boss->y>400)
            {
                boss->dy=-1;
            }
            boss->x=boss->x+boss->dx;       ///On applique le déplacement au boss
            boss->y=boss->y+boss->dy;
            boss->cmpt++;                   ///On incrémente le compteur de 1
        }
        else        ///Le boss tire 1 fois sur que le compteur arrive a 100
        {
            ajouterMissile(a,boss,xf);      ///Le boss tire un missile
            boss->cmpt=0;                   ///On rénéitialise le compteur à 0
            boss->dx=rand()%3-1;           ///déplacement aléatoire du boss selon l'axe x
            boss->dy=rand()%3-1;           ///déplacement aléatoire du boss selon l'axe y
        }
    }
}
