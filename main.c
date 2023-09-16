#include"statique.h"
#include<allegro.h>
int main()
{
    allegro_init();
    srand(time(NULL));

    BITMAP *page;       ///Le buffer
    BITMAP *fond;       ///Fond du jeu
    BITMAP *fond2;       ///Fond du jeu
    BITMAP *fond3;       ///Fond du jeu
    BITMAP *hitbox;     ///Hitbox
    BITMAP *gameover;   ///Ecran de game over
    BITMAP *victoire;   ///Ecran de victoire
    BITMAP *menu;       ///Ecran de menu
    BITMAP *regles;     ///Ecran de regles
    SAMPLE* piou = load_sample("piou.wav");   ///Bruit de tir
    SAMPLE* theme = load_sample("theme.wav");   ///Theme de l'écran d'accueil

    t_perso diri;
    t_liste *missile;
    t_liste *missile2;
    t_perso boss;
    t_ennemi avion[31];
    t_bonus bonus[6];

    int xf1=0,xf=0,retard1=0,retard=0,cmptir=31;
    int i;
    int fin=0,retour=0;
    int nbe;            ///nombre d'ennemis

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    if(install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL)!=0)
    {
        allegro_message("erreur");
    }
    play_sample(theme, 255, 0, 1000,30);  ///On joue la musique du jeu

    install_keyboard();
    install_mouse();
    show_mouse(screen);

    ///On charge le fond///
    fond=load_bitmap("fond.bmp",NULL);
    if (!fond)
    {
        allegro_message("pas pu trouver/charger fond.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    ///On charge le fond2///
    fond2=load_bitmap("fond2.bmp",NULL);
    if (!fond2)
    {
        allegro_message("pas pu trouver/charger fond2.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    ///On charge le fond3///
    fond3=load_bitmap("fond3.bmp",NULL);
    if (!fond3)
    {
        allegro_message("pas pu trouver/charger fond3.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    ///On charge l'écran de game over///
    gameover=load_bitmap("gameover.bmp",NULL);
    if (!gameover)
    {
        allegro_message("pas pu trouver/charger gameover.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    ///On charge l'écran de game over///
    victoire=load_bitmap("victoire.bmp",NULL);
    if (!victoire)
    {
        allegro_message("pas pu trouver/charger victoire.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    ///On charge la hitbox///
    hitbox=create_bitmap(fond->w*2,fond->h);
    if (!hitbox)
    {
        allegro_message("Pb de creation de hitbox");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    ///On charge le menu///
    menu=load_bitmap("menu.bmp",NULL);
    if (!menu)
    {
        allegro_message("pas pu trouver/charger menu.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    ///On charge les regles///
    regles=load_bitmap("regles.bmp",NULL);
    if (!regles)
    {
        allegro_message("pas pu trouver/charger regles.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    ///On charge le buffer///
    page=create_bitmap(fond->w*3,SCREEN_H);


    while (fin!=1)
    {
        if (mouse_b&1 && mouse_x>=0 && mouse_x<=250 && mouse_y>=310 && mouse_y<=360)  ///REGLES
        {
            while(retour!=1)
            {
                blit(regles,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                if (mouse_b&1 && mouse_x>=620 && mouse_x<=SCREEN_W && mouse_y>=540 && mouse_y<=SCREEN_H)  ///Zone pour retourner au menu
                {
                    retour=1;
                }
            }
        }
        if (mouse_b&1 && mouse_x>=0 && mouse_x<=250 && mouse_y>=361 && mouse_y<=436)  ///NIVEAU 1///
        {
            xf=0;
            retard=0;
            nbe=10;
            ///On charge le dirigable (personnage que l'on controle)///
            diri=creerDirigeable();

            ///On charge le boss ///
            boss=creerBoss();

            ///Creer 10 avions (ennemis)
            for(i=0; i<nbe; i++)
            {
                avion[i]=creerEnnemi();
            }

            ///Creer 5 bonus
            for(i=0; i<5; i++)
            {
                bonus[i]=creerBonus();
                if(i==0)                    ///On place les bonus de maniere homogene pour la beaté du jeu
                    bonus[i].cx=400;
                if(i==1)
                    bonus[i].cx=700;
                if(i==2)
                    bonus[i].cx=1000;
                if(i==3)
                    bonus[i].cx=1300;
                if(i==4)
                    bonus[i].cx=1600;
            }

            ///On crée une liste de de missile
            missile=creerListe(10);       ///missiles diri
            missile2=creerListe(10);      ///missiles Boss

            while(!key[KEY_ESC])
            {
                blit(fond,page,0,0,0,0,fond->w,fond->h);              ///On copie 3 map pour le fond
                blit(fond,page,0,0,fond->w,0,fond->w,fond->h);
                blit(fond,page,0,0,2*fond->w,0,fond->w,fond->h);

                textprintf_ex(page,font,xf+40,20,makecol(0,0,0),-1,"SCORE: %d",diri.score);     ///Affichage du score
                textprintf_ex(hitbox,font,xf+40,20,makecol(255,255,255),-1,"SCORE: %d",diri.score);
                textprintf_ex(page,font,xf+150,20,makecol(0,0,0),-1,"DEGATS: %d",diri.degat);     ///Affichage du score

                affichageBoss(&boss,page,hitbox,xf);
                affichageEnnemi(avion,page,hitbox,nbe);                   ///affichage des ennemis
                verificationMissile(missile,xf,hitbox,&diri);                 ///On vérifie la hitbox des missiles du dirigeable

                affichageDiri(&diri,page,hitbox,xf);                  ///Affichage du dirigeable
                verificationMissile(missile2,xf,hitbox,&boss);                 ///On vérifie la hitbox des missiles du boss

                dessinerListe(page,missile,hitbox,&diri);
                affichageDiri(&diri,page,hitbox,xf);                  ///Affichage du dirigeable
                verificationEnnemi(avion,hitbox,&diri,nbe);                 ///On vérifie la hitbox des ennemis
                verificationBoss(&boss,hitbox,&diri);

                affichageBoss(&boss,page,hitbox,xf);
                affichageBonus(bonus,page,hitbox);                    ///Affichage des bonus
                affichageEnnemi(avion,page,hitbox,nbe);                   ///affichage des ennemis
                dessinerListe(page,missile2,hitbox,&boss);
                verificationDiri(hitbox,&diri,xf);                      ///On vérifie la hitbox du dirigeable

                affichageDiri(&diri,page,hitbox,xf);                  ///Affichage du dirigeable
                verificationBonus(bonus,hitbox,&diri);                  ///On vérifie la hitbox des bonus

                if(diri.vie<0)      ///On vérifie si le dirigeable est en vie
                {
                    blit(gameover,page,0,0,0,0,SCREEN_W,SCREEN_H);
                    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                }
                else if(boss.vie<0)         ///On verifie si le dirigeable est en vie
                {
                    blit(victoire,page,0,0,0,0,SCREEN_W,SCREEN_H);
                    textprintf_ex(page,font,350,530,makecol(0,0,0),-1,"SCORE: %d",diri.score);     ///Affichage du score
                    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                }
                else        ///Sinon on affiche le jeu
                {
                    blit(page,screen,xf,0,0,0,SCREEN_W,SCREEN_H);                     ///Enfin on affiche la page sur le screen
                }

                actualiserEnnemi(avion,nbe);                                   ///actualisation des ennemis
                actualiserDiri(&diri);                                     ///actualisation du dirigeable
                actualiserListe(missile);                             ///actualisation des missiles
                actualiserListe(missile2);
                actualiserBoss(&boss,missile2);
                actualiserBonus(bonus);

                if(key[KEY_SPACE]&&cmptir>=30)      ///Tirer avec le dirigeable si espace et le compteur à 30
                {
                    play_sample(piou, 255, 128, 1000,0);        ///Bruit de tir du dirigeable
                    ajouterMissile(missile,&diri,xf);           ///On ajoute un missile
                    cmptir=0;                                   ///On remet le compteur à 0
                }
                else            ///Sinon on incrémente le competeur de 1
                {
                    cmptir++;
                }

                if(retard==3 && xf!=1500)       ///On incrémente xf de 1 tous les 3 tours de boucle et on stop le scroll quan xf atteint 1500
                {
                    xf++;
                    retard=0;
                }
                else
                {
                    retard++;
                }

                clear_bitmap(page);                                                 ///On raffraichit la page
                clear_bitmap(hitbox);                                               ///On raffraichit la hitbox

                rest(1);
            }
        }
        if (mouse_b&1 && mouse_x>=0 && mouse_x<=250 && mouse_y>=437 && mouse_y<=514)  ///NIVEAU 2///
        {
            xf=0;
            retard=0;
            nbe=15;
            ///On charge le dirigable (personnage que l'on controle)///
            diri=creerDirigeable();

            ///On charge le boss ///
            boss=creerBoss2();

            ///Creer 10 avions (ennemis)
            for(i=0; i<nbe; i++)
            {
                avion[i]=creerEnnemi();
            }

            ///Creer 5 bonus
            for(i=0; i<5; i++)
            {
                bonus[i]=creerBonus();
                if(i==0)
                    bonus[i].cx=400;
                if(i==1)
                    bonus[i].cx=800;
                if(i==2)
                    bonus[i].cx=1200;
                if(i==3)
                    bonus[i].cx=1600;
                if(i==4)
                    bonus[i].cx=2000;
            }

            ///On crée une liste de de missile
            missile=creerListe(10);       ///missiles diri
            missile2=creerListe(10);      ///missiles Boss

            while(!key[KEY_ESC])
            {
                blit(fond2,page,0,0,0,0,fond2->w,fond2->h);              ///On copie 3 map pour le fond
                blit(fond2,page,0,0,fond2->w,0,fond2->w,fond2->h);
                blit(fond2,page,0,0,2*fond2->w,0,fond2->w,fond2->h);

                textprintf_ex(page,font,xf+40,20,makecol(0,0,0),-1,"SCORE: %d",diri.score);     ///Affichage du score
                textprintf_ex(hitbox,font,xf+40,20,makecol(255,255,255),-1,"SCORE: %d",diri.score);
                textprintf_ex(page,font,xf+150,20,makecol(0,0,0),-1,"DEGATS: %d",diri.degat);     ///Affichage du score

                affichageBoss2(&boss,page,hitbox,xf);
                affichageEnnemi(avion,page,hitbox,nbe);                   ///affichage des ennemis
                verificationMissile(missile,xf,hitbox,&diri);                 ///On vérifie la hitbox des missiles du dirigeable

                affichageDiri(&diri,page,hitbox,xf);                  ///Affichage du dirigeable
                verificationMissile(missile2,xf,hitbox,&boss);                 ///On vérifie la hitbox des missiles du boss

                dessinerListe(page,missile,hitbox,&diri);
                affichageDiri(&diri,page,hitbox,xf);                  ///Affichage du dirigeable
                verificationEnnemi(avion,hitbox,&diri,nbe);                 ///On vérifie la hitbox des ennemis
                verificationBoss2(&boss,hitbox,&diri);

                affichageBoss2(&boss,page,hitbox,xf);
                affichageBonus(bonus,page,hitbox);                    ///Affichage des bonus
                affichageEnnemi(avion,page,hitbox,nbe);                   ///affichage des ennemis
                dessinerListe(page,missile2,hitbox,&boss);
                verificationDiri(hitbox,&diri,xf);                      ///On vérifie la hitbox du dirigeable

                affichageDiri(&diri,page,hitbox,xf);                  ///Affichage du dirigeable
                verificationBonus(bonus,hitbox,&diri);                  ///On vérifie la hitbox des bonus

                if(diri.vie<0)      ///On vérifie si le dirigeable est en vie
                {
                    blit(gameover,page,0,0,0,0,SCREEN_W,SCREEN_H);
                    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                }
                else if(boss.vie<0)         ///On verifie si le dirigeable est en vie
                {
                    blit(victoire,page,0,0,0,0,SCREEN_W,SCREEN_H);
                    textprintf_ex(page,font,350,530,makecol(0,0,0),-1,"SCORE: %d",diri.score);     ///Affichage du score
                    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                }
                else        ///Sinon on affiche le jeu
                {
                    blit(page,screen,xf,0,0,0,SCREEN_W,SCREEN_H);                     ///Enfin on affiche la page sur le screen
                }

                actualiserEnnemi(avion,nbe);                                   ///actualisation des ennemis
                actualiserDiri(&diri);                                     ///actualisation du dirigeable
                actualiserListe(missile);                             ///actualisation des missiles
                actualiserListe(missile2);
                actualiserBoss2(&boss,missile2);
                actualiserBonus(bonus);

                if(key[KEY_SPACE]&&cmptir>=30)      ///Tirer avec le dirigeable
                {
                    play_sample(piou, 255, 128, 1000,0);
                    ajouterMissile(missile,&diri,xf);
                    cmptir=0;
                }
                else
                {
                    cmptir++;
                }

                if(retard==2 && xf!=2000)
                {
                    xf++;
                    retard=0;
                }
                else
                {
                    retard++;
                }

                clear_bitmap(page);                                                 ///On raffraichit la page
                clear_bitmap(hitbox);                                               ///On raffraichit la hitbox

                rest(1);
            }
        }
        if (mouse_b&1 && mouse_x>=0 && mouse_x<=250 && mouse_y>=515 && mouse_y<=580)  ///NIVEAU 3///
        {
            xf=0;
            retard=0;
            nbe=25;
            ///On charge le dirigable (personnage que l'on controle)///
            diri=creerDirigeable();

            ///On charge le boss ///
            boss=creerBoss3();

            ///Creer 10 avions (ennemis)
            for(i=0; i<nbe; i++)
            {
                avion[i]=creerEnnemi();
            }

            ///Creer 5 bonus
            for(i=0; i<5; i++)
            {
                bonus[i]=creerBonus();
                if(i==0)
                    bonus[i].cx=500;
                if(i==1)
                    bonus[i].cx=1000;
                if(i==2)
                    bonus[i].cx=1500;
                if(i==3)
                    bonus[i].cx=2000;
                if(i==4)
                    bonus[i].cx=2500;
            }

            ///On crée une liste de de missile
            missile=creerListe(10);       ///missiles diri
            missile2=creerListe(50);      ///missiles Boss

            while(!key[KEY_ESC])
            {
                blit(fond3,page,0,0,0,0,fond3->w,fond3->h);              ///On copie 3 map pour le fond
                blit(fond3,page,0,0,fond3->w,0,fond3->w,fond3->h);
                blit(fond3,page,0,0,2*fond3->w,0,fond3->w,fond3->h);

                textprintf_ex(page,font,xf+40,20,makecol(0,0,0),-1,"SCORE: %d",diri.score);     ///Affichage du score
                textprintf_ex(hitbox,font,xf+40,20,makecol(255,255,255),-1,"SCORE: %d",diri.score);
                textprintf_ex(page,font,xf+150,20,makecol(0,0,0),-1,"DEGATS: %d",diri.degat);     ///Affichage du score

                affichageBoss3(&boss,page,hitbox,xf);
                affichageEnnemi(avion,page,hitbox,nbe);                   ///affichage des ennemis
                verificationMissile(missile,xf,hitbox,&diri);                 ///On vérifie la hitbox des missiles du dirigeable

                affichageDiri(&diri,page,hitbox,xf);                  ///Affichage du dirigeable
                verificationMissile(missile2,xf,hitbox,&boss);                 ///On vérifie la hitbox des missiles du boss

                dessinerListe(page,missile,hitbox,&diri);
                affichageDiri(&diri,page,hitbox,xf);                  ///Affichage du dirigeable
                verificationEnnemi(avion,hitbox,&diri,nbe);                 ///On vérifie la hitbox des ennemis
                verificationBoss3(&boss,hitbox,&diri);

                affichageBoss3(&boss,page,hitbox,xf);
                affichageBonus(bonus,page,hitbox);                    ///Affichage des bonus
                affichageEnnemi(avion,page,hitbox,nbe);                   ///affichage des ennemis
                dessinerListe(page,missile2,hitbox,&boss);
                verificationDiri(hitbox,&diri,xf);                      ///On vérifie la hitbox du dirigeable

                affichageDiri(&diri,page,hitbox,xf);                  ///Affichage du dirigeable
                verificationBonus(bonus,hitbox,&diri);                  ///On vérifie la hitbox des bonus

                if(diri.vie<0)      ///On vérifie si le dirigeable est en vie
                {
                    blit(gameover,page,0,0,0,0,SCREEN_W,SCREEN_H);
                    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                }
                else if(boss.vie<0)         ///On verifie si le dirigeable est en vie
                {
                    blit(victoire,page,0,0,0,0,SCREEN_W,SCREEN_H);
                    textprintf_ex(page,font,350,530,makecol(0,0,0),-1,"SCORE: %d",diri.score);     ///Affichage du score
                    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                }
                else        ///Sinon on affiche le jeu
                {
                    blit(page,screen,xf,0,0,0,SCREEN_W,SCREEN_H);                     ///Enfin on affiche la page sur le screen
                }

                actualiserEnnemi(avion,nbe);                                   ///actualisation des ennemis
                actualiserDiri(&diri);                                     ///actualisation du dirigeable
                actualiserListe(missile);                             ///actualisation des missiles
                actualiserListe(missile2);
                actualiserBoss3(&boss,missile2);
                actualiserBonus(bonus);

                if(key[KEY_SPACE]&&cmptir>=30)      ///Tirer avec le dirigeable
                {
                    play_sample(piou, 255, 128, 1000,0);
                    ajouterMissile(missile,&diri,xf);
                    cmptir=0;
                }
                else
                {
                    cmptir++;
                }

                if(retard==2 && xf!=2500)
                {
                    xf++;
                    retard=0;
                }
                else
                {
                    retard++;
                }

                clear_bitmap(page);                                                 ///On raffraichit la page
                clear_bitmap(hitbox);                                               ///On raffraichit la hitbox

                rest(1);
            }
        }
        if (mouse_b&1 && mouse_x>=600 && mouse_x<=SCREEN_W && mouse_y>=300 && mouse_y<=360)   ///QUITTER
        {
            fin=1;
        }

        mouse_b=0;      ///On reinitialise le clique à 0
        retour=0;       ///On réinitialise retour à 0

        blit(fond,page,0,0,0,0,fond->w,fond->h);              ///On copie 2 map pour le fond du menu
        blit(fond,page,0,0,fond->w,0,fond->w,fond->h);
        masked_blit(menu,page,0,0,xf1,0,SCREEN_W,SCREEN_H);

        blit(page,screen,xf1,0,0,0,SCREEN_W,SCREEN_H);

        if(retard1==3)      ///Scroll infini en fond du menu
        {                   ///retard permet de faire avancer le fond de 1 tous les 3 tours de boucle
            xf1++;      ///On incrémente le fond de 1
            retard1=0;
        }
        else
        {
            retard1++;
        }

        if(xf1>=fond->w)        ///Si on arrive au bout de la premier map alors on retourne au début
        {
            xf1=0;
        }
        rest(1);
    }
    return 0;
}
END_OF_MAIN();
