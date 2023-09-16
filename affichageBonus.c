#include "statique.h"

///AFFICHE LES BONUS AINSI QUE LEUR HITBOX///

void affichageBonus(t_bonus *bonus,BITMAP *page,BITMAP*hitbox)
{
    int i;

    for(i=0; i<5; i++)      ///On parcours les 5 bonus
    {
        if(bonus[i].visible==1)     ///On vérifie s'ils sont bien visibles
        {
            masked_blit(bonus[i].bmp,page,0,0,bonus[i].x,bonus[i].y,SCREEN_W,SCREEN_H);                ///On affiche les bonus sur la page
            rectfill(hitbox,bonus[i].x,bonus[i].y,bonus[i].x+36,bonus[i].y+36,makecol(255,255,0));        ///On crée un rectangle rouge sur la hitbox pour les ennemis
        }
    }
}
