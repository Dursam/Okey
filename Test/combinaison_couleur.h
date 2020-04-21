/* Fichier contenant les fonctions de combinaison de couleur */
#ifndef _COMBICOUL_H_
#define _COMBICOUL_H_

#include <commun.h>

/**
* \file combinaison_couleur.h
* \brief Fichier contenant les fonctions de combinaison de couleur
* \author Samuel DURAN
* \version 1.0
* \date 12 avril 2020
*/

/**
* \fn void affiche_tuile(t_tuile * jeu[], int taille)
* \brief Vérifie les tuiles supprimées ou non
*/
extern void affiche_tuile(t_tuile * jeu[],int taille);

/**
* \fn int compte_coul_diff(int tab_coul[4])
* \brief Compte le nombre de couleurs différentes d'une tuile
*/
extern int compte_coul_diff(int tab_coul[4]);

/**
* \fn void combinaison_coul(t_tuile * chev[])
* \brief Vérifie les ensembles de combinaisons de 3 ou 4 couleurs
*/
extern void combinaison_coul(t_tuile * chev[]);

#endif
