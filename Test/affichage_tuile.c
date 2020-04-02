/* Fichier contenant les fonctions d'affichages */

#include <init_pile.h>
#include <affichage_tuile.h>

/* Affichage des 14/15 tuiles du chevalet */
extern
void affiche_chevalet(t_tuile * jeu[],int taille){

  int i;

  printf("\033[1;32m\t\b\t1\t2\t3\t4\t5\t6\t7\t\033[00m");
  printf("\n\t------------------------------------------------------\n");

  for(i = 0;i < taille;i++){

    if(i == 0)
      printf("\t|");
    if(i == 14 && jeu[14]->nbr != V_DEL)
      printf("--------------->");

    if(jeu[i]->nbr == V_DEL)                // Cas d'affichage où la tuile a été supprimer
      printf("\t");
    else{
      if(jeu[i]->nbr==13){                  // Cas d'affichage pour tuiles okey rouge et noire
          if(jeu[i]->clr==noire)
            printf("OK\033[34;40m__\033[00m\t");
          else if(jeu[i]->clr==rouge)
            printf("OK\033[34;41m__\033[00m\t");
      }
      else{                                 // Cas d'affichage des tuiles de 1 à 13 des 4 couleurs différentes
        if(jeu[i]->nbr < 9){
          printf("%i ",(jeu[i]->nbr)+1);
          switch (jeu[i]->clr){
            case jaune: printf("\033[34;43m__\033[00m\t");break;
            case rouge: printf("\033[34;41m__\033[00m\t");break;
            case noire: printf("\033[34;40m__\033[00m\t");break;
            case bleu:  printf("\033[34;44m__\033[00m\t");break;
          }
        }
        else{                                // Cas d'affichage pour éviter d'espacer les nombres à 2 chiffres
          printf("%i",(jeu[i]->nbr)+1);
          switch (jeu[i]->clr){
            case jaune: printf("\033[34;43m__\033[00m\t");break;
            case rouge: printf("\033[34;41m__\033[00m\t");break;
            case noire: printf("\033[34;40m__\033[00m\t");break;
            case bleu:  printf("\033[34;44m__\033[00m\t");break;
          }
        }
      }
      if(i == 6)
        printf("\b\b\b|");
      if(i == 13)
        printf("\b\b\b|");
    }
    if(i == 6 && jeu[14]->nbr == V_DEL)
      printf("\n\t|\t\t\t\t\t\t\t\b\b\b|\n\t|");
    else if(i == 6 && jeu[14]->nbr != V_DEL)
      printf("\n\t|\t\t\t\t\t\t\t\b\b\b| NOUVELLE TUILE \n\t|");
  }
  printf("\n\t------------------------------------------------------\n");
  printf("\033[1;32m\t\b\t8\t9\t10\t11\t12\t13\t14\n\033[00m");
}

/* Affichage du sommet d'une pile */
extern
void affiche_sommet_pile(t_pile * pile){

  t_tuile * tuile;

  if(pile_vide(pile))
    printf("* \033[34;47m__\033[00m\t");
  else{
    sommet_pile(pile,&tuile);

    if(tuile->nbr < 9){
      printf("%i ",(tuile->nbr)+1);
      switch (tuile->clr){
        case jaune: printf("\033[34;43m__\033[00m\t");break;
        case rouge: printf("\033[34;41m__\033[00m\t");break;
        case noire: printf("\033[34;40m__\033[00m\t");break;
        case bleu:  printf("\033[34;44m__\033[00m\t");break;
      }
    }
    else{
      printf("%i",(tuile->nbr)+1);
      switch (tuile->clr){
        case jaune: printf("\033[34;43m__\033[00m\t");break;
        case rouge: printf("\033[34;41m__\033[00m\t");break;
        case noire: printf("\033[34;40m__\033[00m\t");break;
        case bleu:  printf("\033[34;44m__\033[00m\t");break;
      }
    }
  }
}

/* Affichage du sommet des piles de tout les joueurs */
extern
void affiche_pile(t_pile * p1,t_pile * p2,t_pile * p3,t_pile * p4){

  printf("\n\t");
  affiche_sommet_pile(p1);
  printf("\t\t\t\t\t");
  affiche_sommet_pile(p2);
  printf("\n\t\t\t\tPIOCHE\n\t\t\t\t\033[34;47m__\033[00m  \033[34;47m__\033[00m\n\n\t");
  affiche_sommet_pile(p3);
  printf("\t\t\t\t\t");
  affiche_sommet_pile(p4);
  printf("\n\n");

}
