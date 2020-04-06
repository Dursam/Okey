/* Fichier contenant les fonctions d'initialisation pour les tableaux de strutures */
#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

#include <commun.h>

/* Initialise le jeu de 106 tuiles */
extern void init_tuile(t_tuile * jeu[N_T]);

/* Alloue une mémoire dynamique à un chevalet */
extern void creer_chevalet(t_tuile * joueur[],int taille);

/* Libère la mémoire d'une tuile ou de plusieurs tuiles d'un tableau de structure */
extern void detruire_tuile(t_tuile * jeu[],int taille);

/* Affiche les tuiles une par une */
extern void affiche_chaque_tuile(t_tuile * jeu[],int taille);

/* Donne une tuile au hasard à un des 4 joueurs */
extern int demarrage(t_tuile * jeu[N_T], t_tuile * j1[N_CHEV],t_tuile * j2[N_CHEV],t_tuile * j3[N_CHEV],t_tuile * j4[N_CHEV]);

/* Distribue 14 tuiles à un joueur */
extern void distribution_joueur(t_tuile * jeu[N_T], t_tuile * joueur[N_CHEV]);

/* Distribue une tuile parmi le jeu des 106 tuiles, au hasard */
extern t_tuile distribution_pioche(t_tuile * jeu[N_T]);

/* Alloue une mémoire dynamique à une tuile */
extern t_tuile * creer_tuile(void);

/* Renvoie la taille des tuiles alloués */
extern int taille_tuile(t_tuile * jeu[],int taille_jeu);

#endif
