/**
 * \file      affichages_sdl.c
 * \author    Girod Valentin
 * \version   1.0
 * \date     Mars 2019
 * \brief    Contient toutes les fonctions d'affichage du jeu en sdl
 */
#include <affichage.h>
#include <map.h>
#include <fonctions_affichage.h>
#include <SDL2/SDL.h>
#include <map_menace.h>





/**
 * \fn void afficher_inv(int PH, int PW, int H, int W, int PSH, int PSW, int partie_items)
 * \brief Gère l'affichage de l'inventaire
 * \param[in] 1% de la largeur de l'image d'inventaire en pixels
 * \param[in] 1% de la hauteur de l'image d'inventaire en pixels
 * \param[in] pixels en largeur de l'image
 * \param[in] pixels en hauteur de l'image
 * \param[in] abscisse de l'image sur l'écran
 * \param[in] ordonnée de l'image sur l'écran
 * \param[in] un entier qui représente la partie de l'inventaire qui est affichée, comme tous les items ne peuvent être affichés en meme temps
 */
void afficher_inv(int PH, int PW, int H, int W, int PSH, int PSW, int partie_items){
  //la longueur des barres de vie/mana/xp est de 8.54% de l'image, suivie d'une autre barre de 8.54% de l'image d'une autre couleur pour la barre vide
  //Il faut (pour l'instant) 100xp par niveau, 100hp en tout,
  //8.54%/100 = le nombre de pixels pour 1xp
  //nouvelle taille en pixels de l'image: (SCREEN_HEIGHT/100)*90
  //8.54% de cette taille = nb de pixels qu'il faut

  float pixels = ((SCREEN_WIDTH/100)*95/100*8.54);
  //calcul du nombre d'xp du niveau actuel:
  //int actual_xp = 100-Personnage->level*100-Personnage->xp;
  int actual_xp=Personnage->xp;

  //le calcul du nombre de pixels pour afficher le texte suis la même logique que les pixels

  //variables de taille du texte et chaine de charactère pour afficher les nombres
  char num[3];
  int textH = 55;
  int textW = 35;

  //affichage des barres
  drawImage( (Personnage->health*pixels/100)-pixels+PSW, PSH, "life_bar.png", W, H);
  drawImage( actual_xp*pixels/100-pixels+PSW, PSH, "xp_bar.png", W, H);
  drawImage( Personnage->mana*pixels/100-pixels+PSW, PSH, "mana_bar.png", W, H);
  drawImage( PSW, PSH, "inventory.png", W, H);

  //affichage du level
  float PxTextXlevel = ((SCREEN_WIDTH/100)*47);
  float PxTextYlevel = ((SCREEN_WIDTH/100)*2.8);
  sprintf(num,"%d",Personnage->level);
  drawText( PxTextXlevel, PxTextYlevel, num, textH, textW);


  float PxTextXActuel = ((SCREEN_WIDTH/100)*35.1); //X ne change pas pour les 3 premier nombres
  float PxTextYVie = ((SCREEN_WIDTH/100)*7.2);
  float PxTextYXP = ((SCREEN_WIDTH/100)*11.2);
  float PxTextYMana = ((SCREEN_WIDTH/100)*15.2);

  //affichage des valeurs des barres
  sprintf(num,"%d",Personnage->health);
  drawText( PxTextXActuel, PxTextYVie, num, textH, textW);
  sprintf(num,"%d",actual_xp);
  drawText( PxTextXActuel, PxTextYXP, num, textH, textW);
  sprintf(num,"%d",Personnage->mana);
  drawText( PxTextXActuel, PxTextYMana, num, textH, textW);

  PxTextXActuel = ((SCREEN_WIDTH/100)*47); //on redéfinit X pour les 3 autres nombres, y ne change pas

  //affichage des valeurs max des barres
  drawText( PxTextXActuel, PxTextYVie, "100", textH, textW);
  drawText( PxTextXActuel, PxTextYXP, "100", textH, textW);
  drawText( PxTextXActuel, PxTextYMana, "100", textH, textW);

  //affichage des items équipés
  //Les images des items ont les mêmes noms que les items eux-même, cela facilite leur affichage graçe à la fonction
  //display_object dans perso.c
  drawImage( (SCREEN_WIDTH/100)*75.75, (SCREEN_HEIGHT/100)*37, Personnage->char_armor->name_object, 110, 110);
  drawImage( (SCREEN_WIDTH/100)*60.75, (SCREEN_HEIGHT/100)*37, Personnage->char_weapon->name_object, 110, 110);

  //affichage de l'accessoire
  char accessory[20];
  if(Personnage->accessory==green_amulet) sprintf(accessory, "%s", "green amulet");
  if(Personnage->accessory==ruby_ring) sprintf(accessory, "%s", "ruby ring");
  if(Personnage->accessory==crystal_ring) sprintf(accessory, "%s", "crystal ring");
  drawImage( (SCREEN_WIDTH/100)*60.75, (SCREEN_HEIGHT/100)*9, accessory, 110, 110);


  //affichage des items de l'inventaire
  for(int i=15*partie_items, j=0, k=0; i<Inventaire->nb_objects && i < partie_items+15; i++, j++){
    if(i%5==0 && i!=0 && i!=15){
      j=0;
      k++;
    }
    drawImage( (j*9.25+3.05)*PW+PSW, (k*15.25+61)*PH+PSH, Inventaire->object[i]->name_object, 60, 60);
    //strcpy(item[i], display_object(*(Inventaire->object[i])));
  }
  faire_rendu();
}

/**
 * \fn void showInventory()
 * \brief Gère les interractions avec l'inventaire
 */
void showInventory(){
  //les pixels de l'image
  int W = 95*SCREEN_WIDTH/100;
  int H = SCREEN_HEIGHT;

  //les pixels qui représentent 1% de l'image
  int PW = W/100;
  int PH = H/100;

  //les pixels qui représentent les coordonnées de l'image
  int PSW = 2.5*SCREEN_WIDTH/100;
  int PSH = 0;
  //l'inventaire est séparé en deux parties étant donné que l'image contient 15 cases d'inventaire
  //et que l'inventaire peut contenir 30 items
  int partie_items = 0;
  afficher_inv(PH, PW, H, W, PSH, PSW, partie_items);
  int running = 1;
  while(running) {
  	SDL_Event e;
  	while(SDL_PollEvent(&e)) {
  		switch(e.type) {
        case SDL_KEYDOWN:
        {
          //l'état du clavier à l'instant actuel
          const Uint8 *state = SDL_GetKeyboardState(NULL);

          //si c'est la touche d'inventaire, ou la touche échap, ou la touche entrée
          if(state[SDL_SCANCODE_I] || state[SDL_SCANCODE_ESCAPE] || state[SDL_SCANCODE_RETURN]){
            running = 0;
          }

          break;
        }
        case SDL_MOUSEBUTTONDOWN:
        //quand on clique, si on clique au dessus du sélecteur, on va placer une case.
        //Sinon, on regarde si on a cliqué dans une case du sélecteur.
        {
          int mouse_x, mouse_y;
          SDL_GetMouseState(&mouse_x, &mouse_y);
          //si on est sur la fleche vers le bas
          printf("souris y: %d x: %d, y: %d%% x: %d%% \n", mouse_y, mouse_x, mouse_y/PH, (mouse_x-PSW)/PW);
          printf("coordonnées: y: %.2f, %.2f, x: %.2f, %.2f\n", 74.7*PH, 93.66*PH, 43.82*PW+PSW, 51.6*PW+PSW);
          if(mouse_y > 82.7*PH && mouse_y < 102.66*PH && mouse_x > 47.82*PW+PSW && mouse_x < 55.6*PW+PSW){
            partie_items = 1;
            printf("partieitem %d\n", partie_items);
            afficher_inv(PH, PW, H, W, PSH, PSW, partie_items);
          }
          else if(mouse_y < 80.66*PH && mouse_y > 59.55*PH && mouse_x > 47.82*PW+PSW && mouse_x < 55.6*PW+PSW){
            partie_items = 0;
            printf("partieitem %d\n", partie_items);
            afficher_inv(PH, PW, H, W, PSH, PSW, partie_items);
          }
        break;
      }
      }
    }
  }
  afficher_Map( X, Y);
  faire_rendu();

}

/**
 * \fn int afficher_menu(char menu[4][30])
 * \brief Gère l'affichage du menu pricipal
 * \param[in] tableau de chaines de caractères qui seront affichées sur les boutons du menu
 * \return l'action choisie par le joueur dans le menu
 */
int afficher_menu(char menu[4][30]){
  fond_blanc();
  for(int i = 0, y=100; i<4; i++, y+=150){
    drawImage( 500, y, "button.png", 475, 130);
    drawText(525, y+25, menu[i], 25, 12);
  }
  faire_rendu();
  SDL_Event e;
  int running = -1;
  while(running==-1) {
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
                switch(i){
                  case 1: running = 0; break; //nouvelle partie
                  case 2: break; //charger partie
                  case 3: running = 2; break; //editeur carte
                  case 4: running=3; break; //quitter jeu
                }
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
 * \fn int detecter_mouvement(float * x, float * y)
 * \brief Gère le mouvement du personnage
 * \param[in] abscisse du perso
 * \param[in] ordonnée du perso
 * \return 1 si le personnage a bougé, 0 sinon
 */
int detecter_mouvement(float * x, float * y){
  //l'état du clavier à l'instant actuel
  const Uint8 *state = SDL_GetKeyboardState(NULL); //en sdl
  //si c'est une touche de mouvement
  if(state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_DOWN]){
    //on gère les colisions et la vitesse du perso
    //on a besoin de regarder à quel endroit de la map on est et ce qu'il *y a après
    //on fait cohabiter le sdl et le terminal pour un code le plus optimisé possible
    if (state[SDL_SCANCODE_RIGHT] && (map[(int)(floor(*y))][(int)(floor(*x+VITESSE_PERSO))]==4 || map[(int)(floor(*y))][(int)(floor(*x+VITESSE_PERSO))]==5)) *x+=VITESSE_PERSO;
    else if (state[SDL_SCANCODE_LEFT] && (map[(int)(floor(*y))][(int)(floor(*x-VITESSE_PERSO))]==4 || map[(int)(floor(*y))][(int)(floor(*x-VITESSE_PERSO))]==5)) *x-=VITESSE_PERSO;
    if (state[SDL_SCANCODE_UP] && (map[(int)(floor(*y-VITESSE_PERSO))][(int)(floor(*x))]==4 || map[(int)(floor(*y-VITESSE_PERSO))][(int)(floor(*x))]==5)) *y-=VITESSE_PERSO;
    else if (state[SDL_SCANCODE_DOWN] && (map[(int)(floor(*y+VITESSE_PERSO))][(int)(floor(*x))]==4 || map[(int)(floor(*y+VITESSE_PERSO))][(int)(floor(*x))]==5)) *y+=VITESSE_PERSO;
    if(*x<0) *x=0;
    if(*y<0) *y=0;
    if(*x>999) *x=999;
    if(*y>999) *y=999;
    return 1;
  }
  return 0;
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
        //si c'est la touche d'inventaire
        if(state[SDL_SCANCODE_I]){
          showInventory();
        }
        else if(state[SDL_SCANCODE_ESCAPE]){
          *running = 0;
        }
        break;
      }
      case SDL_MOUSEBUTTONDOWN:
      //quand on clique, si on clique au dessus du sélecteur, on va placer une case.
      //Sinon, on regarde si on a cliqué dans une case du sélecteur.
      {
        int mouse_x, mouse_y;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        break;
      }
    }
  }
  SDL_Delay(5);
}
