/* Fichier contenant les fonctions principaux pour lancer une partie de Okey */

#include <init_structure.h>
#include <init_pile.h>
#include <affichage_tuile.h>
#include <combinaison_couleur.h>
#include <combinaison_suite_entiers.h>
#include <selection_tuile.h>

/**
* \fn void valeur_okey(t_tuile * okey,t_tuile * joker)
* \brief Donne une valeur + 1 de la tuile retournée (le okey) à la tuile joker rouge ou noire posséder par le joueur
* \param okey la tuile okey
* \param okey la tuile joker qui prend la valeur du okey +1
*/
extern
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
* \fn void affiche_plateau(t_tuile * okey, t_pile * pfg, t_pile * pfd, t_pile * pg, t_pile * pd)
* \brief Affichage du sommet des piles de tout les joueurs, valeur du okey et une pioche
* \param okey la tuile okey
* \param okey la tuile okey
* \param pfg pile fond gauche
* \param pfd pile fond droite
* \param pg pile gauche
* \param pd pile droite
*/
extern
void affiche_plateau(t_tuile * okey,t_pile * p1,t_pile * p2,t_pile * p3,t_pile * p4){

  printf("\n\t");
  affiche_sommet_pile(p1);
  printf("\t\t\t\t\t");
  affiche_sommet_pile(p2);

  // Cas d'affichage pour éviter d'espacer les nombres à 2 chiffres
  printf("\n\t\t\t   OKEY\tPIOCHE\n\t\t\t   ");

  if(okey->nbr < 9){
    printf("%i ",(okey->nbr)+1);
    switch (okey->clr){
      case jaune: printf("\033[34;43m__\033[00m\t");break;
      case rouge: printf("\033[34;41m__\033[00m\t");break;
      case noire: printf("\033[34;40m__\033[00m\t");break;
      case bleu:  printf("\033[34;44m__\033[00m\t");break;
    }
  }
  else{
    printf("%i",(okey->nbr)+1);
    switch (okey->clr){
      case jaune: printf("\033[34;43m__\033[00m\t");break;
      case rouge: printf("\033[34;41m__\033[00m\t");break;
      case noire: printf("\033[34;40m__\033[00m\t");break;
      case bleu:  printf("\033[34;44m__\033[00m\t");break;
    }
  }

  printf("\033[34;47m__\033[00m  \033[34;47m__\033[00m\n\n\t");
  affiche_sommet_pile(p3);
  printf("\t\t\t\t\t");
  affiche_sommet_pile(p4);
  printf("\n\n");

}

/**
* \fn void premier_tour_partie(t_tuile * chevalet[N_CHEV], t_pile * pile_J1, t_pile * pile_J2, t_pile * pile_J3, t_pile * pile_J4, t_tuile * okey, int dem)
* \brief Tour 1 du joueur qui commence la partie
* \param chevalet[N_CHEV] Chevalet du joueur
* \param pile joueur 1
* \param pile joueur 2
* \param pile joueur 3
* \param pile joueur 4
* \param okey la tuile okey
* \param dem numéro du joueur qui débute la débute la partie
*/
extern
void premier_tour_partie(t_tuile * chevalet[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int dem){

  tri_rapide(chevalet,0,13);

  if(dem == 1){
    affiche_plateau(okey,pile_J3,pile_J2,pile_J4,pile_J1);
  }
  else if(dem == 2){
    affiche_plateau(okey,pile_J4,pile_J3,pile_J1,pile_J2);
  }
  else if(dem == 3){
    affiche_plateau(okey,pile_J1,pile_J4,pile_J2,pile_J3);
  }
  else if(dem == 4){
    affiche_plateau(okey,pile_J2,pile_J1,pile_J3,pile_J4);
  }
  affiche_chevalet(chevalet,N_CHEV);
}

/**
* \fn void depiler_toutes_tuiles(t_pile * pile_J1, t_pile * pile_J2, t_pile * pile_J3, t_pile * pile_J4)
* \brief Dépile toutes les piles de tuiles, utilisé pour finir la partie
* \param pile joueur 1
* \param pile joueur 2
* \param pile joueur 3
* \param pile joueur 4
*/
extern
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

/**
* \fn int regle_combinaison(t_tuile * chevalet[N_CHEV], t_tuile * okey)
* \brief Vérifie si le chevalet est gagnant (return 1, 0 pour contraire) en utilisant les combinaisons de couleurs et de suite d'entier
* \param chevalet[N_CHEV] Chevalet du joueur
* \param okey la tuile okey
*/
extern
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


  combinaison_coul(copy_chev);
  combinaison_suite(copy_chev);

  //affiche_chevalet(copy_chev,N_CHEV);  // Vérifie si les algorithmes de combinaisons fonctionnent

  for(i = 0; i < N_CHEV-1; i++)          // Si l'un des tuiles est n'est pas supprimée alors ce n'est pas un chevalet gagnant
    if(copy_chev[i]->nbr != V_DEL)
      reponse = 0;

  detruire_tuile(copy_chev,N_CHEV);

  return reponse;
}

/**
* \fn int choix_tri(t_tuile * chevalet[N_CHEV])
* \brief Laisse le choix au joueur de pouvoir faire un tri rapide, un tri manuel ou pas de tri
* \param chevalet[N_CHEV] Chevalet du joueur
*/
extern
int choix_tri(t_tuile * chevalet[N_CHEV]){

  int * choix = malloc(sizeof(int)),res;

  do{
  printf("CHOIX : TRI RAPIDE(2) OU TRI MANUEL(1) OU ANNULER(0) ? ");
  scanf("%i",choix);
  }while(*choix != 0 && *choix != 1 && *choix != 2);

  if(*choix == 2){
    tri_rapide(chevalet,0,13);
    res = 2;
  }

  else if(*choix == 1){
    tri_manuel(chevalet);
    res = 1;
  }

  else if(*choix == 0)
    res = 0;

  free(choix);

  return res;
}

/**
* \fn int debut_partie(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur)
* \brief Débute le première tour de la partie en démarrant avec le joueur qui reçoit une 15 ème tuile
* \param joueur1
* \param joueur2
* \param joueur3
* \param joueur4
* \param pile_J1
* \param pile_J2
* \param pile_J3
* \param pile_J4
* \param J1_p1
* \param J2_p2
* \param J3_p3
* \param J4_p4
* \param okey la tuile okey
* \param num_joueur le numéro du joueur de 1 à 4
*/
extern
int debut_partie(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur){

  /* Caractère pour faire une pause dans le programme */
  char pause;

  /* Détermine la tuile à enlever pour le joueur qui commence la partie en premier */
  int num_tuile_dep;

  /* Test si le chevalet du joueur est gagnant ou non */
  int issue_partie = 0;

  /* Détermine le choix de tri ou non */
  int tri_choix;

  /* DEBUT DE PARTIE */
  printf("\n\nTour 1\n");

  /* Determine le joueur qui va débuter la partie en premier */
  if(num_joueur == 1){
    premier_tour_partie(joueur1,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
  }
  else if(num_joueur == 2){
    premier_tour_partie(joueur2,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
  }
  else if(num_joueur == 3){
    premier_tour_partie(joueur3,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
  }
  else if(num_joueur == 4){
    premier_tour_partie(joueur4,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
  }

  /* Puis on retire une tuile du joueur qui commence la partie est on vérifie si son chevalet est gagnant ou non (Situation très rare) */
  printf("\n\nCHOIX : RETIRER UN NUMERO DE TUILE (1 à 15) ? ");
  scanf("%i",&num_tuile_dep);
  printf("\n");

  if(num_joueur == 1){
    empile_enr_tuile(joueur1,J1_p1,pile_J1,N_CHEV,num_tuile_dep-1);
    affiche_chevalet(joueur1,N_CHEV);
    issue_partie = regle_combinaison(joueur1,okey);
    if(issue_partie == 1){
      printf("\nLe joueur 1 a gagné la partie\n");
      return 1;
    }

    tri_choix = choix_tri(joueur1);
    if(tri_choix == 2)
      affiche_chevalet(joueur1,N_CHEV);
    else if(tri_choix == 1){
      do{
        printf("CHOIX : CONTINUER TRI MANUEL(1) OU ARRETER(0) ? ");
        scanf("%i",&tri_choix);
        if(tri_choix == 1)
          tri_manuel(joueur1);
      } while(tri_choix == 1);
    }
  }

  else if(num_joueur == 2){
    empile_enr_tuile(joueur2,J2_p2,pile_J2,N_CHEV,num_tuile_dep-1);
    affiche_chevalet(joueur2,N_CHEV);
    issue_partie = regle_combinaison(joueur2,okey);
    if(issue_partie == 1){
      printf("\nLe joueur 2 a gagné la partie\n");
      return 2;
    }

    tri_choix = choix_tri(joueur2);
    if(tri_choix == 2)
      affiche_chevalet(joueur2,N_CHEV);
    else if(tri_choix == 1){
      do{
        printf("CHOIX : CONTINUER TRI MANUEL(1) OU ARRETER(0) ? ");
        scanf("%i",&tri_choix);
        if(tri_choix == 1)
          tri_manuel(joueur2);
      } while(tri_choix == 1);
    }
  }

  else if(num_joueur == 3){
    empile_enr_tuile(joueur3,J3_p3,pile_J3,N_CHEV,num_tuile_dep-1);
    affiche_chevalet(joueur3,N_CHEV);
    issue_partie = regle_combinaison(joueur3,okey);
    if(issue_partie == 1){
      printf("\nLe joueur 3 a gagné la partie\n");
      return 3;
    }

    tri_choix = choix_tri(joueur3);
    if(tri_choix == 2)
      affiche_chevalet(joueur3,N_CHEV);
    else if(tri_choix == 1){
      do{
        printf("CHOIX : CONTINUER TRI MANUEL(1) OU ARRETER(0) ? ");
        scanf("%i",&tri_choix);
        if(tri_choix == 1)
          tri_manuel(joueur3);
      } while(tri_choix == 1);
    }
  }

  else if(num_joueur == 4){
    empile_enr_tuile(joueur4,J4_p4,pile_J4,N_CHEV,num_tuile_dep-1);
    affiche_chevalet(joueur4,N_CHEV);
    issue_partie = regle_combinaison(joueur4,okey);
    if(issue_partie == 1){
      printf("\nLe joueur 4 a gagné la partie\n");
      return 4;
    }

    tri_choix = choix_tri(joueur4);
    if(tri_choix == 2)
      affiche_chevalet(joueur4,N_CHEV);
    else if(tri_choix == 1){
      do{
        printf("CHOIX : CONTINUER TRI MANUEL(1) OU ARRETER(0) ? ");
        scanf("%i",&tri_choix);
        if(tri_choix == 1)
          tri_manuel(joueur4);
      } while(tri_choix == 1);
    }
  }

  printf("FIN DE TOUR\n");
  pause = getchar();
  while(getchar() != '\n');
  system("clear");

  return 0;
}

/**
* \fn void issue_partie(int issue_joueur)
* \brief Annonce de l'issue de la partie un vainqueur ou non
* \param issue_joueur le numéro de joueur de 1 à 4, 0 signifie qu'aucun joueur n'a gagné
*/
extern
void issue_partie(int issue_joueur){

  /* Annonce du vainqueur de la partie */
  if(issue_joueur == 0){
    printf("La pioche est vide, la partie est terminée\n");
  }
  else{
    printf("\nLe joueur %i a gagné \n\n",issue_joueur);
  }

}

/**
* \fn void selection_tuile_v2(t_tuile * jeu[N_T], t_tuile * chevalet[N_CHEV], t_tuile * enr[], t_pile * pfg, t_pile * pfd, t_pile * pg, t_pile * pd,t_tuile * okey)
* \brief Permet de sélection une tuile soit de la pioche ou de la pile de gauche et retire une tuile du chevalet, version avec affiche_pile et le okey
* \param jeu[N_T] Tableau contenant les tuiles
* \param chevalet[N_CHEV] Chevalet du joueur
* \param enr[] enregistrement temporaire des tuiles d'un chevalet
* \param pfg pile fond gauche
* \param pfd pile fond droit
* \param pg  pile gauche
* \param pd  pile droite
* \param okey la tuile okey
*/

extern
void selection_tuile_v2(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd,t_tuile * okey){

  int numero,* choix = malloc(sizeof(int));

  char pause;

  t_tuile * tuile_sommet;

  affiche_plateau(okey,pfg,pfd,pg,pd);
  affiche_chevalet(chevalet,N_CHEV);

  do{
  printf("CHOIX : PIOCHE(0) OU PILE DE GAUCHE(1) ? ");
  scanf("%i",choix);
} while(*choix != 0 && *choix != 1);


  if(*choix==0)
    *chevalet[14] = distribution_pioche(jeu);

  else{
    sommet_pile(pg,&tuile_sommet);
    chevalet[14]->nbr = tuile_sommet->nbr;
    chevalet[14]->clr = tuile_sommet->clr;
    depiler(pg);
  }

  affiche_plateau(okey,pfg,pfd,pg,pd);
  affiche_chevalet(chevalet,N_CHEV);

  printf("CHOIX : RETIRER UN NUMERO DE TUILE (1 à 15) ? ");
  scanf("%i",&numero);

  empile_enr_tuile(chevalet,enr,pd,N_CHEV,numero-1);

  affiche_plateau(okey,pfg,pfd,pg,pd);
  affiche_chevalet(chevalet,N_CHEV);

  free(choix);

  printf("FIN DE TOUR\n");
  pause = getchar();
  while(getchar() != '\n');
}

/**
* \fn int pioche_vide(t_tuile * jeu[N_T])
* \brief Permet de vérifier si le jeu ne posséde plus aucune tuiles,return vrai (1) et faux (0)
* \param jeu[N_T] Tableau contenant les 106 tuiles
*/
extern
int pioche_vide(t_tuile * jeu[N_T]){

  for(int i = 0;i < N_T; i++)
      if(jeu[i] != NULL)
        return 0;

  return 1;
}


/**
* \fn void tour_joueur(t_tuile * jeu[N_T],t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int cpt_tour,int num_joueur)
* \brief Permet de réaliser le tour d'un joueur
* \param joueur1
* \param joueur2
* \param joueur3
* \param joueur4
* \param J1_p1
* \param J2_p2
* \param J3_p3
* \param J4_p4
* \param pile_J1
* \param pile_J2
* \param pile_J3
* \param pile_J4
* \param okey la tuile okey
* \param cpt_tour Numéro de tour
* \param num_joueur le numéro du joueur de 1 à 4
*/
extern
int tour_joueur(t_tuile * jeu[N_T],t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int cpt_tour,int num_joueur){

  char pause;
  int tri_choix, issue_partie = NO_VALUE;

  if(pioche_vide(jeu) == 1)
    return 0;
  printf("\nJoueur %i - Tour %i\n",num_joueur,cpt_tour);

  /* TOUR JOUEUR 1 */
  if(num_joueur == 1){
    selection_tuile_v2(jeu,joueur1,J1_p1,pile_J3,pile_J2,pile_J4,pile_J1,okey);
    issue_partie = regle_combinaison(joueur1,okey);
    if(issue_partie == 1)
      return 1;
    tri_choix = choix_tri(joueur1);
    if(tri_choix == 2)
      affiche_chevalet(joueur1,N_CHEV);
    else if(tri_choix == 1){
      do{
        printf("CHOIX : CONTINUER TRI MANUEL(1) OU ARRETER(0) ? ");
        scanf("%i",&tri_choix);
        if(tri_choix == 1)
          tri_manuel(joueur1);
      } while(tri_choix == 1);
    }
  }
  /* TOUR JOUEUR 2 */
  else if(num_joueur == 2){
    selection_tuile_v2(jeu,joueur2,J2_p2,pile_J4,pile_J3,pile_J1,pile_J2,okey);
    issue_partie = regle_combinaison(joueur2,okey);
    if(issue_partie == 1)
      return 2;
    tri_choix = choix_tri(joueur2);
    if(tri_choix == 2)
      affiche_chevalet(joueur2,N_CHEV);
    else if(tri_choix == 1){
      do{
        printf("CHOIX : CONTINUER TRI MANUEL(1) OU ARRETER(0) ? ");
        scanf("%i",&tri_choix);
        if(tri_choix == 1)
          tri_manuel(joueur2);
      } while(tri_choix == 1);
    }
  }
  /* TOUR JOUEUR 3 */
  else if(num_joueur == 3){
    selection_tuile_v2(jeu,joueur3,J3_p3,pile_J1,pile_J4,pile_J2,pile_J3,okey);
    issue_partie = regle_combinaison(joueur3,okey);
    if(issue_partie == 1)
      return 3;
    tri_choix = choix_tri(joueur3);
    if(tri_choix == 2)
      affiche_chevalet(joueur3,N_CHEV);
    else if(tri_choix == 1){
      do{
        printf("CHOIX : CONTINUER TRI MANUEL(1) OU ARRETER(0) ? ");
        scanf("%i",&tri_choix);
        if(tri_choix == 1)
          tri_manuel(joueur3);
      } while(tri_choix == 1);
    }
  }
  /* TOUR JOUEUR 4 */
  else if(num_joueur == 4){
    selection_tuile_v2(jeu,joueur4,J4_p4,pile_J2,pile_J1,pile_J3,pile_J4,okey);
    issue_partie = regle_combinaison(joueur4,okey);
    if(issue_partie == 1)
      return 4;
    tri_choix = choix_tri(joueur4);
    if(tri_choix == 2)
      affiche_chevalet(joueur4,N_CHEV);
    else if(tri_choix == 1){
      do{
        printf("CHOIX : CONTINUER TRI MANUEL(1) OU ARRETER(0) ? ");
        scanf("%i",&tri_choix);
        if(tri_choix == 1)
          tri_manuel(joueur4);
      } while(tri_choix == 1);
    }
  }

  cpt_tour++;
  printf("FIN DE RANGEMENT\n");
  pause = getchar();
  while(getchar() != '\n');
  system("clear");

  return NO_VALUE;
}

/**
* \fn int partie_en_cours(t_tuile * jeu[N_T], t_tuile * joueur1[N_CHEV], t_tuile * joueur2[N_CHEV], t_tuile * joueur3[N_CHEV], t_tuile * joueur4[N_CHEV], t_tuile * J1_p1[], t_tuile * J2_p2[], t_tuile * J3_p3[], t_tuile * J4_p4[], t_pile * pile_J1, t_pile * pile_J2, t_pile * pile_J3, t_pile * pile_J4, t_tuile * okey, int num_joueur)
* \brief Permet le déroulement de la partie, après que le première joueur désigné commence
* \param joueur1
* \param joueur2
* \param joueur3
* \param joueur4
* \param J1_p1
* \param J2_p2
* \param J3_p3
* \param J4_p4
* \param pile_J1
* \param pile_J2
* \param pile_J3
* \param pile_J4
* \param num_joueur le numéro du joueur de 1 à 4
* \param okey la tuile okey
*/
extern
int partie_en_cours(t_tuile * jeu[N_T],t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int num_joueur){

    int issue_partie = NO_VALUE;               // Test si le chevalet du joueur est gagnant ou non
    int cpt_tour = 2;

    while(issue_partie == NO_VALUE){
    /* Si le joueur 1 à commencé la partie au tour du joueur 2,3,4 et 1 */
    if(num_joueur == 1){
      /* TOUR JOUEUR 2 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,2);
      /* TOUR JOUEUR 3 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,3);
      /* TOUR JOUEUR 4 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,4);
      /* TOUR JOUEUR 1 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,1);
    }
    /* Si le joueur 2 à commencé la partie au tour du joueur 3,4,1 et 2 */
    else if(num_joueur == 2){
      /* TOUR JOUEUR 3 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,3);
      /* TOUR JOUEUR 4 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,4);
      /* TOUR JOUEUR 1 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,1);
      /* TOUR JOUEUR 2 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,2);
    }
    /* Si le joueur 3 à commencé la partie au tour du joueur 4,1,2 et 3 */
    else if(num_joueur == 3){
      /* TOUR JOUEUR 4 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,4);
      /* TOUR JOUEUR 1 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,1);
      /* TOUR JOUEUR 2 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,2);
      /* TOUR JOUEUR 3 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,3);
    }
    /* Si le joueur 4 à commencé la partie au tour du joueur 1,2,3 et 4 */
    else if(num_joueur == 4){
      /* TOUR JOUEUR 1 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,1);
      /* TOUR JOUEUR 2 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,2);
      /* TOUR JOUEUR 3 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,3);
      /* TOUR JOUEUR 4 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,4);
    }
  }
  return 0;
}
