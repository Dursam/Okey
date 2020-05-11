#include <jeu.h>

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

/**
* \fn void maj_sauvegarde(t_fichier * fichier,int num_partie,int num_joueur)
* \brief Met à jour les scores d'une sauvegarde de partie
*/
void maj_sauvegarde(t_fichier * fichier,int num_partie,int num_joueur);
