#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define N 106
#define J 15


typedef enum {jaune,rouge,noire,bleu} t_couleur;

typedef struct s_tuile {
  int nbr;
  t_couleur clr;
} t_tuile;

typedef struct s_element { t_tuile * tuile; struct s_element * suivant;} t_element;

typedef struct s_pile { t_element * premier ;} t_pile;



