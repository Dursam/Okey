/* L'objectif de ce fichier est de tester les combinaisons gagnant des tuiles */

#include "./test.h"

#define N_T 106
#define T_CHEV 15
#define T_DEL 100

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
    //i++;
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

/* Fonction qui compte le nombre de couleur différente d'une tuile */
int compte_coul_diff(int tab_coul[4]){

  int i,nb_diff_coul = 0;

  for(i = 0; i < 4 ; i++ ){ // On compte le nombre de couleurs différentes de la tuile

    if (tab_coul[i] > 0)
        nb_diff_coul++;
    }

  return nb_diff_coul;
}

/* Fonction qui vérifie les ensembles de combinaisons de 3 ou 4 couleurs */
void combinaison_coul(t_tuile * chev[]){

  int cpt_tuil[13] = { 0 },                           // Compteur de chaque tuiles de 1 à 13
  i,j,k,                                              // Indices de parcours à incrémenter
  num = 1,nb_corr,                                    // Numéro et nombre de tuiles
  cpt_coul[4] = { 0 },                                // Compteur de tuile(s) d'une couleur
  nb_diff_coul,                                       // Nombre de couleur(s) d'une tuile
  enr4_ind[4],enr3_ind[3],enr14_ind[14] = {100};      // Tableau d'enregistrement de l'indice de la couleur (3 ou 4) en fonction de l'indice du chevalet;

  // Permet de compter l'occurence d'une tuile
  for(i = 0; i < T_CHEV-1; i++){
    if (chev[i]->nbr >= 0 && chev[i]->nbr < 13) {
      nb_corr = (chev[i]->nbr);
      cpt_tuil[nb_corr]++;
    }
  }
/*
  // Affiche les occurrences
  for(i = 0; i < 13; i++){
    printf("La tuile numéro %i à %i jeton(s).\n",num,cpt_tuil[i]);
    num++;
  }
*/
  for(i = 0; i < 13; i++){              // On parcours les tuiles existante de 1 à 13

    if(cpt_tuil[i]>=3){                // On le numéro de tuile supérieur ou égale à 3

      cpt_coul[0] = 0;
      cpt_coul[1] = 0;
      cpt_coul[2] = 0;
      cpt_coul[3] = 0;

      for(j = 0; j < T_CHEV-1 ; j++){        // On parcours le chevalet gagnant soit 14 tuiles
                                     // On compte le nombre de tuiles de même couleurs
        if(chev[j]->clr == jaune && chev[j]->nbr == i) // JAUNE 0
          cpt_coul[0]++;

        else if(chev[j]->clr == rouge && chev[j]->nbr == i) // ROUGE 1
          cpt_coul[1]++;

        else if(chev[j]->clr == noire && chev[j]->nbr == i) // NOIRE 2
          cpt_coul[2]++;

        else if(chev[j]->clr == bleu && chev[j]->nbr == i) // BLEUE 3
          cpt_coul[3]++;
      }

      nb_diff_coul = compte_coul_diff(cpt_coul);                  // Compte le nombre de couleurs différentes
      //printf("Le nombre nb_diff_coul est de  %i\n",nb_diff_coul);

      while (nb_diff_coul == 3 || nb_diff_coul == 4){

        if(nb_diff_coul == 4){                                    // 4 couleurs différentes est égale à 1 combinaison

          for(k = 0; k < T_CHEV-1; k++){                               // On parcours le chevalet, on enregistre les 4 couleurs d'un même chiffre de tuile

            if(chev[k]->nbr == i && chev[k]->clr == jaune){
              enr4_ind[0] = k;
            }
            else if(chev[k]->nbr == i && chev[k]->clr == rouge){
              enr4_ind[1] = k;
            }
            else if(chev[k]->nbr == i && chev[k]->clr == noire){
              enr4_ind[2] = k;
            }
            else if(chev[k]->nbr == i && chev[k]->clr == bleu){
              enr4_ind[3] = k;
            }
          }
          // Enregistre sur enr14 des couleurs de combinaison 4 à partir de l'enregistrement enr4

          for(j = 0; j < 4; j++){
            //printf("Les indices enr4 %i\n",enr4_ind[j]);
            enr14_ind[enr4_ind[j]] = enr4_ind[j];
          }

        }

        else { // Si le nombre de couleur différente est égale à 3, il y a 4 combinaisons différentes

          // Association couleur et indice JAUNE 0 ROUGE 1 NOIRE 2 BLEU 3
          // --------------------------------------------------------------
          // Combinaison JAUNE NOIRE ROUGE
          if(cpt_coul[0] > 0 && cpt_coul[2] > 0 && cpt_coul[1] > 0){

            for(k = 0; k < T_CHEV-1; k++){

              if(chev[k]->nbr == i && chev[k]->clr == jaune){
                enr3_ind[0] = k;
              }
              else if(chev[k]->nbr == i && chev[k]->clr == noire){
                enr3_ind[1] = k;
              }
              else if(chev[k]->nbr == i && chev[k]->clr == rouge){
                enr3_ind[2] = k;
              }
            }
          }

          // Combinaison JAUNE ROUGE BLEU
          else if(cpt_coul[0] > 0 && cpt_coul[1] > 0 && cpt_coul[3] > 0){

            for(k = 0; k < T_CHEV-1; k++){

              if(chev[k]->nbr == i && chev[k]->clr == jaune){
                enr3_ind[0] = k;
              }
              else if(chev[k]->nbr == i && chev[k]->clr == rouge){
                enr3_ind[1] = k;
              }
              else if(chev[k]->nbr == i && chev[k]->clr == bleu){
                enr3_ind[2] = k;
            }
          }
        }

        // Combinaison JAUNE NOIRE BLEU
        else if(cpt_coul[0] > 0 && cpt_coul[2] > 0 && cpt_coul[3] > 0){

          for(k = 0; k < T_CHEV-1; k++){

            if(chev[k]->nbr == i && chev[k]->clr == jaune){
              enr3_ind[0] = k;
            }
            else if(chev[k]->nbr == i && chev[k]->clr == noire){
              enr3_ind[1] = k;
            }
            else if(chev[k]->nbr == i && chev[k]->clr == bleu){
              enr3_ind[2] = k;
          }
        }
      }

        // Combinaison NOIRE ROUGE BLEU
        else if(cpt_coul[2] > 0 && cpt_coul[1] > 0 && cpt_coul[3] > 0){

          for(k = 0; k < T_CHEV-1; k++){

            if(chev[k]->nbr == i && chev[k]->clr == noire){
              enr3_ind[0] = k;
            }
            else if(chev[k]->nbr == i && chev[k]->clr == rouge){
              enr3_ind[1] = k;
            }
            else if(chev[k]->nbr == i && chev[k]->clr == bleu){
              enr3_ind[2] = k;
          }
        }
      }

      // Enregistre sur enr14 des couleurs de combinaison 4 à partir de l'enregistrement enr3
      for(j = 0; j < 3; j++){
        //printf("Les indices enr4 %i\n",enr3_ind[j]);
        enr14_ind[enr3_ind[j]] = enr3_ind[j];
      }

    } // Fin de else 3 couleurs différentes

    // On décrémente les couleurs
    cpt_coul[0]--;
    cpt_coul[1]--;
    cpt_coul[2]--;
    cpt_coul[3]--;

    nb_diff_coul = compte_coul_diff(cpt_coul); // On compte recompte le nombre de couleur différente
    }
  }                                            // Fin if de nombre d'occurence supérieur à 3
  /*else{                                        // Sinon le nombre d'occurence est inférieur à 3 (option)
    printf("Le nombre d'occurence est inférieur à 3\n");
  }*/
 } // Fin for de compte tuile

 for(i=0;i<14;i++){                            // Suppresion des tuiles de l'enregistrement enr14

   if(enr14_ind[i] == i){
    //printf("Les indices enr14 %i\n",enr14_ind[i]);
    chev[enr14_ind[i]]->nbr = T_DEL;
    }
  }
}

int main(){

  /* On iniitialise les joueurs et on leur donne 14 tuiles chacun avec un joueur au hasard qui démarre */
  t_tuile * jeu[N_T],* j1[T_CHEV],* jc[T_CHEV];
  init_tuile(jeu);

  /* On iniitialise les joueurs et on leur donne 14 tuiles chacun avec un joueur au hasard qui démarre */
  creer_chev(j1,T_CHEV);
  creer_chev(jc,T_CHEV);

  /* Distribution des tuiles */
  distribution_joueur(jeu,j1);

  /* Creation d'une combinaison gagnante */

  /* Combinaison du numéro 1 avec 4 couleurs différentes */
  jc[0]->nbr=0;
  jc[0]->clr=jaune;
  jc[1]->nbr=0;
  jc[1]->clr=bleu;
  jc[2]->nbr=0;
  jc[2]->clr=rouge;
  jc[3]->nbr=0;
  jc[3]->clr=noire;
  /* Combinaison d'une suite de numéro (minimum de 3) */
  jc[4]->nbr=0;
  jc[4]->clr=bleu;
  jc[5]->nbr=1;
  jc[5]->clr=bleu;
  jc[6]->nbr=2;
  jc[6]->clr=bleu;
  jc[7]->nbr=3;
  jc[7]->clr=bleu;
  jc[8]->nbr=4;
  jc[8]->clr=bleu;
  jc[9]->nbr=5;
  jc[9]->clr=bleu;
  jc[10]->nbr=6;
  jc[10]->clr=bleu;
  /* Combinaison du numéro 10 avec 3 couleurs différentes */
  jc[11]->nbr=9;
  jc[11]->clr=noire;
  jc[12]->nbr=9;
  jc[12]->clr=rouge;
  jc[13]->nbr=9;
  jc[13]->clr=jaune;
  /* Tuile qui est supprimer */
  jc[14]->nbr=T_DEL;
  jc[14]->clr=jaune;

  printf("\nEXEMPLE DE CHEVALET DE 14 TUILES DEFINIS\n");
  printf("\nVERIFICATION DES COMBINAISONS DE COULEURS\n");
  printf("\n---------------AVANT-------------\n");

  affiche_tuile(jc,taille_tuile(jc,sizeof(jc)));

  /* Affichage des répétitions */
  combinaison_coul(jc);

  printf("\n---------------APRES-------------\n");

  affiche_tuile(jc,taille_tuile(jc,sizeof(jc)));

  printf("\n----------------FIN--------------\n");

  /* Affichage d'un chevalet de 15 tuiles aléatoires */
  printf("\nEXEMPLE DE CHEVALET DE 14 TUILES ALEATOIRES\n");
  printf("\nVERIFICATION DES COMBINAISONS DE COULEURS\n");
  printf("\n---------------AVANT-------------\n");

  affiche_tuile(j1,taille_tuile(j1,sizeof(j1)));

  /* Affichage des répétitions */
  combinaison_coul(j1);

  printf("\n---------------APRES-------------\n");

  affiche_tuile(j1,taille_tuile(j1,sizeof(j1)));

  printf("\n----------------FIN--------------\n");

  /* On détruit le jeu et les chevalets */
  detruire_tuile(jeu,taille_tuile(jeu,sizeof(jeu)));
  detruire_tuile(j1,taille_tuile(j1,sizeof(j1)));
  detruire_tuile(jc,taille_tuile(jc,sizeof(jc)));
}
