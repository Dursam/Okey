/* L'objectif de ce fichier est de tester la pile de tuiles */

#include "./test.h"
#define N 106

/* FONCTIONS DE LA PILE */
/* Initialise la pile */
void initpile(t_pile * pile){
  pile = NULL;
}

/* Fonction qui vérifie si la pile est vide */
int pilevide(t_pile * pile){
  return (pile == NULL);
}

/* Fonction qui empile une tuile */
void empiler(t_pile * pile,t_tuile * t){
  t_element * nouv;
  nouv=malloc(sizeof(t_element));
  nouv->tuile = t;
  nouv->suivant = pile->premier;
  pile->premier = nouv;
}

/* Fonction qui désempile une tuile */
void depiler(t_pile * pile){

  t_element * sommet;
  if(pile != NULL){
    sommet = pile->premier;
    pile->premier = sommet->suivant;
    free(sommet);
  }

}

/* Fonction qui pointe la tuile du sommet de la pile */
void sommetpile(t_pile * pile,t_tuile ** c){
  if(pile != NULL)
    *c = pile->premier->tuile;
}
/*-----------------------------------*/

/* Fonction qui distribus une tuile parmi le jeu des 106 tuiles, au hasard */
t_tuile distribution_pioche(t_tuile * jeu[N]){

  unsigned int i,elem;

  t_tuile tuile_okey;

  srand(time(NULL));

  elem = rand() % (105 + 1 - 0) + 0;
  while((jeu[elem] == NULL))
      elem = rand() % (105 + 1 - 0) + 0;

  tuile_okey.nbr = jeu[elem]->nbr;
  tuile_okey.clr = jeu[elem]->clr;
  free(jeu[elem]);
  jeu[elem] = NULL;

  printf("On est dans la fct distribution ");
  printf("%i\n",tuile_okey.nbr);
  return tuile_okey;
}

/* Fonction qui alloue une mémoire dynamique à une tuile */
t_tuile * creer_tuile(void){

  t_tuile * t1 = malloc(sizeof(t_tuile));
  return t1;
}

/* Fonction qui initialise les 106 tuiles */
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

/* Fonction qui libère la mémoire d'une tuile */
void detruire_tuile(t_tuile * jeu[],int taille){

  for (int i = 0; i < taille; i++) {
    free(jeu[i]);
    jeu[i] = NULL;
  }
}

/* Fonction qui renvoie la taille des tuiles alloués */
int taille_tuile(t_tuile * jeu[],int taille_jeu){

  int i = taille_jeu/sizeof(t_tuile);
  return i;
}

int main(){

  /* TEST */
  /* Variables d'initialisation */
  t_pile * pile = malloc(sizeof(t_pile));
  t_tuile * tuile_okey,* tuile_ok1,* tuile_c,* tuile_test, * jeu[N];
  initpile(pile);
  init_tuile(jeu);

  /* On distribue 2 tuiles parmi le jeu */
  tuile_okey = creer_tuile();
  *tuile_okey = distribution_pioche(jeu);
  tuile_ok1 = creer_tuile();
  *tuile_ok1 = distribution_pioche(jeu);

  /* On teste l'empilation et on affiche le sommmet de la pile et on affiche */
  empiler(pile,tuile_okey);
  empiler(pile,tuile_ok1);
  pile!=NULL?printf("On affiche le sommet de la pile sans fct %i\n",pile->premier->tuile->nbr):printf("FAUX\n");

  /* On teste la récupération des valeurs du sommet de la pile et on affiche */
  sommetpile(pile,&tuile_test);
  printf("On affiche le sommet de la pile avec fct %i\n",tuile_test->nbr);

  /* On teste la désempilation et les destructions des tuiles empilés et de la pile */
  depiler(pile);
  depiler(pile);
  free(pile);

  /* On detruit les mémoires alloués du main */
  detruire_tuile(&tuile_okey,taille_tuile(&tuile_okey,sizeof(tuile_okey)));
  detruire_tuile(&tuile_ok1,taille_tuile(&tuile_okey,sizeof(tuile_okey)));
  detruire_tuile(jeu,taille_tuile(jeu,sizeof(jeu)));

  return 0;
}
