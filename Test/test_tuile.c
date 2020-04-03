/* L'objectif de ce fichier est de tester les combinaisons gagnant des tuiles */

#include "./test.h"
#include <stdlib.h>
#include <time.h>
#define N 106
#define J 15

/* Initialise la pile */
void init_tuile(t_tuile * jeu[N]){

  int i,j,k;

  t_couleur couleur = jaune;

  for (i = 0;i < N ; i++){
    jeu[i] = (t_tuile *)malloc(sizeof(t_tuile));
  }
  for(j=0;j<N;j++){
    jeu[j]->clr = couleur;
    jeu[j]->nbr = j%13;
    if((j+1) % 26 == 0)
      couleur++;
    if(j == 104){
      jeu[j]->clr = noire;
      jeu[j]->nbr = 13;
    }
    if(j == 105){
      jeu[j]->clr = rouge;
      jeu[j]->nbr = 13;
    }
  }
}

/* Fonction qui renvoie la taille des tuiles alloués */
int taille_tuile(t_tuile * jeu[],int taille_jeu){

  int i = taille_jeu/sizeof(t_tuile);
  return i;
}

/* Fonction qui alloue une mémoire dynamique à un chevalet */
void creer_joueur(t_tuile * joueur[],int taille){

  for (int i = 0; i < taille; i++) {
    joueur[i] = (t_tuile *)malloc(sizeof(t_tuile));
    joueur[i]->nbr = 14;
  }
}

/* Fonction qui libère la mémoire d'une tuile */
void detruire_tuile(t_tuile * jeu[],int taille){

  for (int i = 0; i < taille; i++) {
    free(jeu[i]);
    jeu[i] = NULL;
  }
}

/* Affiche les tuiles un par un */
void affJeu(t_tuile * jeu[],int taille){

  //printf("La taille est de %i\n",taille);

  for(int i = 0; i < taille; i++){

    if(jeu[i]->nbr==14){
        printf("\n");
    }
    else{
      printf("%i ",(jeu[i]->nbr)+1);
      switch (jeu[i]->clr){
        case jaune: printf(" JAUNE\n");break;
        case rouge: printf(" ROUGE\n");break;
        case noire: printf(" NOIRE\n");break;
        case bleu:  printf(" BLEU\n");break;
      }
    }
  }
}

/* Fonction qui distribue 14 tuiles à un joueur */
void distribution_joueur(t_tuile * jeu[N], t_tuile * j1[J]){

  unsigned int i,elem;

  srand(time(NULL));

  elem = rand() % (105 + 1 - 0) + 0;

  for (i = 0; i < J-1 ; i++) {
    while((jeu[elem] == NULL))
      elem = rand() % (105 + 1 - 0) + 0;
    j1[i]->nbr = jeu[elem]->nbr;
    j1[i]->clr = jeu[elem]->clr;
    free(jeu[elem]);
    jeu[elem] = NULL;
 }
}

void shuffle(t_tuile * chev[J]){
  srand( time( NULL ) );
  for(int i = 0; i<20; i++){
    int sav1 = rand() % (J-1);
    int sav2 = rand() % (J-1);

    t_tuile * sav = chev[sav1];
    chev[sav1] = chev[sav2];
    chev[sav2] = sav;
  }
}


/* Fonction qui vérifie les ensembles de combinaisons de même couleur */
void combinaison_suite(t_tuile * chev[J]){
  for(int i = 0; i<13; i++){
    for
  }
}

/* Fonction qui vérifie les ensembles de combinaisons de même couleur */
void combinaison_suite(t_tuile * chev[J]){
  int cpt_comb = 0; //nombre de combinaisons
  int i=0;

  while(i<J-1){
    int cpt_len_comb = 1; //longueur de la combinaison

    while(i+1 < J && !(chev[i]->clr == chev[i+1]->clr &&  (chev[i]->nbr+1 == chev[i+1]->nbr || (chev[i]->nbr == 12 && chev[i+1]->nbr == 0)))){
      i++;
    }
    while(i+1 < J && chev[i]->clr == chev[i+1]->clr && (chev[i]->nbr+1 == chev[i+1]->nbr || (chev[i]->nbr == 12 && chev[i+1]->nbr == 0))){
      cpt_len_comb++;
      i++;
    }
    if(cpt_len_comb >2){
      cpt_comb++;
      for(int k=i+1-cpt_len_comb; k<=i; k++)
        affJeu(&chev[k], 1);
    }
    printf("\n");
  }
printf("Combinaisons:%d\n", cpt_comb);
}

/* Fonction qui vérifie les ensembles de combinaisons de couleur différente  */
void combinaison_coul(t_tuile * chev[J]){
  int cpt_comb = 0; //nombre de combinaisons
  int i=0;

  while(i<J-1){
    int cpt_len_comb = 1; //longueur de la combinaison

    while(i+1 < J && !(chev[i]->clr != chev[i+1]->clr && chev[i]->nbr == chev[i+1]->nbr)){
      i++;
    }
    while(i+1 < J && chev[i]->clr != chev[i+1]->clr && (chev[i]->nbr == chev[i+1]->nbr)){
      int can_continue = 1;
      for(int k = cpt_len_comb-1; k>0; k--){
          if( chev[i+1]->clr == chev[i-k]->clr ){
            can_continue= 0;
          }
      }
      if(can_continue){
        cpt_len_comb++;
        i++;
      }
      else break;
    }
    if(cpt_len_comb >2){
      cpt_comb++;
      for(int k=i+1-cpt_len_comb; k<=i; k++)
        affJeu(&chev[k], 1);
    }
    printf("\n");
  }
printf("Combinaisons:%d\n", cpt_comb);
}





int main(){

  /* On iniitialise les joueurs et on leur donne 14 tuiles chacun avec un joueur au hasard qui démarre */
  t_tuile * jeu[N],* j1[J],* jc[J];
  init_tuile(jeu);

  /* On iniitialise les joueurs et on leur donne 14 tuiles chacun avec un joueur au hasard qui démarre */
  creer_joueur(j1,J);
  creer_joueur(jc,J);

  /* Distribution des tuiles */
  distribution_joueur(jeu,j1);

  /* Creation d'une combinaison gagnante */
  /* Combinaison du numéro 1 avec 4 couleurs différentes */
  jc[0]->nbr=0;
  jc[0]->clr=bleu;
  jc[1]->nbr=0;
  jc[1]->clr=jaune;
  jc[2]->nbr=0;
  jc[2]->clr=rouge;
  jc[3]->nbr=0;
  jc[3]->clr=noire;
  /* Combinaison d'une suite de numéro (minimum de 3) */
  jc[4]->nbr=0;
  jc[4]->clr=bleu;
  jc[5]->nbr=1;
  jc[5]->clr=bleu;
  jc[6]->nbr=2;
  jc[6]->clr=bleu;
  jc[7]->nbr=3;
  jc[7]->clr=bleu;
  jc[8]->nbr=4;
  jc[8]->clr=bleu;
  jc[9]->nbr=5;
  jc[9]->clr=bleu;
  jc[10]->nbr=6;
  jc[10]->clr=bleu;
  /* Combinaison du numéro 10 avec 3 couleurs différentes */
  jc[11]->nbr=9;
  jc[11]->clr=noire;
  jc[12]->nbr=9;
  jc[12]->clr=rouge;
  jc[13]->nbr=9;
  jc[13]->clr=jaune;

  shuffle(jc);
  /* Affichage de tuiles */
  //printf("Jeu du J1 %i \n\n\n",taille_tuile(j1,sizeof(j1)));
  //affJeu(j1,taille_tuile(j1,sizeof(j1)));
  affJeu(jc,taille_tuile(jc,sizeof(jc)));

  /* Affichage des répétitions */
  combinaison_suite(jc);
  combinaison_coul(jc);

  /* On détruit le jeu et les chevalets */
  detruire_tuile(jeu,taille_tuile(jeu,sizeof(jeu)));
  detruire_tuile(j1,taille_tuile(j1,sizeof(j1)));
  detruire_tuile(jc,taille_tuile(jc,sizeof(jc)));


}
