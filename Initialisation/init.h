/**
* \file init_structure.h
* \brief Fichier contenant les fonctions d'initialisation pour les tableaux de structures et pour les piles
* \author Samuel DURAN
* \version 1.0
* \date 21 avril 2020
*/

#include <definitions.h>

/**
* \fn void init_tuile(t_tuile * jeu[N_T])
* \brief Initialise le jeu de 106 tuiles
*/
void init_tuile(t_tuile * jeu[N_T]);

/**
* \fn void creer_chevalet(t_tuile * joueur[], int taille)
* \brief Alloue une mémoire dynamique à un chevalet
*/
void creer_chevalet(t_tuile * joueur[],int taille);

/**
* \fn void detruire_tuile(t_tuile * jeu[], int taille)
* \brief Libère la mémoire d'une tuile ou de plusieurs tuiles d'un tableau de structure
*/
void detruire_tuile(t_tuile * jeu[],int taille);

/**
* \fn int demarrage(t_tuile * jeu[N_T], t_tuile * j1[N_CHEV], t_tuile * j2[N_CHEV], t_tuile * j3[N_CHEV], t_tuile * j4[N_CHEV])
* \brief Donne une tuile au hasard à un des 4 joueurs
*/
int demarrage(t_tuile * jeu[N_T], t_tuile * j1[N_CHEV],t_tuile * j2[N_CHEV],t_tuile * j3[N_CHEV],t_tuile * j4[N_CHEV]);

/**
* \fn void distribution_joueur(t_tuile * jeu[N_T], t_tuile * joueur[N_CHEV])
* \brief Distribue 14 tuiles à un joueur
*/
void distribution_joueur(t_tuile * jeu[N_T], t_tuile * joueur[N_CHEV]);

/**
* \fn t_tuile distribution_pioche(t_tuile * jeu[N_T])
* \brief Distribue une tuile parmi le jeu des 106 tuiles, au hasard
*/
t_tuile distribution_pioche(t_tuile * jeu[N_T]);

/**
* \fn t_tuile * creer_tuile(void);
* \brief Alloue une mémoire dynamique à une tuile
*/
t_tuile * creer_tuile(void);

/**
* \fn int taille_tuile(t_tuile * jeu[], int taille_jeu)
* \brief Renvoie la taille des tuiles alloués
*/
int taille_tuile(t_tuile * jeu[],int taille_jeu);

/**
* \fn void init_pile(t_pile * pile)
* \brief Initialise la pile
*/
void init_pile(t_pile * pile);

/**
* \fn int pile_vide(t_pile * pile)
* \brief Vérifie si la pile est vide
*/
int pile_vide(t_pile * pile);

/**
* \fn void empiler(t_pile * pile, t_tuile * t)
* \brief Empile une tuile de la pile
*/
void empiler(t_pile * pile,t_tuile * t);

/**
* \fn void depiler(t_pile * pile)
* \brief Retire une tuile de la pile
*/
void depiler(t_pile * pile);

/**
* \fn sommet_pile(t_pile * pile, t_tuile ** c)
* \brief Récupère la tuile du sommet de la pile
*/
void sommet_pile(t_pile * pile,t_tuile ** c);

/**
* \fn int compte_element(t_pile * pile)
* \brief Compte le nombre d'élément d'une tuile
*/
int compte_element(t_pile * pile);

/**
* \fn void init_enr_tuile(t_tuile * enr[], int taille)
* \brief Initialise un tableau de struture de tuile pour enregistrer les tuiles qui seront empilés
*/
void init_enr_tuile(t_tuile * enr[],int taille);

/**
* \fn void empile_enr_tuile(t_tuile * chevalet[N_CHEV], t_tuile * enr[], t_pile * pile, int taille, int numero)
* \brief Créer une tuile, lui affecte une valeur puis l'empile sur une pile
*/
void empile_enr_tuile(t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pile,int taille,int numero);

/**
* \fn void depiler_toutes_tuiles(t_pile * pile_J1, t_pile * pile_J2, t_pile * pile_J3, t_pile * pile_J4)
* \brief Dépile toutes les piles de tuiles, utilisé pour finir la partie
*/
void depiler_toutes_tuiles(t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4);
