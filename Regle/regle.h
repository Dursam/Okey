/**
* \file combinaison_couleur.h
* \brief Fichier contenant les fonctions de combinaison de couleur
* \author Samuel DURAN
* \version 1.0
* \date 12 avril 2020
*/

#include <affichage.h>

/**
* \fn void affiche_tuile(t_tuile * jeu[], int taille)
* \brief Vérifie les tuiles supprimées ou non
*/
void affiche_tuile(t_tuile * jeu[],int taille);

/**
* \fn int compte_coul_diff(int tab_coul[4])
* \brief Compte le nombre de couleurs différentes d'une tuile
*/
int compte_coul_diff(int tab_coul[4]);

/**
* \fn void combinaison_coul(t_tuile * chev[])
* \brief Vérifie les ensembles de combinaisons de 3 ou 4 couleurs
*/
void regle_coul(t_tuile * chev[]);

/**
* \fn void combinaison_suite(t_tuile * chev[])
* \brief Vérifie les ensembles de combinaisons à partir de 3 suites d'entiers
*/
void regle_suite(t_tuile * chev[]);

/**
* \fn void valeur_okey(t_tuile * okey, t_tuile * joker)
* \brief Donne une valeur + 1 de la tuile retournée (le okey) à la tuile joker rouge ou noire posséder par le joueur
*/
void valeur_okey(t_tuile * okey,t_tuile * joker);

/**
* \fn int regle_combinaison(t_tuile * chevalet[N_CHEV], t_tuile * okey)
* \brief Vérifie si le chevalet est gagnant (return 1, 0 pour contraire) en utilisant les combinaisons de couleurs et de suite d'entier
*/
int regle_combinaison(t_tuile * chevalet[N_CHEV],t_tuile * okey);

/**
* \fn void selection_tuile(t_tuile * jeu[N_T], t_tuile * chevalet[N_CHEV], t_tuile * enr[], t_pile * pfg, t_pile * pfd, t_pile * pg, t_pile * pd,t_tuile * okey)
* \brief  Permet de sélection une tuile soit de la pioche ou de la pile de gauche et retire une tuile du chevalet, version avec affiche_pile
*/
void selection_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd,t_tuile * okey);
