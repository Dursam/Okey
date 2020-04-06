/* Fichier contenant les fonctions principaux pour lancer une partie de Okey */

#include <init_structure.h>
#include <init_pile.h>
#include <affichage_tuile.h>
#include <combinaison_couleur.h>
#include <combinaison_suite_entiers.h>
#include <selection_tuile.h>

/* Donne une valeur + 1 de la tuile retournée (le okey) à la tuile joker rouge ou noire posséder par le joueur */
extern
void valeur_okey(t_tuile * okey,t_tuile * joker){

  if(joker->nbr == 13 && (joker->clr == noire || joker->clr == rouge)){
    // Si la tuile est 13 alors on l'incrémente, ce qui nous donne 1
    if(okey->nbr == 12){
      joker->nbr = 0;
      joker->clr = okey->clr;
    }
    // On incrément le joker et on associe la couleur du okey au joker
    else{
      joker->nbr = okey->nbr + 1;
      joker->clr = okey->clr;
    }
  }
}

/* Affichage du sommet des piles de tout les joueurs */
extern
void affiche_plateau(t_tuile * okey,t_pile * p1,t_pile * p2,t_pile * p3,t_pile * p4){

  printf("\n\t");
  affiche_sommet_pile(p1);
  printf("\t\t\t\t\t");
  affiche_sommet_pile(p2);

  // Cas d'affichage pour éviter d'espacer les nombres à 2 chiffres
  printf("\n\t\t\t   OKEY\tPIOCHE\n\t\t\t   ");

  if(okey->nbr < 9){
    printf("%i ",(okey->nbr)+1);
    switch (okey->clr){
      case jaune: printf("\033[34;43m__\033[00m\t");break;
      case rouge: printf("\033[34;41m__\033[00m\t");break;
      case noire: printf("\033[34;40m__\033[00m\t");break;
      case bleu:  printf("\033[34;44m__\033[00m\t");break;
    }
  }
  else{
    printf("%i",(okey->nbr)+1);
    switch (okey->clr){
      case jaune: printf("\033[34;43m__\033[00m\t");break;
      case rouge: printf("\033[34;41m__\033[00m\t");break;
      case noire: printf("\033[34;40m__\033[00m\t");break;
      case bleu:  printf("\033[34;44m__\033[00m\t");break;
    }
  }

  printf("\033[34;47m__\033[00m  \033[34;47m__\033[00m\n\n\t");
  affiche_sommet_pile(p3);
  printf("\t\t\t\t\t");
  affiche_sommet_pile(p4);
  printf("\n\n");

}

/* Début de partie en fonction de la tuile de démarrage */
extern
void debut_partie(t_tuile * chevalet[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int dem){

  tri_rapide(chevalet,0,13);

  if(dem == 1){
    affiche_plateau(okey,pile_J3,pile_J2,pile_J4,pile_J1);
  }
  else if(dem == 2){
    affiche_plateau(okey,pile_J4,pile_J3,pile_J1,pile_J2);
  }
  else if(dem == 3){
    affiche_plateau(okey,pile_J1,pile_J4,pile_J2,pile_J3);
  }
  else if(dem == 4){
    affiche_plateau(okey,pile_J2,pile_J1,pile_J3,pile_J4);
  }
  affiche_chevalet(chevalet,N_CHEV);
}

/* Dépile toutes les piles de tuiles, utilisé pour finir la partie */
extern
void depiler_toutes_tuiles(t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4){

  /* Compteurs qui compte le nombre d'élément d'une pile de tuile */
  int cpt_p1, cpt_p2, cpt_p3, cpt_p4;

  /* On dépile toute les piles si elle possèdent des éléments */
  cpt_p1 = compte_element(pile_J1);
  cpt_p2 = compte_element(pile_J2);
  cpt_p3 = compte_element(pile_J3);
  cpt_p4 = compte_element(pile_J4);

  while(cpt_p1 > 0){
    depiler(pile_J1);
    cpt_p1--;
  }

  while(cpt_p2 > 0){
    depiler(pile_J2);
    cpt_p2--;
  }

  while(cpt_p3 > 0){
    depiler(pile_J3);
    cpt_p3--;
  }

  while(cpt_p4 > 0){
    depiler(pile_J4);
    cpt_p4--;
  }
}
