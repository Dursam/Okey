
#include <jeu.h>
#include <unistd.h>

/*
void rejoindrePartie(){
  char * ip = malloc(sizeof(char) * 16);
  //menuServeur(ip);
}
*/

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
void premier_tour_partie(t_tuile * chevalet[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int dem){

  tri_rapide(chevalet,0,13);

  if(dem == 1){
    affiche_piles(okey,pile_J3,pile_J2,pile_J4,pile_J1);
  }
  else if(dem == 2){
    affiche_piles(okey,pile_J4,pile_J3,pile_J1,pile_J2);
  }
  else if(dem == 3){
    affiche_piles(okey,pile_J1,pile_J4,pile_J2,pile_J3);
  }
  else if(dem == 4){
    affiche_piles(okey,pile_J2,pile_J1,pile_J3,pile_J4);
  }
  affiche_chevalet(chevalet,N_CHEV);
}

/**
* \fn int pioche_vide(t_tuile * jeu[N_T])
* \brief Permet de vérifier si le jeu ne posséde plus aucune tuiles,return vrai (1) et faux (0)
* \param jeu[N_T] Tableau contenant les 106 tuiles
*/
int pioche_vide(t_tuile * jeu[N_T]){

  for(int i = 0;i < N_T; i++)
      if(jeu[i] != NULL)
        return 0;

  return 1;
}

/**
* \fn int tour_1_joueur(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur)
* \brief Réalise le premier tour d'un joueur
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
int tour_1_joueur(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur){

  /* Caractère pour faire une pause dans le programme */
  char pause;

  /* Détermine la tuile à enlever pour le joueur qui commence la partie en premier */
  int num_tuile_dep;

  /* Test si le chevalet du joueur est gagnant ou non */
  int issue_partie = 0;

  /* Détermine le choix de tri ou non */
  int tri_choix;

  /* Puis on retire une tuile du joueur qui commence la partie est on vérifie si son chevalet est gagnant ou non (Situation très rare) */
  printf("\n\nCHOIX : RETIRER UN NUMERO DE TUILE (1 à 15) ? ");
  scanf("%i",&num_tuile_dep);
  printf("\n");

  if(num_joueur == 1){
    empile_enr_tuile(joueur1,J1_p1,pile_J1,N_CHEV,num_tuile_dep-1);
    affiche_piles(okey,pile_J3,pile_J2,pile_J4,pile_J1);
    affiche_chevalet(joueur1,N_CHEV);
    issue_partie = regle_combinaison(joueur1,okey);
  }
  else if(num_joueur == 2){
    empile_enr_tuile(joueur2,J2_p2,pile_J2,N_CHEV,num_tuile_dep-1);
    affiche_piles(okey,pile_J4,pile_J3,pile_J1,pile_J2);
    affiche_chevalet(joueur2,N_CHEV);
    issue_partie = regle_combinaison(joueur2,okey);
  }
  else if(num_joueur == 3){
    empile_enr_tuile(joueur3,J3_p3,pile_J3,N_CHEV,num_tuile_dep-1);
    affiche_piles(okey,pile_J1,pile_J4,pile_J2,pile_J3);
    affiche_chevalet(joueur3,N_CHEV);
    issue_partie = regle_combinaison(joueur3,okey);
  }
  else if(num_joueur == 4){
    empile_enr_tuile(joueur4,J4_p4,pile_J4,N_CHEV,num_tuile_dep-1);
    affiche_piles(okey,pile_J2,pile_J1,pile_J3,pile_J4);
    affiche_chevalet(joueur4,N_CHEV);
    issue_partie = regle_combinaison(joueur4,okey);
  }

  if(issue_partie == 1){
    printf("\nLe joueur %i a gagné la partie\n",num_joueur);
    return num_joueur;
  }

  if(num_joueur == 1){
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

  return issue_partie;
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
int debut_partie(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur){

  /* Test si le chevalet du joueur est gagnant ou non */
  int issue_partie = 0;

  /* DEBUT DE PARTIE */
  printf("\n\nTour 1\n");

  /* Determine le joueur qui va débuter la partie en premier */
  if(num_joueur == 1){
    premier_tour_partie(joueur1,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
    issue_partie = tour_1_joueur(joueur1,joueur2,joueur3,joueur4,pile_J1,pile_J2,pile_J3,pile_J4,J1_p1,J2_p2,J3_p3,J4_p4,okey,1);
  }
  else if(num_joueur == 2){
    premier_tour_partie(joueur2,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
    issue_partie = tour_1_joueur(joueur1,joueur2,joueur3,joueur4,pile_J1,pile_J2,pile_J3,pile_J4,J1_p1,J2_p2,J3_p3,J4_p4,okey,2);
  }
  else if(num_joueur == 3){
    premier_tour_partie(joueur3,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
    issue_partie = tour_1_joueur(joueur1,joueur2,joueur3,joueur4,pile_J1,pile_J2,pile_J3,pile_J4,J1_p1,J2_p2,J3_p3,J4_p4,okey,3);
  }
  else if(num_joueur == 4){
    premier_tour_partie(joueur4,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
    issue_partie = tour_1_joueur(joueur1,joueur2,joueur3,joueur4,pile_J1,pile_J2,pile_J3,pile_J4,J1_p1,J2_p2,J3_p3,J4_p4,okey,4);
  }
  return issue_partie;
}

/**
* \fn void issue_partie(int issue_joueur)
* \brief Annonce de l'issue de la partie un vainqueur ou non
* \param issue_joueur le numéro de joueur de 1 à 4, 0 signifie qu'aucun joueur n'a gagné
*/
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
int tour_joueur(t_tuile * jeu[N_T],t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int cpt_tour,int num_joueur){

  char pause;
  int tri_choix, issue_partie = NO_VALUE;

  if(pioche_vide(jeu) == 1)
    return 0;
  printf("\nJoueur %i - Tour %i\n",num_joueur,cpt_tour);

  /* TOUR JOUEUR 1 */
  if(num_joueur == 1){
    selection_tuile(jeu,joueur1,J1_p1,pile_J3,pile_J2,pile_J4,pile_J1,okey);
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
    selection_tuile(jeu,joueur2,J2_p2,pile_J4,pile_J3,pile_J1,pile_J2,okey);
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
    selection_tuile(jeu,joueur3,J3_p3,pile_J1,pile_J4,pile_J2,pile_J3,okey);
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
    selection_tuile(jeu,joueur4,J4_p4,pile_J2,pile_J1,pile_J3,pile_J4,okey);
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
