<<<<<<< HEAD
/**
 * \file menu_principal.c
 * \brief Menu principal du jeu
 * \author Girod Valentin
 * \date 12 mars 2019
 *
 * Menu principal
 *
 */
#include <affichage.h>
#include <fonctions_affichage.h>

/**
 * \fn void showMenu()
 * \brief Gestion et affichage du menu principal
 */
void showMenu(){
	//fond_blanc();
	int running; //la variable qui gère le choix du menu
	char list[3][30] = { "Nouvelle partie", "Charger scores", "Quitter" };
	running = afficher_menu(list);
	if(running==0){
		//startGame( 500.0, 500.0);
	}
	if(running==1){}
	if(running==2){
		//delete_player(&Personnage);
		quitter_affichage();
	}
}
=======
#include "./menu.h"
>>>>>>> 145bdc6973453f0199ca025802b64ece446bcd0f
