
#include <reseau.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
#define PORT 4242
#define errno 0


typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;


void attendreConnection(int joueurs){
	printf("En attente de connection de %n joueurs", joueurs);
	//connec(joueurs);
}

int client(){

  //Création du socket
  SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock == INVALID_SOCKET){
      perror("socket()");
      exit(errno);
  }

  //Connection au serveur
  struct hostent *hostinfo = NULL;
  SOCKADDR_IN sin = { 0 }; /* initialise la structure avec des 0 */
  char hostname[32] = "ic2s120-12.univ-lemans.fr";
  printf("Entrez l'ip du serveur: ");
   //scanf("%[^\n]s\n", hostname);
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



int serveur(){

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
