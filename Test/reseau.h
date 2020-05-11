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

/**
* \fn void affiche_chevalet_IA(t_tuile * jeu[], int taille)
* \brief Affichage des 14/15 tuiles cachés du chevalet d'une IA
*/
void affiche_chevalet_IA(t_tuile * jeu[],int taille);

#endif
