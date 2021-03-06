/**
 * \file fonctions_terminal.c
 * \brief Fonctions de gestion terminal
 * \author Girod Valentin
 * \date 30 Avril 2020
 *
 * Contient les fonctions d'affichage et de gestion de fenêtres en terminal
 *
 */
#include <ncurses.h>
#include <stdlib.h>
#include <fonctions_affichage.h>
#include <unistd.h>


void drawText (int x, int y, char * z, int a, int b);
void drawImage (int x, int y, char * z, int a, int b);



/**
 * \fn int colornum(int fg, int bg)
 * \brief Retourne le numéro de couleur
 * \param fg
 * \param bg
 */
int colornum(int fg, int bg)
{
    int B, bbb, ffff;

    B = 1 << 7;
    bbb = (7 & bg) << 4;
    ffff = 7 & fg;

    return (B | bbb | ffff);
}

/**
 * \fn void curs_color()
 * \brief Transforme un nombre en une couleur ncurses
 * \param fg
 */
short curs_color(int fg)
{
    switch (7 & fg) {           /* RGB */
    case 0:                     /* 000 */
        return (COLOR_BLACK);
    case 1:                     /* 001 */
        return (COLOR_BLUE);
    case 2:                     /* 010 */
        return (COLOR_GREEN);
    case 3:                     /* 011 */
        return (COLOR_CYAN);
    case 4:                     /* 100 */
        return (COLOR_RED);
    case 5:                     /* 101 */
        return (COLOR_MAGENTA);
    case 6:                     /* 110 */
        return (COLOR_YELLOW);
    case 7:                     /* 111 */
        return (COLOR_WHITE);
    }
    return -1;
}

/**
 * \fn void is_bold()
 * \brief Vérifie si le texte est déjà surligné
 */
int is_bold(int fg)
{
    /* return the intensity bit */

    int i;

    i = 1 << 3;
    return (i & fg);
}

/**
 * \fn void init_colorpairs()
 * \brief Initialise les couleurs ncurses
 */
void init_colorpairs(void)
{
    int fg, bg;
    int colorpair;

    for (bg = 0; bg <= 7; bg++) {
        for (fg = 0; fg <= 7; fg++) {
            colorpair = colornum(fg, bg);
            init_pair(colorpair, curs_color(fg), curs_color(bg));
        }
    }
}

/**
 * \fn void setcolor()
 * \brief Définit la couleur du texte et de son surlignage
 * \param[in] Entier représentant l'état du texte
 * \param[in] Entier représentant l'état du surlignage
 */
void setcolor(int fg, int bg)
{
    /* set the color pair (colornum) and bold/bright (A_BOLD) */

    attron(COLOR_PAIR(colornum(fg, bg)));
    if (is_bold(fg)) {
        attron(A_BOLD);
    }
}

/**
 * \fn void faire_rendu()
 * \brief met l'écran à jour
 */
void faire_rendu(){
		refresh();
    wrefresh( fenetre );
}

/**
 * \fn void quitter_affichage()
 * \brief Quitte totallement Ncurses
 */
void quitter_affichage(){
  curs_set(1);
  clear();
  delwin(fenetre);
  endwin();
}

/**
 * \fn void init_affichage()
 * \brief initialise les couleur ncurses, les bordures de fenêtre et la taille du terminal
*/
void init_affichage(){
  initscr(); // initialize Ncurses
  sdl = 0;
  taille_terminal(SCREEN_WIDTH,SCREEN_HEIGHT); // Récupère la taille de la fenetre du terminal
  fenetre = newwin( SCREEN_HEIGHT, SCREEN_WIDTH, 0, 0 ); // création d'une fenêtre
  //initialisation des couleurs terminal
  if (has_colors() == FALSE) {
      endwin();
      puts("Votre terminal ne supporte pas les couleurs");
      exit(1);
  }
  start_color();
  init_colorpairs();
  SPRITE_W = 1;
}

/**
 * \fn void fond_blanc()
 * \brief Met le fond de la fenêtre en blanc
 */
void fond_blanc(){
  setcolor(7, 7);
  for(int i=0; i<=SCREEN_HEIGHT; i++){
    for(int j=0; j<=SCREEN_WIDTH; j++){
      mvwprintw( fenetre,i, j, " " );
      mvaddstr( i, j, "_" );
    }
  }
  faire_rendu();
}
