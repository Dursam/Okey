/**
* \file affichage_tuile.h
* \brief Fichier contenant les fonctions d'affichages
* \author Samuel DURAN
* \version 1.0
* \date 12 avril 2020
*/

#include <regle.h>
/**
* \fn void selection_tuile(t_tuile * jeu[N_T], t_tuile * chevalet[N_CHEV], t_tuile * enr[], t_pile * pfg, t_pile * pfd, t_pile * pg, t_pile * pd,t_tuile * okey)
* \brief  Permet de sélection une tuile soit de la pioche ou de la pile de gauche et retire une tuile du chevalet, version avec affiche_pile
*/
void selection_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd,t_tuile * okey);

int select_tuile(int AutoriserFinTour);

void menuServeur(char*ip);

int afficher_menu(char menu[4][30], int taille);

char * afficher_sauvegarde(int max_fichier);

int detecter_mouvement(float*x, float*y);

void afficher_regle(void);
/**
* \fn void tri_manuel(t_tuile * chevalet[N_CHEV]);
* \brief Tri manuel d'un chevalet de tuiles
*/
void tri_manuel(t_tuile * chevalet[N_CHEV]);

/**
* \fn void tri_rapide(t_tuile * chevalet[], int i, int j);
* \brief Tri rapide d'un chevalet de tuiles
*/
void tri_rapide(t_tuile * chevalet[], int i, int j);

/**
* \fn int choix_tri(t_tuile * chevalet[N_CHEV])
* \brief Laisse le choix au joueur de pouvoir faire un tri rapide, un tri manuel ou un pas de tri
*/
int choix_tri(t_tuile * chevalet[N_CHEV]);

/**
* \fn void affiche_chevalet(t_tuile * jeu[], int taille);
* \brief Affichage des 14/15 tuiles du chevalet
*/
void affiche_chevalet(t_tuile * jeu[],int taille);

/**
* \fn void affiche_sommet_pile(t_pile * pile);
* \brief Affichage du sommet d'une pile
*/
void affiche_sommet_pile(t_pile * pile, int nb_pile);

/**
* \fn void affiche_plateau(t_tuile * okey, t_pile * pfg, t_pile * pfd, t_pile * pg, t_pile * pd)
* \brief Affichage du sommet des piles de tout les joueurs, valeur du okey et une pioche
*/
void affiche_piles(t_tuile * okey, t_pile * pfg, t_pile * pfd, t_pile * pg, t_pile * pd);

/**
* \fn void affiche_chevalet_IA(t_tuile * jeu[], int taille)
* \brief Affichage des 14/15 tuiles cachés du chevalet d'une IA
*/
void affiche_chevalet_IA(t_tuile * jeu[],int taille);
