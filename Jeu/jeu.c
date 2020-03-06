#include <affichage.h>
#include <fonctions_affichage.h>
#include <reseau.h>


void nouvellePartie(){
  char list2[4][30] = { "1 joueur et 3 bots", "2 joueurs et 2 bots", "3 joueurs et 1 bot", "4 joueurs" };
  running = afficher_menu(list2);
  attendreConnection(running+1);
}


void rejoindrePartie(){
  //char* ip = menuServeur()
}
