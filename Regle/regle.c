#include <regle.h>

/**
* \file combinaison_couleur.c
* \brief Fichier contenant les fonctions de combinaison de couleur et de suites d'entiers
* \author Samuel DURAN
* \version 1.0
* \date 21 avril 2020
*/

/**
* \fn int compte_coul_diff(int tab_coul[4])
* \brief Compte le nombre de couleurs différentes d'une tuile
* \param tab_coul[4] Tableau des couleurs
* \return Le nombre de couleurs différentes
*/
int compte_coul_diff(int tab_coul[4]){

  int i,nb_diff_coul = 0;

  for(i = 0; i < 4 ; i++ ){

    if (tab_coul[i] > 0)    // Si l'une des couleurs est supérieure à 0 alors la couleur d'indice i est présente
        nb_diff_coul++;
    }

  return nb_diff_coul;
}

/**
* \fn void regle_coul(t_tuile * chev[])
* \brief Vérifie les ensembles de combinaisons de 3 ou 4 couleurs
* \param chev[] Chevalet
*/
void regle_coul(t_tuile * chev[]){

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

/**
* \fn void regle_suite(t_tuile * chev[])
* \brief Vérifie les ensembles de combinaisons à partir de 3 suites d'entiers
* \param chev[] Chevalet contenant les tuiles
*/
void regle_suite(t_tuile * chev[]){

  int enr14_ind[14] = {V_DEL},                    // Enregistre les tuiles pour suppression (Cas d'une même tuile)
  enr13_coul[13] = {0},                           // Enregistre les tuiles de 1 à 13 de la couleur d'indice i, utilisé dans la boucle WHILE
  cpt_len_comb,                                   // Compte le nombre de combinaison
  i,j,k,copy_i;                                   // Indices, copy_i est une aide visuelle et remplaçable par i (facultatif)
  int nbr_suiv, nbr_pred,nbr_suiv_2,nbr_pred_2;   // Nombres qui permettent de calculer les 2 nombres précédent et les 2 nombres suivant de la tuile d'indice copy_i
  t_couleur coul_actuel;                          // Valeur temporaire de la couleur de la tuile d'indice i
  t_tuile * enr14_rep[14];                        // Enregistre les tuiles pour suppression (Cas de 2 même tuile)

  creer_chevalet(enr14_rep,14);                   // Initialise l'enregistrement

  for(i = 0;i < N_CHEV-1;i++){                    // Donne une valeur de comparaison, la couleur est sans importance
    enr14_rep[i]->nbr = NO_VALUE;
    enr14_rep[i]->clr = jaune;
  }

  for(i = 0;i < N_CHEV-1;i++){                    // Initialise l'enregistrement
    enr14_ind[i] = V_DEL;
  }

  for(i = 0;i < N_CHEV-1;i++){                    // Parcours du chevalet

    if(chev[i]->nbr != V_DEL){                    // Si tuile présente

      cpt_len_comb = 1;                           // On compte la tuile présente
      coul_actuel = chev[i]->clr;                 // On conserve la couleur de la tuile actuelle

      for(j = 0; j < 13; j++)                     // On initialise l'enregistrement à 0, il permet de compter le
          enr13_coul[j] = 0;                      // nombres de tuiles (1 à 13) de la couleur actuelle

      for(j = 0; j < 13; j++){                    // On compte le nombres de tuiles (1 à 13) de la couleur actuelle
        for(k = 0; k < N_CHEV-1; k++){
          if(chev[k]->clr == coul_actuel && chev[k]->nbr == j)
            enr13_coul[chev[k]->nbr]++;
        }
      }

      for(j = 0; j < 14; j++){                    // Permet d'éviter de supprimer 2 fois une même tuile du chevalet
          if(enr14_rep[j]->nbr == chev[i]->nbr && enr14_rep[j]->clr == chev[i]->clr)
            enr13_coul[chev[i]->nbr] = 1;
      }

      while(cpt_len_comb == 1){

        copy_i = i;                               // Facultatif, aide visuelle

        if(chev[copy_i]->nbr == 0){               // Si tuile numéro 1 alors précédent '13' et 12 et suivant 2 et 3
          nbr_pred = 12;
          nbr_suiv = chev[copy_i]->nbr + 1;
          nbr_pred_2 = nbr_pred - 1;
          nbr_suiv_2 = nbr_suiv + 1;
        }
        else if(chev[copy_i]->nbr == 12){         // Si tuile numéro 13 alors précédent 12 et 11 et suivant '1' et 2
          nbr_pred = chev[copy_i]->nbr - 1;
          nbr_suiv = 0;
          nbr_pred_2 = nbr_pred - 1;
          nbr_suiv_2 = nbr_suiv + 1;
        }
        else if(chev[copy_i]->nbr == 1){          // Si tuile numéro 2 alors précédent 1 et '13' et suivant 3 et 4
          nbr_pred = chev[copy_i]->nbr - 1;
          nbr_suiv = chev[copy_i]->nbr + 1;
          nbr_pred_2 = 12;
          nbr_suiv_2 = nbr_suiv + 1;
        }
        else if(chev[copy_i]->nbr == 11){         // Si tuile numéro 12 alors précédent 11 et 10 et suivant 13 et '1'
          nbr_pred = chev[copy_i]->nbr - 1;
          nbr_suiv = chev[copy_i]->nbr + 1;
          nbr_pred_2 = nbr_pred - 1;
          nbr_suiv_2 = 0;
        }
        else{                                    // Si autre numéro de tuile alors précédent -1 et -2 et suivant +1 et +2 du nombre
          nbr_pred = chev[copy_i]->nbr - 1;      // de la tuile actuelle
          nbr_suiv = chev[copy_i]->nbr + 1;
          nbr_pred_2 = nbr_pred - 1;
          nbr_suiv_2 = nbr_suiv + 1;
        }

        //printf("CPT1 : -> %i et %i\n",nbr_pred,nbr_suiv);           // Permet de vérifier les nombres précédent et suivant sont bon
        //printf("CPT2 -> %i et %i\n",nbr_pred_2,nbr_suiv_2);
        if(enr13_coul[chev[i]->nbr] == 2){                            // Si il y a 2 fois la même tuile de même couleur

          if(enr13_coul[nbr_pred] == 2 && enr13_coul[nbr_suiv] == 2){ // Si il y a 2 fois le nombre précédent et suivant -> VALIDE
            cpt_len_comb = cpt_len_comb + 2;
          }
          else if(enr13_coul[nbr_pred] != 2 && enr13_coul[nbr_suiv] == 2){ // Si il y a 2 fois le nombre suivant et 2 fois le nombre
            cpt_len_comb++;                                                // précédent 2 ou suivant 2 -> VALIDE
            if(enr13_coul[nbr_pred_2] == 2 || enr13_coul[nbr_suiv_2] == 2){
              cpt_len_comb++;
            }
          }
          else if(enr13_coul[nbr_pred] == 2 && enr13_coul[nbr_suiv] != 2){ // Si il y a 2 fois le nombre précédent et 2 fois le nombre
            cpt_len_comb++;                                                // précédent 2 ou suivant 2 -> VALIDE
            if(enr13_coul[nbr_pred_2] == 2 || enr13_coul[nbr_suiv_2] == 2){
              cpt_len_comb++;
            }
          }
          else{                                                            // On enregistre la tuile et on sort de la boucle WHILE
            enr14_rep[i]->nbr = chev[i]->nbr;
            enr14_rep[i]->clr = chev[i]->clr;
            cpt_len_comb = V_DEL;
          }
        }
        else{                                                              // Si la tuile actuelle est présente qu'une seule fois
          for(j = 0;j < N_CHEV-1;j++){                                     // On parcours le chevalet

            if(chev[j]->nbr != V_DEL){                                     // On compte si le nombre suivant ou précédent est présent du chevalet
              if(chev[j]->nbr != chev[i]->nbr && chev[j]->clr == coul_actuel && (chev[j]->nbr == nbr_pred || chev[j]->nbr == nbr_suiv)){
                cpt_len_comb++;
              }
            }
          }

          if((enr13_coul[nbr_pred] == 2 && enr13_coul[nbr_suiv] == 0) || (enr13_coul[nbr_pred] == 0 && enr13_coul[nbr_suiv] == 2))
            cpt_len_comb = 1;                                              // S'il y a 2 fois le nombre précédent et 0 fois le nombre suivant

          // Si ce qu'on a compté auparavant est égaux à 2                                                                 // et vice-versa -> NON VALIDE
          if(cpt_len_comb == 2){

            for(j = 0;j < N_CHEV-1;j++){ // On parcours le chevalet

              if(chev[j]->nbr != V_DEL){

                // Si le nombre précédent 2 est présent alors on reparcours le chevalet à la recherche du nombre précédent 1 et on incrémente le compteur
                if(chev[j]->nbr != chev[i]->nbr && chev[j]->clr == coul_actuel && chev[j]->nbr == nbr_pred_2){
                  for(k=0;k<N_CHEV-1;k++)
                    if(chev[j]->nbr != chev[k]->nbr && chev[k]->clr == coul_actuel && chev[k]->nbr == nbr_pred)
                      cpt_len_comb++;
                }

                // Si le nombre suivant 2 est présent alors on reparcours le chevalet à la recherche du nombre suivant 1 et on incrémente le compteur
                else if(chev[j]->nbr != chev[i]->nbr && chev[j]->clr == coul_actuel && chev[j]->nbr == nbr_suiv_2){
                  for(k=0;k<N_CHEV-1;k++)
                    if(chev[j]->nbr != chev[k]->nbr && chev[k]->clr == coul_actuel && chev[k]->nbr == nbr_suiv)
                      cpt_len_comb++;
                }
              }
            }
          }
        }

        if(cpt_len_comb >= 3) // On enregistre l'indice
          enr14_ind[i] = i;

        // On sort de la boucle
        cpt_len_comb = V_DEL;
      }
    }
  }
  // Suppression des tuiles présentes dans une combinaison
  for(i = 0; i < 14; i++){
    if(enr14_ind[i] == i){
     //printf("Les indices enr14 %i\n",enr14_ind[i]);
     chev[enr14_ind[i]]->nbr = V_DEL;
    }
   }
  // Suppression des tuiles présentes dans une combinaison
  for(i = 0; i < 14; i++){
    if(enr14_rep[i]->nbr != NO_VALUE)
      chev[enr14_ind[i]]->nbr = enr14_rep[i]->nbr;
  }
  // Affiche les répétitions d'une tuiles si elle est présente 2 fois
/*
  for(i = 0; i < 14; i++){
     if(enr14_rep[i]->nbr != NO_VALUE)
      printf("Les répétitions %i\n",enr14_rep[i]->nbr);
   }
*/
  detruire_tuile(enr14_rep,taille_tuile(enr14_rep,sizeof(enr14_rep))); // Detruit l'enregistrement
}

/**
* \fn void valeur_okey(t_tuile * okey,t_tuile * joker)
* \brief Donne une valeur + 1 de la tuile retournée (le okey) à la tuile joker rouge ou noire posséder par le joueur
* \param okey la tuile okey
* \param okey la tuile joker qui prend la valeur du okey +1
*/
void valeur_okey(t_tuile * okey,t_tuile * joker){

  if(joker->nbr == 13 && (joker->clr == noire || joker->clr == rouge)){
    // Si la tuile est 13 alors on l'incrémente, ce qui nous donne 1
    if(okey->nbr == 12){
      joker->nbr = 0;
      joker->clr = okey->clr;
    }
    // On incrément le joker et on associe la couleur du okey au joker
    else{
      joker->nbr = okey->nbr + 1;
      joker->clr = okey->clr;
    }
  }
}

/**
* \fn int regle_combinaison(t_tuile * chevalet[N_CHEV], t_tuile * okey)
* \brief Vérifie si le chevalet est gagnant (return 1, 0 pour contraire) en utilisant les combinaisons de couleurs et de suite d'entier
* \param chevalet[N_CHEV] Chevalet du joueur
* \param okey la tuile okey
*/
int regle_combinaison(t_tuile * chevalet[N_CHEV],t_tuile * okey){

  int i,reponse = 1;
  t_tuile * copy_chev[N_CHEV];

  creer_chevalet(copy_chev,N_CHEV);

  for(i = 0; i < N_CHEV-1; i++){         // Copie des tuiles de paramètre du chevalet d'entree
    copy_chev[i]->nbr = chevalet[i]->nbr;
    copy_chev[i]->clr = chevalet[i]->clr;
  }

  for(i = 0; i < N_CHEV-1; i++){         // Remplace les tuiles Joker par la valeur Okey + 1
    if(copy_chev[i]->nbr == 13){
      valeur_okey(okey,copy_chev[i]);
    }
  }


  regle_coul(copy_chev);
  regle_suite(copy_chev);

  //affiche_chevalet(copy_chev,N_CHEV);  // Vérifie si les algorithmes de combinaisons fonctionnent

  for(i = 0; i < N_CHEV-1; i++)          // Si l'un des tuiles est n'est pas supprimée alors ce n'est pas un chevalet gagnant
    if(copy_chev[i]->nbr != V_DEL)
      reponse = 0;

  detruire_tuile(copy_chev,N_CHEV);

  return reponse;
}
