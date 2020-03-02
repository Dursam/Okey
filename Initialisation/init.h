#include <definitions.h>



void init_tuile(t_tuile * jeu[N]);

void creer_joueur(t_tuile * joueur[],int taille);

t_tuile * creer_tuile(void);

void detruire_tuile(t_tuile * jeu[],int taille);

void distribution_joueur(t_tuile * jeu[N], t_tuile * j1[J]);

t_tuile distribution_pioche(t_tuile * jeu[N]);

void demarrage(t_tuile * jeu[N], t_tuile * j1[J],t_tuile * j2[J],t_tuile * j3[J],t_tuile * j4[J]);

int taille_tuile(t_tuile * jeu[],int taille_jeu);

/* FONCTION DE LA PILE */

void initpile(t_pile * pile);

int pilevide(t_pile * pile);

void empiler(t_pile * pile,t_tuile * t);

void depiler(t_pile * pile);

void sommetpile(t_pile * pile,t_tuile ** c);
/*-----------------------------------*/
