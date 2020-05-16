/**
 * \file      affichages_sdl.c
 * \author    Samuel DURAN Valentin GIROD
 * \date     \date 30 Avril 2020
 * \brief    Contient toutes les fonctions d'affichage du jeu en sdl
 */
#include <affichage.h>
#include <fonctions_affichage.h>
#include <SDL2/SDL.h>


char * afficher_sauvegarde(int max_fichier){
	float pourcent = (SCREEN_WIDTH/100.0);
	float pourcentH = (SCREEN_HEIGHT/100.0);
	fond_blanc();
	drawText(25 * pourcent, 2*pourcentH, "Choisissez votre sauvegarde", 25, 12);

		char list_sav1[max_fichier][30],
	  * prefixe_sav = "Sauvegarde/",
		* nom_sav = malloc(sizeof(char)*30);
		int i = 0,blon,blar,cpt_fichier = 0;
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
		//affichage des boutons
		int ecart = 2*pourcent;
		int hauteur = 5*pourcentH;
		for( i=0; i<max_fichier; i++ ) {
				drawImage( ecart,hauteur, "button.png", 15*pourcent, 25 );
				drawText( ecart+6,hauteur+3, list_sav1[i], 20, 10 );
				ecart +=  16*pourcent;
				if(ecart+16*pourcent > 100*pourcent){
					ecart = 2*pourcent;
					hauteur+= 2*pourcent;
				}
		}
		faire_rendu();
			SDL_Event e;
		while(1) {
			int mouse_x, mouse_y;
			SDL_GetMouseState(&mouse_x, &mouse_y);
				if (SDL_WaitEvent(&e) != 0) {
					switch(e.type) {
						case SDL_MOUSEBUTTONDOWN:
						{
							ecart = 2*pourcent;
							hauteur = 5*pourcentH;
							for( i=0; i<max_fichier; i++ ) {
									if(mouse_x >= ecart && mouse_x <= ecart + 15*pourcent && mouse_y >= hauteur && mouse_y <= hauteur + 25){
										strcpy(nom_sav,prefixe_sav);
									  strcat(nom_sav,list_sav1[i]);
										return nom_sav;
									}
									ecart +=  16*pourcent;
									if(ecart+16*pourcent > 100*pourcent){
										ecart = 2*pourcent;
										hauteur+= 2*pourcent;
									}
							}
						}
					}
				}
		}
		sleep(10);
		return nom_sav;
}

char * tuileVersImage(t_tuile * t){
  char*tuile;
	if(t->nbr==13){                  // Cas d'affichage pour tuiles okey rouge et noire
			if(t->clr==noire)
				return "TON.png";
			else if(t->clr==rouge)
				return "TOR.png";
	}
   if(t->nbr >9){
     tuile = malloc(sizeof(char)*9);
   }else{
     tuile = malloc(sizeof(char)*8);
   }
   tuile[0] = 'T';
   switch (t->clr){
     case jaune: tuile[1] = 'J';break;
     case rouge: tuile[1] = 'R';break;
     case noire: tuile[1] = 'N';break;
     case bleu:  tuile[1] = 'B';break;
  }
  tuile[2] = '\0';
  char nb[10];
  sprintf(nb, "%d", t->nbr+1);
  strncat(tuile, nb, strlen(nb));
  strncat(tuile, ".png", 4);
  return tuile;
}

/**
* \fn void affiche_chevalet(t_tuile * jeu[], int taille)
* \brief Affichage des 14/15 tuiles du chevalet
* \param jeu[] Chevalet
* \param taille Taille du chevalet
*/
void affiche_chevalet_sans_rendu(t_tuile * jeu[],int taille){
  float pourcent = (SCREEN_WIDTH/100.0);
  float pourcentH = (SCREEN_HEIGHT/100.0);

  int i;

  int pixels = pourcent * 25;
  int hauteur = pourcentH * 66;
  drawImage( 0, 0, "chevalet.png", SCREEN_WIDTH, SCREEN_HEIGHT);
  for(i = 0;i < taille;i++){
    if (i==7){
      hauteur = pourcentH *82;
      pixels = pourcent * 25;
    }
    if(!(jeu[i]->nbr == V_DEL)){                             // Cas d'affichage des tuiles de 1 à 13 des 4 couleurs différentes
      drawImage( pixels, hauteur, tuileVersImage(jeu[i]), 60, 100);

    }
		pixels += pourcent * 7;

  }


}

int select_tuile_to_replace(char * tuileDansMains, t_tuile * chevalet[N_CHEV]){
	SDL_Event e;
	int running = -1;
  while(running==-1  || running >=N_CHEV) {
		int mouse_x, mouse_y;
		SDL_GetMouseState(&mouse_x, &mouse_y);
		affiche_chevalet_sans_rendu(chevalet, N_CHEV);
		drawImage( mouse_x - 30, mouse_y - 50, tuileDansMains, 60, 100);
		faire_rendu();
      if (SDL_WaitEvent(&e) != 0) {
        switch(e.type) {
          case SDL_MOUSEBUTTONDOWN:
          {

						float pourcent = (SCREEN_WIDTH/100.0);
					  float pourcentH = (SCREEN_HEIGHT/100.0);

					  int i;
					  int pixels = pourcent * 25;
					  int hauteur = pourcentH * 66;
					  for(i = 0;i < N_CHEV;i++){
					    if (i==7){
					      hauteur = pourcentH *82;
					      pixels = pourcent * 25;
					    }
							if(mouse_x >= pixels && mouse_x <= pixels + 60 && mouse_y >= hauteur && mouse_y <= hauteur + 100){
								running = i+1;
							}
							pixels += pourcent *7;
					}
				}
				break;
			}
		}
	}
	return running;
}

int select_tuile(int AutoriserFinTour){
	float pourcent = (SCREEN_WIDTH/100.0);
	float pourcentH = (SCREEN_HEIGHT/100.0);

	int mouse_x, mouse_y;
	SDL_Event e;
	int running = -1;
  while(running==-1  || running >=N_CHEV) {
      if (SDL_WaitEvent(&e) != 0) {
        switch(e.type) {
          case SDL_MOUSEBUTTONDOWN:
          {

            SDL_GetMouseState(&mouse_x, &mouse_y);
						if(AutoriserFinTour>0 && mouse_x >=pourcent *83 && mouse_x <=pourcent *99 && mouse_y >= pourcentH * 82 && mouse_y <= pourcentH * 91.5 ){
							return 100;
						}
					  int pixels = pourcent * 25;
					  int hauteur = pourcentH * 66;
					  for(int i = 0;i < N_CHEV;i++){
					    if (i==7){
					      hauteur = pourcentH *82;
					      pixels = pourcent * 25;
					    }
							if(mouse_x >= pixels && mouse_x <= pixels + 60 && mouse_y >= hauteur && mouse_y <= hauteur + 100){
								running = i+1;
							}
							pixels += pourcent *7;
					}
				}
				break;
			}
		}
	}
	return running;
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

  int numero=0,* choix = malloc(sizeof(int));
  t_tuile * tuile_sommet;

  affiche_piles(okey,pfg,pfd,pg,pd);
  affiche_chevalet(chevalet,N_CHEV);

	float pourcent = (SCREEN_WIDTH/100.0);
	float pourcentH = (SCREEN_HEIGHT/100.0);

	int mouse_x, mouse_y;
	SDL_Event e;

	while(*choix != 0 && *choix != 1) {
			if (SDL_WaitEvent(&e) != 0) {
				switch(e.type) {
					case SDL_MOUSEBUTTONDOWN:
					{

						SDL_GetMouseState(&mouse_x, &mouse_y);
						if( mouse_x >= pourcent * 27.5 && mouse_x <= pourcent * 27.5+60 && mouse_y >= pourcentH * 36.7 && mouse_y <= pourcentH * 36.7+100 ){
							*choix = 1;
						}else if( mouse_x >= pourcent * 51 && mouse_x <= pourcent * 51+60 && mouse_y >= pourcentH * 22 && mouse_y <= pourcentH * 22+100 ){
							*choix = 0;
						}
					}
				}
			}
	}


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

	while(numero < 1 || numero > 15){
	  numero = select_tuile(0);
	}

  empile_enr_tuile(chevalet,enr,pd,N_CHEV,numero-1);

  affiche_piles(okey,pfg,pfd,pg,pd);
  affiche_chevalet(chevalet,N_CHEV);
  free(choix);
}

/**
 * \fn int afficher_menu(char menu[4][30])
 * \brief Gère l'affichage du menu pricipal
 * \param[in] tableau de chaines de caractères qui seront affichées sur les boutons du menu
 * \return l'action choisie par le joueur dans le menu
 */
int afficher_menu(char menu[][30], int taille){
  fond_blanc();
  for(int i = 0, y=100; i<taille; i++, y+=150){
    drawImage( 500, y, "button.png", 475, 130);
    drawText(525, y+25, menu[i], 25, 12);
  }
  faire_rendu();
  SDL_Event e;
  int running = -1;
  while(running==-1  || running >=taille) {
      if (SDL_WaitEvent(&e) != 0) {
        switch(e.type) {
          case SDL_QUIT: running = 0;
          break;
          case SDL_MOUSEBUTTONDOWN:
          {
            int mouse_x, mouse_y;
            SDL_GetMouseState(&mouse_x, &mouse_y);
            //si on est dans la largeur du menu
            if(mouse_x>500 && mouse_x<975){
              //si on est à la hauteur d'une case du sélecteur
                int pos = mouse_y-100;
                int i=1;
                for(int j=0; j<pos+150 ;i++, j+=150){
                  if(pos >= j && pos <= j+150) break;
                }
                running = i-1;
              }

            }
          break;
      }
    }
    //SDL_Delay(80);
  }
  return running;
}



/**
 * \fn void afficher_regle(void)
 * \brief Affiche les règles du jeu
 */
void afficher_regle(void){
  fond_blanc();
  drawText(525, 25, "Voici les règles blablabla", 25, 12);
  faire_rendu();
  int * running = malloc(sizeof(int));
	*running = 1;


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

	while(1){

		int tuile1 = select_tuile(1)-1;
		if(tuile1 == 99){
			return 0;
		}
		int tuile2 = select_tuile_to_replace(tuileVersImage(chevalet[tuile1]), chevalet)-1;
		t_tuile * tuile = chevalet[tuile1];
		chevalet[tuile1] = chevalet[tuile2];
		chevalet[tuile2] = tuile;
		affiche_chevalet(chevalet, N_CHEV);
	}

}


/**
* \fn void affiche_chevalet(t_tuile * jeu[], int taille)
* \brief Affichage des 14/15 tuiles du chevalet
* \param jeu[] Chevalet
* \param taille Taille du chevalet
*/
void affiche_chevalet(t_tuile * jeu[],int taille){
  float pourcent = (SCREEN_WIDTH/100.0);
  float pourcentH = (SCREEN_HEIGHT/100.0);

  int i;

  int pixels = pourcent * 25;
  int hauteur = pourcentH * 66;
  drawImage( 0, 0, "chevalet.png", SCREEN_WIDTH, SCREEN_HEIGHT);
  for(i = 0;i < taille;i++){
    if (i==7){
      hauteur = pourcentH *82;
      pixels = pourcent * 25;
    }
    if(!(jeu[i]->nbr == V_DEL)){                           // Cas d'affichage des tuiles de 1 à 13 des 4 couleurs différentes
      drawImage( pixels, hauteur, tuileVersImage(jeu[i]), 60, 100);

		}
		pixels += pourcent * 7;
  }
  faire_rendu();

}




/**
* \fn void affiche_sommet_pile(t_pile * pile)
* \brief ffichage du sommet d'une pile
* \param pile Pile à afficher
* \param nb_pile Numéro de la pile à afficher
*/
void affiche_sommet_pile(t_pile * pile, int nb_pile){

  t_tuile * tuile;
  float pourcent = (SCREEN_WIDTH/100.0);
  float pourcentH = (SCREEN_HEIGHT/100.0);
  int pixels;
  int hauteur;
  if(!pile_vide(pile)){
    sommet_pile(pile,&tuile);
	}
    switch(nb_pile){
      case 1:
        pixels = pourcent * 27.5;
        hauteur = pourcentH * 14.1;
        break;
      case 2:
        pixels = pourcent * 67.3;
        hauteur = pourcentH * 14.1;
        break;
      case 3:
        pixels = pourcent * 27.5;
        hauteur = pourcentH * 36.7;
        break;
      case 4:
        pixels = pourcent * 67.3;
        hauteur = pourcentH * 36.7;
        break;

    }
		if(pile_vide(pile)){
			drawImage( pixels, hauteur, "NULL.png", 70, 115);
		}
		else{
    drawImage( pixels, hauteur, tuileVersImage(pile->premier->tuile), 70, 115);
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

  affiche_sommet_pile(pfg, 1);
  affiche_sommet_pile(pfd, 2);

  // Cas d'affichage pour éviter d'espacer les nombres à 2 chiffres
  float pourcent = 43.5*(SCREEN_WIDTH/100.0);
  float pourcentH = 22*(SCREEN_HEIGHT/100.0);
  drawImage( pourcent, pourcentH, tuileVersImage(okey), 70, 115);
	 pourcent = 51.5*(SCREEN_WIDTH/100.0);
	drawImage( pourcent, pourcentH, "PIOCHE.png", 70, 115);

  affiche_sommet_pile(pg, 3);
  affiche_sommet_pile(pd, 4);
  printf("\n\n");
	faire_rendu();

}

/**
* \fn void affiche_chevalet_IA(t_tuile * jeu[], int taille)
* \brief Affichage des 14/15 tuiles cachés du chevalet d'une IA
* \param jeu[] Chevalet
* \param taille Taille du chevalet
*/
void affiche_chevalet_IA(t_tuile * jeu[],int taille){

}
