/* L'objectif de ce fichier est de tester le tableau de structure de tuiles */

#include <init_structure.h>

int main (void){

  /* TEST */
  /* Variables d'initialisation */
  t_tuile * jeu[N_T],* j1[N_CHEV],* j2[N_CHEV],* j3[N_CHEV],* j4[N_CHEV], * tuile_okey;

  /* initialisation du jeu */
  init_tuile(jeu);

  /* Affiche la liste complète des tuiles du jeu */
  affiche_chaque_tuile(jeu,taille_tuile(jeu,sizeof(jeu)));

  /* On initialise les joueurs et on leur donne 14 tuiles chacun avec un joueur au hasard qui démarre */
  creer_chevalet(j1,N_CHEV);
  creer_chevalet(j2,N_CHEV);
  creer_chevalet(j3,N_CHEV);
  creer_chevalet(j4,N_CHEV);

  distribution_joueur(jeu,j1);
  distribution_joueur(jeu,j2);
  distribution_joueur(jeu,j3);
  distribution_joueur(jeu,j4);

  demarrage(jeu,j1,j2,j3,j4);

  /* On affiche les chevalets des joueurs */
  printf("Jeu du J1 %i \n\n\n",taille_tuile(j1,sizeof(j1)));
  affiche_chaque_tuile(j1,taille_tuile(j1,sizeof(j1)));
  printf("\nJeu du J2 %i \n\n\n",taille_tuile(j2,sizeof(j2)));
  affiche_chaque_tuile(j2,taille_tuile(j2,sizeof(j2)));
  printf("\nJeu du J3 %i \n\n\n",taille_tuile(j3,sizeof(j3)));
  affiche_chaque_tuile(j3,taille_tuile(j3,sizeof(j3)));
  printf("\nJeu du J4 %i \n\n\n",taille_tuile(j4,sizeof(j4)));
  affiche_chaque_tuile(j4,taille_tuile(j4,sizeof(j4)));

  /* On test la distribution d'une tuile parmi le jeu existant */
  printf("\nTEST pour une tuile\n\n");
  tuile_okey = creer_tuile();
  *tuile_okey = distribution_pioche(jeu);
  affiche_chaque_tuile(&tuile_okey,taille_tuile(&tuile_okey,sizeof(tuile_okey)));
  detruire_tuile(&tuile_okey,sizeof(tuile_okey));

  /* On détruit le jeu et les chevalets */
  detruire_tuile(jeu,taille_tuile(jeu,sizeof(jeu)));
  detruire_tuile(j1,taille_tuile(j1,sizeof(j1)));
  detruire_tuile(j2,taille_tuile(j2,sizeof(j2)));
  detruire_tuile(j3,taille_tuile(j3,sizeof(j3)));
  detruire_tuile(j4,taille_tuile(j4,sizeof(j4)));

  return 0;
}
