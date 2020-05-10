#include <jeu.h>

t_fichier * nom_fichier(void);

int numero_partie(t_fichier * fichier);

void ajout_score(t_fichier * fichier,int num_partie,int s_J1,int s_J2,int s_J3,int s_J4);

void charger_partie(t_fichier * fichier);

int calcul_score(t_fichier * fichier,int num_partie,int num_joueur);

void afficher_scores(t_fichier * fichier,int num_partie);
