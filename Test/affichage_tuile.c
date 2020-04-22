#include <init_pile.h>
#include <affichage_tuile.h>

/**
* \file affichage_tuile.c
* \brief Fichier contenant les fonctions d'affichages
* \author Samuel DURAN
* \version 1.0
* \date 12 avril 2020
*/

/**
* \fn void permuter(t_tuile * tab[N_CHEV], int i, int j)
* \brief Permute les indices de tuiles d'un chevalet
* \param chev[N_CHEV] Chevalet
* \param i Premier indice à permuter
* \param j Deuxième indice à permuter
*/
static
void permuter(t_tuile * chev[N_CHEV], int i, int j){

  t_tuile * sav = chev[i];
  chev[i] = chev[j];
  chev[j] = sav;
}

/**
* \fn int partition(t_tuile * chev[N_CHEV], int deb, int fin, int pivot)
* \brief Echange les tuiles d'un chevalet utile pour les fonctions de tri
* \param chev[N_CHEV] Chevalet
* \param deb Début du tri
* \param fin Fin du tri
* \param pivot Valeur pivot
* \return Nouvel indice de tuile
*/
static
int partition(t_tuile * chev[N_CHEV], int deb, int fin, int pivot){

    int j = deb;
    for(int i=deb+1; i<=fin; i++){
      if(chev[i]->nbr<pivot){
        j++;
        permuter(chev, j, i);
      }
    }
    permuter(chev,j,deb);
    return (j);
}

/**
* \fn void tri_manuel(t_tuile * chevalet[N_CHEV])
* \brief Tri manuel d'un chevalet de tuiles
* \param chevalet[N_CHEV] Chevalet
*/
extern
void tri_manuel(t_tuile * chevalet[N_CHEV]){

    int i=-1, j=-1;

    printf("Quelles tuiles voulez-vous échanger?\n\nLa première Tuile : ");

    while(i == -1 || (i<0 && i>N_CHEV-1))
      scanf("%d", &i);

    printf("La deuxième Tuile : ");

    while(j == -1 || (j<0 && j>N_CHEV-1))
      scanf("%d",&j);

    permuter(chevalet, i-1, j-1);

    affiche_chevalet(chevalet, N_CHEV);

    printf("\n\n");
}

/**
* \fn void tri_rapide(t_tuile * chevalet[], int i, int j)
* \brief Tri rapide d'un chevalet de tuiles
* \param chevalet Chevalet du jeu
* \param i Première valeur
* \param j Deuxième valeur
*/
extern
void tri_rapide(t_tuile * chevalet[], int i, int j) {

    int k;

    if (i < j) {
        k = partition(chevalet, i, j, chevalet[i]->nbr);
        tri_rapide(chevalet, i, k);
        tri_rapide(chevalet, k+1, j);
    }
}

/**
* \fn void affiche_chevalet(t_tuile * jeu[], int taille)
* \brief Affichage des 14/15 tuiles du chevalet
* \param jeu[] Chevalet
* \param taille Taille du chevalet
*/
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

    if(jeu[i]->nbr == V_DEL)                // Cas d'affichage où la tuile a été supprimée
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
      printf("\n\t|\t\t\t\t\t\t\t\b\b\b| NOUVELLE TUILE \033[1;32m15\033[00m\n\t|");
  }
  printf("\n\t------------------------------------------------------\n");
  printf("\033[1;32m\t\b\t8\t9\t10\t11\t12\t13\t14\n\033[00m");
}

/**
* \fn void affiche_sommet_pile(t_pile * pile)
* \brief ffichage du sommet d'une pile
* \param pile Pile à afficher
*/
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

/**
* \fn void affiche_pile(t_pile * p1, t_pile * p2, t_pile * p3, t_pile * p4)
* \brief Affichage du sommet des piles de tous les joueurs
* \param p1 Pile du joueur 1
* \param p2 Pile du joueur 2
* \param p3 Pile du joueur 3
* \param p4 Pile du joueur 4
*/
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
