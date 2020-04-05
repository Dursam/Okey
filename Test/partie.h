/* Fichier contenant les fonctions principaux pour lancer une partie de Okey */

#ifndef _PARTIE_H_
#define _PARTIE_H_

#include <commun.h>

/* Donne une valeur + 1 de la tuile retournée (le okey) à la tuile joker rouge ou noire posséder par le joueur */
extern void valeur_okey(t_tuile * okey,t_tuile * joker);

extern void affiche_plateau(t_tuile * okey,t_pile * p1,t_pile * p2,t_pile * p3,t_pile * p4);

#endif
