/* L'objectif de ce fichier est de tester les combinaisons gagnant (couleur et suite d'entiers) du chevalet */

#include <init_structure.h>
#include <init_pile.h>
#include <combinaison_couleur.h>
#include <combinaison_suite_entiers.h>

int main(){

  /* Variables chevalets */
  t_tuile * jeu[N_T],* test_gagnant[N_CHEV],* test_perdant[N_CHEV],* test_aleatoire[N_CHEV],* test_joker[N_CHEV];

  /* Nombre de répétition d'une tuile inclus les jokers */
  //int nbr_rep_tuile;

  /* Initialise le jeu */
  init_tuile(jeu);

  /* Création des chevalets */
  creer_chevalet(test_gagnant,N_CHEV);
  creer_chevalet(test_perdant,N_CHEV);
  creer_chevalet(test_aleatoire,N_CHEV);
  creer_chevalet(test_joker,N_CHEV);

  /* Distribution des tuiles au chevalet du test aléatoire */
  distribution_joueur(jeu,test_aleatoire);

  /* Creation d'un chevalet gagnant */

  /* Combinaison du numéro 1 avec 4 couleurs différentes */
  test_gagnant[0]->nbr=0;
  test_gagnant[0]->clr=jaune;
  test_gagnant[1]->nbr=0;
  test_gagnant[1]->clr=bleu;
  test_gagnant[2]->nbr=0;
  test_gagnant[2]->clr=rouge;
  test_gagnant[3]->nbr=0;
  test_gagnant[3]->clr=noire;
  /* Combinaison d'une suite de numéro (minimum de 3) */
  test_gagnant[4]->nbr=0;
  test_gagnant[4]->clr=bleu;
  test_gagnant[5]->nbr=1;
  test_gagnant[5]->clr=bleu;
  test_gagnant[6]->nbr=2;
  test_gagnant[6]->clr=bleu;
  test_gagnant[7]->nbr=3;
  test_gagnant[7]->clr=bleu;
  test_gagnant[8]->nbr=4;
  test_gagnant[8]->clr=bleu;
  test_gagnant[9]->nbr=5;
  test_gagnant[9]->clr=bleu;
  test_gagnant[10]->nbr=6;
  test_gagnant[10]->clr=bleu;
  /* Combinaison du numéro 10 avec 3 couleurs différentes */
  test_gagnant[11]->nbr=9;
  test_gagnant[11]->clr=noire;
  test_gagnant[12]->nbr=9;
  test_gagnant[12]->clr=rouge;
  test_gagnant[13]->nbr=9;
  test_gagnant[13]->clr=jaune;
  /* Tuile qui est supprimée pour que le chevalet puisse avoir 14 tuiles */
  test_gagnant[14]->nbr=V_DEL;
  test_gagnant[14]->clr=jaune;

  /* Creation d'un chevalet perdant */

  /* Combinaison fausse deux 4 et une 5 NOIRE */
  test_perdant[0]->nbr=3;
  test_perdant[0]->clr=noire;
  test_perdant[1]->nbr=3;
  test_perdant[1]->clr=noire;
  test_perdant[2]->nbr=4;
  test_perdant[2]->clr=noire;
  /* Combinaison bonne une 13,11,12 et 1 ROUGE */
  test_perdant[3]->nbr=12;
  test_perdant[3]->clr=rouge;
  test_perdant[4]->nbr=10;
  test_perdant[4]->clr=rouge;
  test_perdant[5]->nbr=11;
  test_perdant[5]->clr=rouge;
  test_perdant[6]->nbr=0;
  test_perdant[6]->clr=rouge;
  /* Combinaison fausse une 6 et 5 BLEU */
  test_perdant[7]->nbr=5;
  test_perdant[7]->clr=bleu;
  test_perdant[8]->nbr=4;
  test_perdant[8]->clr=bleu;
  /* Combinaison bonne une 7, 8, 9 JAUNE */
  test_perdant[9]->nbr=6;
  test_perdant[9]->clr=jaune;
  test_perdant[11]->nbr=7;
  test_perdant[11]->clr=jaune;
  test_perdant[12]->nbr=8;
  test_perdant[12]->clr=jaune;
  /* Combinaison fausse unne 11 et 7 JAUNE */
  test_perdant[13]->nbr=10;
  test_perdant[13]->clr=jaune;
  test_perdant[10]->nbr=6;
  test_perdant[10]->clr=jaune;
  /* Tuile qui est supprimée pour que le chevalet puisse avoir 14 tuiles */
  test_perdant[14]->nbr=V_DEL;
  test_perdant[14]->clr=jaune;

  /* Creation d'un chevalet fictif avec jokers */
  // NOTE: Un joker prend la valeur du Okey + 1 et sa couleur, les jokers rouge et noire sont un abus de langage.
  // Cela signifie que dans le jeu, nous avons 4 même tuiles, 2 tuiles normaux et 2 tuile jokers.
  // Dans cet exemple, on va créer un chevalet fictif de 14 tuiles dont certaines tuiles apparaitront 3 ou 4 fois (La tuile 2 Bleu).

  /* Combinaison bonne 1,2,3 et 4 BLEU */
  test_joker[0]->nbr=0;
  test_joker[0]->clr=bleu;
  test_joker[1]->nbr=1;     // 2 BLEU
  test_joker[1]->clr=bleu;
  test_joker[2]->nbr=2;
  test_joker[2]->clr=bleu;
  test_joker[3]->nbr=3;
  test_joker[3]->clr=bleu;
  /* Combinaison bonne 2,3 et 4 BLEU */
  test_joker[4]->nbr=1;    // 2 BLEU
  test_joker[4]->clr=bleu;
  test_joker[5]->nbr=2;
  test_joker[5]->clr=bleu;
  test_joker[6]->nbr=3;
  test_joker[6]->clr=bleu;
  /* Combinaison bonne 2,1 et 13 BLEU */
  test_joker[7]->nbr=1;     // 2 BLEU
  test_joker[7]->clr=bleu;
  test_joker[8]->nbr=0;
  test_joker[8]->clr=bleu;
  test_joker[9]->nbr=12;
  test_joker[9]->clr=bleu;
  /* Combinaison bonne 2,6,7 et 8 BLEU */
  test_joker[11]->nbr=9;    // 2 BLEU
  test_joker[11]->clr=bleu;
  test_joker[12]->nbr=5;
  test_joker[12]->clr=bleu;
  test_joker[13]->nbr=6;
  test_joker[13]->clr=bleu;
  test_joker[10]->nbr=7;
  test_joker[10]->clr=bleu;
  /* Tuile qui est supprimée pour que le chevalet puisse avoir 14 tuiles */
  test_joker[14]->nbr=V_DEL;
  test_joker[14]->clr=bleu;


  /* Affichage d'un chevalet gagnant */
  printf("\nEXEMPLE DE CHEVALET DE 14 TUILES GAGNANTES\n");
  printf("\nVERIFICATION DES COMBINAISONS VALIDES\n");
  printf("\n---------------AVANT-------------\n");
  affiche_tuile(test_gagnant,taille_tuile(test_gagnant,sizeof(test_gagnant)));
  /* Vérification des combinaisons du chevalet */
  combinaison_suite(test_gagnant);
  combinaison_coul(test_gagnant);
  /* Affichage du résultat */
  printf("\n---------------APRES-------------\n");
  affiche_tuile(test_gagnant,taille_tuile(test_gagnant,sizeof(test_gagnant)));
  printf("\n----------------FIN--------------\n");



  /* Affichage d'un chevalet perdant */
  printf("\nEXEMPLE DE CHEVALET DE 14 TUILES PERDANTES\n");
  printf("\nVERIFICATION DES COMBINAISONS VALIDES OU NON\n");
  printf("\n---------------AVANT-------------\n");
  affiche_tuile(test_perdant,taille_tuile(test_perdant,sizeof(test_perdant)));
  /* Vérification des combinaisons du chevalet */
  combinaison_coul(test_perdant);
  combinaison_suite(test_perdant);
  /* Affichage du résultat */
  printf("\n---------------APRES-------------\n");
  affiche_tuile(test_perdant,taille_tuile(test_perdant,sizeof(test_perdant)));
  printf("\n----------------FIN--------------\n");



  /* Affichage d'un chevalet aléatoire */
  printf("\nEXEMPLE DE CHEVALET DE 14 TUILES ALEATOIRES\n");
  printf("\nVERIFICATION DE COMBINAISONS ALEATOIRES\n");
  printf("\n---------------AVANT-------------\n");
  affiche_tuile(test_aleatoire,taille_tuile(test_aleatoire,sizeof(test_aleatoire)));
  /* Vérification des combinaisons du chevalet */
  combinaison_coul(test_aleatoire);
  combinaison_suite(test_aleatoire);
  /* Affichage du résultat */
  printf("\n---------------APRES-------------\n");
  affiche_tuile(test_aleatoire,taille_tuile(test_aleatoire,sizeof(test_aleatoire)));
  printf("\n----------------FIN--------------\n");



  /* Affichage d'un chevalet jokers */
  printf("\nEXEMPLE DE CHEVALET DE 14 TUILES AVEC JOKERS\n");
  /*nbr_rep_tuile = detection_rep_tuile(test_joker);
  printf("\nIl y a une tuile qui a %i de répétition\n",nbr_rep_tuile);*/
  printf("\nVERIFICATION DE COMBINAISONS AVEC JOKERS\n");
  printf("\n---------------AVANT-------------\n");
  affiche_tuile(test_joker,taille_tuile(test_joker,sizeof(test_joker)));
  /* Vérification des combinaisons du chevalet */
  combinaison_coul(test_joker); // Pas nécessaire, c'est la même couleur
  combinaison_suite(test_joker);
  /* Affichage du résultat */
  printf("\n---------------APRES-------------\n");
  affiche_tuile(test_joker,taille_tuile(test_joker,sizeof(test_joker)));
  printf("\n----------------FIN--------------\n");



  /* Destruction du jeu et des chevalets */
  detruire_tuile(jeu,taille_tuile(jeu,sizeof(jeu)));
  detruire_tuile(test_gagnant,taille_tuile(test_gagnant,sizeof(test_gagnant)));
  detruire_tuile(test_perdant,taille_tuile(test_perdant,sizeof(test_perdant)));
  detruire_tuile(test_aleatoire,taille_tuile(test_aleatoire,sizeof(test_aleatoire)));
  detruire_tuile(test_joker,taille_tuile(test_joker,sizeof(test_joker)));
}
