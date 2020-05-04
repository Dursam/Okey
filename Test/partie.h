#ifndef _PARTIE_H_
#define _PARTIE_H_

#include <commun.h>

/**
* \file partie.h
* \brief Fichier contenant les fonctions principales pour lancer une partie de Okey
* \author Samuel DURAN
* \version 1.0
* \date 12 avril 2020
*/

/**
* \fn void valeur_okey(t_tuile * okey, t_tuile * joker)
* \brief Donne une valeur + 1 de la tuile retournée (le okey) à la tuile joker rouge ou noire posséder par le joueur
*/
extern void valeur_okey(t_tuile * okey,t_tuile * joker);

/**
* \fn void affiche_plateau(t_tuile * okey, t_pile * p1, t_pile * p2, t_pile * p3, t_pile * p4)
* \brief Affichage du sommet des piles de tout les joueurs
*/
extern void affiche_plateau(t_tuile * okey,t_pile * p1,t_pile * p2,t_pile * p3,t_pile * p4);

/**
* \fn void premier_tour_partie(t_tuile * chevalet[N_CHEV], t_pile * pile_J1, t_pile * pile_J2, t_pile * pile_J3, t_pile * pile_J4, t_tuile * okey, int dem)
* \brief Début de partie en fonction de la tuile de démarrage
*/
extern void premier_tour_partie(t_tuile * chevalet[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int dem);

/**
* \fn void depiler_toutes_tuiles(t_pile * pile_J1, t_pile * pile_J2, t_pile * pile_J3, t_pile * pile_J4)
* \brief Dépile toutes les piles de tuiles, utilisé pour finir la partie
*/
extern void depiler_toutes_tuiles(t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4);

/**
* \fn int regle_combinaison(t_tuile * chevalet[N_CHEV], t_tuile * okey)
* \brief Vérifie si le chevalet est gagnant (return 1, 0 pour contraire) en utilisant les combinaisons de couleurs et de suite d'entier
*/
extern int regle_combinaison(t_tuile * chevalet[N_CHEV],t_tuile * okey);

/**
* \fn int choix_tri(t_tuile * chevalet[N_CHEV])
* \brief Laisse le choix au joueur de pouvoir faire un tri rapide, un tri manuel ou pas de tri
*/
extern int choix_tri(t_tuile * chevalet[N_CHEV]);

/**
* \fn int debut_partie(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur)
* \brief Débute le première tour de la partie en démarrant avec le joueur qui reçoit une 15 ème tuile
*/
extern int debut_partie(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur);

/**
* \fn void issue_partie(int issue_joueur)
* \brief Annonce de l'issue de la partie un vainqueur ou non
*/
extern void issue_partie(int issue_joueur);

/**
* \fn void selection_tuile_v2(t_tuile * jeu[N_T], t_tuile * chevalet[N_CHEV], t_tuile * enr[], t_pile * pfg, t_pile * pfd, t_pile * pg, t_pile * pd)
* \brief Permet de sélection une tuile soit de la pioche ou de la pile de gauche et retire une tuile du chevalet, version avec affiche plateau
*/
extern void selection_tuile_v2(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd);

/**
* \fn int pioche_vide(t_tuile * jeu[N_T])
* \brief Permet de vérifier si le jeu ne posséde plus aucune tuiles,return vrai (1) et faux (0)
*/
extern int pioche_vide(t_tuile * jeu[N_T]);

/**
* \fn void tour_joueur(t_tuile * jeu[N_T]
                                  ,t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV]
                                  ,t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[]
                                  ,t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4
                                  ,t_tuile * okey
                                  ,int cpt_tour,int num_joueur)
* \brief Permet de réaliser le tour d'un joueur
*/
extern
int tour_joueur(t_tuile * jeu[N_T]
                                  ,t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV]
                                  ,t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[]
                                  ,t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4
                                  ,t_tuile * okey
                                  ,int cpt_tour
                                  ,int num_joueur);
/**
* \fn int partie_en_cours(t_tuile * jeu[N_T],
                                  t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],
                                  t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[],
                                  t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,
                                  ,t_tuile * okey
                                  ,int num_joueur)
* \brief Permet le déroulement de la partie, après que le première joueur désigné commence
*/
extern
int  partie_en_cours(t_tuile * jeu[N_T]
                                       ,t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV]
                                       ,t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[]
                                       ,t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4
                                       ,t_tuile * okey
                                       ,int num_joueur);

#endif
