#ifndef _AFFICHAGE_H_
#define _AFFICHAGE_H_

#include <commun.h>

/** 
* \file affichage_tuile.h
* \brief Fichier contenant les fonctions d'affichages
* \author Samuel DURAN
* \version 1.0
* \date 12 avril 2020
*/

/**
* \fn void affiche_chevalet(t_tuile * jeu[], int taille);
* \brief Affichage des 14/15 tuiles du chevalet
*/
extern void affiche_chevalet(t_tuile * jeu[],int taille);

/**
* \fn void affiche_sommet_pile(t_pile * pile);
* \brief Affichage du sommet d'une pile 
*/
extern void affiche_sommet_pile(t_pile * pile);

/** 
* \fn void affiche_pile(t_pile * p1, t_pile * p2, t_pile p3, t_pile * p4);
* \brief Affichage du sommet des piles de tout les joueurs
*/
extern void affiche_pile(t_pile * p1,t_pile * p2,t_pile * p3,t_pile * p4);

/**
* \fn void tri_manuel(t_tuile * chevalet[N_CHEV]);
* \brief Tri manuel d'un chevalet de tuiles 
*/
extern void tri_manuel(t_tuile * chevalet[N_CHEV]);

/**
* \fn void tri_rapide(t_tuile * chevalet[], int i, int j);
* \brief Tri rapide d'un chevalet de tuiles
*/
extern void tri_rapide(t_tuile * chevalet[], int i, int j) ;

#endif
