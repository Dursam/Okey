#include <init_pile.h>

/**
* \file init_pile.c
* \brief Fichier contenant les fonctions d'initialisation pour les piles
* \author Samuel DURAN
* \version 1.0
* \date 12 avril 2020
*/

/**
* \fn init_pile(t_pile * pile)
* \brief Initialise la pile
* \param pile La pile à initialiser
*/
extern
void init_pile(t_pile * pile){
  pile->premier = NULL;
}

/**
* \fn int pile_vide(t_pile * pile)
* \brief Vérifie si la pile est vide
* \param pile La pile à vérifier
* \return 0 si la valeur de la pile est vide, 1 sinon
*/
extern
int pile_vide(t_pile * pile){
  return (pile->premier == NULL);
}

/**
* \fn void empiler(t_pile * pile, t_tuile * t)
* \brief Empile une tuile de la pile
* \param pile La pile à utiliser
* \param t La tuile à empiler
*/
extern
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
extern
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
