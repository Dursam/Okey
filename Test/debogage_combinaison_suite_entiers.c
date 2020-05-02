/* L'objectif de ce fichier est de pouvoir créer un rapport de débogage. Ceci va permettre de résoudre l'utilisation d'une même tuile présente 3 ou 4 fois */
/* NOTE: L'exécutable est retiré du Makefile car la fonction combinaison_suite est corrigé. DATE: 2 Mai 2020 */

#include <init_structure.h>
#include <init_pile.h>
#include <combinaison_couleur.h>
#include <combinaison_suite_entiers.h>

int main(){

  /* Variable avec joker */
  t_tuile * test_joker[N_CHEV];

  /* Nombre de répétition d'une tuile inclus les jokers */
  int nbr_rep_tuile;

  /* Création des chevalets */
  creer_chevalet(test_joker,N_CHEV);

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
  test_joker[11]->nbr=1;    // 2 BLEU
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


  /* Débogage */

  /* Affichage d'un chevalet jokers */
  printf("\nEXEMPLE DE CHEVALET DE 14 TUILES AVEC LE JOKER 2 BLEU PRESENT 4 FOIS\n");
  nbr_rep_tuile = detection_rep_joker(test_joker);
  printf("\nLa tuile 2 BLEU est répété(s) %i fois\n",nbr_rep_tuile);
  printf("\nVERIFICATION DE COMBINAISONS AVEC JOKERS\n");
  printf("\n---------------AVANT-------------\n");
  affiche_tuile(test_joker,taille_tuile(test_joker,sizeof(test_joker)));
  /* Vérification des combinaisons du chevalet */
  //combinaison_coul(test_joker); // Pas nécessaire, c'est la même couleur
  combinaison_suite(test_joker);
  /* Affichage du résultat */
  printf("\n---------------APRES-------------\n");
  affiche_tuile(test_joker,taille_tuile(test_joker,sizeof(test_joker)));
  printf("\n----------------FIN--------------\n");


  /* Destruction du chevalet joker */
  detruire_tuile(test_joker,taille_tuile(test_joker,sizeof(test_joker)));
}
