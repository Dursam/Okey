/**
* \file fonctions_affichage.h
* \brief Fichier contenant les fonctions d'affichages
* \author Samuel DURAN Girod Valentin
* \date 12 Avril 2020
*/

int SCREEN_HEIGHT; /*!< Hauteur de l'écran en pixels */
int SCREEN_WIDTH; /*!< Largeur de l'écran en pixels */
int SPRITE_W; /*!< Largeur d'un sprite */
void * fenetre; /*!< Poiteur sur la fenêtre de jeu en void: Ce pointeur peut prendre deux types différents selon qu'on est en sdl ou terminal */
float VITESSE_PERSO; /*!< Vitesse du personnage (plus le jeu est optimisé en mémoire vive, moins il va vite, et plus il faut augmenter cette valeur) */
int sdl;


void setcolor(int, int);
void drawText (int , int , char *, int, int);
void drawImage (int , int , char *, int, int );
void init_affichage();
void fond_blanc();
void faire_rendu();
void quitter_affichage();
void taille_terminal(int lon,int lar);
