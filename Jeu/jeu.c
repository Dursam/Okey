
#include <jeu.h>

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
void issue_partie(int issue_joueur){

  /* Annonce du vainqueur de la partie */
  if(issue_joueur == 0){
    printf("La pioche est vide, la partie est terminée\n");
  }
  else{
    printf("\nLe joueur %i a gagné \n\n",issue_joueur);
  }

}

// NOTE : Fonction à raccourcir
/**
* \fn int partie_en_cours(t_tuile * jeu[N_T], t_tuile * joueur1[N_CHEV], t_tuile * joueur2[N_CHEV], t_tuile * joueur3[N_CHEV], t_tuile * joueur4[N_CHEV], t_tuile * J1_p1[], t_tuile * J2_p2[], t_tuile * J3_p3[], t_tuile * J4_p4[], t_pile * pile_J1, t_pile * pile_J2, t_pile * pile_J3, t_pile * pile_J4, int num_joueur, t_tuile * okey)
* \brief Permet le déroulement de la partie, après que le première joueur commence. Retourne le numéro de joueur gagnant
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
int partie_en_cours(t_tuile * jeu[N_T],t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,int num_joueur,t_tuile * okey){


    int issue_partie = 0;               // Test si le chevalet du joueur est gagnant ou non
    int cpt_tour = 2;
    int tri_choix;
    char pause;

    while(issue_partie == 0){

    /* Si le joueur 1 à commencé la partie au tour du joueur 2,3,4 et 1 */
    if(num_joueur == 1){

      /* TOUR JOUEUR 2 */
      if(pioche_vide(jeu) == 1)
        return 0;
      printf("\nJoueur 2 - Tour %i\n",cpt_tour);
      cpt_tour++;
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
      printf("FIN DE RANGEMENT\n");
      pause = getchar();
      while(getchar() != '\n');
      system("clear");

      /* TOUR JOUEUR 3 */
      if(pioche_vide(jeu) == 1)
        return 0;
      printf("\nJoueur 3 - Tour %i\n",cpt_tour);
      cpt_tour++;
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
      printf("FIN DE RANGEMENT\n");
      pause = getchar();
      while(getchar() != '\n');
      system("clear");

      /* TOUR JOUEUR 4 */
      if(pioche_vide(jeu) == 1)
        return 0;
      printf("\nJoueur 4 - Tour %i\n",cpt_tour);
      cpt_tour++;
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
      printf("FIN DE RANGEMENT\n");
      pause = getchar();
      while(getchar() != '\n');
      system("clear");

      /* TOUR JOUEUR 1 */
      if(pioche_vide(jeu) == 1)
        return 0;
      printf("\nJoueur 1 - Tour %i\n",cpt_tour);
      cpt_tour++;
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
      printf("FIN DE RANGEMENT\n");
      pause = getchar();
      while(getchar() != '\n');
      system("clear");

    }

    /* Si le joueur 2 à commencé la partie au tour du joueur 3,4,1 et 2 */
    else if(num_joueur == 2){

      /* TOUR JOUEUR 3 */
      if(pioche_vide(jeu) == 1)
        return 0;
      printf("\nJoueur 3 - Tour %i\n",cpt_tour);
      cpt_tour++;
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
      printf("FIN DE RANGEMENT\n");
      pause = getchar();
      while(getchar() != '\n');
      system("clear");

      /* TOUR JOUEUR 4 */
      if(pioche_vide(jeu) == 1)
        return 0;
      printf("\nJoueur 4 - Tour %i\n",cpt_tour);
      cpt_tour++;
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
      printf("FIN DE RANGEMENT\n");
      pause = getchar();
      while(getchar() != '\n');
      system("clear");

      /* TOUR JOUEUR 1 */
      if(pioche_vide(jeu) == 1)
        return 0;
      printf("\nJoueur 1 - Tour %i\n",cpt_tour);
      cpt_tour++;
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
      printf("FIN DE RANGEMENT\n");
      pause = getchar();
      while(getchar() != '\n');
      system("clear");

      /* TOUR JOUEUR 2 */
      if(pioche_vide(jeu) == 1)
        return 0;
      printf("\nJoueur 2 - Tour %i\n",cpt_tour);
      cpt_tour++;
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
      printf("FIN DE RANGEMENT\n");
      pause = getchar();
      while(getchar() != '\n');
      system("clear");

    }

    /* Si le joueur 3 à commencé la partie au tour du joueur 4,1,2 et 3 */
    else if(num_joueur == 3){

      /* TOUR JOUEUR 4 */
      if(pioche_vide(jeu) == 1)
        return 0;
      printf("\nJoueur 4 - Tour %i\n",cpt_tour);
      cpt_tour++;
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
      printf("FIN DE RANGEMENT\n");
      pause = getchar();
      while(getchar() != '\n');
      system("clear");

      /* TOUR JOUEUR 1 */
      if(pioche_vide(jeu) == 1)
        return 0;
      printf("\nJoueur 1 - Tour %i\n",cpt_tour);
      cpt_tour++;
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
      printf("FIN DE RANGEMENT\n");
      pause = getchar();
      while(getchar() != '\n');
      system("clear");

      /* TOUR JOUEUR 2 */
      if(pioche_vide(jeu) == 1)
        return 0;
      printf("\nJoueur 2 - Tour %i\n",cpt_tour);
      cpt_tour++;
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
      printf("FIN DE RANGEMENT\n");
      pause = getchar();
      while(getchar() != '\n');
      system("clear");

      /* TOUR JOUEUR 3 */
      if(pioche_vide(jeu) == 1)
        return 0;
      printf("\nJoueur 3 - Tour %i\n",cpt_tour);
      cpt_tour++;
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
      printf("FIN DE RANGEMENT\n");
      pause = getchar();
      while(getchar() != '\n');
      system("clear");

    }

    /* Si le joueur 4 à commencé la partie au tour du joueur 1,2,3 et 4 */
    else if(num_joueur == 4){

      /* TOUR JOUEUR 1 */
      if(pioche_vide(jeu) == 1)
        return 0;
      printf("\nJoueur 1 - Tour %i\n",cpt_tour);
      cpt_tour++;
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
      printf("FIN DE RANGEMENT\n");
      pause = getchar();
      while(getchar() != '\n');
      system("clear");

      /* TOUR JOUEUR 2 */
      if(pioche_vide(jeu) == 1)
        return 0;
      printf("\nJoueur 2 - Tour %i\n",cpt_tour);
      cpt_tour++;
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
      printf("FIN DE RANGEMENT\n");
      pause = getchar();
      while(getchar() != '\n');
      system("clear");

      /* TOUR JOUEUR 3 */
      if(pioche_vide(jeu) == 1)
        return 0;
      printf("\nJoueur 3 - Tour %i\n",cpt_tour);
      cpt_tour++;
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
      printf("FIN DE RANGEMENT\n");
      pause = getchar();
      while(getchar() != '\n');
      system("clear");

      /* TOUR JOUEUR 4 */
      if(pioche_vide(jeu) == 1)
        return 0;
      printf("\nJoueur 4 - Tour %i\n",cpt_tour);
      cpt_tour++;
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
      printf("FIN DE RANGEMENT\n");
      pause = getchar();
      while(getchar() != '\n');
      system("clear");
    }
  }
    return 0;
}
