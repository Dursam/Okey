/* Fichier contenant la fonction de combinaison de suite d'entier */
#include <init_structure.h>
#include <combinaison_suite_entiers.h>

/* Vérifie les ensembles de combinaisons à partir de 3 suites d'entiers */
extern
void combinaison_suite(t_tuile * chev[]){

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
