/**
 * \file fonctions_sdl.h
 * \brief Fonctions de gestion SDL
 * \author Girod Valentin
 * \date 30 Avril 2020
*/

#include <SDL2/SDL.h>

int SCREEN_HEIGHT; /*!< Hauteur de l'écran en pixels */
int SCREEN_WIDTH; /*!< Largeur de l'écran en pixels */
int SPRITE_W; /*!< Largeur d'un sprite */
SDL_Window*pWindow; /*!< Poiteur sur la fenêtre de jeu */
SDL_Renderer*renderer; /*!< Pointeur sur l'état du rendu */
int TERMINAL;
int AFFICHAGE;
WINDOW *w; //la fenêtre pour l'affichage terminal

/**
 * \fn void loadImages()
 * \brief Chargement de toutes les textures du jeu dans la mémoire
 */
void loadImages(void);

/**
 * \fn void unloadImages()
 * \brief Déchargement de toutes les textures du jeu
 */
void unloadImages(void);

/**
 * \fn void faire_rendu()
 * \brief Met l'écran à jour
 */
void faire_rendu(void);

/**
 * \fn void fond_blanc()
 * \brief Met le fond de la fenêtre en blanc
 */
void fond_blanc(void);

/**
 * \fn void drawText(int x, int y, char * string, int h, int w)
 * \brief Affiche du texte d'une certaine taille à des coordonnées données
*/
void drawText (int , int , char *, int, int);

/**
 * \fn void drawImage(int x, int y, char * nom, int w, int h)
 * \brief Affiche une image d'une certaine taille à des coordonnées données
*/
void drawImage (int , int , char *, int, int );

/**
 * \fn void showWindow(void);
 * \brief Affiche la fenêtre
*/
void showWindow(void);

/**
 * \fn void quitter_sdl(void);
 * \brief Quitte la sdl
*/
void quitter_sdl(void);
