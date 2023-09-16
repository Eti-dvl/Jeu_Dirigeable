#include "statique.h"

void verificationDiri(BITMAP*hitbox,t_perso *diri,int xf)
{
    int j,k,c,etat=0,degat=0,missile=0;

    for(j=diri->x+xf ; j<diri->x+xf+115 ; j++)      ///On veririfie la hitbox du dirigeable
    {
        for(k=diri->y ; k<diri->y+60 ; k++)
        {
            c=getpixel(hitbox,j,k);
            if(c==makecol(255,0,0))         ///S'il detecte du rouge (pour les ennemis) alors on passe etat à 1
            {
                etat=1;
            }

            if(c==makecol(255,255,0))       ///S'il detecte du jaune (pour les bonus) alors on passe degat à 1
            {
                degat=1;
            }

            if(c==makecol(0,200,0))         ///S'il detecte du vert foncé (pour les missiles du boss) alors on passe missile à 1
            {
                missile=1;
            }
        }
    }

    if(missile==1)      ///Si missile est a 1 alors on retire 20 points de vies au dirigeable
    {
        diri->vie=diri->vie-20;
        missile=0;
    }

    if(etat==1)           ///si etat est à 1 alors on retire 1 point de vie au dirirgeable
    {
        diri->vie=diri->vie-1;
        etat=0;
    }

    if(degat==1)        ///Si degat est a 1 alors on augmente les dégats du dirigeable de 2
    {
        diri->degat=diri->degat+2;
        printf("%d",degat);
        degat=0;
    }


    if(diri->degat==7)      ///Le dirigeable change de forme selon les degats qu'il peut faire
    {
        diri->bmp=load_bitmap("dirigeable2.bmp",NULL);
        if (!diri->bmp)
        {
            allegro_message("pas pu trouver/charger dirigeable2.bmp");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }
    else if(diri->degat==9)
    {
        diri->bmp=load_bitmap("dirigeable3.bmp",NULL);
        if (!diri->bmp)
        {
            allegro_message("pas pu trouver/charger dirigeable3.bmp");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }
    else if(diri->degat==11)
    {
        diri->bmp=load_bitmap("dirigeable4.bmp",NULL);
        if (!diri->bmp)
        {
            allegro_message("pas pu trouver/charger dirigeable4.bmp");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }
    else if(diri->degat==13)
    {
        diri->bmp=load_bitmap("dirigeable5.bmp",NULL);
        if (!diri->bmp)
        {
            allegro_message("pas pu trouver/charger dirigeable5.bmp");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }
}
