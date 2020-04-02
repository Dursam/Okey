/* L'objectif de ce fichier est de tester les combinaisons gagnant (couleur et suite d'entiers) du chevalet */

#include <init_structure.h>
#include <init_pile.h>
#include <combinaison_couleur.h>
#include <combinaison_suite_entiers.h>

int main(){

  /* On iniitialise les joueurs et on leur donne 14 tuiles chacun avec un joueur au hasard qui démarre */
  t_tuile * jeu[N_T],* j1[N_CHEV],* jc[N_CHEV],* je[N_CHEV];
  init_tuile(jeu);

  /* On iniitialise les joueurs et on leur donne 14 tuiles chacun avec un joueur au hasard qui démarre */
  creer_chevalet(j1,N_CHEV);
  creer_chevalet(jc,N_CHEV);
  creer_chevalet(je,N_CHEV);

  /* Distribution des tuiles */
  distribution_joueur(jeu,j1);

  /* Creation d'une combinaison gagnante */

  /* Combinaison du numéro 1 avec 4 couleurs différentes */
  jc[0]->nbr=0;
  jc[0]->clr=jaune;
  jc[1]->nbr=0;
  jc[1]->clr=bleu;
  jc[2]->nbr=0;
  jc[2]->clr=rouge;
  jc[3]->nbr=0;
  jc[3]->clr=noire;
  /* Combinaison d'une suite de numéro (minimum de 3) */
  jc[4]->nbr=0;
  jc[4]->clr=bleu;
  jc[5]->nbr=1;
  jc[5]->clr=bleu;
  jc[6]->nbr=2;
  jc[6]->clr=bleu;
  jc[7]->nbr=3;
  jc[7]->clr=bleu;
  jc[8]->nbr=4;
  jc[8]->clr=bleu;
  jc[9]->nbr=5;
  jc[9]->clr=bleu;
  jc[10]->nbr=6;
  jc[10]->clr=bleu;
  /* Combinaison du numéro 10 avec 3 couleurs différentes */
  jc[11]->nbr=9;
  jc[11]->clr=noire;
  jc[12]->nbr=9;
  jc[12]->clr=rouge;
  jc[13]->nbr=9;
  jc[13]->clr=jaune;
  /* Tuile qui est supprimer */
  jc[14]->nbr=V_DEL;
  jc[14]->clr=jaune;

  /* Combinaison fausse */
  je[0]->nbr=3;
  je[0]->clr=noire;
  je[1]->nbr=3;
  je[1]->clr=noire;
  je[2]->nbr=4;
  je[2]->clr=noire;
  /* Combinaison bonne */
  je[3]->nbr=12;
  je[3]->clr=rouge;
  je[4]->nbr=10;
  je[4]->clr=rouge;
  je[5]->nbr=11;
  je[5]->clr=rouge;
  je[6]->nbr=0;
  je[6]->clr=rouge;
  /* Combinaison fausse */
  je[7]->nbr=5;
  je[7]->clr=bleu;
  je[8]->nbr=4;
  je[8]->clr=bleu;
  /* Combinaison bonne */
  je[9]->nbr=6;
  je[9]->clr=jaune;
  je[11]->nbr=7;
  je[11]->clr=jaune;
  je[12]->nbr=8;
  je[12]->clr=jaune;
  /* Combinaison fausse */
  je[13]->nbr=10;
  je[13]->clr=jaune;
  je[10]->nbr=6;
  je[10]->clr=jaune;
  /* Tuile qui est supprimer */
  je[14]->nbr=V_DEL;
  je[14]->clr=jaune;

  printf("\nEXEMPLE DE CHEVALET DE 14 TUILES DEFINIS\n");
  printf("\nVERIFICATION DES COMBINAISONS DE COULEURS\n");
  printf("\n---------------AVANT-------------\n");


  affiche_tuile(jc,taille_tuile(jc,sizeof(jc)));

  /* Affichage des répétitions */

  combinaison_suite(jc);
  combinaison_coul(jc);

  printf("\n---------------APRES-------------\n");

  affiche_tuile(jc,taille_tuile(jc,sizeof(jc)));

  printf("\n----------------FIN--------------\n");

  /* Affichage d'un chevalet de 15 tuiles aléatoires */
  printf("\nEXEMPLE DE CHEVALET DE 14 TUILES ALEATOIRES\n");
  printf("\nVERIFICATION DES COMBINAISONS DE COULEURS\n");
  printf("\n---------------AVANT-------------\n");

  affiche_tuile(j1,taille_tuile(j1,sizeof(j1)));

  /* Affichage des répétitions */
  combinaison_coul(j1);
  combinaison_suite(j1);

  printf("\n---------------APRES-------------\n");

  affiche_tuile(j1,taille_tuile(j1,sizeof(j1)));

  printf("\n----------------FIN--------------\n");

  /* Affichage d'un chevalet de 15 tuiles aléatoires */
  printf("\nEXEMPLE DE CHEVALET DE 14 TUILES PREDEFINI\n");
  printf("\nVERIFICATION DES COMBINAISONS DE COULEURS\n");
  printf("\n---------------AVANT-------------\n");

  affiche_tuile(je,taille_tuile(je,sizeof(je)));

  /* Affichage des répétitions */
  combinaison_coul(je);
  combinaison_suite(je);

  printf("\n---------------APRES-------------\n");

  affiche_tuile(je,taille_tuile(je,sizeof(je)));

  printf("\n----------------FIN--------------\n");

  /* On détruit le jeu et les chevalets */
  detruire_tuile(jeu,taille_tuile(jeu,sizeof(jeu)));
  detruire_tuile(j1,taille_tuile(j1,sizeof(j1)));
  detruire_tuile(jc,taille_tuile(jc,sizeof(jc)));
  detruire_tuile(je,taille_tuile(je,sizeof(je)));
}
