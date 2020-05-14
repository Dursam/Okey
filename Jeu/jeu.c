
#include <jeu.h>
#include <unistd.h>

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

  t_tuile ** joueur;
  t_pile * pile;
  t_tuile ** J_p;
  t_pile * order[4] = {pile_J3,pile_J2,pile_J4,pile_J1};
  if(num_joueur == 1){
    joueur = joueur1;
    pile = pile_J1;
    J_p = J1_p1;
  }
  if(num_joueur == 2){
    joueur = joueur2;
    pile = pile_J2;
    order[1] = order[0];
    order[0] = order[2];
    order[2] = order[3];
    order[3] = pile;
    J_p = J2_p2;
  }
  if(num_joueur == 3){
    joueur = joueur3;
    pile = pile_J3;
    order[0] = order[3];
    order[3] = pile;
    t_pile * save = order[2];
    order[2] = order[1];
    order[1] = save;
    J_p = J3_p3;
  }
  if(num_joueur == 4){
    joueur = joueur4;
    pile = pile_J4;
    order[2] = order[0];
    order[0] = order[1];
    order[1] = order[3];
    order[3] = pile;
    J_p = J4_p4;
  }

  /* Caractère pour faire une pause dans le programme */
  char pause;

  /* Détermine la tuile à enlever pour le joueur qui commence la partie en premier */
  int num_tuile_dep=0;

  /* Test si le chevalet du joueur est gagnant ou non */
  int issue_partie = 0;

  /* Détermine le choix de tri ou non */
  int tri_choix;

  /* Puis on retire une tuile du joueur qui commence la partie est on vérifie si son chevalet est gagnant ou non (Situation très rare) */
  while(num_tuile_dep < 1 || num_tuile_dep >15){

    num_tuile_dep = select_tuile(0);
  }



  empile_enr_tuile(joueur,J_p,pile,N_CHEV,num_tuile_dep-1);
  affiche_piles(okey,order[0], order[1], order[2], order[3]);
  affiche_chevalet(joueur,N_CHEV);
  issue_partie = regle_combinaison(joueur,okey);


  if(issue_partie == 1){
    printf("\nLe joueur %i a gagné la partie\n",num_joueur);
    return num_joueur;
  }

  tri_choix = choix_tri(joueur);
  if(tri_choix == 2)
    affiche_chevalet(joueur,N_CHEV);
  else if(tri_choix == 1){
    do{
      printf("CHOIX : CONTINUER TRI MANUEL(1) OU ARRETER(0) ? ");
      scanf("%i",&tri_choix);
      if(tri_choix == 1)
        tri_manuel(joueur);
    } while(tri_choix == 1);
  }


  printf("FIN DE TOUR\n");
  if(!sdl){
    pause = getchar();
    while(getchar() != '\n');
    system("clear");
  }else{
    sleep(2);
  }

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
  t_tuile ** joueur;
  if(num_joueur == 1){
    joueur = joueur1;
  }
  if(num_joueur == 2){
    joueur = joueur2;
  }
  if(num_joueur == 3){
    joueur = joueur3;
  }
  if(num_joueur == 4){
    joueur = joueur4;
  }


  /* Determine le joueur qui va débuter la partie en premier */
    premier_tour_partie(joueur,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
    affiche_chevalet(joueur,N_CHEV);
    issue_partie = tour_1_joueur(joueur1,joueur2,joueur3,joueur4,pile_J1,pile_J2,pile_J3,pile_J4,J1_p1,J2_p2,J3_p3,J4_p4,okey,1);
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
  t_tuile ** joueur;
  t_pile * pile;
  t_tuile ** J_p;
  t_pile * order[4] = {pile_J3,pile_J2,pile_J4,pile_J1};
  if(num_joueur == 1){
    joueur = joueur1;
    pile = pile_J1;
    J_p = J1_p1;
  }
  if(num_joueur == 2){
    joueur = joueur2;
    pile = pile_J2;
    order[1] = order[0];
    order[0] = order[2];
    order[2] = order[3];
    order[3] = pile;
    J_p = J2_p2;
  }
  if(num_joueur == 3){
    joueur = joueur3;
    pile = pile_J3;
    order[0] = order[3];
    order[3] = pile;
    t_pile * save = order[2];
    order[2] = order[1];
    order[1] = save;
    J_p = J3_p3;
  }
  if(num_joueur == 4){
    joueur = joueur4;
    pile = pile_J4;
    order[2] = order[0];
    order[0] = order[1];
    order[1] = order[3];
    order[3] = pile;
    J_p = J4_p4;
  }
  /* TOUR JOUEUR 1 */
    selection_tuile(jeu,joueur,J_p,order[0],order[1],order[2],order[3],okey);

    issue_partie = regle_combinaison(joueur,okey);
    if(issue_partie == 1)
      return 1;
    tri_choix = choix_tri(joueur);
    if(tri_choix == 2)
      affiche_chevalet(joueur,N_CHEV);
    else if(tri_choix == 1){
      do{
        printf("CHOIX : CONTINUER TRI MANUEL(1) OU ARRETER(0) ? ");
        scanf("%i",&tri_choix);
        if(tri_choix == 1)
          tri_manuel(joueur);
      } while(tri_choix == 1);
    }





  printf("FIN DE RANGEMENT\n");
  if(!sdl){
    pause = getchar();
    while(getchar() != '\n');
    system("clear");
  }

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
    int cpt_tour = 1;

    while(issue_partie == NO_VALUE){
    /* Si le joueur 1 à commencé la partie au tour du joueur 2,3,4 et 1 */
      for(int i=1; i<5; i++){
        if(num_joueur == i){
          int tour[4] = {num_joueur+1, num_joueur+2, num_joueur+3,num_joueur};
          for(int i=0; i<4; i++){
            if(tour[i]>4) tour[i] = tour[i] - 4;
            issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,tour[i]);

          }
          cpt_tour++;
        }
      }
  }
  return 0;
}




////
/* FONCTIONS IA */
////



/**
* \fn int nombre_combinaison_tuile(t_tuile * chevalet[N_CHEV],t_tuile * okey,int ind_tuile,int ind_dep)
* \brief Retourne vrai si la tuile appartient à une combinaison, faux sinon
* \param chevalet[N_CHEV] chevalet du joueur
* \param okey la tuile okey
* \param ind_tuile indice de la tuile
* \param ind_dep  indice de la tuile qui est remplacé par la 15 ème tuile
*/
int nombre_combinaison_tuile(t_tuile * chevalet[N_CHEV],t_tuile * okey,int ind_tuile,int ind_dep){

  int i = 0,reponse = 0;
  t_tuile * copy_chev[N_CHEV];

  creer_chevalet(copy_chev,N_CHEV);

  for(i = 0; i < N_CHEV; i++){
    if(chevalet[i]->nbr == 13){
      copy_chev[i]->nbr = chevalet[i]->nbr;
      copy_chev[i]->clr = chevalet[i]->clr;
      valeur_okey(okey,copy_chev[i]);
    }
    else{
    copy_chev[i]->nbr = chevalet[i]->nbr; // Copie les tuiles de paramètre du chevalet d'entrée
    copy_chev[i]->clr = chevalet[i]->clr;
    }
  }

  if(ind_dep != N_CHEV-1){
    copy_chev[ind_dep]->nbr = copy_chev[N_CHEV-1]->nbr;
    copy_chev[ind_dep]->clr = copy_chev[N_CHEV-1]->clr;
  }
  regle_coul(copy_chev);         // Vérification des combinaisons des 14 tuiles d'un chevalet
  regle_suite(copy_chev);

  if(ind_tuile != N_CHEV-1){           // Si la tuile est différente de la 15 ème tuile
    if(copy_chev[ind_tuile]->nbr == V_DEL)
      reponse = 1;
  }
  else{                                // Si la tuile est la 15 ème tuile
    if(copy_chev[ind_dep]->nbr == V_DEL)
      reponse = 1;
  }

  detruire_tuile(copy_chev,N_CHEV);      // Détruit la copie du chevalet

  return reponse;
}
/**
* \fn int IA_retire_tuile(t_tuile * chevalet[N_CHEV],t_tuile * okey)
* \brief L'IA retire une tuile de son chevalet
* \param chevalet[N_CHEV] Chevalet du joueur
* \param okey la tuile okey
*/
int IA_retire_tuile(t_tuile * chevalet[N_CHEV],t_tuile * okey){

  int i,j,choix_tuile,nbr_min,nbr_max,cpt_combi_chev[N_CHEV] = {0};

  for(i = 0; i < N_CHEV; i++)                               // Permet d'incrémenter les compteurs si la tuile d'indice i est dans une combinaison
    for(j = 0; j < N_CHEV; j++)
      if(i != j)
        if(nombre_combinaison_tuile(chevalet,okey,i,j) == 1)
          cpt_combi_chev[i]++;

  nbr_min = cpt_combi_chev[0];                              // Permet de donner le nombre minimum et maximum
  nbr_max = cpt_combi_chev[0];
  for(i = 0; i < N_CHEV; i++){
    if(nbr_min > cpt_combi_chev[i])
      nbr_min = cpt_combi_chev[i];
    if(nbr_max < cpt_combi_chev[i])
        nbr_max = cpt_combi_chev[i];
  }

  for(i = 0; i < N_CHEV; i++)                              // Donne l'indice d'une tuile où le compteur est à son maximum
    if(cpt_combi_chev[i] == nbr_max)
      choix_tuile = i;

/*
  printf("Nbr min %i\n",nbr_min);                          // Vérifie si les compteurs, le nombre minimum et maximum
  printf("Nbr max %i\n",nbr_max);
  for(i = 0; i < N_CHEV; i++)
    printf("%i--%i\n",i,cpt_combi_chev[i]);
*/
  if(nbr_max != 0)
    while(cpt_combi_chev[choix_tuile] != nbr_min)          // Prend une tuile restant au hasard dont le compteur est au nombre minimum
      choix_tuile = rand() % N_CHEV;
  else
    choix_tuile = rand() % N_CHEV;                         // Prend une tuile au hasard parmi les 15 tuiles

  return choix_tuile;
}

/**
* \fn int IA_ajout_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * okey,t_pile * pile_tuile)
* \brief L'IA ajout une tuile à son chevalet soit en piochant ou soit en prenant la tuile de sa pile de gauche
* \param jeu[N_T] Jeu de tuile
* \param chevalet[N_CHEV] Chevalet du joueur
* \param okey la tuile okey
* \param pile_tuile la pile de gauche du joueur
*/
int IA_ajout_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * okey,t_pile * pile_tuile){

  int i,j,reponse = 1,cpt_combi_chev[N_CHEV] = {0};

  t_tuile * copy_chev[N_CHEV],* tuile_sommet;

  if(pile_vide(pile_tuile))                                   // Si la pile est vide, on pioche
    *chevalet[14] = distribution_pioche(jeu);
  else{                                                       // Sinon on vérifie que la tuile du sommet de la pile appartient à des combinaisons
    creer_chevalet(copy_chev,N_CHEV);
    sommet_pile(pile_tuile,&tuile_sommet);
    chevalet[14]->nbr = tuile_sommet->nbr;
    chevalet[14]->clr = tuile_sommet->clr;
    for(i = 0; i < N_CHEV; i++)                               // Permet d'incrémenter les compteurs si la tuile d'indice i est dans une combinaison
      for(j = 0; j < N_CHEV; j++)
        if(i != j)
          if(nombre_combinaison_tuile(chevalet,okey,i,j) == 1)
            cpt_combi_chev[i]++;
    /*
    for(i = 0; i < N_CHEV; i++)
      printf("%i--%i\n",i+1,cpt_combi_chev[i]);
    */
    if(cpt_combi_chev[N_CHEV-1] > 0){                         // Si le sommet de la pile comporte plusieurs combinaisons alors on le prend
      chevalet[14]->nbr = tuile_sommet->nbr;
      chevalet[14]->clr = tuile_sommet->clr;
      depiler(pile_tuile);
      reponse = 0;
    }
    else                                                      // Sinon, on pioche
      *chevalet[14] = distribution_pioche(jeu);
    detruire_tuile(copy_chev,N_CHEV);                         // Détruit la copie du chevalet
  }
  return reponse;
}

/**
* \fn int tour_1_IA(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur)
* \brief Réalise le premier tour d'une IA
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
int tour_1_IA(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur){

  /* Détermine la tuile à enlever pour le joueur qui commence la partie en premier */
  int num_tuile_dep;

  /* Test si le chevalet du joueur est gagnant ou non */
  int issue_partie = 0;
  t_tuile ** joueur;
  t_pile * pile;
  t_tuile ** J_p;
  t_pile * order[4] = {pile_J3,pile_J2,pile_J4,pile_J1};
  if(num_joueur == 1){
    joueur = joueur1;
    pile = pile_J1;
    J_p = J1_p1;
  }
  if(num_joueur == 2){
    joueur = joueur2;
    pile = pile_J2;
    order[1] = order[0];
    order[0] = order[2];
    order[2] = order[3];
    order[3] = pile;
    J_p = J2_p2;
  }
  if(num_joueur == 3){
    joueur = joueur3;
    pile = pile_J3;
    order[0] = order[3];
    order[3] = pile;
    t_pile * save = order[2];
    order[2] = order[1];
    order[1] = save;
    J_p = J3_p3;
  }
  if(num_joueur == 4){
    joueur = joueur4;
    pile = pile_J4;
    order[2] = order[0];
    order[0] = order[1];
    order[1] = order[3];
    order[3] = pile;
    J_p = J4_p4;
  }

    num_tuile_dep = IA_retire_tuile(joueur,okey);
    empile_enr_tuile(joueur,J_p,pile,N_CHEV,num_tuile_dep);
    issue_partie = regle_combinaison(joueur,okey);
    if(sdl == 0) sleep(3);
    printf("\n\nLe joueur %i (IA) a retiré la %i ème tuile \n\n",num_joueur,num_tuile_dep+1);
    if(sdl == 0) sleep(3);
    affiche_piles(okey,order[0],order[1],order[2],order[3]);
    affiche_chevalet_IA(joueur,N_CHEV);

  if(issue_partie == 1){
    printf("\nLe joueur %i a gagné la partie\n",num_joueur);
    return num_joueur;
  }

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
int debut_partie_IA(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur){

  /* Test si le chevalet du joueur est gagnant ou non */
  int issue_partie = 0;

  /* DEBUT DE PARTIE */
  printf("\n\nTour 1\n");
  t_tuile ** joueur;
  if(num_joueur == 1){
    joueur = joueur1;
  }else if(num_joueur == 2){
    joueur = joueur2;
  }else if(num_joueur == 3){
    joueur = joueur3;
  }else if(num_joueur == 4){
    joueur = joueur4;
  }
  /* Determine le joueur qui va débuter la partie en premier */
  if(num_joueur == 1){
    premier_tour_partie(joueur,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
    affiche_chevalet(joueur,N_CHEV);
    issue_partie = tour_1_joueur(joueur1,joueur2,joueur3,joueur4,pile_J1,pile_J2,pile_J3,pile_J4,J1_p1,J2_p2,J3_p3,J4_p4,okey,num_joueur);
  }else{
    premier_tour_partie(joueur,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
    affiche_chevalet_IA(joueur,N_CHEV);
    issue_partie = tour_1_IA(joueur1,joueur2,joueur3,joueur4,pile_J1,pile_J2,pile_J3,pile_J4,J1_p1,J2_p2,J3_p3,J4_p4,okey,num_joueur);
  }
  if(sdl == 0) sleep(2);
  printf("FIN DU TOUR 1\n");
  if(sdl == 0) sleep(6);
  system("clear");
  return issue_partie;
}

/**
* \fn int tour_IA(t_tuile * jeu[N_T],t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int cpt_tour,int num_joueur)
* \brief Permet de réaliser le tour d'une IA
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
int tour_IA(t_tuile * jeu[N_T],t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int cpt_tour,int num_joueur){

  int num_tuile_dep,choix_ia,issue_partie = NO_VALUE;

  //printf("\n\nLe joueur %i (IA) joue tour %i\n\n",num_joueur,cpt_tour);

  if(pioche_vide(jeu) == 1)
    return 0;
  printf("\nJoueur IA %i - Tour %i\n",num_joueur,cpt_tour);

  /* TOUR JOUEUR 1 */
  if(num_joueur == 1){
    tri_rapide(joueur1,0,13);
    affiche_piles(okey,pile_J3,pile_J2,pile_J4,pile_J1);
    affiche_chevalet_IA(joueur1,N_CHEV);
    printf("\n\nLe joueur %i (IA) joue le tour %i .\n\n",num_joueur,cpt_tour);
    if(sdl == 0) sleep(2);
    system("clear");
    printf("\nJoueur IA %i - Tour %i\n",num_joueur,cpt_tour);
    affiche_piles(okey,pile_J3,pile_J2,pile_J4,pile_J1);
    affiche_chevalet_IA(joueur1,N_CHEV);
    printf("\n\nLe joueur %i (IA) joue le tour %i ..\n\n",num_joueur,cpt_tour);
    if(sdl == 0) sleep(2);
    system("clear");
    printf("\nJoueur IA %i - Tour %i\n",num_joueur,cpt_tour);
    affiche_piles(okey,pile_J3,pile_J2,pile_J4,pile_J1);
    affiche_chevalet_IA(joueur1,N_CHEV);
    printf("\n\nLe joueur %i (IA) joue le tour %i ...\n\n",num_joueur,cpt_tour);
    if(sdl == 0) sleep(2);
    choix_ia = IA_ajout_tuile(jeu,joueur1,okey,pile_J4);
    choix_ia == 1 ? printf("\n\nLe joueur %i (IA) a pioché \n\n",num_joueur):printf("\n\nLe joueur %i (IA) a pris la tuile de la pile du Joueur 4 (IA)\n\n",num_joueur);
    affiche_piles(okey,pile_J3,pile_J2,pile_J4,pile_J1);
    affiche_chevalet_IA(joueur1,N_CHEV);
    if(sdl == 0) sleep(4);
    num_tuile_dep = IA_retire_tuile(joueur1,okey);
    empile_enr_tuile(joueur1,J1_p1,pile_J1,N_CHEV,num_tuile_dep);
    affiche_piles(okey,pile_J3,pile_J2,pile_J4,pile_J1);
    affiche_chevalet_IA(joueur1,N_CHEV);
    printf("\n\nLe joueur %i (IA) a retiré la %i ème tuile \n\n",num_joueur,num_tuile_dep+1);
    issue_partie = regle_combinaison(joueur1,okey);
    if(issue_partie == 1)
      return 1;
  }
  /* TOUR JOUEUR 2 */
  else if(num_joueur == 2){
    tri_rapide(joueur2,0,13);
    affiche_piles(okey,pile_J4,pile_J3,pile_J1,pile_J2);
    affiche_chevalet_IA(joueur2,N_CHEV);
    printf("\n\nLe joueur %i (IA) joue le tour %i .\n\n",num_joueur,cpt_tour);
    if(sdl == 0) sleep(2);
    system("clear");
    printf("\nJoueur IA %i - Tour %i\n",num_joueur,cpt_tour);
    affiche_piles(okey,pile_J4,pile_J3,pile_J1,pile_J2);
    affiche_chevalet_IA(joueur2,N_CHEV);
    printf("\n\nLe joueur %i (IA) joue le tour %i ..\n\n",num_joueur,cpt_tour);
    if(sdl == 0) sleep(2);
    system("clear");
    printf("\nJoueur IA %i - Tour %i\n",num_joueur,cpt_tour);
    affiche_piles(okey,pile_J4,pile_J3,pile_J1,pile_J2);
    affiche_chevalet_IA(joueur2,N_CHEV);
    printf("\n\nLe joueur %i (IA) joue le tour %i ...\n\n",num_joueur,cpt_tour);
    if(sdl == 0) sleep(2);
    choix_ia = IA_ajout_tuile(jeu,joueur2,okey,pile_J1);
    choix_ia == 1 ? printf("\n\nLe joueur %i (IA) a pioché \n\n",num_joueur):printf("\n\nLe joueur %i (IA) a pris la tuile de la pile du Joueur 1 (IA)\n\n",num_joueur);
    affiche_piles(okey,pile_J4,pile_J3,pile_J1,pile_J2);
    affiche_chevalet_IA(joueur2,N_CHEV);
    if(sdl == 0) sleep(4);
    num_tuile_dep = IA_retire_tuile(joueur2,okey);
    empile_enr_tuile(joueur2,J2_p2,pile_J2,N_CHEV,num_tuile_dep);
    affiche_piles(okey,pile_J4,pile_J3,pile_J1,pile_J2);
    affiche_chevalet_IA(joueur2,N_CHEV);
    printf("\n\nLe joueur %i (IA) a retiré la %i ème tuile \n\n",num_joueur,num_tuile_dep+1);
    issue_partie = regle_combinaison(joueur2,okey);
    if(issue_partie == 1)
      return 2;
  }
  /* TOUR JOUEUR 3 */
  else if(num_joueur == 3){
    tri_rapide(joueur3,0,13);
    affiche_piles(okey,pile_J1,pile_J4,pile_J2,pile_J3);
    affiche_chevalet_IA(joueur3,N_CHEV);
    printf("\n\nLe joueur %i (IA) joue le tour %i .\n\n",num_joueur,cpt_tour);
    if(sdl == 0) sleep(2);
    system("clear");
    printf("\nJoueur IA %i - Tour %i\n",num_joueur,cpt_tour);
    affiche_piles(okey,pile_J1,pile_J4,pile_J2,pile_J3);
    affiche_chevalet_IA(joueur3,N_CHEV);
    printf("\n\nLe joueur %i (IA) joue le tour %i ..\n\n",num_joueur,cpt_tour);
    if(sdl == 0) sleep(2);
    system("clear");
    printf("\nJoueur IA %i - Tour %i\n",num_joueur,cpt_tour);
    affiche_piles(okey,pile_J1,pile_J4,pile_J2,pile_J3);
    affiche_chevalet_IA(joueur3,N_CHEV);
    printf("\n\nLe joueur %i (IA) joue le tour %i ...\n\n",num_joueur,cpt_tour);
    if(sdl == 0) sleep(2);
    choix_ia = IA_ajout_tuile(jeu,joueur3,okey,pile_J2);
    choix_ia == 1 ? printf("\n\nLe joueur %i (IA) a pioché \n\n",num_joueur):printf("\n\nLe joueur %i (IA) a pris la tuile de la pile du Joueur 2 (IA)\n\n",num_joueur);
    affiche_piles(okey,pile_J1,pile_J4,pile_J2,pile_J3);
    affiche_chevalet_IA(joueur3,N_CHEV);
    if(sdl == 0) sleep(4);
    num_tuile_dep = IA_retire_tuile(joueur3,okey);
    empile_enr_tuile(joueur3,J3_p3,pile_J3,N_CHEV,num_tuile_dep);
    affiche_piles(okey,pile_J1,pile_J4,pile_J2,pile_J3);
    affiche_chevalet_IA(joueur3,N_CHEV);
    printf("\n\nLe joueur %i (IA) a retiré la %i ème tuile \n\n",num_joueur,num_tuile_dep+1);
    issue_partie = regle_combinaison(joueur3,okey);
    if(issue_partie == 1)
      return 3;
  }
  /* TOUR JOUEUR 4 */
  else if(num_joueur == 4){
    tri_rapide(joueur4,0,13);
    affiche_piles(okey,pile_J2,pile_J1,pile_J3,pile_J4);
    affiche_chevalet_IA(joueur4,N_CHEV);
    printf("\n\nLe joueur %i (IA) joue le tour %i .\n\n",num_joueur,cpt_tour);
    if(sdl == 0) sleep(2);
    system("clear");
    printf("\nJoueur IA %i - Tour %i\n",num_joueur,cpt_tour);
    affiche_piles(okey,pile_J2,pile_J1,pile_J3,pile_J4);
    affiche_chevalet_IA(joueur4,N_CHEV);
    printf("\n\nLe joueur %i (IA) joue le tour %i ..\n\n",num_joueur,cpt_tour);
    if(sdl == 0) sleep(2);
    system("clear");
    printf("\nJoueur IA %i - Tour %i\n",num_joueur,cpt_tour);
    affiche_piles(okey,pile_J2,pile_J1,pile_J3,pile_J4);
    affiche_chevalet_IA(joueur4,N_CHEV);
    printf("\n\nLe joueur %i (IA) joue le tour %i ...\n\n",num_joueur,cpt_tour);
    if(sdl == 0) sleep(2);
    choix_ia = IA_ajout_tuile(jeu,joueur4,okey,pile_J3);
    choix_ia == 1 ? printf("\n\nLe joueur %i (IA) a pioché \n\n",num_joueur):printf("\n\nLe joueur %i (IA) a pris la tuile de la pile du Joueur 3 (IA)\n\n",num_joueur);
    affiche_piles(okey,pile_J2,pile_J1,pile_J3,pile_J4);
    affiche_chevalet_IA(joueur4,N_CHEV);
    if(sdl == 0) sleep(4);
    num_tuile_dep = IA_retire_tuile(joueur4,okey);
    empile_enr_tuile(joueur4,J4_p4,pile_J4,N_CHEV,num_tuile_dep);
    affiche_piles(okey,pile_J2,pile_J1,pile_J3,pile_J4);
    affiche_chevalet_IA(joueur4,N_CHEV);
    printf("\n\nLe joueur %i (IA) a retiré la %i ème tuile \n\n",num_joueur,num_tuile_dep+1);
    issue_partie = regle_combinaison(joueur4,okey);
    if(issue_partie == 1)
      return 4;
  }
  cpt_tour++;
  if(sdl == 0) sleep(2);
  printf("FIN DU TOUR %i\n",cpt_tour);
  if(sdl == 0) sleep(6);
  system("clear");
  return NO_VALUE;
}

/**
* \fn int partie_en_cours_IA(t_tuile * jeu[N_T], t_tuile * joueur1[N_CHEV], t_tuile * joueur2[N_CHEV], t_tuile * joueur3[N_CHEV], t_tuile * joueur4[N_CHEV], t_tuile * J1_p1[], t_tuile * J2_p2[], t_tuile * J3_p3[], t_tuile * J4_p4[], t_pile * pile_J1, t_pile * pile_J2, t_pile * pile_J3, t_pile * pile_J4, t_tuile * okey, int num_joueur)
* \brief Permet le déroulement de la partie, après que la première IA désigné commence
* \param jeu
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
int partie_en_cours_IA(t_tuile * jeu[N_T],t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int num_joueur){

    int issue_partie = NO_VALUE;               // Test si le chevalet du joueur est gagnant ou non
    int cpt_tour = 2;

    while(issue_partie == NO_VALUE){
    /* Si le joueur 1 à commencé la partie au tour du joueur 2,3,4 et 1 */
    if(num_joueur == 1){
      /* TOUR JOUEUR 2 */
      issue_partie = tour_IA(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,2);

      /* TOUR JOUEUR 3 */
      issue_partie = tour_IA(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,3);

      /* TOUR JOUEUR 4 */
      issue_partie = tour_IA(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,4);

      /* TOUR JOUEUR 1 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,1);

    }

    /* Si le joueur 2 à commencé la partie au tour du joueur 3,4,1 et 2 */
    else if(num_joueur == 2){
      /* TOUR JOUEUR 3 */
      issue_partie = tour_IA(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,3);

      /* TOUR JOUEUR 4 */
      issue_partie = tour_IA(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,4);

      /* TOUR JOUEUR 1 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,1);

      /* TOUR JOUEUR 2 */
      issue_partie = tour_IA(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,2);

    }

    /* Si le joueur 3 à commencé la partie au tour du joueur 4,1,2 et 3 */
    else if(num_joueur == 3){
      /* TOUR JOUEUR 4 */
      issue_partie = tour_IA(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,4);

      /* TOUR JOUEUR 1 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,1);

      /* TOUR JOUEUR 2 */
      issue_partie = tour_IA(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,2);

      /* TOUR JOUEUR 3 */
      issue_partie = tour_IA(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,3);

    }

    /* Si le joueur 4 à commencé la partie au tour du joueur 1,2,3 et 4 */
    else if(num_joueur == 4){
      /* TOUR JOUEUR 1 */
      issue_partie = tour_joueur(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,1);

      /* TOUR JOUEUR 2 */
      issue_partie = tour_IA(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,2);

      /* TOUR JOUEUR 3 */
      issue_partie = tour_IA(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,3);

      /* TOUR JOUEUR 4 */
      issue_partie = tour_IA(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,cpt_tour,4);

    }
    cpt_tour++;
  }
  return 0;
}
