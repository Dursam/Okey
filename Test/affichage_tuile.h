/* Fichier contenant les fonctions d'affichages */

#ifndef _AFFICHAGE_H_
#define _AFFICHAGE_H_

#include <commun.h>

/* Affichage des 14/15 tuiles du chevalet */
extern void affiche_chevalet(t_tuile * jeu[],int taille);

/* Affichage du sommet d'une pile */
extern void affiche_sommet_pile(t_pile * pile);

/* Affichage du sommet des piles de tout les joueurs */
extern void affiche_pile(t_pile * p1,t_pile * p2,t_pile * p3,t_pile * p4);

#endif
