#include <combinaison_couleur.h>

/**
* \file combinaison_couleur.c
* \brief Fichier contenant les fonctions de combinaison de couleur
* \author Samuel DURAN
* \version 1.0
* \date 12 avril 2020
*/

/**
* \fn void affiche_tuile(t_tuile * jeu[], int taille)
* \brief Vérifie les tuiles supprimées ou non
* \param jeu[] L'ensemble des tuiles
* \param taille Taille du tableau des tuiles
*/
extern
void affiche_tuile(t_tuile * jeu[],int taille){

  int i;
                                      // Affiche la taille entrée (option)
  printf("La taille est de %i\n",taille);

  for(i = 0;i < taille;i++){
    if(jeu[i]->nbr == V_DEL)                // Cas d'affichage où la tuile a été supprimer
      printf("X NULL\n");
    else{
      if(jeu[i]->nbr==13){                  // Cas d'affichage pour tuiles okey rouge et noire
          if(jeu[i]->clr==noire)
            printf("OKEY NOIRE\n");
          else if(jeu[i]->clr==rouge)
            printf("OKEY ROUGE\n");
      }
      else{                                 // Cas d'affichage des tuiles de 1 à 13 des 4 couleurs différentes
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

/**
* \fn int compte_coul_diff(int tab_coul[4])
* \brief Compte le nombre de couleurs différentes d'une tuile
* \param tab_coul[4] Tableau des couleurs
* \return Le nombre de couleurs différentes
*/
extern
int compte_coul_diff(int tab_coul[4]){

  int i,nb_diff_coul = 0;

  for(i = 0; i < 4 ; i++ ){

    if (tab_coul[i] > 0)    // Si l'une des couleurs est supérieure à 0 alors la couleur d'indice i est présente
        nb_diff_coul++;
    }

  return nb_diff_coul;
}

/**
* \fn void combinaison_coul(t_tuile * chev[])
* \brief Vérifie les ensembles de combinaisons de 3 ou 4 couleurs
* \param chev[] Chevalet
*/
extern
void combinaison_coul(t_tuile * chev[]){

  int cpt_tuil[13] = { 0 },                           // Compteur de chaque tuiles de 1 à 13
  i,j,k,                                              // Indices de parcours à incrémenter
  nb_corr,                                            // Numéro et nombre de tuiles
  cpt_coul[4] = { 0 },                                // Compteur de tuile(s) d'une couleur
  nb_diff_coul,                                       // Nombre de couleur(s) d'une tuile
  enr4_ind[4],enr3_ind[3],enr14_ind[14] = {V_DEL};    // Tableau d'enregistrement de l'indice de la couleur (3 ou 4) en fonction de l'indice du chevalet;

  // Permet de compter l'occurence d'une tuile
  for(i = 0; i < N_CHEV-1; i++){
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

    if(cpt_tuil[i]>=3){                 // On le numéro de tuile supérieur ou égale à 3

      cpt_coul[0] = 0;
      cpt_coul[1] = 0;
      cpt_coul[2] = 0;
      cpt_coul[3] = 0;

      for(j = 0; j < N_CHEV-1 ; j++){        // On parcours le chevalet gagnant soit 14 tuiles
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

          for(k = 0; k < N_CHEV-1; k++){                          // On parcours le chevalet, on enregistre les 4 couleurs d'un même chiffre de tuile

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

            for(k = 0; k < N_CHEV-1; k++){

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

            for(k = 0; k < N_CHEV-1; k++){

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

          for(k = 0; k < N_CHEV-1; k++){

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

          for(k = 0; k < N_CHEV-1; k++){

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
  /*else{                                      // Sinon le nombre d'occurence est inférieur à 3 (option)
    printf("Le nombre d'occurence est inférieur à 3\n");
  }*/
 } // Fin for de compte tuile

 for(i=0;i<14;i++){                            // Suppresion des tuiles de l'enregistrement enr14

   if(enr14_ind[i] == i){
    //printf("Les indices enr14 %i\n",enr14_ind[i]);
    chev[enr14_ind[i]]->nbr = V_DEL;
    }
  }
}
