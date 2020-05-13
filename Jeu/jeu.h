#include <affichage.h>
#include <fonctions_affichage.h>
#include <reseau.h>


/**
* \fn void premier_tour_partie(t_tuile * chevalet[N_CHEV], t_pile * pile_J1, t_pile * pile_J2, t_pile * pile_J3, t_pile * pile_J4, t_tuile * okey, int dem)
* \brief Début de partie en fonction de la tuile de démarrage
*/
void premier_tour_partie(t_tuile * chevalet[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int dem);

/**
* \fn int pioche_vide(t_tuile * jeu[N_T])
* \brief Permet de vérifier si le jeu ne posséde plus aucune tuiles,return vrai (1) et faux (0)
*/
int pioche_vide(t_tuile * jeu[N_T]);

/**
* \fn int tour_1_joueur(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur)
* \brief Réalise le premier tour d'un joueur
*/
int tour_1_joueur(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur);

/**
* \fn int debut_partie(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur)
* \brief Débute le première tour de la partie en démarrant avec le joueur qui reçoit une 15 ème tuile
*/
int debut_partie(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur);

/**
* \fn void issue_partie(int issue_joueur)
* \brief Annonce de l'issue de la partie un vainqueur ou non
*/
void issue_partie(int issue_joueur);

/**
* \fn void tour_joueur(t_tuile * jeu[N_T]
                                  ,t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV]
                                  ,t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[]
                                  ,t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4
                                  ,t_tuile * okey
                                  ,int cpt_tour,int num_joueur)
* \brief Permet de réaliser le tour d'un joueur
*/
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
int  partie_en_cours(t_tuile * jeu[N_T]
                                       ,t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV]
                                       ,t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[]
                                       ,t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4
                                       ,t_tuile * okey
                                       ,int num_joueur);


////
/* FONCTIONS IA */
////

/**
* \fn int nombre_combinaison_tuile(t_tuile * chevalet[N_CHEV],t_tuile * okey,int ind_tuile,int ind_dep)
* \brief Retourne vrai si la tuile appartient à une combinaison, faux sinon
*/
int nombre_combinaison_tuile(t_tuile * chevalet[N_CHEV],t_tuile * okey,int ind_tuile,int ind_dep);

/**
* \fn int IA_retire_tuile(t_tuile * chevalet[N_CHEV],t_tuile * okey)
* \brief L'IA retire une tuile de son chevalet
*/
int IA_retire_tuile(t_tuile * chevalet[N_CHEV],t_tuile * okey);

/**
* \fn int IA_ajout_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * okey,t_pile * pile_tuile)
* \brief L'IA ajout une tuile à son chevalet soit en piochant ou soit en prenant la tuile de sa pile de gauche
*/
int IA_ajout_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * okey,t_pile * pile_tuile);

/**
* \fn int tour_1_IA(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur)
* \brief Réalise le premier tour d'une IA
*/
int tour_1_IA(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur);

/**
* \fn int debut_partie_IA(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur)
* \brief Débute le première tour de la partie en démarrant avec le joueur qui reçoit une 15 ème tuile
*/
int debut_partie_IA(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur);

/**
* \fn int tour_IA(t_tuile * jeu[N_T],t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int cpt_tour,int num_joueur)
* \brief Permet de réaliser le tour d'une IA
*/
int tour_IA(t_tuile * jeu[N_T],t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int cpt_tour,int num_joueur);

/**
* \fn int partie_en_cours_IA(t_tuile * jeu[N_T], t_tuile * joueur1[N_CHEV], t_tuile * joueur2[N_CHEV], t_tuile * joueur3[N_CHEV], t_tuile * joueur4[N_CHEV], t_tuile * J1_p1[], t_tuile * J2_p2[], t_tuile * J3_p3[], t_tuile * J4_p4[], t_pile * pile_J1, t_pile * pile_J2, t_pile * pile_J3, t_pile * pile_J4, t_tuile * okey, int num_joueur)
* \brief Permet le déroulement de la partie, après que le première joueur désigné commence
*/
int partie_en_cours_IA(t_tuile * jeu[N_T],t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int num_joueur);
