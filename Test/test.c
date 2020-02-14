#include "./test.h"

#define N 106
#define J 15

void initTules(t_tule * jeu[N]){

  int i,j,k;

  t_couleur couleur = jaune;

  for (i = 0;i < N ; i++){
    jeu[i] = (t_tule *)malloc(sizeof(t_tule));
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

void creer_joueur(t_tule * joueur[J]){

  for (int i = 0; i < J; i++) {
    joueur[i] = (t_tule *)malloc(sizeof(t_tule));
  }

}

void detruire_Tules(t_tule * jeu[],int taille){

  for (int i = 0; i < taille; i++) {
    free(jeu[i]);
    jeu[i] = NULL;
  }
}

void affJeu(t_tule * jeu[],int taille){

  for(int i = 0; i < taille; i++){
    printf("%i ",(jeu[i]->nbr)+1);
    switch (jeu[i]->clr) {
      case jaune: printf(" JAUNE\n");break;
      case rouge: printf(" ROUGE\n");break;
      case noire: printf(" NOIRE\n");break;
      case bleu:  printf(" BLEU\n");break;
    }
  }
}

void distribution(t_tule * jeu[N], t_tule * j1[J]){

  unsigned int i,elem;

  srand(time(NULL));

  elem = rand() % (105 + 1 - 0) + 0;

  for (i = 0; i <=14 ; i++) {
    while((jeu[elem] == NULL))
      elem = rand() % (105 + 1 - 0) + 0;
    j1[i]->nbr = jeu[elem]->nbr;
    j1[i]->clr = jeu[elem]->clr;
    free(jeu[elem]);
    jeu[elem] = NULL;
 }
}

int nombreTules(t_tule * jeu[],int taille_jeu){

  int i = taille_jeu/sizeof(t_tule);

  return i;
}

int main (void){

  t_tule * jeu[N],* j1[J];

  int i,j,k;

  initTules(jeu);

  affJeu(jeu,nombreTules(jeu,sizeof(jeu)));

  creer_joueur(j1);

  distribution(jeu,j1);

  printf("Jeu du joueur \n\n\n");

  affJeu(j1,nombreTules(j1,sizeof(j1)));

  printf("\n\n");

  detruire_Tules(jeu,nombreTules(jeu,sizeof(jeu)));

  detruire_Tules(j1,nombreTules(j1,sizeof(j1)));

  return 0;
}
