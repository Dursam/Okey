#include "./test.h"

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

  printf("La taille est de %i\n",taille);

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

/* Fonction qui alloue une mémoire dynamique à une tuile */
t_tuile * creer_tuile(void){

  t_tuile * t1 = malloc(sizeof(t_tuile));
  return t1;
}

/* Fonction qui renvoie la taille des tuiles alloués */
int taille_tuile(t_tuile * jeu[],int taille_jeu){

  int i = taille_jeu/sizeof(t_tuile);
  return i;
}

int main (void){

  /* TEST */
  /* Variables d'initialisation */
  t_tuile * jeu[N],* j1[J],* j2[J],* j3[J],* j4[J], * tuile_okey, * tuile_c;
  int i,j,k;
  init_tuile(jeu);

  /* Affiche la liste complète des tuiles du jeu */
  affJeu(jeu,taille_tuile(jeu,sizeof(jeu)));

  /* On iniitialise les joueurs et on leur donne 14 tuiles chacun avec un joueur au hasard qui démarre */
  creer_joueur(j1,J);
  creer_joueur(j2,J);
  creer_joueur(j3,J);
  creer_joueur(j4,J);

  distribution_joueur(jeu,j1);
  distribution_joueur(jeu,j2);
  distribution_joueur(jeu,j3);
  distribution_joueur(jeu,j4);

  demarrage(jeu,j1,j2,j3,j4);

  /* On affiche les chevalets des joueurs */
  printf("Jeu du J1 %i \n\n\n",taille_tuile(j1,sizeof(j1)));
  affJeu(j1,taille_tuile(j1,sizeof(j1)));
  printf("\nJeu du J2 %i \n\n\n",taille_tuile(j2,sizeof(j2)));
  affJeu(j2,taille_tuile(j2,sizeof(j2)));
  printf("\nJeu du J3 %i \n\n\n",taille_tuile(j3,sizeof(j3)));
  affJeu(j3,taille_tuile(j3,sizeof(j3)));
  printf("\nJeu du J4 %i \n\n\n",taille_tuile(j4,sizeof(j4)));
  affJeu(j4,taille_tuile(j4,sizeof(j4)));

  /* On test la distribution d'une tuile parmi le jeu existant */
  tuile_okey = creer_tuile();
  *tuile_okey = distribution_pioche(jeu);
  affJeu(&tuile_okey,taille_tuile(&tuile_okey,sizeof(tuile_okey)));
  detruire_tuile(&tuile_okey,sizeof(tuile_okey));

  /* On détruit le jeu et les chevalets */
  detruire_tuile(jeu,taille_tuile(jeu,sizeof(jeu)));
  detruire_tuile(j1,taille_tuile(j1,sizeof(j1)));
  detruire_tuile(j2,taille_tuile(j2,sizeof(j2)));
  detruire_tuile(j3,taille_tuile(j3,sizeof(j3)));
  detruire_tuile(j4,taille_tuile(j4,sizeof(j4)));

  return 0;
}
