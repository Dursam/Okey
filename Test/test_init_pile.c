/* L'objectif de ce fichier est de tester la pile de tuiles */

#include <init_structure.h>
#include <init_pile.h>

int main(){

  /* TEST */
  /* Variables d'initialisation */
  int cpt;
  t_pile * pile = malloc(sizeof(t_pile));
  t_tuile * tuile_okey,* tuile_ok1,* tuile_test, * jeu[N_T];
  init_pile(pile);
  init_tuile(jeu);

  /* On distribue 2 tuiles parmi le jeu */
  tuile_okey = creer_tuile();
  *tuile_okey = distribution_pioche(jeu);
  tuile_ok1 = creer_tuile();
  *tuile_ok1 = distribution_pioche(jeu);

  /* On teste l'empilation et on affiche le sommmet de la pile */
  empiler(pile,tuile_okey);
  empiler(pile,tuile_ok1);
  pile!=NULL?printf("\nLe sommet de la pile est présente, c'est le nombre %i\n\n",pile->premier->tuile->nbr):printf("FAUX\n");

  /* On compte le nombre d'élément présent dans la pile */
  cpt = compte_element(pile);
  printf("La pile contient %i élement(s)\n",cpt);

  /* On teste la récupération des valeurs du sommet de la pile et on affiche */
  sommet_pile(pile,&tuile_test);
  printf("\nOn affiche le sommet de la pile avec fct %i\n\nOn retire une tuile\n\n",tuile_test->nbr);

  /* On teste la désempilation et les destructions des tuiles empilés et de la pile */
  depiler(pile);
  sommet_pile(pile,&tuile_test);

  /* On teste la récupération des valeurs du sommet de la pile et on affiche */
  printf("On affiche le sommet de la pile avec fct %i\n\n",tuile_test->nbr);
  depiler(pile);
  free(pile);

  /* On detruit les mémoires alloués du main */
  detruire_tuile(&tuile_okey,taille_tuile(&tuile_okey,sizeof(tuile_okey)));
  detruire_tuile(&tuile_ok1,taille_tuile(&tuile_okey,sizeof(tuile_okey)));
  detruire_tuile(jeu,taille_tuile(jeu,sizeof(jeu)));

  return 0;
}
