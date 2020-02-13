#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

//#define NBR_TULES 104

typedef enum {jaune,rouge,noire,bleu} t_couleur;

typedef struct s_tule {
  int nbr;
  t_couleur clr;
} t_tule;
