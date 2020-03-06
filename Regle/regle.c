#include "./regle.h"

void debut_partie(void){

  /* Variables d'initialisation */
  t_tuile * jeu[N],* j1[J],* j2[J],* j3[J],* j4[J],* pile_j1,* pile_j2,* pile_j3,* pile_j4;
  init_tuile(jeu);

  /* On iniitialise les joueurs et on leur donne 14 tuiles chacun avec un joueur au hasard qui démarre */
  creer_joueur(j1,J);
  creer_joueur(j2,J);
  creer_joueur(j3,J);
  creer_joueur(j4,J);

  /* On initialise les 4 piles */
  pile_j1 = creer_tuile();
  pile_j2 = creer_tuile();
  pile_j3 = creer_tuile();
  pile_j4 = creer_tuile();

  /* On distribue les tuiles du jeu au chevalet des joueurs */
  distribution_joueur(jeu,j1);
  distribution_joueur(jeu,j2);
  distribution_joueur(jeu,j3);
  distribution_joueur(jeu,j4);

  /* On choisi au hasard celui qui commence la partie en lui donnant une tuile suplementaire */
  demarrage(jeu,j1,j2,j3,j4);
}
