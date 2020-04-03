/* Fichier contenant les fonctions de combinaison de couleur */
#ifndef _COMBICOUL_H_
#define _COMBICOUL_H_

#include <commun.h>

/* Vérifie les tuiles supprimer ou non */
extern void affiche_tuile(t_tuile * jeu[],int taille);

/* Compte le nombre de couleur différente d'une tuile */
extern int compte_coul_diff(int tab_coul[4]);

/* Vérifie les ensembles de combinaisons de 3 ou 4 couleurs */
extern void combinaison_coul(t_tuile * chev[]);

#endif
