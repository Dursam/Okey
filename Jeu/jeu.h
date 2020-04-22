#include <regle.h>
#include <reseau.h>

// void rejoindrePartie();

/**
* \fn void debut_partie(t_tuile * chevalet[N_CHEV], t_pile * pile_J1, t_pile * pile_J2, t_pile * pile_J3, t_pile * pile_J4, t_tuile * okey, int num_deb)
* \brief Début de partie en fonction de la tuile de démarrage
*/
void debut_partie(t_tuile * chevalet[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int num_deb);

/**
* \fn int pioche_vide(t_tuile * jeu[N_T])
* \brief Permet de vérifier si le jeu ne posséde plus aucune tuiles,return vrai (1) et faux (0)
*/
int pioche_vide(t_tuile * jeu[N_T]);

/**
* \fn int partie_en_cours(t_tuile * jeu[N_T], t_tuile * joueur1[N_CHEV], t_tuile * joueur2[N_CHEV], t_tuile * joueur3[N_CHEV], t_tuile * joueur4[N_CHEV], t_tuile * J1_p1[], t_tuile * J2_p2[], t_tuile * J3_p3[], t_tuile * J4_p4[], t_pile * pile_J1, t_pile * pile_J2, t_pile * pile_J3, t_pile * pile_J4, int num_joueur, t_tuile * okey)
* \brief Permet le déroulement de la partie, après que le première joueur commence. Retourne le numéro de joueur gagnant
*/
int partie_en_cours(t_tuile * jeu[N_T]
                                      ,t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV]
                                      ,t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[]
                                      ,t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4
                                      ,int num_joueur
                                      ,t_tuile * okey
                                      );

/* A FAIRE */

// Fonction tour_joueur

// Fonction init_partie

// Fonction fin_partie
