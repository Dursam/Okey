#ifndef _COMMUN_H_
#define _COMMUN_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

/* Definition de la couleur */
typedef enum {jaune,rouge,noire,bleu} t_couleur;

/* Definition d'une tuile */
typedef struct s_tuile {
  int nbr;
  t_couleur clr;
} t_tuile;

/* Definition d'un element d'une pile soit une tuile */
typedef struct s_element { t_tuile * tuile; struct s_element * suivant;} t_element;

/* Definition d'une pile de tuile */
typedef struct s_pile { t_element * premier ;} t_pile;

/* Nombre de tuiles du jeu */
#define N_T 106

/* Nombre de tuile d'un chevalet */
#define N_CHEV 15

/* Valeur d'une tuie de okey alias joker */
#define V_OKEY 13

/* Valeur d'une tuile supprimée */
#define V_DEL 100

/* Valeur tampon qui sert pour la fonction combinaison suite entier */
#define NO_VALUE 99

#endif
