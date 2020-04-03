/* L'objectif de ce fichier est d'affiché correctement un chevalet et les 4 piles de tuiles selon un scénario */

#include <init_structure.h>
#include <init_pile.h>
#include <affichage_tuile.h>

int main(void){
  printf("test\n");
  /* On initialise les joueurs et on leur donne 14 tuiles chacun avec un joueur au hasard qui démarre */
  t_tuile * jeu[N_T],* joueur[N_CHEV],* tuile_p1,* tuile_p2,* tuile_p3,* tuile_p4;
  t_pile * pile_droite = malloc(sizeof(t_pile)),* pile_gauche = malloc(sizeof(t_pile)),
  * pile_fond_droit = malloc(sizeof(t_pile)),* pile_fond_gauche = malloc(sizeof(t_pile));

  /* On initialise les tuiles pour des piles de tuiles et d'une tuile pioché */
  tuile_p1 = creer_tuile();
  tuile_p2 = creer_tuile();
  tuile_p3 = creer_tuile();
  tuile_p4 = creer_tuile();
  init_pile(pile_gauche);
  init_pile(pile_droite);
  init_pile(pile_fond_droit);
  init_pile(pile_fond_gauche);

  /* On initialise les joueurs et on leur donne 14 tuiles chacun avec un joueur au hasard qui démarre */
  creer_chevalet(joueur,N_CHEV);

  /* Distribution des tuiles */
  init_tuile(jeu);
  distribution_joueur(jeu,joueur);

  /* TEST AFFICHAGE 15 TUILES */
  printf("\n\t\t\tAFFICHAGE CHEVALET AVEC TUILE SELECTIONNE\n");
  printf("\n-------------------------------------15 TUILES-------------------------------------\n");
  /* On ajoute une tuile pour le 15 ème affichage */
  *joueur[14] = distribution_pioche(jeu);
  /* Affichage avec couleur pour 15 tuiles*/
  affiche_chevalet(joueur,N_CHEV);

  tri_rapide(joueur, 0, 13);

  affiche_chevalet(joueur,N_CHEV);
  printf("\n-------------------------------------FIN---------------------------------------------\n");

  /* TEST AFFICHAGE 14 TUILES */
  printf("\n\t\t\tAFFICHAGE CHEVALET NORMAL\n");
  printf("\n-------------------------------------14 TUILES-------------------------------------\n");
  /* On ajoute une tuile pour le 15 ème affichage */
  joueur[14]->nbr = V_DEL;
  /* Affichage avec couleur pour 15 tuiles*/
  affiche_chevalet(joueur,N_CHEV);
  printf("\n-------------------------------------FIN---------------------------------------------\n");

  /* TEST D'UN SCENARIO DE PILE DE TUILES */

  /* PIOCHE GAUCHE 2 FOIS */
  *tuile_p1 = distribution_pioche(jeu);
  empiler(pile_gauche,tuile_p1);
  *tuile_p1 = distribution_pioche(jeu);
  empiler(pile_gauche,tuile_p1);

  /* PIOCHE DROIT 2 FOIS */
  *tuile_p2 = distribution_pioche(jeu);
  empiler(pile_droite,tuile_p2);
  *tuile_p2 = distribution_pioche(jeu);
  empiler(pile_droite,tuile_p2);

  /* PIOCHE FOND DROIT 1 FOIS */
  *tuile_p3 = distribution_pioche(jeu);
  empiler(pile_fond_droit,tuile_p3);

  /* PIOCHE FOND DROIT 1 FOIS PUIS DEPILER APRES */
  *tuile_p4 = distribution_pioche(jeu);
  empiler(pile_fond_gauche,tuile_p4);
  depiler(pile_fond_gauche);

  /* TEST D'AFFICHAGE D'UNE SIMULATION DE PARTIE */
  printf("\n------------------------------------APERCU-------------------------------------------\n");
  /* Affiche le sommet de la pile de gauche */
  affiche_pile(pile_fond_gauche,pile_fond_droit,pile_gauche,pile_droite);
  affiche_chevalet(joueur,N_CHEV);

  /* On dépile toutes les tuiles */
  depiler(pile_gauche);
  depiler(pile_gauche);
  depiler(pile_droite);
  depiler(pile_droite);
  depiler(pile_fond_droit);

  /* On détruit les tuiles des piles gauche et droite */
  free(pile_gauche);
  free(pile_droite);
  free(pile_fond_gauche);
  free(pile_fond_droit);

  /* On détruit le jeu et les chevalets */
  detruire_tuile(&tuile_p1,taille_tuile(&tuile_p1,sizeof(tuile_p1)));
  detruire_tuile(&tuile_p2,taille_tuile(&tuile_p2,sizeof(tuile_p2)));
  detruire_tuile(&tuile_p3,taille_tuile(&tuile_p3,sizeof(tuile_p3)));
  detruire_tuile(&tuile_p4,taille_tuile(&tuile_p4,sizeof(tuile_p4)));
  detruire_tuile(jeu,taille_tuile(jeu,sizeof(jeu)));
  detruire_tuile(joueur,taille_tuile(joueur,sizeof(joueur)));
}
