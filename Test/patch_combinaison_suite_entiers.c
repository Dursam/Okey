/* L'objectif de ce fichier est de corrigé (patché) un problème présent dans la fonction combinaison_suite.
   Celle-ci doit pouvoir traiter un chevalet comportant une même tuile présente 3 ou 4 fois, soit des jokers */

#include <init_structure.h>
#include <init_pile.h>
#include <combinaison_couleur.h>
#include <combinaison_suite_entiers.h>

int main(){

  /* Variable avec joker */
  t_tuile * test_joker[N_CHEV],* test_joker_2[N_CHEV],* test_joker_3[N_CHEV],* test_joker_4[N_CHEV];

  /* Création des chevalets */
  creer_chevalet(test_joker,N_CHEV);
  creer_chevalet(test_joker_2,N_CHEV);
  creer_chevalet(test_joker_3,N_CHEV);
  creer_chevalet(test_joker_4,N_CHEV);

  /* Creation d'un chevalet fictif avec jokers */
  // NOTE: Un joker prend la valeur du Okey + 1 et sa couleur, les jokers rouge et noire sont un abus de langage.
  // Cela signifie que dans le jeu, nous avons 4 même tuiles, 2 tuiles normaux et 2 tuile jokers.
  // Dans cet exemple, on va créer un chevalet fictif de 14 tuiles dont certaines tuiles apparaitront 3 ou 4 fois (La tuile 2 Bleu).

  /* Chevalet avec 4 même tuile 2 BLEU en forme 2 fois 3 combinaisons(C) et 2C4 */
  /* Combinaison bonne 1,2,13 et 12 BLEU */
  test_joker[0]->nbr=0;
  test_joker[0]->clr=bleu;
  test_joker[1]->nbr=1;     // 2 BLEU
  test_joker[1]->clr=bleu;
  test_joker[2]->nbr=12;
  test_joker[2]->clr=bleu;
  test_joker[3]->nbr=11;
  test_joker[3]->clr=bleu;
  /* Combinaison bonne 2,1 et 13 BLEU */
  test_joker[4]->nbr=1;    // 2 BLEU
  test_joker[4]->clr=bleu;
  test_joker[5]->nbr=0;
  test_joker[5]->clr=bleu;
  test_joker[6]->nbr=12;
  test_joker[6]->clr=bleu;
  /* Combinaison bonne 2,3 et 4 BLEU */
  test_joker[7]->nbr=1;     // 2 BLEU
  test_joker[7]->clr=bleu;
  test_joker[8]->nbr=2;
  test_joker[8]->clr=bleu;
  test_joker[9]->nbr=3;
  test_joker[9]->clr=bleu;
  /* Combinaison bonne 2,3,4 et 5 BLEU */
  test_joker[11]->nbr=1;    // 2 BLEU
  test_joker[11]->clr=bleu;
  test_joker[12]->nbr=2;
  test_joker[12]->clr=bleu;
  test_joker[13]->nbr=3;
  test_joker[13]->clr=bleu;
  test_joker[10]->nbr=4;
  test_joker[10]->clr=bleu;
  /* Tuile qui est supprimée pour que le chevalet puisse avoir 14 tuiles */
  test_joker[14]->nbr=V_DEL;
  test_joker[14]->clr=bleu;

  /* Chevalet avec 4 même tuile 2 BLEU en forme 3C3 et 1C5 */
  /* Combinaison bonne 13,1 et 2 BLEU */
  test_joker_2[0]->nbr=12;
  test_joker_2[0]->clr=bleu;
  test_joker_2[1]->nbr=0;
  test_joker_2[1]->clr=bleu;
  test_joker_2[2]->nbr=1;
  test_joker_2[2]->clr=bleu;
  /* Combinaison bonne 13,1 et 2 BLEU */
  test_joker_2[3]->nbr=12;
  test_joker_2[3]->clr=bleu;
  test_joker_2[4]->nbr=0;
  test_joker_2[4]->clr=bleu;
  test_joker_2[5]->nbr=1;
  test_joker_2[5]->clr=bleu;
  /* Combinaison bonne 2,3 et 4 BLEU */
  test_joker_2[6]->nbr=1;
  test_joker_2[6]->clr=bleu;
  test_joker_2[7]->nbr=2;
  test_joker_2[7]->clr=bleu;
  test_joker_2[8]->nbr=3;
  test_joker_2[8]->clr=bleu;
  /* Combinaison bonne 2,3,4,5 et 6 BLEU */
  test_joker_2[9]->nbr=1;
  test_joker_2[9]->clr=bleu;
  test_joker_2[11]->nbr=2;
  test_joker_2[11]->clr=bleu;
  test_joker_2[12]->nbr=3;
  test_joker_2[12]->clr=bleu;
  test_joker_2[13]->nbr=4;
  test_joker_2[13]->clr=bleu;
  test_joker_2[10]->nbr=5;
  test_joker_2[10]->clr=bleu;
  /* Tuile qui est supprimée pour que le chevalet puisse avoir 14 tuiles */
  test_joker_2[14]->nbr=V_DEL;
  test_joker_2[14]->clr=bleu;

  /* Chevalet avec 3 même tuile 2 BLEU en forme 2C3 et 1C4 et un autre 1C4 */
  /* Combinaison bonne 13,1,2 BLEU */
  test_joker_3[0]->nbr=12;
  test_joker_3[0]->clr=bleu;
  test_joker_3[1]->nbr=0;
  test_joker_3[1]->clr=bleu;
  test_joker_3[2]->nbr=1;
  test_joker_3[2]->clr=bleu;
  /* Combinaison bonne 12,13,1 et 2 BLEU */
  test_joker_3[3]->nbr=11;
  test_joker_3[3]->clr=bleu;
  test_joker_3[4]->nbr=12;
  test_joker_3[4]->clr=bleu;
  test_joker_3[5]->nbr=0;
  test_joker_3[5]->clr=bleu;
  test_joker_3[6]->nbr=1;
  test_joker_3[6]->clr=bleu;
  /* Combinaison bonne 2,3,4 BLEU */
  test_joker_3[7]->nbr=1;
  test_joker_3[7]->clr=bleu;
  test_joker_3[8]->nbr=2;
  test_joker_3[8]->clr=bleu;
  test_joker_3[9]->nbr=3;
  test_joker_3[9]->clr=bleu;
  /* Combinaison bonne 4,5,6 et 7 BLEU */
  test_joker_3[11]->nbr=3;
  test_joker_3[11]->clr=bleu;
  test_joker_3[12]->nbr=4;
  test_joker_3[12]->clr=bleu;
  test_joker_3[13]->nbr=5;
  test_joker_3[13]->clr=bleu;
  test_joker_3[10]->nbr=6;
  test_joker_3[10]->clr=bleu;
  /* Tuile qui est supprimée pour que le chevalet puisse avoir 14 tuiles */
  test_joker_3[14]->nbr=V_DEL;
  test_joker_3[14]->clr=bleu;


  /* Chevalet avec 3 même tuile 2 BLEU en forme 2C3 et 1C4 et un autre 1C4 */
  /* Combinaison bonne 2,3 et 4 BLEU */
  test_joker_4[0]->nbr=1;
  test_joker_4[0]->clr=bleu;
  test_joker_4[1]->nbr=2;
  test_joker_4[1]->clr=bleu;
  test_joker_4[2]->nbr=3;
  test_joker_4[2]->clr=bleu;
  /* Combinaison bonne 2,3,4 et 5 BLEU */
  test_joker_4[3]->nbr=1;
  test_joker_4[3]->clr=bleu;
  test_joker_4[4]->nbr=2;
  test_joker_4[4]->clr=bleu;
  test_joker_4[5]->nbr=3;
  test_joker_4[5]->clr=bleu;
  test_joker_4[6]->nbr=4;
  test_joker_4[6]->clr=bleu;
  /* Combinaison bonne 13,1 et 2 BLEU */
  test_joker_4[7]->nbr=12;
  test_joker_4[7]->clr=bleu;
  test_joker_4[8]->nbr=0;
  test_joker_4[8]->clr=bleu;
  test_joker_4[9]->nbr=1;
  test_joker_4[9]->clr=bleu;
  /* Combinaison bonne 5,6,7 et 8 BLEU */
  test_joker_4[11]->nbr=12;
  test_joker_4[11]->clr=bleu;
  test_joker_4[12]->nbr=11;
  test_joker_4[12]->clr=bleu;
  test_joker_4[13]->nbr=10;
  test_joker_4[13]->clr=bleu;
  test_joker_4[10]->nbr=9;
  test_joker_4[10]->clr=bleu;
  /* Tuile qui est supprimée pour que le chevalet puisse avoir 14 tuiles */
  test_joker_4[14]->nbr=V_DEL;
  test_joker_4[14]->clr=bleu;

  /* Test des situations suivantes
     Exemple: 2 chevalets avec 4 même tuiles
              2 chevalets avec 3 même tuiles
  */

  /* Affichage d'un chevalet jokers */
  printf("\n4 MEME TUILE\n");
  printf("\nEXEMPLE DE CHEVALET 2C3 et 2C5\n");
  printf("\nVERIFICATION DE COMBINAISONS AVEC JOKERS\n");
  printf("\n---------------AVANT-------------\n");
  affiche_tuile(test_joker,taille_tuile(test_joker,sizeof(test_joker)));
  /* Vérification des combinaisons du chevalet */
  combinaison_suite(test_joker);
  /* Affichage du résultat */
  printf("\n---------------APRES-------------\n");
  affiche_tuile(test_joker,taille_tuile(test_joker,sizeof(test_joker)));
  printf("\n----------------FIN--------------\n");

  /* Affichage d'un chevalet jokers */
  printf("\n4 MEME TUILE\n");
  printf("\nEXEMPLE DE CHEVALET 3C3 et 1C5\n");
  printf("\nVERIFICATION DE COMBINAISONS AVEC JOKERS\n");
  printf("\n---------------AVANT-------------\n");
  affiche_tuile(test_joker_2,taille_tuile(test_joker_2,sizeof(test_joker_2)));
  /* Vérification des combinaisons du chevalet */
  combinaison_suite(test_joker_2);
  /* Affichage du résultat */
  printf("\n---------------APRES-------------\n");
  affiche_tuile(test_joker_2,taille_tuile(test_joker_2,sizeof(test_joker_2)));
  printf("\n----------------FIN--------------\n");

  /* Affichage d'un chevalet jokers */
  printf("\n3 MEME TUILE\n");
  printf("\nEXEMPLE DE CHEVALET 2C3, 1C4 et un autre 1C4 sans JOKER\n");
  printf("\nVERIFICATION DE COMBINAISONS AVEC JOKERS\n");
  printf("\n---------------AVANT-------------\n");
  affiche_tuile(test_joker_3,taille_tuile(test_joker_3,sizeof(test_joker_3)));
  /* Vérification des combinaisons du chevalet */
  combinaison_suite(test_joker_3);
  /* Affichage du résultat */
  printf("\n---------------APRES-------------\n");
  affiche_tuile(test_joker_3,taille_tuile(test_joker_3,sizeof(test_joker_3)));
  printf("\n----------------FIN--------------\n");

  /* Affichage d'un chevalet jokers */
  printf("\n3 MEME TUILE\n");
  printf("\nEXEMPLE DE CHEVALET 2C3, 1C4 et un autre 1C4 sans JOKER\n");
  printf("\nVERIFICATION DE COMBINAISONS AVEC JOKERS\n");
  printf("\n---------------AVANT-------------\n");
  affiche_tuile(test_joker_4,taille_tuile(test_joker_4,sizeof(test_joker_4)));
  /* Vérification des combinaisons du chevalet */
  combinaison_suite(test_joker_4);
  /* Affichage du résultat */
  printf("\n---------------APRES-------------\n");
  affiche_tuile(test_joker_4,taille_tuile(test_joker_4,sizeof(test_joker_4)));
  printf("\n----------------FIN--------------\n");

  /* Destruction du chevalet joker */
  detruire_tuile(test_joker,taille_tuile(test_joker,sizeof(test_joker)));
  detruire_tuile(test_joker_2,taille_tuile(test_joker_2,sizeof(test_joker_2)));
  detruire_tuile(test_joker_3,taille_tuile(test_joker_3,sizeof(test_joker_3)));
  detruire_tuile(test_joker_4,taille_tuile(test_joker_4,sizeof(test_joker_4)));
}
