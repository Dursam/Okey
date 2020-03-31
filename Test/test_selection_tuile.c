/* L'objectif de ce fichier est de selectioner une tuile à partir d'une pioche ou de la pile de gauche. */
/* Ensuite, échange la tuile prise par une tuile du chevalet et la poser sur la pile de droite */

#include "./test.h"
#define N_T 106
#define T_CHEV 15
#define T_DEL 100

/* FONCTIONS DE LA PILE */
/* Initialise la pile */
void initpile(t_pile * pile){
  pile->premier = NULL;
}

/* Fonction qui vérifie si la pile est vide */
int pilevide(t_pile * pile){
  return (pile->premier == NULL);
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
  if(!(pilevide(pile))){
    sommet = pile->premier;
    pile->premier = sommet->suivant;
    free(sommet);
    sommet = NULL;
  }

}

/* Fonction qui pointe la tuile du sommet de la pile */
void sommetpile(t_pile * pile,t_tuile ** c){
  if(!(pilevide(pile)))
    *c = pile->premier->tuile;
}
/*-----------------------------------*/

/* Initialise la pile */
void init_tuile(t_tuile * jeu[N_T]){

  int i,j;                                         // Indices

  t_couleur couleur = jaune;                       // Couleur de départ

  for (i = 0;i < N_T ; i++){                       // Alloue la mémoire pour tout le jeu
    jeu[i] = (t_tuile *)malloc(sizeof(t_tuile));
  }
  for(j=0;j<N_T;j++){                              // Affecte une valuer à chaque tuiles
    jeu[j]->clr = couleur;
    jeu[j]->nbr = j%13;
    if((j+1) % 26 == 0)                            // Quand une série de 2 fois 13 tuiles de même couleur est fait alors on change de couleur
      couleur++;
    if(j == 104){                                  // L'avant dernière tuile est un Okey de couleur noire
      jeu[j]->clr = noire;
      jeu[j]->nbr = 13;
    }
    if(j == 105){                                  // La dernière tuile est un Okey de couleur rouge
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
void creer_chev(t_tuile * joueur[],int taille){

  for (int i = 0; i < taille; i++)
    joueur[i] = (t_tuile *)malloc(sizeof(t_tuile));
}

/* Fonction qui libère la mémoire d'une tuile ou plusieurs tuiles d'un tab de stru */
void detruire_tuile(t_tuile * jeu[],int taille){

  for (int i = 0; i < taille; i++) {
    free(jeu[i]);
    jeu[i] = NULL;
  }
}

/* Fonction qui alloue une mémoire dynamique à une tuile */
t_tuile * creer_tuile(void){

  t_tuile * t1 = malloc(sizeof(t_tuile));
  return t1;
}

/* Affiche les tuiles un par un avec boucle WHILE */
void affiche_tuile(t_tuile * jeu[],int taille){

  int i;
                                      // Affiche la taille entrée (option)
  printf("La taille est de %i\n",taille);

  for(i = 0;i < taille;i++){
    if(jeu[i]->nbr == T_DEL)                // Cas où la tuile a été supprimer
      printf("X NULL\n");
    else{
      if(jeu[i]->nbr==13){            // Cas d'affichage pour tuiles okey rouge et noire
          if(jeu[i]->clr==noire)
            printf("OKEY NOIRE\n");
          else if(jeu[i]->clr=rouge)
            printf("OKEY ROUGE\n");
      }
      else{                           // Cas d'affichage des tuiles de 1 à 13 des 4 couleurs différentes
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
}

/* Fonction qui distribue 14 tuiles à un joueur */
void distribution_joueur(t_tuile * jeu[N_T], t_tuile * joueur[T_CHEV]){

  unsigned int i,elem;                  // Indice et élément positif

  srand(time(NULL));                    // Génère des entiers aléatoires de 0 à 105, soit un élément des 106 tuiles

  elem = rand() % (105 + 1 - 0) + 0;

  for (i = 0; i < T_CHEV - 1; i++) {
    while(jeu[elem] == NULL)            // Prend une tuile valide
      elem = rand() % (105 + 1 - 0) + 0;
    joueur[i]->nbr = jeu[elem]->nbr;    // Affecte la valeur d'un élément au chevalet du joueur
    joueur[i]->clr = jeu[elem]->clr;
    free(jeu[elem]);                    // Detruit la tuile de l'élément sélectionné
    jeu[elem] = NULL;
 }
 joueur[14]->nbr=T_DEL;
}

/* Fonction qui distribus une tuile parmi le jeu des 106 tuiles, au hasard */
t_tuile distribution_pioche(t_tuile * jeu[N_T]){

  unsigned int i,elem;

  t_tuile tuile_temp;

  srand(time(NULL));

  elem = rand() % (105 + 1 - 0) + 0;
  while((jeu[elem] == NULL))
      elem = rand() % (105 + 1 - 0) + 0;

  tuile_temp.nbr = jeu[elem]->nbr;
  tuile_temp.clr = jeu[elem]->clr;
  free(jeu[elem]);
  jeu[elem] = NULL;
  return tuile_temp;
}

/* Affiche les tuiles un par un avec boucle WHILE */
void affiche_chevalet(t_tuile * jeu[],int taille){

  int i;

  printf("\033[1;32m\t\b\t1\t2\t3\t4\t5\t6\t7\t\033[00m");
  printf("\n\t------------------------------------------------------\n");

  for(i = 0;i < taille;i++){

    if(i == 0)
      printf("\t|");
    if(i == 14 && jeu[14]->nbr != T_DEL)
      printf("--------------->");

    if(jeu[i]->nbr == T_DEL)                // Cas où la tuile a été supprimer
      printf("\t");
    else{
      if(jeu[i]->nbr==13){                  // Cas d'affichage pour tuiles okey rouge et noire
          if(jeu[i]->clr==noire)
            printf("OK\033[34;40m__\033[00m\t");
          else if(jeu[i]->clr=rouge)
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
        else{
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
    if(i == 6 && jeu[14]->nbr == T_DEL)
      printf("\n\t|\t\t\t\t\t\t\t\b\b\b|\n\t|");
    else if(i == 6 && jeu[14]->nbr != T_DEL)
      printf("\n\t|\t\t\t\t\t\t\t\b\b\b| NOUVELLE TUILE \n\t|");
  }
  printf("\n\t------------------------------------------------------\n");
  printf("\033[1;32m\t\b\t8\t9\t10\t11\t12\t13\t14\n\033[00m");
}

/* Affichage du sommet d'une pile */
void affiche_sommet_pile(t_pile * pile){

  t_tuile * tuile;

  if(pilevide(pile))
    printf("* \033[34;47m__\033[00m\t");
  else{
    sommetpile(pile,&tuile);

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

/* Affichage du sommet des piles de tout les joueurs */
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

/* Fonction qui creer une tuile, lui affecte une valeur puis l'empile sur une pile */
void empile_enr_tuile(t_tuile * chevalet[T_CHEV],t_tuile * enr[],t_pile * pile,int taille,int numero){

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
  chevalet[14]->nbr = T_DEL;
}

/* Fonction qui permet de sélection une tuile soit de la pioche ou de la pile de gauche et retire une tuile du chevalet */
void selection_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[T_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd){

  char choix;

  int numero;

  t_tuile * tuile_sommet;

  affiche_pile(pfg,pfd,pg,pd);
  affiche_chevalet(chevalet,T_CHEV);

  printf("CHOIX : PIOCHE(ENTER) OU PILE DE GAUCHE(ANY KEY) ? ");
  scanf("%c",&choix);


  if(choix==0x0A){                          // Code ASCII pour la touche Entree
    printf("TU PIOCHE\n");
    *chevalet[14] = distribution_pioche(jeu);
    printf("%i\n",jeu[14]->nbr);
  }
  else{
    printf("TU PREND LA TUILE DE LA PILE\n");
    sommetpile(pg,&tuile_sommet);
    chevalet[14]->nbr = tuile_sommet->nbr;
    chevalet[14]->clr = tuile_sommet->clr;
    depiler(pg);

  }
  printf("%i\n",chevalet[14]->nbr+1);
  affiche_pile(pfg,pfd,pg,pd);
  affiche_chevalet(chevalet,T_CHEV);

  printf("CHOIX : RETIRER UN NUMERO DE TUILE (1 à 15) ? ");
  scanf("%i",&numero);

  empile_enr_tuile(chevalet,enr,pd,T_CHEV,numero-1);

  affiche_pile(pfg,pfd,pg,pd);
  affiche_chevalet(chevalet,T_CHEV);
}

/* Fonction qui initialise un tableau de struture de tuile pour enregistrer les tuiles qui seront empilés */
void init_enr_tuile(t_tuile * enr[],int taille){

  for(int i = 0;i<taille;i++)
    enr[i] = NULL;
}

/* Fonction qui creer une tuile, lui affecte une valeur puis l'empile sur une pile */
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

int main(){

  /* On initialise les joueurs et on leur donne 14 tuiles chacun avec un joueur au hasard qui démarre */
  t_tuile * jeu[N_T],* joueur[T_CHEV];

  t_tuile * tuile_sommet,* tuile_p1[T_CHEV],* tuile_p2[T_CHEV],* tuile_p3[T_CHEV],* tuile_p4[T_CHEV];

  t_pile * pile_droite,* pile_gauche,* pile_fond_droit,* pile_fond_gauche;

  /* On initialise les enregistrement pour l'empilement des tuiles sur leur piles respectives */
  init_enr_tuile(tuile_p1,T_CHEV);
  init_enr_tuile(tuile_p2,T_CHEV);
  init_enr_tuile(tuile_p3,T_CHEV);
  init_enr_tuile(tuile_p4,T_CHEV);

  /* Alloue Mémoire */
  pile_droite = malloc(sizeof(t_pile));
  pile_gauche = malloc(sizeof(t_pile));
  pile_fond_droit = malloc(sizeof(t_pile));
  pile_fond_gauche = malloc(sizeof(t_pile));

  /* On initialise les tuiles pour des piles de tuiles et d'une tuile pioché */
  initpile(pile_droite);
  initpile(pile_gauche);
  initpile(pile_fond_droit);
  initpile(pile_fond_gauche);

  /* On initialise les joueurs et on leur donne 14 tuiles chacun avec un joueur au hasard qui démarre */
  creer_chev(joueur,T_CHEV);

  /* Distribution des tuiles */
  init_tuile(jeu);
  distribution_joueur(jeu,joueur);

  // SCENARIO
  // PIOCHE GAUCHE 2 FOIS
  test_enr_tuile(jeu,tuile_p1,pile_gauche,T_CHEV);
  test_enr_tuile(jeu,tuile_p1,pile_gauche,T_CHEV);

  // PIOCHE DROIT 2 FOIS
  test_enr_tuile(jeu,tuile_p2,pile_droite,T_CHEV);
  test_enr_tuile(jeu,tuile_p2,pile_droite,T_CHEV);

  // PIOCHE FOND DROIT 1 FOIS
  test_enr_tuile(jeu,tuile_p3,pile_fond_droit,T_CHEV);

  // PIOCHE FOND GAUCHE 1 FOIS PUIS DEPILER APRES
  test_enr_tuile(jeu,tuile_p4,pile_fond_gauche,T_CHEV);
  depiler(pile_fond_gauche);

  // TEST D'AFFICHAGE D'UNE SIMULATION DE PARTIE
  printf("\n--------------------------------DEBUT DE TOUR----------------------------------------\n");
  // Affiche le sommet de la pile de gauche
  selection_tuile(jeu,joueur,tuile_p2,pile_fond_gauche,pile_fond_droit,pile_gauche,pile_droite);
  //affiche_chevalet(joueur,T_CHEV);
  //affiche_pile(pile_fond_gauche,pile_fond_droit,pile_gauche,pile_droite);

  // On dépile toutes les tuiles
  /*affiche_sommet_pile(pile_gauche);
  sommetpile(pile_gauche,&tuile_sommet);
  printf("On affiche le sommet de la pile avec fct %i\n",tuile_sommet->nbr+1);
  depiler(pile_gauche);
  affiche_sommet_pile(pile_gauche);
  sommetpile(pile_gauche,&tuile_sommet);
  printf("On affiche le sommet de la pile avec fct %i\n",tuile_sommet->nbr+1);*/
  depiler(pile_gauche);
  depiler(pile_gauche);
  depiler(pile_droite);
  depiler(pile_droite);
  depiler(pile_droite);
  depiler(pile_fond_droit);

  /* On détruit les tuiles des piles gauche et droite */
  free(pile_gauche);
  free(pile_droite);
  free(pile_fond_gauche);
  free(pile_fond_droit);

  /* On détruit le jeu et les chevalets */
  detruire_tuile(tuile_p1,taille_tuile(tuile_p1,sizeof(tuile_p1)));
  detruire_tuile(tuile_p2,taille_tuile(tuile_p2,sizeof(tuile_p2)));
  detruire_tuile(tuile_p3,taille_tuile(tuile_p3,sizeof(tuile_p3)));
  detruire_tuile(tuile_p4,taille_tuile(tuile_p4,sizeof(tuile_p4)));
  detruire_tuile(jeu,taille_tuile(jeu,sizeof(jeu)));
  detruire_tuile(joueur,taille_tuile(joueur,sizeof(joueur)));
}
