#include <sav.h>

t_fichier * nom_fichier(void){

  t_fichier * fichier = malloc(sizeof(t_fichier));
  fichier->nom = malloc(sizeof(char)*30);
  __time_t intps;
  struct tm * temps;
  intps = time(NULL);
  temps = localtime(&intps);
  sprintf(fichier->nom,"Sauvegarde/2020-%d-%d-%d-%d.txt",temps->tm_mon+1,temps->tm_mday,temps->tm_min,temps->tm_sec);
  fichier->fichier = fopen(fichier->nom,"w");
  fprintf(fichier->fichier,"Score de la partie : %s\nNuméro\tJ1\tJ2\tJ3\tJ4\n1",fichier->nom);
  fclose(fichier->fichier);
  return fichier;
}

int numero_partie(t_fichier * fichier){

  char buff;
  int num;
  fichier->fichier = fopen(fichier->nom,"r");
  fscanf(fichier->fichier,"%c",&buff);
  while(!feof(fichier->fichier))
    fscanf(fichier->fichier,"%c",&buff);
  num = buff - '0';
  fclose(fichier->fichier);
  return num;
}

void ajout_score(t_fichier * fichier,int num_partie,int s_J1,int s_J2,int s_J3,int s_J4){

  fichier->fichier = fopen(fichier->nom,"a");
  fprintf(fichier->fichier,"\t%i\t%i\t%i\t%i\n%i",s_J1,s_J2,s_J3,s_J4,num_partie);
  fclose(fichier->fichier);
}

void charger_partie(t_fichier * fichier){

  fichier->fichier = fopen(fichier->nom,"r");
  fclose(fichier->fichier);
}

int calcul_score(t_fichier * fichier,int num_partie,int num_joueur){

  char buff;
  int score = 0,temp;
  fichier->fichier = fopen(fichier->nom,"r");

  while(fgetc(fichier->fichier)!='\n');
  while(fgetc(fichier->fichier)!='\n');
  while(fgetc(fichier->fichier)!='\t');

  if(num_joueur >= 2 && num_joueur <= 4)
    while(fgetc(fichier->fichier)!='\t');
  if(num_joueur >= 3 && num_joueur <= 4)
    while(fgetc(fichier->fichier)!='\t');
  if(num_joueur == 4)
    while(fgetc(fichier->fichier)!='\t');

  for(int i = 0;i < num_partie-1; i++){
      fscanf(fichier->fichier,"%c",&buff);
      temp = buff - '0';
      score += temp;
      fseek(fichier->fichier,9,SEEK_CUR);
  }
  fclose(fichier->fichier);
  return score;
}

void afficher_scores(t_fichier * fichier,int num_partie){

  int s_J1,s_J2,s_J3,s_J4;

  s_J1 = calcul_score(fichier,num_partie,1);
  s_J2 = calcul_score(fichier,num_partie,2);
  s_J3 = calcul_score(fichier,num_partie,3);
  s_J4 = calcul_score(fichier,num_partie,4);

  printf("\n--Consultation des scores des joueurs--\n\tJ1\tJ2\tJ3\tJ4\n\t%i\t%i\t%i\t%i",s_J1,s_J2,s_J3,s_J4);
}
