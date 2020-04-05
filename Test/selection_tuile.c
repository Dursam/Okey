/* Fichier contenant les fonctions pour selectionner une tuile */

#include <init_structure.h>
#include <init_pile.h>
#include <affichage_tuile.h>
#include <selection_tuile.h>

/* Fonction qui initialise un tableau de struture de tuile pour enregistrer les tuiles qui seront empilés */
extern
void init_enr_tuile(t_tuile * enr[],int taille){

  for(int i = 0;i<taille;i++)
    enr[i] = NULL;
}

/* Fonction qui creer une tuile, lui affecte une valeur puis l'empile sur une pile */
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

/* Fonction qui creer une tuile, lui affecte une valeur puis l'empile sur une pile */
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

/* Fonction qui permet de sélection une tuile soit de la pioche ou de la pile de gauche et retire une tuile du chevalet */
extern
void selection_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd){

  char choix;

  int numero;

  t_tuile * tuile_sommet;

  affiche_pile(pfg,pfd,pg,pd);
  affiche_chevalet(chevalet,N_CHEV);

  printf("CHOIX : PIOCHE(ENTER) OU PILE DE GAUCHE(ANY KEY) ? ");
  scanf("%c",&choix);


  if(choix==0x0A){                          // Code ASCII pour la touche Entree
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
}
