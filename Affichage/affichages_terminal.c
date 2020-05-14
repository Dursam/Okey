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
#include <sys/ioctl.h>

int select_tuile(int AutoriserFinTour){
  int num_tuile_dep;
  printf("\n\nCHOIX : RETIRER UN NUMERO DE TUILE (1 à 15) ? ");
  scanf("%i",&num_tuile_dep);
  printf("\n");
  return num_tuile_dep;
}


/**
* \fn void selection_tuile(t_tuile * jeu[N_T], t_tuile * chevalet[N_CHEV], t_tuile * enr[], t_pile * pfg, t_pile * pfd, t_pile * pg, t_pile * pd,t_tuile * okey)
* \brief Permet de sélection une tuile soit de la pioche ou de la pile de gauche et retire une tuile du chevalet, version avec affiche_pile
* \param jeu[N_T] Tableau contenant les tuiles
* \param chevalet[N_CHEV] Chevalet du joueur
* \param enr[] enregistrement temporaire des tuiles d'un chevalet
* \param pfg pile fond gauche
* \param pfd pile fond droit
* \param pg  pile gauche
* \param pd  pile droite
* \param okey la tuile okey
*/
void selection_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd,t_tuile * okey){

  int numero,* choix = malloc(sizeof(int));


  t_tuile * tuile_sommet;

  affiche_piles(okey,pfg,pfd,pg,pd);
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

  affiche_piles(okey,pfg,pfd,pg,pd);
  affiche_chevalet(chevalet,N_CHEV);

  printf("CHOIX : RETIRER UN NUMERO DE TUILE (1 à 15) ? ");
  scanf("%i",&numero);

  empile_enr_tuile(chevalet,enr,pd,N_CHEV,numero-1);

  affiche_piles(okey,pfg,pfd,pg,pd);
  affiche_chevalet(chevalet,N_CHEV);

  free(choix);

  printf("FIN DE TOUR\n");
  getchar();
  while(getchar() != '\n');
}

int taille_reduction(int entier){

  int mod,res;
  double div;

  mod = entier % 2;
  res = entier;

  if(mod == 1)
    res--;

  div = res/2;
  res = div;

  return res;
}

void taille_terminal(int lon,int lar){
  struct winsize win;
  ioctl(STDOUT_FILENO, TIOCGWINSZ,&win);
  lon = win.ws_col;
  lar = win.ws_row;
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

	int ch,i = 0,lon,lar,blon,blar;
  FILE * flon,* flar;
  system("tput cols >> data_colonne.txt");
  system("tput lines >> data_ligne.txt");
  flon = fopen("data_colonne.txt","r");
  fscanf(flon,"%i",&blon);
  fclose(flon);
  flar = fopen("data_ligne.txt","r");
  fscanf(flar,"%i",&blar);
  fclose(flar);
  //printf("La longueur est de %i\n",blon);
  //printf("La largueur est de %i\n",blar);
  system("rm data_colonne.txt");
  system("rm data_ligne.txt");

  lon = taille_reduction(blon);                   // Permet de positionner les touches au centre de l'écran
  lar = taille_reduction(blar);
  //printf("%i__%i\n",lar,lon);

  wclear(fenetre);
	box( fenetre, 0, 0 ); //initialisation des bordures
	//affichage des boutons
	for( i=0; i<taille; i++ ) {
			if( i == 0 )
					wattron(fenetre, A_STANDOUT ); //on surligne le premier
			else
					wattroff(fenetre, A_STANDOUT );
			mvwprintw( fenetre,i+lar,lon, "%s", list[i] );
	}
	wrefresh( fenetre ); //mise à jour de l'écran
	int running = 0;
	noecho(); //désactivation de l'écho des caratères
	keypad( fenetre, TRUE ); //on autorise à taper des trucs
	curs_set( 0 ); //on cache le curseur du terminal

	//détection de la touche
	while(( ch = wgetch(fenetre)) != '\n'){
					mvwprintw( fenetre, running+lar,lon, "%s", list[running] );
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
					mvwprintw( fenetre, running+lar,lon, "%s", list[running]);
					wattroff( fenetre, A_STANDOUT );
	}
	return running;
}

char * afficher_sauvegarde(int max_fichier){

	char list_sav1[max_fichier][30],
  * prefixe_sav = "Sauvegarde/",
	* nom_sav = malloc(sizeof(char)*30);
	int ch,i = 0,lon,lar,blon,blar,cpt_fichier = 0;
  FILE * fichier;

	system("tput cols >> data_colonne.txt");
  fichier = fopen("data_colonne.txt","r");
  fscanf(fichier,"%i",&blon);
  fclose(fichier);
	system("rm data_colonne.txt");

	system("tput lines >> data_ligne.txt");
  fichier = fopen("data_ligne.txt","r");
  fscanf(fichier,"%i",&blar);
  fclose(fichier);
  system("rm data_ligne.txt");

	system("ls Sauvegarde/ | grep '2020-' >> data_nbr_max_sav.txt");
	fichier = fopen("data_nbr_max_sav.txt","r");
	while(!feof(fichier)){
		fscanf(fichier,"%s",list_sav1[cpt_fichier]);
		cpt_fichier++;
	}
	fclose(fichier);
	system("rm data_nbr_max_sav.txt");

	lon = taille_reduction(blon);                   // Permet de positionner les touches au centre de l'écran
  lar = taille_reduction(blar);

  wclear(fenetre);
	box(fenetre, 0, 0 ); //initialisation des bordures
	//affichage des boutons
	for( i=0; i<max_fichier; i++ ) {
			if( i == 0 )
					wattron(fenetre, A_STANDOUT ); //on surligne le premier
			else
					wattroff(fenetre, A_STANDOUT );
			mvwprintw( fenetre,i+lar,lon, "%s", list_sav1[i] );
	}
	wrefresh( fenetre ); //mise à jour de l'écran
	int running = 0;
	noecho(); //désactivation de l'écho des caratères
	keypad( fenetre, TRUE ); //on autorise à taper des trucs
	curs_set( 0 ); //on cache le curseur du terminal

	//détection de la touche
	while(( ch = wgetch(fenetre)) != '\n'){
					mvwprintw( fenetre, running+lar,lon, "%s", list_sav1[running] );
					switch( ch ) {
							case KEY_UP:
													running--;
													running = ( running<0 ) ? max_fichier-1 : running;
													break;
							case KEY_DOWN:
													running++;
													running = ( running>max_fichier-1 ) ? 0 : running;
													break;
					}
					wattron( fenetre, A_STANDOUT );
					mvwprintw( fenetre, running+lar,lon, "%s", list_sav1[running]);
					wattroff( fenetre, A_STANDOUT );
	}
  strcpy(nom_sav,prefixe_sav);
  strcat(nom_sav,list_sav1[running]);
  /*fond_blanc();
  printf("Le nom de sauvegarde est %s\n",nom_sav);
  faire_rendu();
  sleep(3);*/
	return nom_sav;
}

/**
 * \fn void afficher_regle(void)
 * \brief Affiche les règles du jeu
 */
 void afficher_regle(void){
   fond_blanc();
   printf("Voici les règles blablablabla\n");
   faire_rendu();
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
* \fn void affiche_chevalet(t_tuile * tuile)
* \brief Affichage d'une tuile
* \param tuile tuile
*/
void afficher_tuile(t_tuile * tuile){
  if(tuile->nbr==13){                  // Cas d'affichage pour tuiles okey rouge et noire
      if(tuile->clr==noire)
        printf("OK\033[34;40m__\033[00m\t");
      else if(tuile->clr==rouge)
        printf("OK\033[34;41m__\033[00m\t");
  }
  else if(tuile->nbr < 9){
    printf("%i ",(tuile->nbr)+1);
    switch (tuile->clr){
      case jaune: printf("\033[34;43m__\033[00m\t");break;
      case rouge: printf("\033[34;41m__\033[00m\t");break;
      case noire: printf("\033[34;40m__\033[00m\t");break;
      case bleu:  printf("\033[34;44m__\033[00m\t");break;
    }
  }
  else{                                // Cas d'affichage pour éviter d'espacer les nombres à 2 chiffres
    printf("%i",(tuile->nbr)+1);
    switch (tuile->clr){
      case jaune: printf("\033[34;43m__\033[00m\t");break;
      case rouge: printf("\033[34;41m__\033[00m\t");break;
      case noire: printf("\033[34;40m__\033[00m\t");break;
      case bleu:  printf("\033[34;44m__\033[00m\t");break;
    }
  }
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
    else{                               // Cas d'affichage des tuiles de 1 à 13 des 4 couleurs différentes
      afficher_tuile(jeu[i]);

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
* \param nb_pile Numéro de la pile à afficher
*/
void affiche_sommet_pile(t_pile * pile, int nb_pile){

  t_tuile * tuile;

  if(pile_vide(pile))
    printf("* \033[34;47m__\033[00m\t");
  else{
    sommet_pile(pile,&tuile);

    afficher_tuile(pile->premier->tuile);
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
  affiche_sommet_pile(pfg,1);
  printf("\t\t\t\t\t");
  affiche_sommet_pile(pfd,2);

  // Cas d'affichage pour éviter d'espacer les nombres à 2 chiffres
  printf("\n\t\t\t   OKEY\tPIOCHE\n\t\t\t   ");

  afficher_tuile(okey);

  printf("\033[34;47m__\033[00m  \033[34;47m__\033[00m\n\n\t");
  affiche_sommet_pile(pg,3);
  printf("\t\t\t\t\t");
  affiche_sommet_pile(pd,4);
  printf("\n\n");

}
/**
* \fn void affiche_chevalet_IA(t_tuile * jeu[], int taille)
* \brief Affichage des 14/15 tuiles cachés du chevalet d'une IA
* \param jeu[] Chevalet
* \param taille Taille du chevalet
*/
void affiche_chevalet_IA(t_tuile * jeu[],int taille){

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
    else{                                   // Cas d'affichage pour une tuile quelconque
        printf("* \033[34;47m__\033[00m\t");
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
