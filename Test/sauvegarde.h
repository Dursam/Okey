/**
* \file sauvegarde.h
* \brief Fichier contenant les fonctions de sauvegarde et de score
* \author Samuel DURAN
* \version 1.0
* \date 10 mai 2020
*/

#ifndef _SAUVEGARDE_H_
#define _SAUVEGARDE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
* \struct s_fichier
* \brief Définition d'un fichier
*/
typedef struct s_fichier {
  FILE * fichier; /**< Le fichier */
  char * nom; /**< Nom du fichier */
} t_fichier;

/**
* \fn t_fichier * nom_fichier(void)
* \brief Créer une sauvegarde pour une partie
*/
t_fichier * nom_fichier(void);

/**
* \fn int numero_partie(t_fichier * fichier)
* \brief Récupère le numéro de partie
*/
int numero_partie(t_fichier * fichier);

/**
* \fn void ajout_score(t_fichier * fichier,int num_partie,int s_J1,int s_J2,int s_J3,int s_J4)
* \brief Ajoute les scores des joueurs de la partie
*/
void ajout_score(t_fichier * fichier,int num_partie,int s_J1,int s_J2,int s_J3,int s_J4);

/**
* \fn void charger_partie(t_fichier * fichier)
* \brief Charge une partie avec un fichier existant
*/
void charger_partie(t_fichier * fichier);

/**
* \fn int calcul_score(t_fichier * fichier,int num_partie,int num_joueur)
* \brief Calcule le score d'un joueur à partir d'une sauvegarde de partie
*/
int calcul_score(t_fichier * fichier,int num_partie,int num_joueur);

/**
* \fn void afficher_scores(t_fichier * fichier,int num_partie)
* \brief Affiche les scores des joueurs d'une partie
*/
void afficher_scores(t_fichier * fichier,int num_partie);

#endif
