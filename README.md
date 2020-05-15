 # Projet de L2 Informatique : Le jeu du Okey
## Membres du projet
Samuel DURAN (_Dursam_), Valentin GIROD (_Guarmanda_) et Taner CELIK (_tancel97_)

## Gestion de projet
Voici la [vue micro](https://trello.com/b/gQjKANUW/projet-okey) (15/05/2020)

Voici le [diagramme de Gantt](https://onedrive.live.com/View.aspx?resid=98EC20023F1E6EC2!116&authkey=!ADXCvBvONsHHCVo) (15/05/2020)

## Le jeu
- [x] Chevalet de 14/15 tuiles

- [x] Jeu de 106 tuiles

- [x] Pile de tuiles pour chaque joueur

- [x] Sélection d'une tuile

- [x] Piocher une tuile

- [x] Retourner une tuile et désigne le Okey

- [x] Tour d'un joueur ou d'une IA

- [x] Partie de jeu

- [x] Sauvegarde des scores

### Les règles

- [x] Combinaison de 3 ou 4 couleurs différentes d'une même tuile

- [x] Combinaison de 3 suites d'entiers ou plus de tuiles de même couleur

- [x] Sens du jeu en fonction du joueur qui débute la partie en premier

- [x] Système de points et scores

### L'interface graphique

- [X] Affichage du menu SDL

- [X] Affichage du menu terminal

- [x] Affichage du tour d'un joueur

- [x] Affichage d'une partie à 4 joueurs en local

- [x] Affichage du terminal

- [x] Affichage de la SDL

### Jeu en réseau

- [x] Préparation des sockets

- [x] Hébergement de partie

- [x] Connexion à une partie

- [ ] Échange des données de jeu

### Jeu contre l'ordinateur

- [x] Choix logique de l'IA à partir du chevalet

### Idées et recherches

- [ ] Choix logique de l'IA à partir de tout le jeu

## L'objectif du jeu

Règles du jeu :

Comment jouer :  

- Vous disposez d'un chevalet qui comporte 14 tuiles.
- Arrangez ces tuiles de sorte à ce que ceux-ci forment une suite de nombre de la même couleur ou une série d'une suite de nombre mais de couleurs différentes.
- Vous ne pouvez avoir de double dans une même suite ou série mais vous pouvez jouer une tuile que vous avez en double dans une autre suite ou série.
- Vous devez avoir minimum 3 tuiles par suite ou série.
- Vous devez utiliser toutes vos tuiles dans votre jeu pour avoir un chevalet gagnant.

Déroulement début/fin de tour :

- Prenez une tuile de la pioche ou ramassez la tuile de votre adversaire de gauche qui vient de défausser.

- A la fin de votre tour, défaussez une tuile ensuite quand vous avez fini votre tour, vous pouvez ranger votre chevalet.

- L'issue de la partie sera annoncée lorsqu'un joueur à fini son jeu ou lorsque la pioche est vide.

Système de points et condition de victoire :

- Chaque joueur commence avec 0 point
- Lorsqu’un joueur gagne une manche, il marque 1 point et les autres joueurs ne remportent pas de points
- Vous pouvez définir les points maximum à atteindre pour qu'un joueur gagne la partie

Tuiles Spéciales :

 - Au début de la manche, une tuile est retournée face visible. Celle qui la succède est le okey et remplace les deux tuiles joker du jeu.

Prenez votre temps et bonne partie ! 

