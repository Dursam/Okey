/* L'objectif de ce fichier est de créer de tester les fonctions de sauvegarde et de score */
#include "./sauvegarde.h"

int main(){

  int num_partie;
  t_fichier * fichier;
  t_fichier * fichier2 = malloc(sizeof(t_fichier));

  fichier = nom_fichier();
  num_partie = numero_partie(fichier);
  //printf("Le numéro de partie est %i\n", num_partie);
  num_partie++;
  ajout_score(fichier,num_partie,0,0,1,0);
  num_partie++;
  ajout_score(fichier,num_partie,2,3,1,0);
  num_partie++;
  ajout_score(fichier,num_partie,1,0,1,5);
  //charger_partie(fichier2);
  afficher_scores(fichier,num_partie);

  free(fichier->nom);
  free(fichier);
  free(fichier2);
  printf("\n\n");
  return 0;
}
