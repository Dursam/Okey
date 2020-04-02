/* Fichier contenant les fonctions d'initialisation pour les piles */
#include <init_pile.h>

/* Initialise la pile */
extern
void init_pile(t_pile * pile){
  pile->premier = NULL;
}

/* Vérifie si la pile est vide */
extern
int pile_vide(t_pile * pile){
  return (pile->premier == NULL);
}

/* Empile une tuile de la pile */
extern
void empiler(t_pile * pile,t_tuile * t){
  t_element * nouv;
  nouv=malloc(sizeof(t_element));
  nouv->tuile = t;
  nouv->suivant = pile->premier;
  pile->premier = nouv;
}

/* Retire une tuile de la pile */
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

/* Récupère la tuile du sommet de la pile */
extern
void sommet_pile(t_pile * pile,t_tuile ** c){
  if(!(pile_vide(pile)))
    *c = pile->premier->tuile;
}
