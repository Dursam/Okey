#include <init_structure.h>
#include <init_pile.h>
#include <affichage_tuile.h>
#include <selection_tuile.h>

/**
* \file selection_tuile.c
* \brief Fichier contenant les fonctions pour sélectionner une tuile
* \author Samuel DURAN
* \version 1.0
* \date 12 avril 2020
*/

/**
* \fn void init_enr_tuile(t_tuile * enr[], int taille)
* \brief Initialise un tableau de struture de tuile pour enregistrer les tuiles qui seront empilées
* \param enr[] Tableau des tuiles enregistrées
* \param taille Taille du tableau
*/
extern
void init_enr_tuile(t_tuile * enr[],int taille){

  for(int i = 0;i<taille;i++)
    enr[i] = NULL;
}

/**
* \fn void test_enr_tuile(t_tuile * jeu[N_T], t_tuile * enr[], t_pile, int taille)
* \brief Créer une tuile, lui affecte une valeur puis l'empile sur une pile 
* \param jeu[N_T] Tableau des tuiles
* \param enr[] Tableau des tuiles enregistrées
* \param pile Pile où la tuile est empilée
* \param taille Taille du tableau
*/
extern
void test_enr_tuile(t_tuile * jeu[N_T],t_tuile * enr[],t_pile * pile,int taille){

  int i = 0,statut = 0;

  while(statut == 0){
    if(enr[i] == NULL){
      enr[i] = creer_tuile();
      *enr[i] = distribution_pioche(jeu);
      empiler(pile,enr[i]);
      //printf("Test %i\n",enr[i]->nbr+1);
      statut = 1;
    }
    else if(i == taille)
      statut = 1;
    else
      i++;
  }
}

/**
* \fn void empile_enr_tuile(t_tuile * chevalet[N_CHEV], t_tuile * enr[], t_pile * pile, int taille, int numero)
* \brief Créer une tuile, lui affecte une valeur puis l'empile sur une pile 
* \param chevalet[N_CHEV] Chevalet du joueur
* \param enr[] Tableau des tuiles enregistrées
* \param pile Pile où la tuile est empilée
* \param taille Taille du tableau
* \param numéro ???
*/
extern
void empile_enr_tuile(t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pile,int taille,int numero){

  int i = 0,statut = 0;

  while(statut == 0){
    if(enr[i] == NULL){
      enr[i] = creer_tuile();
      enr[i]->nbr = chevalet[numero]->nbr;
      enr[i]->clr = chevalet[numero]->clr;
      empiler(pile,enr[i]);
      //printf("Test %i\n",enr[i]->nbr+1);
      statut = 1;
    }
    else if(i == taille)
      statut = 1;
    else
      i++;
  }

  chevalet[numero]->nbr = chevalet[14]->nbr;
  chevalet[numero]->clr = chevalet[14]->clr;
  chevalet[14]->nbr = V_DEL;
}

/**
* \fn void selection_tuile(t_tuile * jeu[N_T], t_tuile * chevalet[N_CHEV], t_tuile * enr[], t_pile * pfg, t_pile * pfd, t_pile * pg, t_pile * pd)
* \brief Permet de sélection une tuile soit de la pioche ou de la pile de gauche et retire une tuile du chevalet, version avec affiche_pile 
* \param jeu[N_T] Tableau contenant les tuiles
* \param chevalet[N_CHEV] Chevalet du joueur
* \param enr[] ???
* \param pfg ???
* \param pfd ???
* \param pg ???
* \param pd ???
*/
extern
void selection_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd){

  int numero,* choix = malloc(sizeof(int));

  t_tuile * tuile_sommet;

  affiche_pile(pfg,pfd,pg,pd);
  affiche_chevalet(chevalet,N_CHEV);

  do{
  printf("CHOIX : PIOCHE(0) OU PILE DE GAUCHE(1) ? ");
  scanf("%i",choix);
} while(*choix != 0 && *choix != 1);


  if(*choix==0){                       
    printf("TU PIOCHE\n");
    *chevalet[14] = distribution_pioche(jeu);
    printf("%i\n",jeu[14]->nbr);
  }
  else{
    printf("TU PREND LA TUILE DE LA PILE\n");
    sommet_pile(pg,&tuile_sommet);
    chevalet[14]->nbr = tuile_sommet->nbr;
    chevalet[14]->clr = tuile_sommet->clr;
    depiler(pg);

  }
  printf("%i\n",chevalet[14]->nbr+1);
  affiche_pile(pfg,pfd,pg,pd);
  affiche_chevalet(chevalet,N_CHEV);

  printf("CHOIX : RETIRER UN NUMERO DE TUILE (1 à 15) ? ");
  scanf("%i",&numero);

  empile_enr_tuile(chevalet,enr,pd,N_CHEV,numero-1);

  affiche_pile(pfg,pfd,pg,pd);
  affiche_chevalet(chevalet,N_CHEV);

  free(choix);
}
