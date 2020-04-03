/* L'objectif de ce fichier est de selectioner une tuile à partir d'une pioche ou de la pile de gauche. */
/* Ensuite, on échange la tuile prise par une tuile du chevalet et on la pose sur la pile de droite */

#include <init_structure.h>
#include <init_pile.h>
#include <affichage_tuile.h>
#include <selection_tuile.h>

int main(){

  /* On initialise les joueurs et on leur donne 14 tuiles chacun avec un joueur au hasard qui démarre */
  t_tuile * jeu[N_T],* joueur[N_CHEV];

  t_tuile * tuile_p1[N_CHEV],* tuile_p2[N_CHEV],* tuile_p3[N_CHEV],* tuile_p4[N_CHEV];//,* tuile_sommet;

  t_pile * pile_droite,* pile_gauche,* pile_fond_droit,* pile_fond_gauche;

  /* On initialise les enregistrement pour l'empilement des tuiles sur leur piles respectives */
  init_enr_tuile(tuile_p1,N_CHEV);
  init_enr_tuile(tuile_p2,N_CHEV);
  init_enr_tuile(tuile_p3,N_CHEV);
  init_enr_tuile(tuile_p4,N_CHEV);

  /* Alloue Mémoire */
  pile_droite = malloc(sizeof(t_pile));
  pile_gauche = malloc(sizeof(t_pile));
  pile_fond_droit = malloc(sizeof(t_pile));
  pile_fond_gauche = malloc(sizeof(t_pile));

  /* On initialise les tuiles pour des piles de tuiles et d'une tuile pioché */
  init_pile(pile_droite);
  init_pile(pile_gauche);
  init_pile(pile_fond_droit);
  init_pile(pile_fond_gauche);

  /* On initialise les joueurs et on leur donne 14 tuiles chacun avec un joueur au hasard qui démarre */
  creer_chevalet(joueur,N_CHEV);

  /* Distribution des tuiles */
  init_tuile(jeu);
  distribution_joueur(jeu,joueur);

  // SCENARIO
  // PIOCHE GAUCHE 2 FOIS
  test_enr_tuile(jeu,tuile_p1,pile_gauche,N_CHEV);
  test_enr_tuile(jeu,tuile_p1,pile_gauche,N_CHEV);

  // PIOCHE DROIT 2 FOIS
  test_enr_tuile(jeu,tuile_p2,pile_droite,N_CHEV);
  test_enr_tuile(jeu,tuile_p2,pile_droite,N_CHEV);

  // PIOCHE FOND DROIT 1 FOIS
  test_enr_tuile(jeu,tuile_p3,pile_fond_droit,N_CHEV);

  // PIOCHE FOND GAUCHE 1 FOIS PUIS DEPILER APRES
  test_enr_tuile(jeu,tuile_p4,pile_fond_gauche,N_CHEV);
  depiler(pile_fond_gauche);

  // TEST D'AFFICHAGE D'UNE SIMULATION DE PARTIE
  printf("\n--------------------------------DEBUT DE TOUR----------------------------------------\n");
  // Affiche le sommet de la pile de gauche
  selection_tuile(jeu,joueur,tuile_p2,pile_fond_gauche,pile_fond_droit,pile_gauche,pile_droite);
  //affiche_chevalet(joueur,N_CHEV);
  //affiche_pile(pile_fond_gauche,pile_fond_droit,pile_gauche,pile_droite);

  // On dépile toutes les tuiles
  /*affiche_sommet_pile(pile_gauche);
  sommetpile(pile_gauche,&tuile_sommet);
  printf("On affiche le sommet de la pile avec fct %i\n",tuile_sommet->nbr+1);
  depiler(pile_gauche);
  affiche_sommet_pile(pile_gauche);
  sommetpile(pile_gauche,&tuile_sommet);
  printf("On affiche le sommet de la pile avec fct %i\n",tuile_sommet->nbr+1);*/
  depiler(pile_gauche);
  depiler(pile_gauche);
  depiler(pile_droite);
  depiler(pile_droite);
  depiler(pile_droite);
  depiler(pile_fond_droit);

  /* On détruit les tuiles des piles gauche et droite */
  free(pile_gauche);
  free(pile_droite);
  free(pile_fond_gauche);
  free(pile_fond_droit);

  /* On détruit le jeu et les chevalets */
  detruire_tuile(tuile_p1,taille_tuile(tuile_p1,sizeof(tuile_p1)));
  detruire_tuile(tuile_p2,taille_tuile(tuile_p2,sizeof(tuile_p2)));
  detruire_tuile(tuile_p3,taille_tuile(tuile_p3,sizeof(tuile_p3)));
  detruire_tuile(tuile_p4,taille_tuile(tuile_p4,sizeof(tuile_p4)));
  detruire_tuile(jeu,taille_tuile(jeu,sizeof(jeu)));
  detruire_tuile(joueur,taille_tuile(joueur,sizeof(joueur)));
}
