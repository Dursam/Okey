#include "./test.h"

#define N 52
#define J 15

void initTules(t_tule * jeu[N]){

  int i;

  t_couleur couleur = jaune;

  for (int j = 0; j < N; j++) {
    jeu[j] = (t_tule *)malloc(sizeof(t_tule));
  }

  for(i=0;i<N;i++){
    jeu[i]->clr = couleur;
    jeu[i]->nbr = i%13;
    if((i+1) % 13 == 0)
      couleur++;
  }
}

void detruire_Tules(t_tule * jeu[N]){

  for (int i = 0; i < N; i++) {
    free(jeu[i]);
  }
}

void affJeu(t_tule * jeu[N]){

  for(int i = 0; i < N; i++){
    printf("%i ",(jeu[i]->nbr)+1);
    switch (jeu[i]->clr) {
      case jaune: printf(" JAUNE\n");break;
      case rouge: printf(" ROUGE\n");break;
      case noire: printf(" NOIRE\n");break;
      case bleu:  printf(" BLEU\n");break;
    }
  }
}

void creer_joueur(t_tule * joueur[J]){

  for (int i = 0; i < J; i++) {
    joueur[i] = (t_tule *)malloc(sizeof(t_tule));
  }

}

void detruire_joueur(t_tule * joueur[J]){

  for (int i = 0; i < J; i++) {
    free(joueur[i]);
  }
}

void distribution(t_tule * jeu[N], t_tule * j1[J], t_tule * j2[J], t_tule * j3[J], t_tule * j4[J]){


}

int main (void){

  t_tule * jeu[N],* j1[J];

  int i = 0;

  initTules(jeu);

  affJeu(jeu);

  creer_joueur(j1);

  detruire_joueur(j1);

  detruire_Tules(jeu);

  return 0;
}
