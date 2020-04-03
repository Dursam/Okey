#include <definitions.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h> /* gethostbyname */
#include <ifaddrs.h> /*get ip addr */
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
          else perror("Listen");
      }else perror("Bind");
  }else perror("Socket");
}

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
  } else perror("Connection");
}

void deconnexion (SOCKET sock){
  printf("Fermeture de la socket Client et Serveur\n");
  closesocket(sock);
}

/*
int client(){

  //Création du socket
  SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock == INVALID_SOCKET){
      perror("socket()");
      exit(errno);
  }

  //Connection au serveur
  struct hostent *hostinfo = NULL;
  SOCKADDR_IN sin = { 0 }; // initialise la structure avec des 0
  char hostname[32] = "ic2s120-12.univ-lemans.fr";
  printf("Entrez l'ip du serveur: ");
   //scanf("%[^\n]s\n", hostname);
  hostinfo = gethostbyname(hostname); // on récupère les informations de l'hôte auquel on veut se connecter
  if (hostinfo == NULL){ // l'hôte n'existe pas
      fprintf (stderr, "Unknown host %s.\n", hostname);
      exit(EXIT_FAILURE);
  }

  sin.sin_addr = *(IN_ADDR *) "192.168.0.1"; //l'adresse se trouve dans le champ h_addr de la structure hostinfo
  sin.sin_port = htons(PORT); // on utilise htons pour le port
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
  sin.sin_addr.s_addr = htonl(INADDR_ANY); // nous sommes un serveur, nous acceptons n'importe quelle adresse
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
*/
