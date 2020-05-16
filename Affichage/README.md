# Fonctions du jeu (31)
## Samuel DURAN (Dursam) et Valentin GIROD (Guarmanda)

1. Retourne le numéro de couleur
```
int colornum(int fg, int bg);
```

2. Transforme un nombre en une couleur ncurses
```
short curs_color(int fg);
```

3. Vérifie si le texte est déjà surligné
```
int is_bold(int fg);
```

4. Initialise les couleurs ncurses
```
void init_colorpairs(void);
```

5. Définit la couleur du texte et de son surlignage
```
void setcolor(int fg, int bg);
```

6. Définit la couleur du texte et de son surlignage
```
void setcolor(int fg, int bg);
```

7. Chargement de toutes les textures du jeu dans la mémoire
```
void loadImages(void);
```

8. Déchargement de toutes les textures du jeu
```
void unloadImages(void);
```

9. Met l'écran à jour
```
void faire_rendu(void);
```

10. Met le fond de la fenêtre en blanc
```
void fond_blanc(void);
```

11. Affiche du texte d'une certaine taille à des coordonnées données
```
void drawText (int , int , char *, int, int);
```

12. Affiche une image d'une certaine taille à des coordonnées données
```
void drawImage (int , int , char *, int, int );
```

13. Affiche la fenêtre
```
void showWindow(void);
```

14. Quitte la sdl
```
void quitter_sdl(void);
```

15. Initialise l'affichage sdl
```
void init_affichage();
```

16. Quitte l'affichage sdl
```
void quitter_affichage();
```

17. Récupère la taille du terminal
```
void taille_terminal(int lon,int lar);
```

18. Sélectionne une tuile
```
void selection_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd,t_tuile * okey);
```

19. Autorise la sélection d'une tuile
```
int select_tuile(int AutoriserFinTour);
```

20. Menu du serveur sous sdl
```
void menuServeur(char*ip);
```

21. Affiche le menu sous terminal
```
int afficher_menu(char menu[4][30], int taille);
```

22. Affiche les sauvegardes sous terminal
```
char * afficher_sauvegarde(int max_fichier);
```

23. Détecte les touches flèches sous terminal
```
int detecter_mouvement(float*x, float*y);
```

24. Affiche les règles
```
void afficher_regle(void);
```

25. Tri manuel d'un chevalet de tuiles
```
void tri_manuel(t_tuile * chevalet[N_CHEV]);
```

26. Tri rapide d'un chevalet de tuiles
```
void tri_rapide(t_tuile * chevalet[], int i, int j);
```

27. Laisse le choix au joueur de pouvoir faire un tri rapide, un tri manuel ou un pas de tri
```
int choix_tri(t_tuile * chevalet[N_CHEV]);
```

28. Affichage des 14/15 tuiles du chevalet
```
void affiche_chevalet(t_tuile * jeu[],int taille);
```

29. Affichage du sommet d'une pile
```
void affiche_sommet_pile(t_pile * pile, int nb_pile);
```

30. Affichage du sommet des piles de tout les joueurs, valeur du okey et une pioche
```
void affiche_piles(t_tuile * okey, t_pile * pfg, t_pile * pfd, t_pile * pg, t_pile * pd);
```

31. Affichage des 14/15 tuiles cachés du chevalet d'une IA
```
void affiche_chevalet_IA(t_tuile * jeu[],int taille);
```
