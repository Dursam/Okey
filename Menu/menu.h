/**
 * \file menu.h
 * \brief Menu principal du jeu
 * \author Duran Samuel Girod Valentin
 * \date 12 mars 2019
 */

#include <sav.h>
#include <fonctions_affichage.h>

/**
* \fn void mode_4_joueurs(void)
* \brief Lance le mode de jeu avec 4 joueurs en local
*/
int mode_local_4_joueurs(void);

/**
* \fn int mode_local_1_joueurs_3_IA(void)
* \brief Lance le mode de jeu avec 1 joueur et 3 IA en local
*/
int mode_local_1_joueurs_3_IA(void);

/**
 * \fn void showMenu(void)
 * \brief Gestion et affichage du menu principal
 */
int showMenu(void);
