/* Fichier contenant les fonctions principaux pour lancer une partie de Okey */

#include <init_structure.h>
#include <init_pile.h>
#include <affichage_tuile.h>
#include <combinaison_couleur.h>
#include <combinaison_suite_entiers.h>
#include <selection_tuile.h>

/* Donne une valeur + 1 de la tuile retournée (le okey) à la tuile joker rouge ou noire posséder par le joueur */
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

/* Affichage du sommet des piles de tout les joueurs */
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

/* Début de partie en fonction de la tuile de démarrage */
extern
void debut_partie(t_tuile * chevalet[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int dem){

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

/* Dépile toutes les piles de tuiles, utilisé pour finir la partie */
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

/* Vérifie si le chevalet est gagnant (return 1, 0 pour contraire) en utilisant les combinaisons de couleurs et de suite d'entier */
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

/* Laisse le choix au joueur de pouvoir faire un tri rapide, un tri manuel ou un pas de tri */
extern
void choix_tri(t_tuile * chevalet[N_CHEV]){

  //int choix;
  printf("A FAIRE\n");
}

/* Permet de sélection une tuile soit de la pioche ou de la pile de gauche et retire une tuile du chevalet, version avec affiche plateau */
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

/* Permet le déroulement de la partie, après que le première joueur commence. Retourne le numéro de joueur gagnant */
extern
int partie_en_cours(t_tuile * jeu[N_T]
                                       ,t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV]
                                       ,t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[]
                                       ,t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4
                                       ,int num_joueur
                                       ,t_tuile * okey){


    int issue_partie = 0;               // Test si le chevalet du joueur est gagnant ou non

    while(issue_partie == 0){

    if(num_joueur == 1){

      printf("\nTour joueur 2\n");
      selection_tuile_v2(jeu,joueur2,J2_p2,pile_J4,pile_J3,pile_J1,pile_J2,okey);
      issue_partie = regle_combinaison(joueur2,okey);
      if(issue_partie == 1)
        return 2;
      system("clear");

      printf("\nTour joueur 3\n");
      selection_tuile_v2(jeu,joueur3,J3_p3,pile_J1,pile_J4,pile_J2,pile_J3,okey);
      issue_partie = regle_combinaison(joueur3,okey);
      if(issue_partie == 1)
        return 3;
      system("clear");

      printf("\nTour joueur 4\n");
      selection_tuile_v2(jeu,joueur4,J4_p4,pile_J2,pile_J1,pile_J3,pile_J4,okey);
      issue_partie = regle_combinaison(joueur4,okey);
      if(issue_partie == 1)
        return 4;
      system("clear");

      printf("\nTour joueur 1\n");
      selection_tuile_v2(jeu,joueur1,J1_p1,pile_J3,pile_J2,pile_J4,pile_J1,okey);
      issue_partie = regle_combinaison(joueur1,okey);
      if(issue_partie == 1)
        return 1;
      system("clear");

    }
    else if(num_joueur == 2){

      printf("\nTour joueur 3\n");
      selection_tuile_v2(jeu,joueur3,J3_p3,pile_J1,pile_J4,pile_J2,pile_J3,okey);
      issue_partie = regle_combinaison(joueur3,okey);
      if(issue_partie == 1)
        return 3;
      system("clear");

      printf("\nTour joueur 4\n");
      selection_tuile_v2(jeu,joueur4,J4_p4,pile_J2,pile_J1,pile_J3,pile_J4,okey);
      issue_partie = regle_combinaison(joueur4,okey);
      if(issue_partie == 1)
        return 4;
      system("clear");

      printf("\nTour joueur 1\n");
      selection_tuile_v2(jeu,joueur1,J1_p1,pile_J3,pile_J2,pile_J4,pile_J1,okey);
      issue_partie = regle_combinaison(joueur1,okey);
      if(issue_partie == 1)
        return 1;
      system("clear");

      printf("\nTour joueur 2\n");
      selection_tuile_v2(jeu,joueur2,J2_p2,pile_J4,pile_J3,pile_J1,pile_J2,okey);
      issue_partie = regle_combinaison(joueur2,okey);
      if(issue_partie == 1)
        return 2;
      system("clear");

    }
    else if(num_joueur == 3){

      printf("\nTour joueur 4\n");
      selection_tuile_v2(jeu,joueur4,J4_p4,pile_J2,pile_J1,pile_J3,pile_J4,okey);
      issue_partie = regle_combinaison(joueur4,okey);
      if(issue_partie == 1)
        return 4;
      system("clear");

      printf("\nTour joueur 1\n");
      selection_tuile_v2(jeu,joueur1,J1_p1,pile_J3,pile_J2,pile_J4,pile_J1,okey);
      issue_partie = regle_combinaison(joueur1,okey);
      if(issue_partie == 1)
        return 1;
      system("clear");

      printf("\nTour joueur 2\n");
      selection_tuile_v2(jeu,joueur2,J2_p2,pile_J4,pile_J3,pile_J1,pile_J2,okey);
      issue_partie = regle_combinaison(joueur2,okey);
      if(issue_partie == 1)
        return 2;
      system("clear");

      printf("\nTour joueur 3\n");
      selection_tuile_v2(jeu,joueur3,J3_p3,pile_J1,pile_J4,pile_J2,pile_J3,okey);
      issue_partie = regle_combinaison(joueur3,okey);
      if(issue_partie == 1)
        return 3;
      system("clear");

    }
    else if(num_joueur == 4){

      printf("\nTour joueur 1\n");
      selection_tuile_v2(jeu,joueur1,J1_p1,pile_J3,pile_J2,pile_J4,pile_J1,okey);
      issue_partie = regle_combinaison(joueur1,okey);
      if(issue_partie == 1)
        return 1;
      system("clear");

      printf("\nTour joueur 2\n");
      selection_tuile_v2(jeu,joueur2,J2_p2,pile_J4,pile_J3,pile_J1,pile_J2,okey);
      issue_partie = regle_combinaison(joueur2,okey);
      if(issue_partie == 1)
        return 2;
      system("clear");

      printf("\nTour joueur 3\n");
      selection_tuile_v2(jeu,joueur3,J3_p3,pile_J1,pile_J4,pile_J2,pile_J3,okey);
      issue_partie = regle_combinaison(joueur3,okey);
      if(issue_partie == 1)
        return 3;
      system("clear");

      printf("\nTour joueur 4\n");
      selection_tuile_v2(jeu,joueur4,J4_p4,pile_J2,pile_J1,pile_J3,pile_J4,okey);
      issue_partie = regle_combinaison(joueur4,okey);
      if(issue_partie == 1)
        return 4;
      system("clear");
    }
  }
    return 0;
}
