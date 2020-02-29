#include "./reseau.h"

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
#define errno 0
#define PORT 4242

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;


int main(){

  //obtention de l'adresse ip du serveur
  char hostbuffer[256];
  char *IPbuffer;
  struct hostent *host_entry;
  int hostname;

  // To retrieve hostname
  hostname = gethostname(hostbuffer, sizeof(hostbuffer));

  // To retrieve host information
  host_entry = gethostbyname(hostbuffer);

  // To convert an Internet network
  // address into ASCII string
  IPbuffer = inet_ntoa(*((struct in_addr*)
                         host_entry->h_addr_list[0]));

  printf("Hostname: %s\n", hostbuffer);
  printf("Host IP: %s\n", IPbuffer);


  //Création du socket

  SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock == INVALID_SOCKET){
      perror("socket()");
      exit(errno);
  }

  //Création de l'interface d'écoute
  SOCKADDR_IN sin = { 0 };
  sin.sin_addr.s_addr = htonl(INADDR_ANY); /* nous sommes un serveur, nous acceptons n'importe quelle adresse */
  sin.sin_family = AF_INET;
  sin.sin_port = htons(PORT);
  if(bind (sock, (SOCKADDR *) &sin, sizeof sin) == SOCKET_ERROR){
      perror("bind()");
      exit(errno);
  }

  //Ecoute et connexion clients
  if(listen(sock, 5) == SOCKET_ERROR){
    perror("listen()");
    exit(errno);
  }

  SOCKADDR_IN csin = { 0 };
  SOCKET csock;
  int sinsize = sizeof csin;
  printf("En attente de connection sur %d\n", AF_INET);
  csock = accept(sock, (SOCKADDR *)&csin, &sinsize);
  if(csock == INVALID_SOCKET){
      perror("accept()");
      exit(errno);
  }
  printf("Connection établie, en attente de données\n");
  char buffer[1024];
  recv(csock, buffer, sizeof(buffer), 0);
  printf("Données reçues: %s\n", buffer);
  //fermeture du socket
  closesocket(sock);
  closesocket(csock);


}
