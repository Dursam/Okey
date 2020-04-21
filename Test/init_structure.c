#include <init_structure.h>

/**
* \file init_structure.c
* \brief Fichier contenant les fonctions d'initialisation pour les tableaux de structures
* \author Samuel DURAN
* \version 1.0
* \date 12 avril 2020
*/

/**
* \fn void init_tuile(t_tuile * jeu[N_T])
* \brief Initialise le jeu de 106 tuiles
* \param jeu[N_T] Tableau contenant les 106 tuiles
*/
extern
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
      jeu[j]->nbr = V_OKEY;
    }
    if(j == 105){                                  // La dernière tuile est un Okey de couleur rouge
      jeu[j]->clr = rouge;
      jeu[j]->nbr = V_OKEY;
    }
  }
}

/**
* \fn void creer_chevalet(t_tuile * joueur[], int taille)
* \brief Alloue une mémoire dynamique à un chevalet
* \param joueur[] Chevalet du joueur
* \param taille Taille du chevalet
*/
extern
void creer_chevalet(t_tuile * joueur[],int taille){

  for (int i = 0; i < taille; i++)
    joueur[i] = (t_tuile *)malloc(sizeof(t_tuile));
}

/**
* \fn void detruire_tuile(t_tuile * jeu[], int taille)
* \brief Libère la mémoire d'une tuile ou de plusieurs tuiles d'un tableau de structure
* \param jeu[] Tableau de structures
* \param taille Taille du tableau
*/
extern
void detruire_tuile(t_tuile * jeu[],int taille){

  for (int i = 0; i < taille; i++) {
    free(jeu[i]);
    jeu[i] = NULL;
  }
}

/**
* \fn void affiche_chaque_tuile(t_tuile * jeu[], int taille)
* \brief Affiche les tuiles une par une
* \param jeu[] Tableau des tuiles
* \param taille Taille du tableau
*/
extern
void affiche_chaque_tuile(t_tuile * jeu[],int taille){

  printf("La taille est de %i\n",taille);

  for(int i = 0; i < taille; i++){

    if(jeu[i]->nbr==V_DEL)
        printf("\n");
    else if(jeu[i]->nbr==V_OKEY && jeu[i]->clr == rouge)
        printf("OKEY ROUGE\n");
    else if(jeu[i]->nbr==V_OKEY && jeu[i]->clr == noire)
        printf("OKEY NOIRE\n");
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

/**
* \fn int demarrage(t_tuile * jeu[N_T], t_tuile * j1[N_CHEV], t_tuile * j2[N_CHEV], t_tuile * j3[N_CHEV], t_tuile * j4[N_CHEV])
* \brief Donne une tuile au hasard à un des 4 joueurs
* \param jeu[N_T] Tableau contenant toutes les tuiles
* \param j1[N_CHEV] Chevalet du joueur 1
* \param j2[N_CHEV] Chevalet du joueur 2
* \param j3[N_CHEV] Chevalet du joueur 3
* \param j4[N_CHEV] Chevalet du joueur 4
* \return Le numéro du joueur qui commence
*/
extern
int demarrage(t_tuile * jeu[N_T], t_tuile * j1[N_CHEV],t_tuile * j2[N_CHEV],t_tuile * j3[N_CHEV],t_tuile * j4[N_CHEV]){

  unsigned int num_joueur,elem;

  srand(time(NULL));

  num_joueur = rand() % (4 + 1 - 1) + 1; // Donne un nombre de 1 à 4

  elem = rand() % N_T; // Element est une indice des tuiles présent du jeu

  while((jeu[elem] == NULL))
    elem = rand() % N_T; // Donne un élément valide

  switch (num_joueur) {
    case 1: j1[N_CHEV-1]->nbr = jeu[elem]->nbr;j1[N_CHEV-1]->clr = jeu[elem]->clr;break;
    case 2: j2[N_CHEV-1]->nbr = jeu[elem]->nbr;j2[N_CHEV-1]->clr = jeu[elem]->clr;break;
    case 3: j3[N_CHEV-1]->nbr = jeu[elem]->nbr;j3[N_CHEV-1]->clr = jeu[elem]->clr;break;
    case 4: j4[N_CHEV-1]->nbr = jeu[elem]->nbr;j4[N_CHEV-1]->clr = jeu[elem]->clr;break;
  }
  printf("\nLe joueur %i commence la partie\n\n",num_joueur);
  return num_joueur;
}

/**
* \fn void distribution_joueur(t_tuile * jeu[N_T], t_tuile * joueur[N_CHEV])
* \brief Distribue 14 tuiles à un joueur
* \param jeu[N_T] Tableau contenant toutes les tuiles
* \param joueur[N_CHEV] Chevalet du joueur
*/
extern
void distribution_joueur(t_tuile * jeu[N_T], t_tuile * joueur[N_CHEV]){

  unsigned int i,elem;                  // Indice et élément positif

  srand(time(NULL));                    // Génère des entiers aléatoires de 0 à 105, soit un élément des 106 tuiles

  elem = rand() % N_T;

  for (i = 0; i < N_CHEV - 1; i++) {
    while(jeu[elem] == NULL)            // Prend une tuile valide
      elem = rand() % N_T;
    joueur[i]->nbr = jeu[elem]->nbr;    // Affecte la valeur d'un élément au chevalet du joueur
    joueur[i]->clr = jeu[elem]->clr;
    free(jeu[elem]);                    // Detruit la tuile de l'élément sélectionné
    jeu[elem] = NULL;
 }
 joueur[N_CHEV-1]->nbr=V_DEL;
}

/**
* \fn t_tuile distribution_pioche(t_tuile * jeu[N_T])
* \brief Distribue une tuile parmi le jeu des 106 tuiles, au hasard
* \param jeu[N_T] Tableau contenant toutes les tuiles
* \return La tuile distribuée
*/
extern
t_tuile distribution_pioche(t_tuile * jeu[N_T]){

  unsigned int elem;

  t_tuile tuile_temp;

  srand(time(NULL));

  elem = rand() % N_T;      // Element est une indice des tuiles présent du jeu
  while((jeu[elem] == NULL))
      elem = rand() % N_T;  // Donne un élément valide

  tuile_temp.nbr = jeu[elem]->nbr;  // Affecte l'élément à la tuile en paramètre
  tuile_temp.clr = jeu[elem]->clr;
  free(jeu[elem]);
  jeu[elem] = NULL;                 // Supprime la tuile du jeu
  return tuile_temp;
}

/**
* \fn t_tuile * creer_tuile(void)
* \brief Alloue une mémoire dynamique à une tuile
* \return Une mémoire allouée pour une variable de type tuile
*/
extern
t_tuile * creer_tuile(void){

  t_tuile * t1 = malloc(sizeof(t_tuile));
  return t1;
}

/**
* \fn int taille_tuile(t_tuile * jeu[], int taille_jeu)
* \brief  Renvoie la taille des tuiles alloués
* \param jeu[] Tableau contenant les tuiles
* \param taille_jeu Taille du tableau
*/
extern
int taille_tuile(t_tuile * jeu[],int taille_jeu){

  return taille_jeu/sizeof(t_tuile);
}
