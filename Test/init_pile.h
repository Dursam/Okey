#ifndef _PILE_H_
#define _PILE_H_

#include <commun.h>

/**
* \file init_pile.h
* \brief Fichier contenant les fonctions d'initialisation pour les piles
* \author Samuel DURAN
* \version 1.0
* \date 12 avril 2020
*/

/** 
* \fn void init_pile(t_pile * pile)
* \brief Initialise la pile
*/
extern void init_pile(t_pile * pile);

/**
* \fn int pile_vide(t_pile * pile)
* \brief Vérifie si la pile est vide
*/
extern int pile_vide(t_pile * pile);

/**
* \fn void empiler(t_pile * pile, t_tuile * t)
* \brief Empile une tuile de la pile
*/
extern void empiler(t_pile * pile,t_tuile * t);

/**
* \fn void depiler(t_pile * pile)
* \brief Retire une tuile de la pile
*/
extern void depiler(t_pile * pile);

/**
* \fn sommet_pile(t_pile * pile, t_tuile ** c)
* \brief Récupère la tuile du sommet de la pile
*/
extern void sommet_pile(t_pile * pile,t_tuile ** c);

/**
* \fn int compte_element(t_pile * pile)
* \brief Compte le nombre d'élément d'une tuile
*/
extern int compte_element(t_pile * pile);

#endif
