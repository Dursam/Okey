#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

#include <commun.h>

/**
* \file init_structure.h
* \brief Fichier contenant les fonctions d'initialisation pour les tableaux de structures
* \author Samuel DURAN
* \version 1.0
* \date 12 avril 2020
*/

/**
* \fn void init_tuile(t_tuile * jeu[N_T])
* \brief Initialise le jeu de 106 tuiles 
*/
extern void init_tuile(t_tuile * jeu[N_T]);

/**
* \fn void creer_chevalet(t_tuile * joueur[], int taille)
* \brief Alloue une mémoire dynamique à un chevalet
*/
extern void creer_chevalet(t_tuile * joueur[],int taille);

/**
* \fn void detruire_tuile(t_tuile * jeu[], int taille)
* \brief Libère la mémoire d'une tuile ou de plusieurs tuiles d'un tableau de structure
*/
extern void detruire_tuile(t_tuile * jeu[],int taille);

/**
* \fn void affiche_chaque_tuile(t_tuile * jeu[], int taille)
* \brief Affiche les tuiles une par une
*/
extern void affiche_chaque_tuile(t_tuile * jeu[],int taille);

/**
* \fn int demarrage(t_tuile * jeu[N_T], t_tuile * j1[N_CHEV], t_tuile * j2[N_CHEV], t_tuile * j3[N_CHEV], t_tuile * j4[N_CHEV])
* \brief Donne une tuile au hasard à un des 4 joueurs
*/
extern int demarrage(t_tuile * jeu[N_T], t_tuile * j1[N_CHEV],t_tuile * j2[N_CHEV],t_tuile * j3[N_CHEV],t_tuile * j4[N_CHEV]);

/**
* \fn void distribution_joueur(t_tuile * jeu[N_T], t_tuile * joueur[N_CHEV])
* \brief Distribue 14 tuiles à un joueur
*/
extern void distribution_joueur(t_tuile * jeu[N_T], t_tuile * joueur[N_CHEV]);

/**
* \fn t_tuile distribution_pioche(t_tuile * jeu[N_T])
* \brief Distribue une tuile parmi le jeu des 106 tuiles, au hasard
*/
extern t_tuile distribution_pioche(t_tuile * jeu[N_T]);

/**
* \fn t_tuile * creer_tuile(void);
* \brief Alloue une mémoire dynamique à une tuile
*/
extern t_tuile * creer_tuile(void);

/**
* \fn int taille_tuile(t_tuile * jeu[], int taille_jeu)
* \brief Renvoie la taille des tuiles alloués
*/
extern int taille_tuile(t_tuile * jeu[],int taille_jeu);

#endif
