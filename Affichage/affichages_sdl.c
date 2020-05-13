/**
 * \file      affichages_sdl.c
 * \author    Girod Valentin
 * \version   1.0
 * \date     Mars 2019
 * \brief    Contient toutes les fonctions d'affichage du jeu en sdl
 */
#include <affichage.h>
#include <fonctions_affichage.h>
#include <SDL2/SDL.h>


char * afficher_sauvegarde(int max_fichier){
	return " ";
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
 * \fn void detecter_touches(int * running)
 * \brief Gère les touche échap pour le menu et i pour l'inventaire
 * \param[in] l'état du jeu à modifier si le joueur appuis sur échap
 */
void detecter_touches(int * running){
  SDL_Event e;
  while(SDL_PollEvent(&e)) {
    switch(e.type) {
      //la gestion du clavier hors déplacements se fait ici
      case SDL_KEYDOWN:
      {
        const Uint8 *state = SDL_GetKeyboardState(NULL); //en sdl
        if(state[SDL_SCANCODE_ESCAPE]){
          *running = 0;
        }
        break;
      }
    }
  }

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
	while(running){
		detecter_touches(running);
	}

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

char * tuileVersImage(t_tuile * t){
  char*tuile;
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
  printf("\nnumero1: %d\n", t->nbr+1);
  sprintf(nb, "%d", t->nbr+1);
  printf("\nnumero2: %s\n", nb);
  strncat(tuile, nb, strlen(nb));
  strncat(tuile, ".png", 4);
  printf("tuile: %s\n", tuile);
  return tuile;
}


/**
* \fn void affiche_chevalet(t_tuile * jeu[], int taille)
* \brief Affichage des 14/15 tuiles du chevalet
* \param jeu[] Chevalet
* \param taille Taille du chevalet
*/
void affiche_chevalet(t_tuile * jeu[],int taille){
  fond_blanc();
  float pourcent = (SCREEN_WIDTH/100);
  float pourcentH = (SCREEN_HEIGHT/100);

  int i;

  int pixels = pourcent * 25;
  int hauteur = pourcentH * 73;
  drawImage( 0, 0, "chevalet.png", SCREEN_WIDTH, SCREEN_HEIGHT);
  for(i = 0;i < taille;i++){
    if (i==7){
      hauteur = pourcentH *90;
      pixels = pourcent * 25;
    }
    if(i == 0)
      printf("\t|");
    if(i == 14 && jeu[14]->nbr != V_DEL)
      printf("--------------->");

    if(jeu[i]->nbr == V_DEL)                // Cas d'affichage où la tuile a été supprimée
      printf("\t");
    else{
      if(jeu[i]->nbr==13){                  // Cas d'affichage pour tuiles okey rouge et noire
          if(jeu[i]->clr==noire)
            drawImage( pixels, hauteur, "TON.png", 60, 100);
          else if(jeu[i]->clr==rouge)
            drawImage( pixels, hauteur, "TOR.png", 60, 100);
      }
      else{
        printf("%s\n", tuileVersImage(jeu[i]));                              // Cas d'affichage des tuiles de 1 à 13 des 4 couleurs différentes
        drawImage( pixels, hauteur, tuileVersImage(jeu[i]), 60, 100);
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
  float pourcent = (SCREEN_WIDTH/100);
  float pourcentH = (SCREEN_HEIGHT/100);
  int pixels;
  int hauteur;
  if(pile_vide(pile))
    printf("* \033[34;47m__\033[00m\t");
  else{
    sommet_pile(pile,&tuile);
    switch(nb_pile){
      case 1:
        pixels = pourcent * 25;
        hauteur = pourcentH * 25;
        break;
      case 2:
        pixels = pourcent * 75;
        hauteur = pourcentH * 25;
        break;
      case 3:
        pixels = pourcent * 25;
        hauteur = pourcentH * 75;
        break;
      case 4:
        pixels = pourcent * 75;
        hauteur = pourcentH * 75;
        break;

    }
    drawImage( pixels, hauteur, tuileVersImage(tuile), 60, 100);
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
  printf("\n\t\t\t   OKEY\tPIOCHE\n\t\t\t   ");
  float pourcent = 50*(SCREEN_WIDTH/100);
  float pourcentH = 50*(SCREEN_HEIGHT/100);
  drawImage( pourcent, pourcentH, tuileVersImage(okey), 60, 100);

  printf("\033[34;47m__\033[00m  \033[34;47m__\033[00m\n\n\t");
  affiche_sommet_pile(pg, 3);
  printf("\t\t\t\t\t");
  affiche_sommet_pile(pd, 4);
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
