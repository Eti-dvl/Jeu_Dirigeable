#ifndef STATIQUE_H_INCLUDED
#define STATIQUE_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<allegro.h>
#include<math.h>

typedef struct bonus
{
    int x,y,cx,cy;
    float angle;
    int visible;
    BITMAP *bmp;
}t_bonus;

typedef struct missile
{
    int x,y;
    int dx,dy;
    int visible;
    BITMAP *bmp;
}t_missile;

typedef struct perso
{
    char type;
    int x,y;
    int dx,dy;
    int score;
    int vie;
    int cmpt;
    int degat;
    BITMAP *bmp;
}t_perso;


typedef struct listeStatique
{
    int maxi;
    int n;
    t_missile **tab;
}t_liste;

typedef struct ennemi
{
    int x,y;
    int dx,dy;
    int vie;
    int tir;
    BITMAP *bmp;
}t_ennemi;



t_missile *ajouterMissile(t_liste *a,t_perso *b,int xf);
t_liste *creerListe(int maxi);
t_perso creerDirigeable();
t_ennemi creerEnnemi();
t_missile *creer(t_perso *b,int xf);
t_bonus creerBonus();
t_perso creerBoss();
t_perso creerBoss2();
t_perso creerBoss3();

void actualiserDiri(t_perso *diri);
void actualiser(t_missile *missile,BITMAP*hitbox,int xf);
void actualiserListe(t_liste *a);
void actualiserEnnemi(t_ennemi *avion,int nbe);
void enleverMissile(t_liste*a,int i);
void detection_tir_allie(t_ennemi*avion,BITMAP*hitbox,t_perso *diri);
void actualiserBonus(t_bonus *bonus);
void actualiserBoss(t_perso *boss,t_liste *a);
void actualiserBoss2(t_perso *boss,t_liste *a);
void actualiserBoss3(t_perso *boss,t_liste *a);

void verificationDiri(BITMAP*hitbox,t_perso *diri,int xf);
void verificationMissile(t_liste *a,int xf,BITMAP*hitbox,t_perso *b);
void verificationEnnemi(t_ennemi *avion,BITMAP*hitbox,t_perso *diri,int nbe);
void verificationBonus(t_bonus *bonus,BITMAP*hitbox,t_perso *diri);
void verificationBoss(t_perso *boss,BITMAP*hitbox,t_perso *diri);
void verificationBoss2(t_perso *boss,BITMAP*hitbox,t_perso *diri);
void verificationBoss3(t_perso *boss,BITMAP*hitbox,t_perso *diri);

void affichageEnnemi(t_ennemi *avion,BITMAP *page,BITMAP*hitbox,int nbe);
void affichageDiri(t_perso *diri,BITMAP *page,BITMAP *hitbox,int xf);
void dessinerListe(BITMAP *bmp,t_liste *a,BITMAP*hitbox,t_perso*b);
void afficherMissile(BITMAP*page,t_missile *missile,BITMAP*hitbox,t_perso *b);
void affichageBonus(t_bonus *bonus,BITMAP *page,BITMAP*hitbox);
void affichageBoss(t_perso *boss,BITMAP *page,BITMAP *hitbox,int xf);
void affichageBoss2(t_perso *boss,BITMAP *page,BITMAP *hitbox,int xf);
void affichageBoss3(t_perso *boss,BITMAP *page,BITMAP *hitbox,int xf);


#endif // STATIQUE_H_INCLUDED
