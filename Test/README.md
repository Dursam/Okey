# Test et création de fonctions
## Samuel DURAN (Dursam) et Valentin GIROD (Guarmanda)
### A. Les constantes (5):
1. Nombre de tuiles du jeu
```
# define N_T 106
```

2. Nombre de tuile d'un chevalet
```
#define N_CHEV 15
```

3. Valeur d'une tuile de joker
```
#define V_OKEY 13
```

4. Valeur d'une tuile supprimée
```
#define V_DEL 100
```

5. Valeur tampon qui sert pour la fonction combinaison suite entier
```
#define NO_VALUE 99
```

### Les structures (4):
1. Définition de la couleur
```
typedef enum {jaune,rouge,noire,bleu} t_couleur;
```

2. Définition d'une tuile
```
typedef struct s_tuile { int nbr; t_couleur clr; } t_tuile;
```

3. Définition d'un élément d'une pile, soit une tuile
```
typedef struct s_element { t_tuile * tuile; struct s_element * suivant;} t_element;
```

4. Définition d'une pile de tuile
```
typedef struct s_pile { t_element * premier ;} t_pile;
```

### Les fonctions (37)
#### Fichier init_structure (9)
1. Initialise le jeu de 106 tuiles
```
void init_tuile(t_tuile * jeu[N_T]);
```

2. Alloue une mémoire dynamique à un chevalet
```
void creer_chevalet(t_tuile * joueur[],int taille);
```

3. Libère la mémoire d'une tuile ou de plusieurs tuiles d'un tableau de structure
```
void detruire_tuile(t_tuile * jeu[],int taille);
```

4. Affiche les tuiles une par une
```
void affiche_chaque_tuile(t_tuile * jeu[],int taille);
```

5. Donne une tuile au hasard à un des 4 joueurs
```
demarrage(t_tuile * jeu[N_T], t_tuile * j1[N_CHEV],t_tuile * j2[N_CHEV],t_tuile * j3[N_CHEV],t_tuile * j4[N_CHEV]);
```

6. Distribue 14 tuiles à un joueur
```
void distribution_joueur(t_tuile * jeu[N_T], t_tuile * joueur[N_CHEV]);
```

7. Distribue une tuile parmi le jeu des 106 tuiles, au hasard
```
t_tuile distribution_pioche(t_tuile * jeu[N_T]);
```

8. Alloue une mémoire dynamique à une tuile
```
t_tuile * creer_tuile(void);
```

9. Renvoie la taille des tuiles alloués
```
int taille_tuile(t_tuile * jeu[],int taille_jeu);
```

#### Fichier init_pile (6)
10. Initialise la pile
```
void init_pile(t_pile * pile);
```

11. Vérifie si la pile est vide
```
int pile_vide(t_pile * pile);
```

12. Empile une tuile de la pile
```
void empiler(t_pile * pile,t_tuile * t);
```

13. Retire une tuile de la pile
```
void depiler(t_pile * pile);
```

14. Récupère la tuile du sommet de la pile
```
void sommet_pile(t_pile * pile,t_tuile ** c);
```

15. Compte le nombre d'élément d'une tuile
```
int compte_element(t_pile * pile);
```

#### Fichier affichage_tuile (5)
16. Affichage des 14/15 tuiles du chevalet
```
void affiche_chevalet(t_tuile * jeu[],int taille);
```

17. Affichage du sommet d'une pile
```
void affiche_sommet_pile(t_pile * pile);
```

18. Affichage du sommet des piles de tout les joueurs
```
void affiche_pile(t_pile * p1,t_pile * p2,t_pile * p3,t_pile * p4);
```

19. Tri manuel d'un chevalet de tuiles
```
void tri_manuel(t_tuile * chevalet[N_CHEV]);
```

20. Tri rapide d'un chevalet de tuiles
```
void tri_rapide(t_tuile * chevalet[],int i,int j);
```

#### Fichier combinaison_couleur (3)
21. Vérifie les tuiles supprimer ou non
```
void affiche_tuile(t_tuile * jeu[],int taille);
```

22. Compte le nombre de couleur différente d'une tuile
```
int compte_coul_diff(int tab_coul[4]);
```

23. Vérifie les ensembles de combinaisons de 3 ou 4 couleurs
```
void combinaison_coul(t_tuile * chev[]);
```

#### Fichier combinaison_suite (1)
24. Vérifie les ensembles de combinaisons à partir de 3 suites d'entiers
```
void combinaison_suite(t_tuile * chev[]);
```

#### Fichier selection_tuile (4)
25. Initialise un tableau de struture de tuile pour enregistrer les tuiles qui seront empilés
```
void init_enr_tuile(t_tuile * enr[],int taille);
```

26. Creer une tuile, lui affecte une valeur puis l'empile sur une pile
```
void test_enr_tuile(t_tuile * jeu[N_T],t_tuile * enr[],t_pile * pile,int taille);
```

27. Creer une tuile, lui affecte une valeur puis l'empile sur une pile
```
void empile_enr_tuile(t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pile,int taille,int numero);
```

28. Permet de sélection une tuile soit de la pioche ou de la pile de gauche et retire une tuile du chevalet, version avec affiche_pile
```
void selection_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd);
```

#### Fichier partie (9)
29. Donne une valeur + 1 de la tuile retournée (le okey) à la tuile joker rouge ou noire posséder par le joueur
```
void valeur_okey(t_tuile * okey,t_tuile * joker);
```

30. Affichage du sommet des piles de tout les joueurs
```
void affiche_plateau(t_tuile * okey,t_pile * p1,t_pile * p2,t_pile * p3,t_pile * p4);
```

31. Commence le premier tour de la partie en fonction du joueur ayant reçu la tuile de demarrage
```
void premier_tour_partie(t_tuile * chevalet[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int dem);
```

32. Dépile toutes les piles de tuiles, utilisé pour finir la partie
```
void depiler_toutes_tuiles(t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4);
```

33. Vérifie si le chevalet est gagnant (return 1, 0 pour contraire) en utilisant les combinaisons de couleurs et de suite d'entier
```
int regle_combinaison(t_tuile * chevalet[N_CHEV],t_tuile * okey);
```

34. Laisse le choix au joueur de pouvoir faire un tri rapide, un tri manuel ou pas de tri
```
int choix_tri(t_tuile * chevalet[N_CHEV]);
```

35. Début de partie, réalise le premier tour complètement avec la tuile de démarrage et la tuile a retirée
```
void debut_partie(t_tuile * chevalet[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int dem);
```

36. Annonce de l'issue de la partie un vainqueur ou non
```
void issue_partie(int issue_joueur);
```

37. Permet de sélection une tuile soit de la pioche ou de la pile de gauche et retire une tuile du chevalet, version avec affiche plateau
```
selection_tuile_v2(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd);
```

38. Permet de vérifier si le jeu ne posséde plus aucune tuiles,return vrai (1) et faux (0)
```
int pioche_vide(t_tuile * jeu[N_T]);
```

39.Permet le déroulement de la partie, après que le première joueur commence. Retourne le numéro de joueur gagnant
```
int partie_en_cours(t_tuile * jeu[N_T] ,t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV] ,t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[] ,t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4 ,int num_joueur ,t_tuile * okey );
```
