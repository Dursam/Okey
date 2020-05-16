/**
 * \file fonctions_terminal.h
 * \brief Fonctions de gestion terminal
 * \author Girod Valentin
 * \date 30 Avril 2020
 *
 * Contient les fonctions d'affichage et de gestion de fenêtres en terminal
 *
 */

/**
  * \fn int colornum(int fg, int bg)
  * \brief Retourne le numéro de couleur
*/
int colornum(int fg, int bg);

/**
 * \fn void curs_color()
 * \brief Transforme un nombre en une couleur ncurses
*/
short curs_color(int fg);

/**
 * \fn void is_bold()
 * \brief Vérifie si le texte est déjà surligné
 */
int is_bold(int fg);

/**
 * \fn void init_colorpairs()
 * \brief Initialise les couleurs ncurses
 */
void init_colorpairs(void);

/**
 * \fn void setcolor()
 * \brief Définit la couleur du texte et de son surlignage
*/
void setcolor(int fg, int bg);
