/* Fichier contenant les fonctions principaux pour lancer une partie de Okey en réseau */
/**
* \file reseau.c
* \brief Fichier contenant les fonctions de reseau
* \author Samuel DURAN
* \version 1.0
* \date 30 Janvier 2020
*/

#include <init_structure.h>
#include <init_pile.h>
#include <affichage_tuile.h>
#include <combinaison_couleur.h>
#include <combinaison_suite_entiers.h>
#include <selection_tuile.h>
#include <partie.h>
#include <partie_IA.h>
#include <reseau.h>

/**
* \fn SOCKET serveur (SOCKET sock)
* \brief Ouverture d'un port, le serveur attends une demande de connexion
* \param sock Socket réseau
*/
SOCKET serveur (SOCKET sock){

  SOCKADDR_IN sin;
  socklen_t recsize = sizeof(sin);
  // Socket et contexte d'adressage du client
  SOCKET csock;
  SOCKADDR_IN csin;
  socklen_t crecsize = sizeof(csin);
  // Vérifie si les étapes du protocoles TCP IP sont fait
  int sock_err;
  // Création d'une socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  // Adresse IP du serveur
  printf("Veuillez saisir l'adresse IP du serveur: ");
  int adresse_ip_len = 255;
  char * adresse_ip;
  adresse_ip = (char *) malloc(adresse_ip_len);
  fgets(adresse_ip,adresse_ip_len,stdin);
  // Si la socket est valide
  if(sock != INVALID_SOCKET){
      printf("Ouverture de la socket %d en mode TCP/IP\n", sock);
      // Configuration
      sin.sin_addr.s_addr = inet_addr(adresse_ip);
      free(adresse_ip);
      sin.sin_family = AF_INET;
      sin.sin_port = htons(PORT);
      sock_err = bind(sock, (SOCKADDR*)&sin, recsize);
      // Verifie si l'opération de liaison fonctionne
      if(sock_err != SOCKET_ERROR){
          // Démarrage du listage (mode server)
          sock_err = listen(sock, 5);
          printf("Listage du port %d...\n", PORT);
          // Vérifie si le port est occupé
          if(sock_err != SOCKET_ERROR){
              //Attente pendant laquelle le client se connecte
              printf("Patientez pendant que le client se connecte sur le port %d...\n", PORT);
              csock = accept(sock, (SOCKADDR*)&csin, &crecsize);
              printf("Un client se connecte avec la socket %d de %s:%d\n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));
              return csock;
          }
					else
						perror("Listen");
      }
			else
				perror("Bind");
  }
	else
		perror("Socket");
}

/**
* \fn SOCKET client (SOCKET sock)
* \brief Connexion d'un client au près d'un serveur, entre son adresse IP
* \param sock Socket réseau
*/
SOCKET client (SOCKET sock) {

  // Adresse IP du serveur
  printf("Veuillez saisir l'adresse IP du serveur: ");
  int adresse_ip_len = 255;
  char * adresse_ip;
  adresse_ip = (char *) malloc(adresse_ip_len);
  fgets(adresse_ip,adresse_ip_len,stdin);
  // Création de la socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  // Configuration de la connexion
  SOCKADDR_IN sin;
  sin.sin_addr.s_addr = inet_addr(adresse_ip);
  free(adresse_ip);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(PORT);
  // Si le client arrive à se connecter et si l'on a réussi à se connecter
  if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR){
      printf("Connexion à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
      return sock;
  }
	else
		perror("Connection");


}

/**
* \fn void deconnexion (SOCKET sock)
* \brief Déconnecte une socket réseau, client ou serveur
* \param sock Socket réseau
*/
void deconnexion (SOCKET sock){
  printf("Fermeture de la socket Client et Serveur\n");
  closesocket(sock);
}

/**
* \fn void affiche_chevalet_IA(t_tuile * jeu[], int taille)
* \brief Affichage des 14/15 tuiles cachés du chevalet d'une IA
* \param jeu[] Chevalet
* \param taille Taille du chevalet
*/
void affiche_chevalet_IA(t_tuile * jeu[],int taille){

  int i;
  printf("\033[1;32m\t\b\t1\t2\t3\t4\t5\t6\t7\t\033[00m");
  printf("\n\t------------------------------------------------------\n");

  for(i = 0;i < taille;i++){

    if(i == 0)
      printf("\t|");
    if(i == 14 && jeu[14]->nbr != V_DEL)
      printf("--------------->");

    if(jeu[i]->nbr == V_DEL)                // Cas d'affichage où la tuile a été supprimée
      printf("\t");
    else{                                   // Cas d'affichage pour une tuile quelconque
        printf("* \033[34;47m__\033[00m\t");
        if(i == 6)
          printf("\b\b\b|");
        if(i == 13)
          printf("\b\b\b|");
    }
    if(i == 6 && jeu[14]->nbr == V_DEL)
      printf("\n\t|\t\t\t\t\t\t\t\b\b\b|\n\t|");
    else if(i == 6 && jeu[14]->nbr != V_DEL)
      printf("\n\t|\t\t\t\t\t\t\t\b\b\b| NOUVELLE TUILE \033[1;32m15\033[00m\n\t|");
  }
  printf("\n\t------------------------------------------------------\n");
  printf("\033[1;32m\t\b\t8\t9\t10\t11\t12\t13\t14\n\033[00m");
}

/**
* \fn void affiche_chevalet_factice(int mode)
* \brief Affichage de 14/15 tuiles factices
* \param mode 1 sans 15 ème tuile, 2 avec.
*/
void affiche_chevalet_factice(int mode){

  int i;
  printf("\033[1;32m\t\b\t1\t2\t3\t4\t5\t6\t7\t\033[00m");
  printf("\n\t------------------------------------------------------\n");

  for(i = 0;i < N_CHEV;i++){

    if(i == 0)
      printf("\t|");
    if(i == 14 && mode == 2)
      printf("--------------->");

    if(mode == 1)                // Cas d'affichage où la tuile a été supprimée
      printf("\t");
    else{                        // Cas d'affichage pour une tuile quelconque
        printf("* \033[34;47m__\033[00m\t");
        if(i == 6)
          printf("\b\b\b|");
        if(i == 13)
          printf("\b\b\b|");
    }
    if(i == 6 && mode == 1)
      printf("\n\t|\t\t\t\t\t\t\t\b\b\b|\n\t|");
    else if(i == 6 && mode == 2)
      printf("\n\t|\t\t\t\t\t\t\t\b\b\b| NOUVELLE TUILE \033[1;32m15\033[00m\n\t|");
  }
  printf("\n\t------------------------------------------------------\n");
  printf("\033[1;32m\t\b\t8\t9\t10\t11\t12\t13\t14\n\033[00m");
}

/**
* \fn void affiche_sommet_reseau(t_tuile * tuile)
* \brief Affichage de la tuile du sommet d'une pile, la tuile provient du serveur
* \param tuile Le sommet de la pile
*/
void affiche_sommet_reseau(t_tuile * tuile){

  if(tuile == NULL)
    printf("* \033[34;47m__\033[00m\t");
  else{
    if(tuile->nbr < 9){
      printf("%i ",(tuile->nbr)+1);
      switch (tuile->clr){
        case jaune: printf("\033[34;43m__\033[00m\t");break;
        case rouge: printf("\033[34;41m__\033[00m\t");break;
        case noire: printf("\033[34;40m__\033[00m\t");break;
        case bleu:  printf("\033[34;44m__\033[00m\t");break;
      }
    }
    else{
      printf("%i",(tuile->nbr)+1);
      switch (tuile->clr){
        case jaune: printf("\033[34;43m__\033[00m\t");break;
        case rouge: printf("\033[34;41m__\033[00m\t");break;
        case noire: printf("\033[34;40m__\033[00m\t");break;
        case bleu:  printf("\033[34;44m__\033[00m\t");break;
      }
    }
  }
}

/**
* \fn void affiche_piles_reseau(t_tuile * okey,t_tuile * sommet_p1,t_tuile * sommet_p2,t_tuile * sommet_p3,t_tuile * sommet_p4)
* \brief Affichage des sommets des piles et de la tuile Okey
* \param okey La tuile Okey
* \param sommet_p1 La tuile sommet de la pile 1
* \param sommet_p2 La tuile sommet de la pile 2
* \param sommet_p3 La tuile sommet de la pile 3
* \param sommet_p4 La tuile sommet de la pile 4
*/
void affiche_piles_reseau(t_tuile * okey,t_tuile * sommet_p1,t_tuile * sommet_p2,t_tuile * sommet_p3,t_tuile * sommet_p4){

  printf("\n\t");
  affiche_sommet_reseau(sommet_p1);
  printf("\t\t\t\t\t");
  affiche_sommet_reseau(sommet_p2);

  // Cas d'affichage pour éviter d'espacer les nombres à 2 chiffres
  printf("\n\t\t\t   OKEY\tPIOCHE\n\t\t\t   ");

  if(okey->nbr < 9){
    printf("%i ",(okey->nbr)+1);
    switch (okey->clr){
      case jaune: printf("\033[34;43m__\033[00m\t");break;
      case rouge: printf("\033[34;41m__\033[00m\t");break;
      case noire: printf("\033[34;40m__\033[00m\t");break;
      case bleu:  printf("\033[34;44m__\033[00m\t");break;
    }
  }
  else{
    printf("%i",(okey->nbr)+1);
    switch (okey->clr){
      case jaune: printf("\033[34;43m__\033[00m\t");break;
      case rouge: printf("\033[34;41m__\033[00m\t");break;
      case noire: printf("\033[34;40m__\033[00m\t");break;
      case bleu:  printf("\033[34;44m__\033[00m\t");break;
    }
  }

  printf("\033[34;47m__\033[00m  \033[34;47m__\033[00m\n\n\t");
  affiche_sommet_reseau(sommet_p3);
  printf("\t\t\t\t\t");
  affiche_sommet_reseau(sommet_p4);
  printf("\n\n");

}


/**
* \fn void tuile_to_int(t_tuile * tuile,int * entier)
* \brief Convertit une tuile en une donnée sous forme d'entier
* \param tuile Une tuile quelconque
* \param entier Un entier
*/
void tuile_to_int(t_tuile * tuile,int * entier){

  if(tuile->clr == jaune){
    if(tuile->nbr == V_DEL)
      *entier = 14;
    else if(tuile->nbr == NO_VALUE)
      *entier = 15;
    else
      *entier = tuile->nbr + 1;
  }
  else if(tuile->clr == rouge && tuile->nbr != 13){
    if(tuile->nbr == V_DEL)
      *entier = 29;
    else if(tuile->nbr == NO_VALUE)
      *entier = 30;
    else
      *entier = tuile->nbr + 16;
  }
  else if(tuile->clr == noire && tuile->nbr != 13){
    if(tuile->nbr == V_DEL)
      *entier = 44;
    else if(tuile->nbr == NO_VALUE)
      *entier = 45;
    else
      *entier = tuile->nbr + 31;
  }
  else if(tuile->clr == bleu){
    if(tuile->nbr == V_DEL)
      *entier = 59;
    else if(tuile->nbr == NO_VALUE)
      *entier = 60;
    else
      *entier = tuile->nbr + 46;
  }
  else if(tuile->clr == rouge && tuile->nbr == 13)
    *entier = 61;
  else if(tuile->clr == noire && tuile->nbr == 13)
    *entier = 62;
}

/**
* \fn void int_to_tuile(t_tuile * tuile,int * entier)
* \brief Interprète et convertit un entier en tuile
* \param tuile Une tuile quelconque
* \param entier Un entier
*/
void int_to_tuile(t_tuile * tuile,int * entier){

  if(*entier >= 1 && *entier <= 13){
    tuile->clr = jaune;
    tuile->nbr = *entier - 1;
  }
  else if(*entier >= 16 && *entier <= 28){
    tuile->clr = rouge;
    tuile->nbr = *entier - 16;
  }
  else if(*entier >= 31 && *entier <= 43){
    tuile->clr = noire;
    tuile->nbr = *entier - 31;
  }
  else if(*entier >= 46 && *entier <= 58){
    tuile->clr = bleu;
    tuile->nbr = *entier - 46;
  }
  else if(*entier == 61){
    tuile->clr = rouge;
    tuile->nbr = 13;
  }
  else if(*entier == 62){
    tuile->clr = noire;
    tuile->nbr = 13;
  }
  else if(*entier == 14){
    tuile->clr = jaune;
    tuile->nbr = V_DEL;
  }
  else if(*entier == 15){
    tuile->clr = jaune;
    tuile->nbr = NO_VALUE;
  }
  else if(*entier == 29){
    tuile->clr = rouge;
    tuile->nbr = V_DEL;
  }
  else if(*entier == 30){
    tuile->clr = rouge;
    tuile->nbr = NO_VALUE;
  }
  else if(*entier == 44){
    tuile->clr = noire;
    tuile->nbr = V_DEL;
  }
  else if(*entier == 45){
    tuile->clr = noire;
    tuile->nbr = NO_VALUE;
  }
  else if(*entier == 59){
    tuile->clr = bleu;
    tuile->nbr = V_DEL;
  }
  else if(*entier == 60){
    tuile->clr = bleu;
    tuile->nbr = NO_VALUE;
  }
}

/**
* \fn void affiche_1_factice(t_tuile * okey,t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,int num_joueur)
* \brief Affichage des sommets des piles et de la tuile Okey en fonction du numéro du joueur
* \param okey La tuile Okey
* \param sommet_J1 La tuile sommet de la pile 1
* \param sommet_J2 La tuile sommet de la pile 2
* \param sommet_J3 La tuile sommet de la pile 3
* \param sommet_J4 La tuile sommet de la pile 4
* \param num_joueur Le numéro du joueur
*/
void affiche_1_factice(t_tuile * okey,t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,int num_joueur){

  if(num_joueur == 1)
    affiche_piles_reseau(okey,sommet_J3,sommet_J2,sommet_J4,sommet_J1);
  else if(num_joueur == 1)
    affiche_piles_reseau(okey,sommet_J4,sommet_J3,sommet_J1,sommet_J2);
  else if(num_joueur == 1)
    affiche_piles_reseau(okey,sommet_J1,sommet_J4,sommet_J2,sommet_J3);
  else if(num_joueur == 1)
    affiche_piles_reseau(okey,sommet_J2,sommet_J1,sommet_J3,sommet_J4);
}

/**
* \fn void tour_1_client(SOCKET csock,t_tuile * joueur[N_CHEV],t_tuile * okey,t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,int num_joueur)
* \brief Réalise le tour 1 côté client
* \param csock
* \param joueur[N_CHEV] Chevalet du joueur
* \param okey La tuile Okey
* \param sommet_J1 La tuile sommet de la pile 1
* \param sommet_J2 La tuile sommet de la pile 2
* \param sommet_J3 La tuile sommet de la pile 3
* \param sommet_J4 La tuile sommet de la pile 4
* \param num_joueur Le numéro du joueur
*/
void tour_1_client(SOCKET csock,t_tuile * joueur[N_CHEV],t_tuile * okey,t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,int num_joueur){
  /* Caractère pour faire une pause dans le programme */
  char pause;

  /* Détermine la tuile à enlever pour le joueur qui commence la partie en premier */
  int num_tuile_dep;

  /* Test si le chevalet du joueur est gagnant ou non */
  int issue_partie = 0;

  /* Détermine le choix de tri ou non */
  int tri_choix;

  /* Entiers de conversion de donnée */
  int * val1,val2;

  /* Tableau d'entiers de conversion de donnée */
  int * tab[N_CHEV],tab2[N_CHEV];

  /* Entiers pour valider le début de tour */
  int reponse,demande = 1;

  /* Indice */
  int i;

  for (i = 0; i < N_CHEV; i++)
    tab[i] = malloc(sizeof(int));

  /* Puis on retire une tuile du joueur qui commence la partie est on vérifie si son chevalet est gagnant ou non (Situation très rare) */
  printf("\n\nCHOIX : RETIRER UN NUMERO DE TUILE (1 à 15) ? ");
  scanf("%i",&num_tuile_dep);
  printf("\n");
  send(csock,num_tuile_dep,sizeof(num_tuile_dep),0);

  /* Reçoit le chevalet */
  recv(csock,tab2,sizeof(tab2),0);
  for (i = 0; i < N_CHEV; i++){
    *tab[i] = tab2[i];
    int_to_tuile(joueur[i],tab[i]);
  }
  /* Reçoit le sommet de la pile 2*/
  recv(csock,val2,sizeof(val2),0);
  *val1 = val2;
  int_to_tuile(sommet_J2,val1);

  affiche_piles_reseau(okey,sommet_J4,sommet_J3,sommet_J1,sommet_J2);
  affiche_chevalet(joueur,N_CHEV);

  tri_choix = choix_tri(joueur);
  if(tri_choix == 2)
    affiche_chevalet(joueur,N_CHEV);
  else if(tri_choix == 1){
    do{
      printf("CHOIX : CONTINUER TRI MANUEL(1) OU ARRETER(0) ? ");
      scanf("%i",&tri_choix);
      if(tri_choix == 1)
        tri_manuel(joueur);
      }while(tri_choix == 1);
  }
  /* On envoit le chevalet trié */
  for (i = 0;i < N_CHEV; i++){
    tuile_to_int(joueur[i],tab[i]);
    tab2[i] = *tab[i];
  }
  send(csock,tab2,sizeof(tab2),0);

  for (i = 0; i < N_CHEV; i++)
    free(tab[i]);

  printf("\nENTRER POUR CONTINUER\n");
  pause = getchar();
  while(getchar() != '\n');

  if(send(csock,demande,sizeof(demande), 0)!= SOCKET_ERROR)
    recv(csock,reponse,sizeof(reponse), 0);
}

/**
* \fn int tour_1_serveur(SOCKET ssock,t_tuile * joueur2[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J2_p2[N_CHEV],t_tuile * okey,int num_joueur)
* \brief Réalise le tour 1 côté serveur
* \param ssock
* \param joueur2[N_CHEV] Chevalet du joueur2
* \param okey La tuile Okey
* \param sommet_J1 La tuile sommet de la pile 1
* \param sommet_J2 La tuile sommet de la pile 2
* \param sommet_J3 La tuile sommet de la pile 3
* \param sommet_J4 La tuile sommet de la pile 4
* \param num_joueur Le numéro du joueur
*/
int tour_1_serveur(SOCKET ssock,t_tuile * joueur2[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J2_p2[N_CHEV],t_tuile * okey,int num_joueur){

  /* Détermine la tuile à enlever pour le joueur qui commence la partie en premier */
  int num_tuile_dep;

  /* Test si le chevalet du joueur est gagnant ou non */
  int issue_partie = 0;

  /* Entiers de conversion de donnée */
  int * val1,val2;

  /* Tableau d'entiers de conversion de donnée */
  int * tab[N_CHEV],tab2[N_CHEV];

  /* Entiers pour valider le début de tour */
  int reponse,demande = 1;

  /* Sommet de la pile du joueur2 */
  t_tuile * sommet = creer_tuile();

  /* Indice */
  int i;

  for (i = 0; i < N_CHEV; i++)
    tab[i] = malloc(sizeof(int));

  /* Puis on retire une tuile du joueur qui commence la partie est on vérifie si son chevalet est gagnant ou non (Situation très rare) */
  affiche_plateau(okey,pile_J4,pile_J3,pile_J1,pile_J2);
  affiche_chevalet_factice(2);

  while(recv(ssock,num_tuile_dep,sizeof(num_tuile_dep),0) == SOCKET_ERROR){
    affiche_plateau(okey,pile_J4,pile_J3,pile_J1,pile_J2);
    affiche_chevalet_factice(2);
    sleep(1);
    printf(".");
    sleep(1);
    affiche_plateau(okey,pile_J4,pile_J3,pile_J1,pile_J2);
    affiche_chevalet_factice(2);
    printf(". .");
    sleep(1);
    affiche_plateau(okey,pile_J4,pile_J3,pile_J1,pile_J2);
    affiche_chevalet_factice(2);
    sleep(1);
    printf(". . .");
    sleep(1);
  }

  empile_enr_tuile(joueur2,J2_p2,pile_J2,N_CHEV,num_tuile_dep-1);
  affiche_plateau(okey,pile_J4,pile_J3,pile_J1,pile_J2);
  affiche_chevalet_factice(1);

  /* Envoit le chevalet */
  for (i = 0;i < N_CHEV; i++){
    tuile_to_int(joueur2[i],tab[i]);
    tab2[i] = *tab[i];
  }
  send(ssock,tab2,sizeof(tab2),0);

  /* Envoit le sommet de la pile 2 */
  sommet_pile(pile_J2,&sommet);
  tuile_to_int(sommet,val1);
  val2 = *val1;
  send(ssock,val2,sizeof(val2),0);

  issue_partie = regle_combinaison(joueur2,okey);
  if(issue_partie == 1){
    printf("\nLe joueur %i a gagné la partie\n",num_joueur);
    return num_joueur;
  }
  /* Le tri a été reçu*/
  recv(ssock,tab2,sizeof(tab2),0);
  for (i = 0; i < N_CHEV; i++){
    *tab[i] = tab2[i];
    int_to_tuile(joueur2[i],tab[i]);
  }

  for (i = 0; i < N_CHEV; i++)
    free(tab[i]);

  detruire_tuile(&sommet,taille_tuile(&sommet,sizeof(sommet)));

  if(recv(ssock,reponse,sizeof(reponse), 0)!= SOCKET_ERROR)
    send(ssock,demande,sizeof(demande), 0);

  return issue_partie;
}

/**
* \fn int debut_partie_serveur(SOCKET ssock,t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur)
* \brief Réalise le début de la partie côté serveur
* \param ssock
* \param joueur1
* \param joueur2
* \param joueur3
* \param joueur4
* \param J1_p1
* \param J2_p2
* \param J3_p3
* \param J4_p4
* \param pile_J1
* \param pile_J2
* \param pile_J3
* \param pile_J4
* \param num_joueur le numéro du joueur de 1 à 4
* \param okey la tuile okey
* \param num_joueur Le numéro du joueur
*/
int debut_partie_serveur(SOCKET ssock,t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur){

  /* Test si le chevalet du joueur est gagnant ou non */
  int issue_partie = 0;

  /* Sommet de la pile du joueur ayant joué */
  t_tuile * sommet = creer_tuile();

  /* Entiers de conversion de donnée */
  int * val1,val2;

  /* Entiers pour valider le début de tour */
  int reponse,demande = 1;

  /* DEBUT DE PARTIE */
  printf("\n\nTour 1\n");

  /* Determine le joueur qui va débuter la partie en premier */
  if(num_joueur == 1){
    premier_tour_partie(joueur1,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
    issue_partie = tour_1_joueur(joueur1,joueur2,joueur3,joueur4,pile_J1,pile_J2,pile_J3,pile_J4,J1_p1,J2_p2,J3_p3,J4_p4,okey,1);
    sommet_pile(pile_J1,&sommet);
    tuile_to_int(sommet,val1);
    val2 = *val1;
    send(ssock,val2,sizeof(val2),0);
  }
  else if(num_joueur == 2){
    issue_partie = tour_1_serveur(ssock,joueur2,pile_J1,pile_J2,pile_J3,pile_J4,J2_p2,okey,num_joueur);
  }
  else if(num_joueur == 3){
    premier_tour_partie(joueur3,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
    issue_partie = tour_1_IA(joueur1,joueur2,joueur3,joueur4,pile_J1,pile_J2,pile_J3,pile_J4,J1_p1,J2_p2,J3_p3,J4_p4,okey,3);
    sommet_pile(pile_J3,&sommet);
    tuile_to_int(sommet,val1);
    val2 = *val1;
    send(ssock,val2,sizeof(val2),0);
  }
  else if(num_joueur == 4){
    premier_tour_partie(joueur4,pile_J1,pile_J2,pile_J3,pile_J4,okey,num_joueur);
    issue_partie = tour_1_IA(joueur1,joueur2,joueur3,joueur4,pile_J1,pile_J2,pile_J3,pile_J4,J1_p1,J2_p2,J3_p3,J4_p4,okey,4);
    sommet_pile(pile_J4,&sommet);
    tuile_to_int(sommet,val1);
    val2 = *val1;
    send(ssock,val2,sizeof(val2),0);
  }
  sleep(2);
  printf("FIN DU TOUR 1\n");
  if(send(ssock,demande,sizeof(demande), 0)!= SOCKET_ERROR)
    recv(ssock,reponse,sizeof(reponse), 0);

  detruire_tuile(&sommet,taille_tuile(&sommet,sizeof(sommet)));

  if(reponse != 1)
    return NO_VALUE;
  system("clear");
  return issue_partie;
}

/**
* \fn debut_partie_client(SOCKET csock,t_tuile * joueur[N_CHEV],t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,t_tuile * okey,int num_joueur)
* \brief Réalise le début de la partie côté client
* \param csock
* \param joueur
* \param okey La tuile Okey
* \param sommet_J1 La tuile sommet de la pile 1
* \param sommet_J2 La tuile sommet de la pile 2
* \param sommet_J3 La tuile sommet de la pile 3
* \param sommet_J4 La tuile sommet de la pile 4
* \param num_joueur Le numéro du joueur
*/
int debut_partie_client(SOCKET csock,t_tuile * joueur[N_CHEV],t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,t_tuile * okey,int num_joueur){

  /* Test si le chevalet du joueur est gagnant ou non */
  int issue_partie = 0;

  /* Entiers de conversion de donnée */
  int * val1,val2;

  /* Entiers pour valider le début de tour */
  int reponse,demande = 1;

  /* DEBUT DE PARTIE */
  printf("\n\nTour 1\n");

  /* Determine le joueur qui va débuter la partie en premier */
  if(num_joueur == 1){
    affiche_1_factice(okey,sommet_J1,sommet_J2,sommet_J3,sommet_J4,num_joueur);
    affiche_chevalet_factice(2);
    while(recv(csock,val2,sizeof(val2),0) == SOCKET_ERROR){
      affiche_1_factice(okey,sommet_J1,sommet_J2,sommet_J3,sommet_J4,num_joueur);
      affiche_chevalet_factice(2);
      sleep(1);
      printf(".");
      sleep(1);
      affiche_1_factice(okey,sommet_J1,sommet_J2,sommet_J3,sommet_J4,num_joueur);
      affiche_chevalet_factice(2);
      printf(". .");
      sleep(1);
      affiche_1_factice(okey,sommet_J1,sommet_J2,sommet_J3,sommet_J4,num_joueur);
      affiche_chevalet_factice(2);
      sleep(1);
      printf(". . .");
      sleep(1);
    }
    *val1 = val2;
    int_to_tuile(sommet_J1,val1);
    affiche_1_factice(okey,sommet_J1,sommet_J2,sommet_J3,sommet_J4,num_joueur);
    affiche_chevalet_factice(1);
  }
  else if(num_joueur == 2){
    tour_1_client(csock,joueur,okey,sommet_J1,sommet_J2,sommet_J3,sommet_J4,num_joueur);
  }
  else if(num_joueur == 3){
    affiche_1_factice(okey,sommet_J1,sommet_J2,sommet_J3,sommet_J4,num_joueur);
    affiche_chevalet_factice(2);
    while(recv(csock,val2,sizeof(val2),0) == SOCKET_ERROR){
      affiche_1_factice(okey,sommet_J1,sommet_J2,sommet_J3,sommet_J4,num_joueur);
      affiche_chevalet_factice(2);
      sleep(1);
      printf(".");
      sleep(1);
      affiche_1_factice(okey,sommet_J1,sommet_J2,sommet_J3,sommet_J4,num_joueur);
      affiche_chevalet_factice(2);
      printf(". .");
      sleep(1);
      affiche_1_factice(okey,sommet_J1,sommet_J2,sommet_J3,sommet_J4,num_joueur);
      affiche_chevalet_factice(2);
      sleep(1);
      printf(". . .");
      sleep(1);
    }
    *val1 = val2;
    int_to_tuile(sommet_J3,val1);
    affiche_1_factice(okey,sommet_J1,sommet_J2,sommet_J3,sommet_J4,num_joueur);
    affiche_chevalet_factice(1);
  }
  else if(num_joueur == 4){
    affiche_1_factice(okey,sommet_J1,sommet_J2,sommet_J3,sommet_J4,num_joueur);
    affiche_chevalet_factice(2);
    while(recv(csock,val2,sizeof(val2),0) == SOCKET_ERROR){
      affiche_1_factice(okey,sommet_J1,sommet_J2,sommet_J3,sommet_J4,num_joueur);
      affiche_chevalet_factice(2);
      sleep(1);
      printf(".");
      sleep(1);
      affiche_1_factice(okey,sommet_J1,sommet_J2,sommet_J3,sommet_J4,num_joueur);
      affiche_chevalet_factice(2);
      printf(". .");
      sleep(1);
      affiche_1_factice(okey,sommet_J1,sommet_J2,sommet_J3,sommet_J4,num_joueur);
      affiche_chevalet_factice(2);
      sleep(1);
      printf(". . .");
      sleep(1);
    }
    *val1 = val2;
    int_to_tuile(sommet_J4,val1);
    affiche_1_factice(okey,sommet_J1,sommet_J2,sommet_J3,sommet_J4,num_joueur);
    affiche_chevalet_factice(1);
  }
  sleep(2);
  printf("FIN DU TOUR 1\n");
  if(recv(csock,reponse,sizeof(reponse), 0)!= SOCKET_ERROR)
    send(csock,demande,sizeof(demande), 0);
  if(reponse != 1)
    return NO_VALUE;
  system("clear");
  return issue_partie;
}
