#include <definitions.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h> /* gethostbyname */
#include <ifaddrs.h> /*get ip addr */

int client();
int serveur();
