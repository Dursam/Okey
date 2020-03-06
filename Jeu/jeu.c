#include <affichage.h>
#include <fonctions_affichage.h>
#include <reseau.h>


void nouvellePartie(){
  int running =-1;
  char list2[4][30] = { "1 joueur et 3 bots", "2 joueurs et 2 bots", "3 joueurs et 1 bot", "4 joueurs" };
  running = afficher_menu(list2);
  attendreConnection(running+1);
}


void rejoindrePartie(){
  //char* ip = menuServeur()
}

void debut_partie(void){

  /* Variables d'initialisation */
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

void fin_partie(void){

  /* On détruit le jeu et les chevalets */
  detruire_tuile(jeu,taille_tuile(jeu,sizeof(jeu)));
  detruire_tuile(j1,taille_tuile(j1,sizeof(j1)));
  detruire_tuile(j2,taille_tuile(j2,sizeof(j2)));
  detruire_tuile(j3,taille_tuile(j3,sizeof(j3)));
  detruire_tuile(j4,taille_tuile(j4,sizeof(j4)));

  /* On détruit les 4 piles */
  detruire_tuile(&pile_j1,sizeof(pile_j1));
  detruire_tuile(&pile_j2,sizeof(pile_j2));
  detruire_tuile(&pile_j3,sizeof(pile_j3));
  detruire_tuile(&pile_j4,sizeof(pile_j4));
}
