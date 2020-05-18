/* Fichier contenant les fonctions principaux de sauvegarde et de score */
/**
* \file sauvegarde.c
* \brief Fichier contenant les fonctions de sauvegarde et de score
* \author Samuel DURAN
* \version 1.0
* \date 10 mai 2020
*/

#include "./sauvegarde.h"
/**
* \fn t_fichier * nom_fichier(void)
* \brief Créer une sauvegarde pour une partie
*/
t_fichier * nom_fichier(void){

  t_fichier * fichier = malloc(sizeof(t_fichier));
  fichier->nom = malloc(sizeof(char)*20);
  __time_t intps;
  struct tm * temps;
  intps = time(NULL);
  temps = localtime(&intps);
  sprintf(fichier->nom,"2020-%d-%d-%d-%d.txt",temps->tm_mon+1,temps->tm_mday,temps->tm_min,temps->tm_sec);
  fichier->fichier = fopen(fichier->nom,"w");
  fprintf(fichier->fichier,"Score de la partie : %s\nNuméro\tJ1\tJ2\tJ3\tJ4\n1",fichier->nom);
  fclose(fichier->fichier);
  return fichier;
}

/**
* \fn int numero_partie(t_fichier * fichier)
* \brief Récupère le numéro de partie
* \param fichier Un fichier et son nom
*/
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

/**
* \fn void ajout_score(t_fichier * fichier,int num_partie,int s_J1,int s_J2,int s_J3,int s_J4)
* \brief Ajoute les scores des joueurs de la partie
* \param fichier Un fichier et son nom
* \param num_partie Numéro de la partie
* \param  s_J1 Score du joueur 1
* \param  s_J2 Score du joueur 2
* \param  s_J3 Score du joueur 3
* \param  s_J4 Score du joueur 4
*/
void ajout_score(t_fichier * fichier,int num_partie,int s_J1,int s_J2,int s_J3,int s_J4){

  fichier->fichier = fopen(fichier->nom,"a");
  fprintf(fichier->fichier,"\t%i\t%i\t%i\t%i\n%i",s_J1,s_J2,s_J3,s_J4,num_partie);
  fclose(fichier->fichier);
}

/**
* \fn void charger_partie(t_fichier * fichier)
* \brief Charge une partie avec un fichier existant
* \param fichier Un fichier et son nom
*/
void charger_partie(t_fichier * fichier){

  char nom_fichier[256] = " ";

  if(!(fopen(nom_fichier,"r"))){
    do{
  printf("\n");
  system("ls | grep '2020-'");
  printf("\nNom de la sauvegarde de partie : ");
  scanf("%s",nom_fichier);
  fichier->nom = nom_fichier;
  fichier->fichier = fopen(fichier->nom,"r");
    }while(!(fopen(fichier->nom,"r")));
  }
  fclose(fichier->fichier);
}

/**
* \fn int calcul_score(t_fichier * fichier,int num_partie,int num_joueur)
* \brief Calcule le score d'un joueur à partir d'une sauvegarde de partie
* \param fichier Un fichier et son nom
* \param num_partie Numéro de la partie
* \param num_joueur Numéro du joueur de 1 à 4
*/
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

/**
* \fn void afficher_scores(t_fichier * fichier,int num_partie)
* \brief Affiche les scores des joueurs d'une partie
* \param fichier Un fichier et son nom
* \param num_partie Numéro de la partie
*/
void afficher_scores(t_fichier * fichier,int num_partie){

  int s_J1,s_J2,s_J3,s_J4;

  s_J1 = calcul_score(fichier,num_partie,1);
  s_J2 = calcul_score(fichier,num_partie,2);
  s_J3 = calcul_score(fichier,num_partie,3);
  s_J4 = calcul_score(fichier,num_partie,4);

  printf("\n--Consultation des scores des joueurs--\n\tJ1\tJ2\tJ3\tJ4\n\t%i\t%i\t%i\t%i",s_J1,s_J2,s_J3,s_J4);
}
