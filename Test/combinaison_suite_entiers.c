#include <init_structure.h>
#include <combinaison_suite_entiers.h>

/**
* \file combinaison_suite_entiers.c
* \brief Fichier contenant la fonction de combinaison de suites d'entiers
* \author Samuel DURAN
* \version 1.0
* \date 12 avril 2020
*/

/**
* \fn int detection_rep_tuile(t_tuile * chev[])
* \brief Détecte si dans le chevalet il y a 3 ou 4 fois la même tuile, signifie que le chevalet possède des jokers
* \param chev[] Chevalet contenant les tuiles
*/
extern
int detection_rep_joker(t_tuile * chev[]){

  // Enregistre le nombre de tuiles d'une même couleur: bleu,noire,rouge et jaune. Indice i.
  int enr13_jaune[13] = {0},enr13_rouge[13] = {0},enr13_noire[13] = {0},enr13_bleu[13] = {0},i;

  // On compte le nombre de tuiles de chaque couleur du chevalet, les tuiles supprimées ne sont pas comptés
  for(i = 0;i < N_CHEV-1;i++){
    if(chev[i]->clr == jaune && chev[i]->nbr != V_DEL)
      enr13_jaune[chev[i]->nbr]++;
    else if(chev[i]->clr == rouge && chev[i]->nbr != V_DEL)
      enr13_rouge[chev[i]->nbr]++;
    else if(chev[i]->clr == noire && chev[i]->nbr != V_DEL)
      enr13_noire[chev[i]->nbr]++;
    else if(chev[i]->clr == bleu && chev[i]->nbr != V_DEL)
      enr13_bleu[chev[i]->nbr]++;
  }
  // Si le nombre de l'une des tuiles est égale à 3 ou à 4 alors on retoune le nombre de joker
  for(i = 0;i < 13;i++){
    if(enr13_jaune[i] >= 3 || enr13_rouge[i] >= 3 || enr13_noire[i] >= 3 || enr13_bleu[i] >= 3)
      return i;
  }
  // Si rien, on retoune NO_VALUE
  return NO_VALUE;
}

/**
* \fn void combinaison_suite(t_tuile * chev[])
* \brief Vérifie les ensembles de combinaisons à partir de 3 suites d'entiers
* \param chev[] Chevalet contenant les tuiles
*/
extern
void combinaison_suite(t_tuile * chev[]){

  int enr14_ind[14] = {V_DEL},                    // Enregistre les tuiles pour suppression (Cas d'une même tuile)
  enr13_coul[13] = {0},                           // Enregistre les tuiles de 1 à 13 de la couleur d'indice i, utilisé dans la boucle WHILE
  cpt_len_comb,                                   // Compte le nombre de combinaison
  i,j,k                                           // Indices, i est une aide visuelle et remplaçable par i (facultatif)
  ,nbr_suiv, nbr_pred,nbr_suiv_2,nbr_pred_2,      // Nombres qui permettent de calculer les 2 nombres précédent et les 2 nombres suivant de la tuile d'indice i
  i_joker;                                        // Indice du Joker si présent dans le chevalet
  t_couleur coul_actuel;                          // Valeur temporaire de la couleur de la tuile d'indice i
  t_tuile * enr14_rep[14];                        // Enregistre les tuiles pour suppression (Cas de 2 même tuile)

  creer_chevalet(enr14_rep,14);                   // Initialise l'enregistrement

  for(i = 0;i < N_CHEV-1;i++){                    // Donne une valeur de comparaison, la couleur est sans importance
    enr14_rep[i]->nbr = NO_VALUE;
    enr14_rep[i]->clr = jaune;
  }

  for(i = 0;i < N_CHEV-1;i++)                     // Initialise l'enregistrement
    enr14_ind[i] = V_DEL;

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

      for(j = 0; j < 14; j++)
        if(enr14_rep[j]->nbr == chev[i]->nbr && enr14_rep[j]->clr == chev[i]->clr) // Permet d'éviter de supprimer 2 fois une même tuile du chevalet
          enr13_coul[chev[i]->nbr]-- ;

      i_joker = detection_rep_joker(chev);
      if(i_joker != NO_VALUE)
        if(enr13_coul[chev[i]->nbr] == 2 && (enr13_coul[i_joker] == 3 || enr13_coul[i_joker] == 4))
          enr13_coul[i_joker] = 2;

      while(cpt_len_comb == 1){

        if(chev[i]->nbr == 0){               // Si tuile numéro 1 alors précédent '13' et 12 et suivant 2 et 3
          nbr_pred = 12;
          nbr_suiv = chev[i]->nbr + 1;
          nbr_pred_2 = nbr_pred - 1;
          nbr_suiv_2 = nbr_suiv + 1;
        }
        else if(chev[i]->nbr == 12){         // Si tuile numéro 13 alors précédent 12 et 11 et suivant '1' et 2
          nbr_pred = chev[i]->nbr - 1;
          nbr_suiv = 0;
          nbr_pred_2 = nbr_pred - 1;
          nbr_suiv_2 = nbr_suiv + 1;
        }
        else if(chev[i]->nbr == 1){          // Si tuile numéro 2 alors précédent 1 et '13' et suivant 3 et 4
          nbr_pred = chev[i]->nbr - 1;
          nbr_suiv = chev[i]->nbr + 1;
          nbr_pred_2 = 12;
          nbr_suiv_2 = nbr_suiv + 1;
        }
        else if(chev[i]->nbr == 11){         // Si tuile numéro 12 alors précédent 11 et 10 et suivant 13 et '1'
          nbr_pred = chev[i]->nbr - 1;
          nbr_suiv = chev[i]->nbr + 1;
          nbr_pred_2 = nbr_pred - 1;
          nbr_suiv_2 = 0;
        }
        else{                                // Si autre numéro de tuile alors précédent tuile nbr -1 et tuile nbr -2 et suivant tuile nbr +1 et tuile nbr +2 du nombre
          nbr_pred = chev[i]->nbr - 1;      // de la tuile actuelle
          nbr_suiv = chev[i]->nbr + 1;
          nbr_pred_2 = nbr_pred - 1;
          nbr_suiv_2 = nbr_suiv + 1;
        }

        if(enr13_coul[chev[i]->nbr] == 2){                                 // S'il y a 2 fois la même tuile de même couleur
          // S'il y a 2 fois le nombre précédent et suivant -> VALIDE
          if(enr13_coul[nbr_pred] == 2 && enr13_coul[nbr_suiv] == 2)
            cpt_len_comb = cpt_len_comb + 2;

          // S'il y a 2 fois le nombre suivant et 2 fois le nombre
          else if(enr13_coul[nbr_pred] != 2 && enr13_coul[nbr_suiv] == 2){
            cpt_len_comb++;                                                // précédent (2) ou suivant (2) -> VALIDE
            if(enr13_coul[nbr_pred_2] == 2 || enr13_coul[nbr_suiv_2] == 2){
              cpt_len_comb++;
            }
          }
          // Si il y a 2 fois le nombre précédent et 2 fois le nombre
          else if(enr13_coul[nbr_pred] == 2 && enr13_coul[nbr_suiv] != 2){
            cpt_len_comb++;                                                // précédent (2) ou suivant (2) -> VALIDE
            if(enr13_coul[nbr_pred_2] == 2 || enr13_coul[nbr_suiv_2] == 2){
              cpt_len_comb++;
            }
          }
          /* Dans une situation où le joker est présent 3 fois, si une tuile présent 2 fois dont l'une est dans une combinaison avec un joker, l'autre sans joker
           et que la tuile indépendante du joker respecte les conditions tel que :
           - Son nombre nbr_pred, nbr_pred_2, nbr_suiv sont égaux à 1 et nbr_suiv_2 à 2
           - Son nombre nbr_suiv, nbr_suiv_2, nbr_pred sont égaux à 1 et nbr_pred_2 à 2
           alors celle-ci est dans une combinaison */
          else if(i_joker != NO_VALUE && enr13_coul[nbr_pred] == 1 && enr13_coul[nbr_pred_2] == 2 && enr13_coul[nbr_suiv] == 1 && enr13_coul[nbr_suiv_2] == 1){
            cpt_len_comb = V_DEL;
          }
          else if(i_joker != NO_VALUE && enr13_coul[nbr_pred] == 1 && enr13_coul[nbr_pred_2] == 1 && enr13_coul[nbr_suiv] == 1 && enr13_coul[nbr_suiv_2] == 2){
            cpt_len_comb = V_DEL;
          }
          // On enregistre la tuile et on sort de la boucle WHILE
          else{
            enr14_rep[i]->nbr = chev[i]->nbr;
            enr14_rep[i]->clr = chev[i]->clr;
            cpt_len_comb = V_DEL;
          }
        }
        else if(enr13_coul[chev[i]->nbr] == 4){                            // S'il y a 2 fois la même tuile et 2 jokers correspondant à la valeur de cette tuile
          if(enr13_coul[nbr_pred] == 2 && enr13_coul[nbr_suiv] == 2 && enr13_coul[nbr_pred_2] == 2 && enr13_coul[nbr_suiv_2] == 2)
            cpt_len_comb = V_DEL;                                          // Alors la tuile qui est présente 4 fois sont tous dans une combinaison
        }
        else if(enr13_coul[chev[i]->nbr] == 3){                            // S'il y a 2 fois la même tuile et un joker correspondant à la valeur de cette tuile
          if(enr13_coul[nbr_pred] == 2 && enr13_coul[nbr_pred_2] == 2 && enr13_coul[nbr_suiv] >= 1 && enr13_coul[nbr_suiv_2] >= 1)
            cpt_len_comb = V_DEL;                                          // Alors la tuile qui est présente 4 fois sont tous dans une combinaison
          else if(enr13_coul[nbr_pred] >= 1  && enr13_coul[nbr_pred_2] >= 1 && enr13_coul[nbr_suiv] == 2 && enr13_coul[nbr_suiv_2] == 2)
            cpt_len_comb = V_DEL;                                          // Alors la tuile qui est présente 4 fois sont tous dans une combinaison
        }
        else{                                                              // Si la tuile actuelle est présente qu'une seule fois
          for(j = 0;j < N_CHEV-1;j++)                                      // On parcours le chevalet
            if(chev[j]->nbr != V_DEL)                                      // On compte si le nombre suivant ou précédent est présent du chevalet
              if(chev[j]->nbr != chev[i]->nbr && chev[j]->clr == coul_actuel && (chev[j]->nbr == nbr_pred || chev[j]->nbr == nbr_suiv))
                cpt_len_comb++;

          if(i_joker == NO_VALUE && ((enr13_coul[nbr_pred] == 2 && enr13_coul[nbr_suiv] == 0) || (enr13_coul[nbr_pred] == 0 && enr13_coul[nbr_suiv] == 2))){
            cpt_len_comb = 1;                                              // S'il y a 2 fois le nombre précédent et 0 fois le nombre suivant et vice-versa -> NON VALIDE
          }

          if(cpt_len_comb == 2){                                           // Si ce qu'on a compté auparavant est égaux à 2
            for(j = 0;j < N_CHEV-1;j++){                                   // On parcours le chevalet

              if(chev[j]->nbr != V_DEL){
                // Si le nombre précédent (2) est présent alors on reparcours le chevalet à la recherche du nombre précédent (1) et on incrémente le compteur
                if(chev[j]->nbr != chev[i]->nbr && chev[j]->clr == coul_actuel && chev[j]->nbr == nbr_pred_2){
                  for(k=0;k<N_CHEV-1;k++)
                    if(chev[j]->nbr != chev[k]->nbr && chev[k]->clr == coul_actuel && chev[k]->nbr == nbr_pred)
                      cpt_len_comb++;
                }
                // Si le nombre suivant (2) est présent alors on reparcours le chevalet à la recherche du nombre suivant (1) et on incrémente le compteur
                else if(chev[j]->nbr != chev[i]->nbr && chev[j]->clr == coul_actuel && chev[j]->nbr == nbr_suiv_2)
                  for(k=0;k<N_CHEV-1;k++)
                    if(chev[j]->nbr != chev[k]->nbr && chev[k]->clr == coul_actuel && chev[k]->nbr == nbr_suiv)
                      cpt_len_comb++;
              }
            }
          }
        }

        if(cpt_len_comb >= 3 )                                             // On enregistre l'indice
          enr14_ind[i] = i;

        cpt_len_comb = V_DEL;                                              // On sort de la boucle
      }
    }
  }
  // Suppression des tuiles présentes dans une combinaison
  for(i = 0; i < 14; i++)
    if(enr14_ind[i] == i)
     chev[enr14_ind[i]]->nbr = V_DEL;
  // Suppression des tuiles présentes dans une combinaison
  for(i = 0; i < 14; i++)
    if(enr14_rep[i]->nbr != NO_VALUE)
      chev[enr14_ind[i]]->nbr = enr14_rep[i]->nbr;

  detruire_tuile(enr14_rep,taille_tuile(enr14_rep,sizeof(enr14_rep))); // Detruit l'enregistrement
}
