#include <regle.h>
#include <reseau.h>

// void rejoindrePartie();

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
