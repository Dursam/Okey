/* L'objectif de ce fichier est de tester la pile de tuiles */

#include <init_structure.h>
#include <init_pile.h>

int main(){

  /* TEST */
  /* Variables d'initialisation */
  t_pile * pile = malloc(sizeof(t_pile));
  t_tuile * tuile_okey,* tuile_ok1,* tuile_test, * jeu[N_T];
  init_pile(pile);
  init_tuile(jeu);

  /* On distribue 2 tuiles parmi le jeu */
  tuile_okey = creer_tuile();
  *tuile_okey = distribution_pioche(jeu);
  tuile_ok1 = creer_tuile();
  *tuile_ok1 = distribution_pioche(jeu);

  /* On teste l'empilation et on affiche le sommmet de la pile et on affiche */
  empiler(pile,tuile_okey);
  empiler(pile,tuile_ok1);
  pile!=NULL?printf("\nOn affiche le sommet de la pile sans fct %i\n\n",pile->premier->tuile->nbr):printf("FAUX\n");

  /* On teste la récupération des valeurs du sommet de la pile et on affiche */
  sommet_pile(pile,&tuile_test);
  printf("\nOn affiche le sommet de la pile avec fct %i\n\n",tuile_test->nbr);

  /* On teste la désempilation et les destructions des tuiles empilés et de la pile */
  depiler(pile);
  sommet_pile(pile,&tuile_test);

  /* On teste la récupération des valeurs du sommet de la pile et on affiche */
  printf("\nOn affiche le sommet de la pile avec fct %i\n\n",tuile_test->nbr);
  depiler(pile);
  free(pile);

  /* On detruit les mémoires alloués du main */
  detruire_tuile(&tuile_okey,taille_tuile(&tuile_okey,sizeof(tuile_okey)));
  detruire_tuile(&tuile_ok1,taille_tuile(&tuile_okey,sizeof(tuile_okey)));
  detruire_tuile(jeu,taille_tuile(jeu,sizeof(jeu)));

  return 0;
}
