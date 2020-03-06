/**
 * \file      affichages_terminal.c
 * \author    Girod Valentin
 * \version   1.0
 * \date     Mars 2019
 * \brief    Contient toutes les fonctions d'affichage du jeu en ncurses
 */
#include <affichage.h>
#include <fonctions_affichage.h>
#include <ncurses.h>
#include <math.h>
#include <unistd.h>


void affJeu(t_tuile * jeu[],int taille){

  printf("La taille est de %i\n",taille);

  for(int i = 0; i < taille; i++){

    if(jeu[i]->nbr==14){
        printf("\n");
    }
    else{
      printf("%i ",(jeu[i]->nbr)+1);
      switch (jeu[i]->clr){
        case jaune: printf(" JAUNE\n");break;
        case rouge: printf(" ROUGE\n");break;
        case noire: printf(" NOIRE\n");break;
        case bleu:  printf(" BLEU\n");break;
      }
    }
  }
}



void detecter_touches(int*running){
  char ch = wgetch(fenetre);
	switch( ch ) {
			case 'i':
									//showInventory();
									break;
			case 27:
									*running = 0;
                  wclear(fenetre);
									break;
  }
}



/**
 * \fn void creerPerso_terminal()
 * \brief Fonction de gestion de l'édition du personnage en terminal
 */
void afficher_creation(char*name, char*class_char, char*gender){
	int running = -1; //la variable qui gère le choix du menu
	int ch, i = 0, width = 30;
	wclear(fenetre);
	initscr(); // initialize Ncurses
	box( fenetre, 0, 0 ); //initialisation des bordures
	//affichage des boutons
	mvwprintw( fenetre, 12, 10, "ip: %s        ", name);
	wrefresh( fenetre ); //mise à jour de l'écran
	noecho(); //désactivation de l'écho des caratères
	keypad( fenetre, TRUE ); //on autorise à taper des trucs
	curs_set( 0 ); //on cache le curseur du terminal
  mvwscanw(fenetre, 13, 27, " %s\n", name);
}





int afficher_menu(char list[][30]){
  int taille = 3;
  if(0 == strcmp(list[0], "1 joueur et 3 bots")){
    taille = 4;
  }
	int ch, i = 0;
  //int width = 30;
	box( fenetre, 0, 0 ); //initialisation des bordures
	//affichage des boutons
	for( i=0; i<taille; i++ ) {
			if( i == 0 )
					wattron( fenetre, A_STANDOUT ); //on surligne le premier
			else
					wattroff( fenetre, A_STANDOUT );
			mvwprintw( fenetre, i+12, 30, "%s", list[i] );
	}
	wrefresh( fenetre ); //mise à jour de l'écran
	int running = 0;
	noecho(); //désactivation de l'écho des caratères
	keypad( fenetre, TRUE ); //on autorise à taper des trucs
	curs_set( 0 ); //on cache le curseur du terminal

	//détection de la touche
	while(( ch = wgetch(fenetre)) != '\n'){
					mvwprintw( fenetre, running+12, 30, "%s", list[running] );
					switch( ch ) {
							case KEY_UP:
													running--;
													running = ( running<0 ) ? taille : running;
													break;
							case KEY_DOWN:
													running++;
													running = ( running>taille-1 ) ? 0 : running;
													break;
					}
					wattron( fenetre, A_STANDOUT );
					mvwprintw( fenetre, running+12, 30, "%s", list[running]);
					wattroff( fenetre, A_STANDOUT );
	}
	return running;
}

void showInventory(){
  //int running = -1; //la variable qui gère le choix du menu
  /*char classe[Inventaire->nb_objects][30];
  for(int i=0; i<Inventaire->nb_objects; i++){
    strcpy(classe[i], Inventaire->object[i]->name_object);
  }*/
  //char item[30];
  int ch;
  //int width = 30;
  wclear(fenetre);
  initscr(); // initialize Ncurses
  box( fenetre, 0, 0 ); //initialisation des bordures
  //affichage des boutons
  /*for( i=0; i<Inventaire->nb_objects; i++ ) {
      if( i == 0 )
          wattron( fenetre, A_STANDOUT ); //on surligne le premier
      else
          wattroff( fenetre, A_STANDOUT );
      mvwprintw( fenetre, i+12, 30, "%s", classe[i] );
  }*/
  /*mvwprintw( fenetre, 12, 10, "Nom: %s        ", Personnage->name);
  mvwprintw( fenetre, 13, 10, "Classe: %s     ", Personnage->class_char);
  mvwprintw( fenetre, 14, 10, "Genre: %s      ", Personnage->gender);*/
  wrefresh( fenetre ); //mise à jour de l'écran


  noecho(); //désactivation de l'écho des caratères
  keypad( fenetre, TRUE ); //on autorise à taper des trucs
  curs_set( 0 ); //on cache le curseur du terminal

  //détection de la touche
  while(( ch = wgetch(fenetre)) != '\n'){
          //mvwprintw( fenetre, classe_ind+12, 30, "%s", classe[classe_ind] );
          /*switch( ch ) {
              case KEY_UP:
                          classe_ind--;
                          classe_ind = ( classe_ind<0 ) ? Inventaire->nb_objects-1 : classe_ind;
                          break;
              case KEY_DOWN:
                          classe_ind++;
                          classe_ind = ( classe_ind>Inventaire->nb_objects-1 ) ? 0 : classe_ind;
                          break;
          }*/
          wattron( fenetre, A_STANDOUT );
          //mvwprintw( fenetre, classe_ind+12, 30, "%s", classe[classe_ind]);
          wattroff( fenetre, A_STANDOUT );
          /*mvwprintw( fenetre, 12, 10, "Nom: %s        ", Personnage->name);
          mvwprintw( fenetre, 13, 10, "Classe: %s     ", Personnage->class_char);
          mvwprintw( fenetre, 14, 10, "Genre: %s      ", Personnage->gender);*/
    }
}



int detecter_mouvement(float*x, float*y){
  //l'état du clavier à l'instant actuel
  int touche = wgetch(fenetre); //en terminal
  //si c'est une touche de mouvement
  if(touche == KEY_UP || touche == KEY_DOWN || touche == KEY_LEFT || touche == KEY_RIGHT){
    //on gère les colisions et la vitesse du perso
    //on a besoin de regarder à quel endroit de la map on est et ce qu'il y a après
    //on fait cohabiter le sdl et le terminal pour un code le plus optimisé possible
    /*if (touche == KEY_RIGHT && (map[(int)(floor(*y))][(int)(floor(*x+VITESSE_PERSO))]==4 || map[(int)(floor(*y))][(int)(floor(*x+VITESSE_PERSO))]==5)) *x+=VITESSE_PERSO;
    else if (touche == KEY_LEFT && (map[(int)(floor(*y))][(int)(floor(*x-VITESSE_PERSO))]==4 || map[(int)(floor(*y))][(int)(floor(*x-VITESSE_PERSO))]==5)) *x-=VITESSE_PERSO;
    if (touche == KEY_UP && (map[(int)(floor(*y-VITESSE_PERSO))][(int)(floor(*x))]==4 || map[(int)(floor(*y-VITESSE_PERSO))][(int)(floor(*x))]==5)) *y-=VITESSE_PERSO;
    else if (touche == KEY_DOWN && (map[(int)(floor(*y+VITESSE_PERSO))][(int)(floor(*x))]==4 || map[(int)(floor(*y+VITESSE_PERSO))][(int)(floor(*x))]==5)) *y+=VITESSE_PERSO;
    */if(*x<0) *x=0;
    if(*y<0) *y=0;
    if(*x>999) *x=999;
    if(*y>999) *y=999;
    return 1;
  }
  return 0;
}
