/**
* \file init_structure.c
* \brief Fichier contenant les fonctions d'initialisation pour les tableaux de structures et pour les piles
* \author Samuel DURAN
* \version 1.0
* \date 21 avril 2020
*/

#include <init.h>

/**
* \fn void init_tuile(t_tuile * jeu[N_T])
* \brief Initialise le jeu de 106 tuiles
* \param jeu[N_T] Tableau contenant les 106 tuiles
*/
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
void detruire_tuile(t_tuile * jeu[],int taille){

  for (int i = 0; i < taille; i++) {
    free(jeu[i]);
    jeu[i] = NULL;
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
int taille_tuile(t_tuile * jeu[],int taille_jeu){

  return taille_jeu/sizeof(t_tuile);
}

/**
* \fn init_pile(t_pile * pile)
* \brief Initialise la pile
* \param pile La pile à initialiser
*/
void init_pile(t_pile * pile){
  pile->premier = NULL;
}

/**
* \fn int pile_vide(t_pile * pile)
* \brief Vérifie si la pile est vide
* \param pile La pile à vérifier
* \return 0 si la valeur de la pile est vide, 1 sinon
*/
int pile_vide(t_pile * pile){
  return (pile->premier == NULL);
}

/**
* \fn void empiler(t_pile * pile, t_tuile * t)
* \brief Empile une tuile de la pile
* \param pile La pile à utiliser
* \param t La tuile à empiler
*/
void empiler(t_pile * pile,t_tuile * t){

  t_element * nouv;
  nouv=malloc(sizeof(t_element));
  nouv->tuile = t;
  nouv->suivant = pile->premier;
  pile->premier = nouv;
}

/**
* \fn void depiler(t_pile pile)
* \brief Retire une tuile de la pile
* \param pile La pile à dépiler
*/
void depiler(t_pile * pile){

  t_element * sommet;
  if(!(pile_vide(pile))){
    sommet = pile->premier;
    pile->premier = sommet->suivant;
    free(sommet);
    sommet = NULL;
  }
}

/**
* \fn void sommet_pile(t_pile * pile, t_tuile ** c)
* \brief Récupère la tuile du sommet de la pile
* \param pile Pile à vérifier
* \param c Sommet de la pile
*/
extern
void sommet_pile(t_pile * pile,t_tuile ** c){

  if(!(pile_vide(pile)))
    *c = pile->premier->tuile;
}

/**
* \fn int compte_element(t_pile * pile)
* \brief Compte le nombre d'élément d'une tuile
* \param pile Pile à vérifier
* \return Le nombre d'éléments
*/
extern
int compte_element(t_pile * pile){

  t_element * cp_element;

  int cpt = 0;

  cp_element = pile->premier;

  while(cp_element != NULL){
    cp_element = cp_element->suivant;
    cpt++;
  }

  return cpt;
}

/**
* \fn void init_enr_tuile(t_tuile * enr[], int taille)
* \brief Initialise un tableau de struture de tuile pour enregistrer les tuiles qui seront empilées
* \param enr[] Tableau des tuiles enregistrées
* \param taille Taille du tableau
*/
void init_enr_tuile(t_tuile * enr[],int taille){

  for(int i = 0;i<taille;i++)
    enr[i] = NULL;
}

/**
* \fn void empile_enr_tuile(t_tuile * chevalet[N_CHEV], t_tuile * enr[], t_pile * pile, int taille, int numero)
* \brief Créer une tuile, lui affecte une valeur puis l'empile sur une pile
* \param chevalet[N_CHEV] Chevalet du joueur
* \param enr[] Tableau des tuiles enregistrées
* \param pile Pile où la tuile est empilée
* \param taille Taille du tableau
* \param numéro Indice d'une tuille du chevalet
*/
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

/**
* \fn void depiler_toutes_tuiles(t_pile * pile_J1, t_pile * pile_J2, t_pile * pile_J3, t_pile * pile_J4)
* \brief Dépile toutes les piles de tuiles, utilisé pour finir la partie
* \param pile joueur 1
* \param pile joueur 2
* \param pile joueur 3
* \param pile joueur 4
*/
void depiler_toutes_tuiles(t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4){

  /* Compteurs qui compte le nombre d'élément d'une pile de tuile */
  int cpt_p1, cpt_p2, cpt_p3, cpt_p4;

  /* On dépile toute les piles si elle possèdent des éléments */
  cpt_p1 = compte_element(pile_J1);
  cpt_p2 = compte_element(pile_J2);
  cpt_p3 = compte_element(pile_J3);
  cpt_p4 = compte_element(pile_J4);

  while(cpt_p1 > 0){
    depiler(pile_J1);
    cpt_p1--;
  }

  while(cpt_p2 > 0){
    depiler(pile_J2);
    cpt_p2--;
  }

  while(cpt_p3 > 0){
    depiler(pile_J3);
    cpt_p3--;
  }

  while(cpt_p4 > 0){
    depiler(pile_J4);
    cpt_p4--;
  }
}
