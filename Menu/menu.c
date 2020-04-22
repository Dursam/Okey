/**
 * \file menu_principal.c
 * \brief Menu principal du jeu
 * \author Girod Valentin
 * \date 12 mars 2019
 *
 * Menu principal
 *
 */

#include <menu.h>

/**
 * \fn void showMenu()
 * \brief Gestion et affichage du menu principal
 */
void showMenu(){
	//fond_blanc();
	int running; //la variable qui gère le choix du menu
	char list[][30] = { "Jouer en local", "Jouer en ligne","Charger scores", "Quitter" };
	running = afficher_menu(list, 4);

	if(running==0){
		  char list2[][30] = { "Joueur contre IA", "Joueurs contre joueurs" };
		  running = afficher_menu(list2, 2);
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
