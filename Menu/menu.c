/**
 * \file menu_principal.c
 * \brief Menu principal du jeu
 * \author Duran Samuel Girod Valentin
 * \date 12 mars 2019
 *
 * Menu principal
 *
 */

#include <menu.h>

/**
* \fn void mode_4_joueurs(void)
* \brief Lance le mode de jeu avec 4 joueurs en local
*/
void mode_local_4_joueurs(void){

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
	/* Détermine lequel des joueurs est gagnant */
	int joueur_gagnant;
	/* Test si l'un des chevalets est gagnant au premier tour 1 (Situation très exceptionnel) */
	int issue_partie_tour_1;

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

	/* on démarre la partie en donnant une tuile supplémentaire à l'un des joueurs au hasard */
	num_joueur = demarrage(jeu,joueur1,joueur2,joueur3,joueur4);

	/* Déroulement du premier tour de la partie */
	issue_partie_tour_1 = debut_partie(joueur1,joueur2,joueur3,joueur4,pile_J1,pile_J2,pile_J3,pile_J4,J1_p1,J2_p2,J3_p3,J4_p4,okey,num_joueur);

	if(issue_partie_tour_1 != 0){
		issue_partie(issue_partie_tour_1);
	}

	/* Déroulement de la partie */
	joueur_gagnant = partie_en_cours(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,num_joueur,okey);

	/* Annonce de l'issue de la partie, un vainqueur ou non */
	issue_partie(joueur_gagnant);

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

/**
 * \fn void showMenu(void)
 * \brief Gestion et affichage du menu principal
 */
void showMenu(void){
	//fond_blanc();
	int running; //la variable qui gère le choix du menu
	char list[][30] = { "Jouer en local", "Jouer en ligne","Charger scores", "Quitter" };
	running = afficher_menu(list, 4);

	if(running==0){
		  char list2[][30] = { "Joueur contre IA", "Joueurs contre joueurs" };
		  running = afficher_menu(list2, 2);
			if(running == 1){
				quitter_affichage();
				mode_local_4_joueurs();
			}
	}

	else if(running==1){
		int running =-1;
		char list3[][30] = { "Héberger une partie", "Rejoindre une partie" };
		running = afficher_menu(list3, 2);

		if(running == 0){
			char list4[][30] = { "2 joueurs et 2 IA", "3 joueurs et 1 IA", "4 joeurs" };
			running = afficher_menu(list4, 1);
		}
		else{
			//rejoindre_partie
		}
		//attendreConnection(running+1);
	}

	else if(running==2){
		//delete_player(&Personnage);
		quitter_affichage();
	}
	else if(running==3){
		//delete_player(&Personnage);
		quitter_affichage();
	}
	quitter_affichage();
}
