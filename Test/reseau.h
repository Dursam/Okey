#ifndef _RESEAU_H_
#define _RESEAU_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
#define PORT 15000

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

#include <commun.h>

SOCKET serveur (SOCKET sock);
SOCKET client (SOCKET sock);
void deconnexion (SOCKET sock);

void affiche_chevalet_IA(t_tuile * jeu[],int taille);
void affiche_chevalet_factice(int mode);
void affiche_sommet_reseau(t_tuile * tuile);
void affiche_piles_reseau(t_tuile * okey,t_tuile * sommet_p1,t_tuile * sommet_p2,t_tuile * sommet_p3,t_tuile * sommet_p4);
/**
* \fn void affiche_chevalet_IA(t_tuile * jeu[], int taille)
* \brief Affichage des 14/15 tuiles cachés du chevalet d'une IA
*/
void affiche_chevalet_IA(t_tuile * jeu[],int taille);

void tuile_to_int(t_tuile * tuile,int * entier);

void int_to_tuile(t_tuile * tuile,int * entier);

void affiche_1_factice(t_tuile * okey,t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,int num_joueur);

void tour_1_client(SOCKET csock,t_tuile * joueur[N_CHEV],t_tuile * okey,t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,int num_joueur);

int tour_1_serveur(SOCKET ssock,t_tuile * joueur2[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J2_p2[N_CHEV],t_tuile * okey,int num_joueur);

int debut_partie_serveur(SOCKET ssock,t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur);

int debut_partie_client(SOCKET csock,t_tuile * joueur,t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,t_tuile * okey,int num_joueur);

#endif
