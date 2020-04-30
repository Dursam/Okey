/**
* \file affichage_tuile.c
* \brief Fichier contenant les fonctions d'affichages
* \author Samuel DURAN Girod Valentin
* \version 1.0
* \date 12 avril 2020
*/

#include <affichage.h>
#include <fonctions_affichage.h>
#include <ncurses.h>
#include <math.h>
#include <unistd.h>


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

void menuServeur(char*ip){

	wclear(fenetre);
	initscr(); // initialize Ncurses
	box( fenetre, 0, 0 ); //initialisation des bordures
	//affichage des boutons
	mvwprintw( fenetre, 12, 10, "ip: %s        ", ip);
	wrefresh( fenetre ); //mise à jour de l'écran
	noecho(); //désactivation de l'écho des caratères
	keypad( fenetre, TRUE ); //on autorise à taper des trucs
	curs_set( 0 ); //on cache le curseur du terminal
  mvwscanw(fenetre, 13, 27, " %s\n", ip);
}

int afficher_menu(char list[][30], int taille){
	int ch, i = 0;
  //int width = 30;
  wclear(fenetre);
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
													running = ( running<0 ) ? taille-1 : running;
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

/**
* \fn void permuter(t_tuile * tab[N_CHEV], int i, int j)
* \brief Permute les indices de tuiles d'un chevalet
* \param chev[N_CHEV] Chevalet
* \param i Premier indice à permuter
* \param j Deuxième indice à permuter
*/
static
void permuter(t_tuile * chev[N_CHEV], int i, int j){

  t_tuile * sav = chev[i];
  chev[i] = chev[j];
  chev[j] = sav;
}

/**
* \fn int partition(t_tuile * chev[N_CHEV], int deb, int fin, int pivot)
* \brief Echange les tuiles d'un chevalet utile pour les fonctions de tri
* \param chev[N_CHEV] Chevalet
* \param deb Début du tri
* \param fin Fin du tri
* \param pivot Valeur pivot
* \return Nouvel indice de tuile
*/
int partition(t_tuile * chev[N_CHEV], int deb, int fin, int pivot){

    int j = deb;
    for(int i=deb+1; i<=fin; i++){
      if(chev[i]->nbr<pivot){
        j++;
        permuter(chev, j, i);
      }
    }
    permuter(chev,j,deb);
    return (j);
}

/**
* \fn void tri_manuel(t_tuile * chevalet[N_CHEV])
* \brief Tri manuel d'un chevalet de tuiles
* \param chevalet[N_CHEV] Chevalet
*/
void tri_manuel(t_tuile * chevalet[N_CHEV]){

    int i=-1, j=-1;

    printf("Quelles tuiles voulez-vous échanger?\n\nLa première Tuile : ");

    while(i == -1 || (i<0 && i>N_CHEV-1))
      scanf("%d", &i);

    printf("La deuxième Tuile : ");

    while(j == -1 || (j<0 && j>N_CHEV-1))
      scanf("%d",&j);

    permuter(chevalet, i-1, j-1);

    affiche_chevalet(chevalet, N_CHEV);

    printf("\n\n");
}

/**
* \fn void tri_rapide(t_tuile * chevalet[], int i, int j)
* \brief Tri rapide d'un chevalet de tuiles
* \param chevalet Chevalet du jeu
* \param i Première valeur
* \param j Deuxième valeur
*/
void tri_rapide(t_tuile * chevalet[], int i, int j) {

    int k;

    if (i < j) {
        k = partition(chevalet, i, j, chevalet[i]->nbr);
        tri_rapide(chevalet, i, k);
        tri_rapide(chevalet, k+1, j);
    }
}

/**
* \fn int choix_tri(t_tuile * chevalet[N_CHEV])
* \brief Laisse le choix au joueur de pouvoir faire un tri rapide, un tri manuel ou un pas de tri
* \param chevalet[N_CHEV] Chevalet du joueur
*/
int choix_tri(t_tuile * chevalet[N_CHEV]){

  int * choix = malloc(sizeof(int)),res;

  do{
  printf("CHOIX : TRI RAPIDE(2) OU TRI MANUEL(1) OU ANNULER(0) ? ");
  scanf("%i",choix);
  }while(*choix != 0 && *choix != 1 && *choix != 2);

  if(*choix == 2){
    tri_rapide(chevalet,0,13);
    res = 2;
  }

  else if(*choix == 1){
    tri_manuel(chevalet);
    res = 1;
  }

  else if(*choix == 0)
    res = 0;

  free(choix);

  return res;
}

/**
* \fn void affiche_chevalet(t_tuile * jeu[], int taille)
* \brief Affichage des 14/15 tuiles du chevalet
* \param jeu[] Chevalet
* \param taille Taille du chevalet
*/
void affiche_chevalet(t_tuile * jeu[],int taille){

  int i;

  printf("\033[1;32m\t\b\t1\t2\t3\t4\t5\t6\t7\t\033[00m");
  printf("\n\t------------------------------------------------------\n");

  for(i = 0;i < taille;i++){

    if(i == 0)
      printf("\t|");
    if(i == 14 && jeu[14]->nbr != V_DEL)
      printf("--------------->");

    if(jeu[i]->nbr == V_DEL)                // Cas d'affichage où la tuile a été supprimée
      printf("\t");
    else{
      if(jeu[i]->nbr==13){                  // Cas d'affichage pour tuiles okey rouge et noire
          if(jeu[i]->clr==noire)
            printf("OK\033[34;40m__\033[00m\t");
          else if(jeu[i]->clr==rouge)
            printf("OK\033[34;41m__\033[00m\t");
      }
      else{                                 // Cas d'affichage des tuiles de 1 à 13 des 4 couleurs différentes
        if(jeu[i]->nbr < 9){
          printf("%i ",(jeu[i]->nbr)+1);
          switch (jeu[i]->clr){
            case jaune: printf("\033[34;43m__\033[00m\t");break;
            case rouge: printf("\033[34;41m__\033[00m\t");break;
            case noire: printf("\033[34;40m__\033[00m\t");break;
            case bleu:  printf("\033[34;44m__\033[00m\t");break;
          }
        }
        else{                                // Cas d'affichage pour éviter d'espacer les nombres à 2 chiffres
          printf("%i",(jeu[i]->nbr)+1);
          switch (jeu[i]->clr){
            case jaune: printf("\033[34;43m__\033[00m\t");break;
            case rouge: printf("\033[34;41m__\033[00m\t");break;
            case noire: printf("\033[34;40m__\033[00m\t");break;
            case bleu:  printf("\033[34;44m__\033[00m\t");break;
          }
        }
      }
      if(i == 6)
        printf("\b\b\b|");
      if(i == 13)
        printf("\b\b\b|");
    }
    if(i == 6 && jeu[14]->nbr == V_DEL)
      printf("\n\t|\t\t\t\t\t\t\t\b\b\b|\n\t|");
    else if(i == 6 && jeu[14]->nbr != V_DEL)
      printf("\n\t|\t\t\t\t\t\t\t\b\b\b| NOUVELLE TUILE \033[1;32m15\033[00m\n\t|");
  }
  printf("\n\t------------------------------------------------------\n");
  printf("\033[1;32m\t\b\t8\t9\t10\t11\t12\t13\t14\n\033[00m");
}

/**
* \fn void affiche_sommet_pile(t_pile * pile)
* \brief ffichage du sommet d'une pile
* \param pile Pile à afficher
*/
void affiche_sommet_pile(t_pile * pile){

  t_tuile * tuile;

  if(pile_vide(pile))
    printf("* \033[34;47m__\033[00m\t");
  else{
    sommet_pile(pile,&tuile);

    if(tuile->nbr < 9){
      printf("%i ",(tuile->nbr)+1);
      switch (tuile->clr){
        case jaune: printf("\033[34;43m__\033[00m\t");break;
        case rouge: printf("\033[34;41m__\033[00m\t");break;
        case noire: printf("\033[34;40m__\033[00m\t");break;
        case bleu:  printf("\033[34;44m__\033[00m\t");break;
      }
    }
    else{
      printf("%i",(tuile->nbr)+1);
      switch (tuile->clr){
        case jaune: printf("\033[34;43m__\033[00m\t");break;
        case rouge: printf("\033[34;41m__\033[00m\t");break;
        case noire: printf("\033[34;40m__\033[00m\t");break;
        case bleu:  printf("\033[34;44m__\033[00m\t");break;
      }
    }
  }
}

/**
* \fn void affiche_piles(t_tuile * okey, t_pile * pfg, t_pile * pfd, t_pile * pg, t_pile * pd)
* \brief Affichage du sommet des piles de tout les joueurs, valeur du okey et une pioche
* \param okey la tuile okey
* \param okey la tuile okey
* \param pfg pile fond gauche
* \param pfd pile fond droite
* \param pg pile gauche
* \param pd pile droite
*/
void affiche_piles(t_tuile * okey, t_pile * pfg, t_pile * pfd, t_pile * pg, t_pile * pd){

  printf("\n\t");
  affiche_sommet_pile(pfg);
  printf("\t\t\t\t\t");
  affiche_sommet_pile(pfd);

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
  affiche_sommet_pile(pg);
  printf("\t\t\t\t\t");
  affiche_sommet_pile(pd);
  printf("\n\n");

}
