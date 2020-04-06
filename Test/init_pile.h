/* Fichier contenant les fonctions d'initialisation pour les piles */
#ifndef _PILE_H_
#define _PILE_H_

#include <commun.h>

/* Initialise la pile */
extern void init_pile(t_pile * pile);

/* Vérifie si la pile est vide */
extern int pile_vide(t_pile * pile);

/* Empile une tuile de la pile */
extern void empiler(t_pile * pile,t_tuile * t);

/* Retire une tuile de la pile */
extern void depiler(t_pile * pile);

/* Récupère la tuile du sommet de la pile */
extern void sommet_pile(t_pile * pile,t_tuile ** c);

/* Compte le nombre d'élément d'une tuile */
extern int compte_element(t_pile * pile);

#endif
