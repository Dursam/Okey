/* Fichier contenant les fonctions pour selectionner une tuile */

#ifndef _SELECTION_H_
#define _SELECTION_H_

#include <commun.h>

/* Initialise un tableau de struture de tuile pour enregistrer les tuiles qui seront empilés */
extern void init_enr_tuile(t_tuile * enr[],int taille);

/* Creer une tuile, lui affecte une valeur puis l'empile sur une pile */
extern void test_enr_tuile(t_tuile * jeu[N_T],t_tuile * enr[],t_pile * pile,int taille);

/* Creer une tuile, lui affecte une valeur puis l'empile sur une pile */
extern void empile_enr_tuile(t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pile,int taille,int numero);

/* Permet de sélection une tuile soit de la pioche ou de la pile de gauche et retire une tuile du chevalet, version avec affiche_pile */
extern void selection_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd);

#endif
