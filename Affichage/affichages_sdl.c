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
    //if (state[SDL_SCANCODE_RIGHT] && (map[(int)(floor(*y))][(int)(floor(*x+VITESSE_PERSO))]==4 || map[(int)(floor(*y))][(int)(floor(*x+VITESSE_PERSO))]==5)) *x+=VITESSE_PERSO;
    //else if (state[SDL_SCANCODE_LEFT] && (map[(int)(floor(*y))][(int)(floor(*x-VITESSE_PERSO))]==4 || map[(int)(floor(*y))][(int)(floor(*x-VITESSE_PERSO))]==5)) *x-=VITESSE_PERSO;
    //if (state[SDL_SCANCODE_UP] && (map[(int)(floor(*y-VITESSE_PERSO))][(int)(floor(*x))]==4 || map[(int)(floor(*y-VITESSE_PERSO))][(int)(floor(*x))]==5)) *y-=VITESSE_PERSO;
    //else if (state[SDL_SCANCODE_DOWN] && (map[(int)(floor(*y+VITESSE_PERSO))][(int)(floor(*x))]==4 || map[(int)(floor(*y+VITESSE_PERSO))][(int)(floor(*x))]==5)) *y+=VITESSE_PERSO;
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
          //showInventory();
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
