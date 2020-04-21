#ifndef _COMMUN_H_
#define _COMMUN_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

/**
* \file commun.h
* \brief Fonctions communes à l'ensemble des fichiers
* \author Samuel DURAN
* \version 1.0
* \date 12 avril 2020
*/

/**
* \enum t_couleur
* \brief Définition de la couleur
*/
typedef enum {jaune,rouge,noire,bleu} t_couleur;

/**
* \struct s_tuile
* \brief Définition d'une tuile
*/
typedef struct s_tuile {
  int nbr; /**< Nombre inscrit sur la tuile */
  t_couleur clr; /**< Couleur de la tuile */
} t_tuile;

/**
* \struct s_element
* \brief Définition d'un élément d'une pile, soit une tuile
*/
typedef struct s_element {
  t_tuile * tuile; /**< Tuile */
  struct s_element * suivant; /**< Elément suivant de la tuile */
} t_element;

/**
* \struct s_pile
* \brief Définition d'une pile de tuile 
*/
typedef struct s_pile {
  t_element * premier ; /**< Premier élément de la pile */
} t_pile;

/**
* \def N_T
* Nombre de tuiles du jeu 
*/
#define N_T 106

/**
* \def N_CHEV
* Nombre de tuiles d'un chevalet
*/
#define N_CHEV 15

/**
* \def V_OKEY
* Valeur d'une tuile de okey alias joker
*/
#define V_OKEY 13

/**
* \def V_DEL
* Valeur d'une tuile supprimée 
*/
#define V_DEL 100

/**
* \def NO_VALUE
* Valeur tampon qui sert pour la fonction combinaison suite entier 
*/
#define NO_VALUE 99

#endif
