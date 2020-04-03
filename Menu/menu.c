
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
#include <affichage.h>
#include <fonctions_affichage.h>
#include <jeu.h>

/**
 * \fn void showMenu()
 * \brief Gestion et affichage du menu principal
 */
void showMenu(){
	//fond_blanc();
	int running; //la variable qui gère le choix du menu
	char list[4][30] = { "Nouvelle partie", "Rejoindre une partie","Charger scores", "Quitter" };
	running = afficher_menu(list);
	if(running==0){
		nouvellePartie();

	}
	if(running==1){
		rejoindrePartie();
	}
	if(running==3){
		//delete_player(&Personnage);
		quitter_affichage();
	}
	quitter_affichage();
}
