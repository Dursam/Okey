/* L'objectif de ce fichier est de créer une partie de Okey avec 4 joueurs */

#include <init_structure.h>
#include <init_pile.h>
#include <affichage_tuile.h>
#include <combinaison_couleur.h>
#include <combinaison_suite_entiers.h>
#include <selection_tuile.h>
#include <partie.h>


int main(void){

  /* Le jeu de 106 tuiles */
  t_tuile * jeu[N_T];
  /* Les 4 joueurs */
  t_tuile * joueur1[N_CHEV],* joueur2[N_CHEV],* joueur3[N_CHEV],* joueur4[N_CHEV];
  /* Les 4 piles */
  t_pile * pile_J1,* pile_J2,* pile_J3,* pile_J4;
  /* Les enregistrement des 4 piles nécessaires pour la fonction de séléction */
  t_tuile * J1_p1[N_CHEV],* J2_p2[N_CHEV],* J3_p3[N_CHEV],* J4_p4[N_CHEV];
  /* Une copie de chevalet */
  t_tuile * copy_chevalet[N_CHEV];
  /* La tuile OKEY */
  t_tuile * okey = creer_tuile();
  /* Détermine le numéro de joueur qui commence la partie */
  int num_joueur;
  /* Détermine la tuile à enlever pour le joueur qui commence la partie en premier */
  int num_tuile_dep;
  /* Test si le chevalet du joueur est gagnant ou non */
  int issue_partie = 0;
  /* Détermine lequel des joueurs est gagnant */
  int joueur_gagnant;
  /* Caractère pour faire une pause dans le programme */
  char pause;

  /* On initialise les joueurs et on leur donne 14 tuiles chacun avec un joueur au hasard qui démarre */
  creer_chevalet(joueur1,N_CHEV);
  creer_chevalet(joueur2,N_CHEV);
  creer_chevalet(joueur3,N_CHEV);
  creer_chevalet(joueur4,N_CHEV);

  /* On initialise la poie du chevalet */
  creer_chevalet(copy_chevalet,N_CHEV);

  /* On initialise les enregistrement pour l'empilement des tuiles sur leur piles respectives */
  init_enr_tuile(J1_p1,N_CHEV);
  init_enr_tuile(J2_p2,N_CHEV);
  init_enr_tuile(J3_p3,N_CHEV);
  init_enr_tuile(J4_p4,N_CHEV);

  /* On alloue la mémoire pour nos piles */
  pile_J1 = malloc(sizeof(t_pile));
  pile_J2 = malloc(sizeof(t_pile));
  pile_J3 = malloc(sizeof(t_pile));
  pile_J4 = malloc(sizeof(t_pile));

  /* On initialise les piles pour les joueurs */
  init_pile(pile_J1);
  init_pile(pile_J2);
  init_pile(pile_J3);
  init_pile(pile_J4);

  /* On initialise le jeu */
  init_tuile(jeu);

  /* On distribution des tuiles aux 4 joueurs */
  distribution_joueur(jeu,joueur1);
  distribution_joueur(jeu,joueur2);
  distribution_joueur(jeu,joueur3);
  distribution_joueur(jeu,joueur4);

  /* On définit le okey */
  *okey = distribution_pioche(jeu);

  /* DEBUT DE PARTIE */

  /* on démarre la partie en donnant une tuile supplémentaire à l'un des joueurs au hasard */
  num_joueur = demarrage(jeu,joueur1,joueur2,joueur3,joueur4);

  if(num_joueur == 1){
    debut_partie(joueur1,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
  }
  else if(num_joueur == 2){
    debut_partie(joueur2,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
  }
  else if(num_joueur == 3){
    debut_partie(joueur3,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
  }
  else if(num_joueur == 4){
    debut_partie(joueur4,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
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
      return 0;
    }
  }
  else if(num_joueur == 2){
    empile_enr_tuile(joueur2,J2_p2,pile_J2,N_CHEV,num_tuile_dep-1);
    affiche_chevalet(joueur2,N_CHEV);
    issue_partie = regle_combinaison(joueur2,okey);
    if(issue_partie == 1){
      printf("\nLe joueur 2 a gagné la partie\n");
      return 0;
    }
  }
  else if(num_joueur == 3){
    empile_enr_tuile(joueur3,J3_p3,pile_J3,N_CHEV,num_tuile_dep-1);
    affiche_chevalet(joueur3,N_CHEV);
    issue_partie = regle_combinaison(joueur3,okey);
    if(issue_partie == 1){
      printf("\nLe joueur 3 a gagné la partie\n");
      return 0;
    }
  }
  else if(num_joueur == 4){
    empile_enr_tuile(joueur4,J4_p4,pile_J4,N_CHEV,num_tuile_dep-1);
    affiche_chevalet(joueur4,N_CHEV);
    issue_partie = regle_combinaison(joueur4,okey);
    if(issue_partie == 1){
      printf("\nLe joueur 4 a gagné la partie\n");
      return 0;
    }
  }
  printf("FIN DE TOUR\n");
  pause = getchar();
  while(getchar() != '\n');
  system("clear");

  /* Déroulement de la partie */
  joueur_gagnant = partie_en_cours(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,num_joueur,okey);

  /* Annonce du vainqueur de la partie */
  printf("\nLe joueur %i a gagné \n\n",joueur_gagnant);

  /* Compteurs qui compte le nombre d'élément d'une pile de tuile */
  depiler_toutes_tuiles(pile_J1,pile_J2,pile_J3,pile_J4);

  /* On détruit les tuiles des piles gauche et droite */
  free(pile_J1);
  free(pile_J2);
  free(pile_J3);
  free(pile_J4);

  /* On détruit le jeu, la tuile okey, les enregistrements des piles, les chevalets et la copie d'un chevalet */
  detruire_tuile(jeu,taille_tuile(jeu,sizeof(jeu)));

  detruire_tuile(&okey,taille_tuile(&okey,sizeof(okey)));

  detruire_tuile(J1_p1,taille_tuile(J1_p1,sizeof(J1_p1)));
  detruire_tuile(J2_p2,taille_tuile(J2_p2,sizeof(J2_p2)));
  detruire_tuile(J3_p3,taille_tuile(J3_p3,sizeof(J3_p3)));
  detruire_tuile(J4_p4,taille_tuile(J4_p4,sizeof(J4_p4)));

  detruire_tuile(joueur1,taille_tuile(joueur1,sizeof(joueur1)));
  detruire_tuile(joueur2,taille_tuile(joueur2,sizeof(joueur2)));
  detruire_tuile(joueur3,taille_tuile(joueur3,sizeof(joueur3)));
  detruire_tuile(joueur4,taille_tuile(joueur4,sizeof(joueur4)));

  detruire_tuile(copy_chevalet,taille_tuile(copy_chevalet,sizeof(copy_chevalet)));

}
