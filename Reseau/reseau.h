/**
* \file reseau.h
* \brief Fichier contenant les fonctions de reseau
* \author Samuel DURAN
* \version 1.0
* \date 30 Janvier 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h> /* gethostbyname */
#include <ifaddrs.h> /*get ip addr */

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
#define PORT 15000

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

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
