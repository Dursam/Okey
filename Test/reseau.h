/**
* \file reseau.h
* \brief Fichier contenant les fonctions de reseau
* \author Samuel DURAN
* \version 1.0
* \date 30 Janvier 2020
*/

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

/**
* \fn SOCKET serveur (SOCKET sock)
* \brief Ouverture d'un port, le serveur attends une demande de connexion
*/
SOCKET serveur (SOCKET sock);

/**
* \fn SOCKET client (SOCKET sock)
* \brief Connexion d'un client au près d'un serveur, entre son adresse IP
*/
SOCKET client (SOCKET sock);

/**
* \fn void deconnexion (SOCKET sock)
* \brief Déconnecte une socket réseau, client ou serveur
*/
void deconnexion (SOCKET sock);

/**
* \fn void affiche_chevalet_IA(t_tuile * jeu[], int taille)
* \brief Affichage des 14/15 tuiles cachés du chevalet d'une IA
*/
void affiche_chevalet_IA(t_tuile * jeu[],int taille);

/**
* \fn void affiche_chevalet_factice(int mode)
* \brief Affichage de 14/15 tuiles factices
*/
void affiche_chevalet_factice(int mode);

/**
* \fn void affiche_sommet_reseau(t_tuile * tuile)
* \brief Affichage de la tuile du sommet d'une pile, la tuile provient du serveur
*/
void affiche_sommet_reseau(t_tuile * tuile);

/**
* \fn void affiche_piles_reseau(t_tuile * okey,t_tuile * sommet_p1,t_tuile * sommet_p2,t_tuile * sommet_p3,t_tuile * sommet_p4)
* \brief Affichage des sommets des piles et de la tuile Okey
*/
void affiche_piles_reseau(t_tuile * okey,t_tuile * sommet_p1,t_tuile * sommet_p2,t_tuile * sommet_p3,t_tuile * sommet_p4);
/**
* \fn void affiche_chevalet_IA(t_tuile * jeu[], int taille)
* \brief Affichage des 14/15 tuiles cachés du chevalet d'une IA
*/
void affiche_chevalet_IA(t_tuile * jeu[],int taille);

/**
* \fn void tuile_to_int(t_tuile * tuile,int * entier)
* \brief Convertit une tuile en une donnée sous forme d'entier
*/
void tuile_to_int(t_tuile * tuile,int * entier);

/**
* \fn void int_to_tuile(t_tuile * tuile,int * entier)
* \brief Interprète et convertit un entier en tuile
*/
void int_to_tuile(t_tuile * tuile,int * entier);

/**
* \fn void affiche_1_factice(t_tuile * okey,t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,int num_joueur)
* \brief Affichage des sommets des piles et de la tuile Okey en fonction du numéro du joueur
*/
void affiche_1_factice(t_tuile * okey,t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,int num_joueur);

/**
* \fn void tour_1_client(SOCKET csock,t_tuile * joueur[N_CHEV],t_tuile * okey,t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,int num_joueur)
* \brief Réalise le tour 1 côté client
*/
void tour_1_client(SOCKET csock,t_tuile * joueur[N_CHEV],t_tuile * okey,t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,int num_joueur);

/**
* \fn int tour_1_serveur(SOCKET ssock,t_tuile * joueur2[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J2_p2[N_CHEV],t_tuile * okey,int num_joueur)
* \brief Réalise le tour 1 côté serveur
*/
int tour_1_serveur(SOCKET ssock,t_tuile * joueur2[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J2_p2[N_CHEV],t_tuile * okey,int num_joueur);

/**
* \fn int debut_partie_serveur(SOCKET ssock,t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur)
* \brief Réalise le début de la partie côté serveur
*/
int debut_partie_serveur(SOCKET ssock,t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur);

/**
* \fn int debut_partie_client(SOCKET csock,t_tuile * joueur[N_CHEV],t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,t_tuile * okey,int num_joueur)
* \brief Réalise le début de la partie côté client
*/
int debut_partie_client(SOCKET csock,t_tuile * joueur[N_CHEV],t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,t_tuile * okey,int num_joueur);

#endif
