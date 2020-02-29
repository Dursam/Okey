#include "./init.h"

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

/* Fonction qui alloue une mémoire dynamique à une tuile */
void creer_joueur(t_tuile * joueur[],int taille){

  for (int i = 0; i < taille; i++) {
    joueur[i] = (t_tuile *)malloc(sizeof(t_tuile));
    joueur[i]->nbr = 14;
  }
}

/* Fonction qui alloue une mémoire dynamique à une tuile */
t_tuile * creer_tuile(void){

  t_tuile * t1 = malloc(sizeof(t_tuile));
  return t1;
}

/* Fonction qui libère la mémoire d'une tuile */
void detruire_tuile(t_tuile * jeu[],int taille){

  for (int i = 0; i < taille; i++) {
    free(jeu[i]);
    jeu[i] = NULL;
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

  return tuile_okey;
}

/* Fonction qui donne une tuile au hasard à un des 4 joueurs */
void demarrage(t_tuile * jeu[N], t_tuile * j1[J],t_tuile * j2[J],t_tuile * j3[J],t_tuile * j4[J]){

  unsigned int num_joueur,elem;

  srand(time(NULL));

  num_joueur = rand() % (4 + 1 - 1) + 1;

  elem = rand() % (105 + 1 - 0) + 0;

  while((jeu[elem] == NULL))
    elem = rand() % (105 + 1 - 0) + 0;

  switch (num_joueur) {
    case 1: j1[14]->nbr = jeu[elem]->nbr;j1[14]->clr = jeu[elem]->clr;break;
    case 2: j2[14]->nbr = jeu[elem]->nbr;j2[14]->clr = jeu[elem]->clr;break;
    case 3: j3[14]->nbr = jeu[elem]->nbr;j3[14]->clr = jeu[elem]->clr;break;
    case 4: j4[14]->nbr = jeu[elem]->nbr;j4[14]->clr = jeu[elem]->clr;break;
  }
  printf("%i\n",num_joueur);
}

/* Fonction qui renvoie la taille des tuiles alloués */
int taille_tuile(t_tuile * jeu[],int taille_jeu){

  int i = taille_jeu/sizeof(t_tuile);
  return i;
}

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
