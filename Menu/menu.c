/**
 * \file menu.c
 * \brief Menu principal du jeu
 * \author Duran Samuel Girod Valentin
 * \date 12 mars 2019
 */

#include <menu.h>


/**
* \fn int mode_4_joueurs(void)
* \brief Lance le mode de jeu avec 4 joueurs en local
*/
int mode_local_4_joueurs(void){

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

	/* Situation extrêment rare: si le joueur gagne dès le premier tour */
	if(issue_partie_tour_1 != 0){
		issue_partie(issue_partie_tour_1);
		return issue_partie_tour_1;
	}

	/* Déroulement de la partie */
	joueur_gagnant = partie_en_cours(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);

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

	return joueur_gagnant;
}

/**
* \fn int mode_local_1_joueurs_3_IA(void)
* \brief Lance le mode de jeu avec 1 joueur et 3 IA en local
*/
int mode_local_1_joueurs_3_IA(void){
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
	issue_partie_tour_1 = debut_partie_IA(joueur1,joueur2,joueur3,joueur4,pile_J1,pile_J2,pile_J3,pile_J4,J1_p1,J2_p2,J3_p3,J4_p4,okey,num_joueur);

	/* Situation extrêment rare: si le joueur gagne dès le premier tour */
	if(issue_partie_tour_1 != 0){
		issue_partie(issue_partie_tour_1);
		return issue_partie_tour_1;
	}

	/* Déroulement de la partie */
	joueur_gagnant = partie_en_cours_IA(jeu,joueur1,joueur2,joueur3,joueur4,J1_p1,J2_p2,J3_p3,J4_p4,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);

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

	return joueur_gagnant;
}

/**
 * \fn int showMenu(void)
 * \brief Gestion et affichage du menu principal
 */
int showMenu(void){

	int running, 				 // Gère le choix du menu
	num_partie,					 // Récupère le numéro de partie d'une sauvegarde
	num_joueur;					 // Le numéro du joueur de 1 à 4, 0 si pas de gagnant
	t_fichier * fichier; // Fichier qui gère la sauvegarde et les scores

	char list0[][30] = {"Nouvelle Partie","Charger Partie","Règle du jeu","Quitter"};
	running = afficher_menu(list0, 4);
	if(running==0){															// Nouvelle Partie
		fichier = nom_fichier();
		num_partie = numero_partie(fichier);
	}
	else if(running==1){											  // Charger Partie

		int nbr_max_sav;
		FILE * sauvegarde;
		system("ls Sauvegarde/ | grep '2020-' | wc -l >> data_nbr_max_sav.txt");
		sauvegarde = fopen("data_nbr_max_sav.txt","r");
		fscanf(sauvegarde,"%i",&nbr_max_sav);
		fclose(sauvegarde);
		system("rm data_nbr_max_sav.txt");
		fichier = malloc(sizeof(t_fichier));
		fichier->nom = afficher_sauvegarde(nbr_max_sav);
		charger_partie(fichier);
		num_partie = numero_partie(fichier);
	}
	else if(running ==2){											// Règle du jeu
			afficher_regle();
			if(sdl ==0){
				getchar();
				while(getchar() == '\n');
			}
			return 1;
	}
	else{																				// Quitter
		quitter_affichage();
		return 0;
	}

	num_partie++;
	char list1[][30] = {"Jouer en local","Jouer en ligne","Quitter"};
	running = afficher_menu(list1,3);
	if(running==0){															// Jouer en local
		  char list2[][30] = {"Joueur contre IA","Joueurs contre joueurs","Quitter"};
		  running = afficher_menu(list2, 3);
			if(running == 0){
				fond_blanc();										// Joueur contre IA
				if(sdl ==0){
					quitter_affichage();
				}
				num_joueur = mode_local_1_joueurs_3_IA();
				maj_sauvegarde(fichier,num_partie,num_joueur);
				afficher_scores(fichier,num_partie);
			}
			else if(running == 1){
				fond_blanc();									// Joueurs contre joueurs
				if(sdl ==0){
					quitter_affichage();
				}
				num_joueur = mode_local_4_joueurs();
				maj_sauvegarde(fichier,num_partie,num_joueur);
				afficher_scores(fichier,num_partie);
			}
			else {																	// Quitter
				//quitter_affichage();
			}
	}
	else if(running==1){											  // Jouer en ligne
		//int running =-1;
		char list3[][30] = {"2 joueurs et 2 IA","Quitter"};
		running = afficher_menu(list3, 2);

		if(running == 0){													// 2 joueurs et 2 IA
			char list4[][30] = {"Héberger une partie","Rejoindre une partie","Quitter"};
			running = afficher_menu(list4, 3);
			if(running == 0){											  // Héberger une partie
				//quitter_affichage();
			}
			else if(running == 1){									// Rejoindre une partie
				//quitter_affichage();
			}
			else {											  					// Quitter
				//quitter_affichage();
			}
		}
		else{ 																		// Quitter
			//quitter_affichage();
		}
	}

	else {																	  	// Quitter
		//quitter_affichage();
	}
	free(fichier->nom);
	free(fichier);
	quitter_affichage();
	return 0;
}
