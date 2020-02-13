#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#include <string.h>


#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
#define PORT 4242
#define errno 0


typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;


int main(){

  //Création du socket
  SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock == INVALID_SOCKET){
      perror("socket()");
      exit(errno);
  }

  //Connection au serveur
  struct hostent *hostinfo = NULL;
  SOCKADDR_IN sin = { 0 }; /* initialise la structure avec des 0 */
  char hostname[16] = "172.18.41.31";
  printf("Entrez l'ip du serveur: ");
   scanf("%[^\n]s\n", hostname);
  hostinfo = gethostbyname(hostname); /* on récupère les informations de l'hôte auquel on veut se connecter */
  if (hostinfo == NULL){ /* l'hôte n'existe pas */
      fprintf (stderr, "Unknown host %s.\n", hostname);
      exit(EXIT_FAILURE);
  }

  sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr; /* l'adresse se trouve dans le champ h_addr de la structure hostinfo */
  sin.sin_port = htons(PORT); /* on utilise htons pour le port */
  sin.sin_family = AF_INET;

  if(connect(sock,(SOCKADDR *) &sin, sizeof(SOCKADDR)) == SOCKET_ERROR){
      perror("connect()");
      exit(errno);
  }
  else{
    printf("Connection établie\n");
  }


  //Envoie de données
  char buffer[1024];
  printf("Tapez les données à envoyer\n");
  scanf("%[^\n]s\n", buffer);
  printf("Envoi de %s...\n", buffer);
  if(send(sock, buffer, strlen(buffer), 0) < 0)
  {
      perror("send()");
      exit(errno);
  }
  else{
    printf("Données envoyées avec succès\n");
  }


  //Fermeture du SOCKET
  closesocket(sock);
  return 1;
}
