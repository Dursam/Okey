#include "./test.h"


t_tule * initTules(void){

  t_tule * jeu = malloc(sizeof(t_tule));

  jeu->nbr = 1;

  jeu->clr = jaune;

  return jeu;
}


int main (void){

  t_tule * jeu1;



  jeu1 = initTules();

  printf("Chiffre %i",jeu1->nbr);

  switch (jeu1->clr) {
    case jaune: printf(" JAUNE\n");break;
    case rouge: printf(" ROUGE\n");break;
    case noire: printf(" NOIRE\n");break;
    case bleu:  printf(" BLEU\n");break;
  }

  free(jeu1);

  return 0;
}
