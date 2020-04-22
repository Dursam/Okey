/**
* \file affichage_tuile.h
* \brief Fichier contenant les fonctions d'affichages
* \author Samuel DURAN
* \version 1.0
* \date 12 avril 2020
*/

#include <init.h>

void detecter_touches(int*running);

void menuServeur(char*ip);

int afficher_menu(char menu[4][30], int taille);

int detecter_mouvement(float*x, float*y);

/**
* \fn void tri_manuel(t_tuile * chevalet[N_CHEV]);
* \brief Tri manuel d'un chevalet de tuiles
*/
void tri_manuel(t_tuile * chevalet[N_CHEV]);

/**
* \fn void tri_rapide(t_tuile * chevalet[], int i, int j);
* \brief Tri rapide d'un chevalet de tuiles
*/
void tri_rapide(t_tuile * chevalet[], int i, int j) ;

/**
* \fn int choix_tri(t_tuile * chevalet[N_CHEV])
* \brief Laisse le choix au joueur de pouvoir faire un tri rapide, un tri manuel ou un pas de tri
*/
int choix_tri(t_tuile * chevalet[N_CHEV]);

/**
* \fn void affiche_chevalet(t_tuile * jeu[], int taille);
* \brief Affichage des 14/15 tuiles du chevalet
*/
void affiche_chevalet(t_tuile * jeu[],int taille);

/**
* \fn void affiche_sommet_pile(t_pile * pile);
* \brief Affichage du sommet d'une pile
*/
void affiche_sommet_pile(t_pile * pile);

/**
* \fn void affiche_plateau(t_tuile * okey, t_pile * pfg, t_pile * pfd, t_pile * pg, t_pile * pd)
* \brief Affichage du sommet des piles de tout les joueurs, valeur du okey et une pioche
*/
void affiche_piles(t_tuile * okey, t_pile * pfg, t_pile * pfd, t_pile * pg, t_pile * pd);
