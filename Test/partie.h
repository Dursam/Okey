/* Fichier contenant les fonctions principaux pour lancer une partie de Okey */

#ifndef _PARTIE_H_
#define _PARTIE_H_

#include <commun.h>

/* Donne une valeur + 1 de la tuile retournée (le okey) à la tuile joker rouge ou noire posséder par le joueur */
extern void valeur_okey(t_tuile * okey,t_tuile * joker);

/* Affichage du sommet des piles de tout les joueurs */
extern void affiche_plateau(t_tuile * okey,t_pile * p1,t_pile * p2,t_pile * p3,t_pile * p4);

/* Début de partie en fonction de la tuile de démarrage */
extern void debut_partie(t_tuile * chevalet[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int dem);

/* Dépile toutes les piles de tuiles, utilisé pour finir la partie */
extern void depiler_toutes_tuiles(t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4);

#endif
