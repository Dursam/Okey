# Fonctions de réseau (3)
## Samuel DURAN (Dursam)


1. Ouverture d'un port, le serveur attends une demande de connexion
```
SOCKET serveur (SOCKET sock);
```

2. Connexion d'un client au près d'un serveur, entre son adresse IP
```
SOCKET client (SOCKET sock);
```

3. Déconnecte une socket réseau, client ou serveur
```
void deconnexion (SOCKET sock);
```
