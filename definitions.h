#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

typedef enum { jaune , rouge , noire , bleu } t_couleur;

typedef enum { joker_1 , joker_2 } t_joker;

typedef union { int nbr ; t_couleur; t_joker; } t_tule;

/*
#if defined(WIN32)
  #define NOIR "@"
  #define BLANC "O"
#elif defined (linux)
  #define NOIR "●"
  #define BLANC "○"
#endif
*/
