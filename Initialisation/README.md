# Fonctions d'initialisation (17)
## Samuel DURAN (Dursam)


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

4. Donne une tuile au hasard à un des 4 joueurs
```
int demarrage(t_tuile * jeu[N_T], t_tuile * j1[N_CHEV],t_tuile * j2[N_CHEV],t_tuile * j3[N_CHEV],t_tuile * j4[N_CHEV]);
```

5. Distribue 14 tuiles à un joueur
```
void distribution_joueur(t_tuile * jeu[N_T], t_tuile * joueur[N_CHEV]);
```

6. Distribue une tuile parmi le jeu des 106 tuiles, au hasard
```
t_tuile distribution_pioche(t_tuile * jeu[N_T]);
```

7. Alloue une mémoire dynamique à une tuile
```
t_tuile * creer_tuile(void);
```

8. Renvoie la taille des tuiles alloués
```
int taille_tuile(t_tuile * jeu[],int taille_jeu);
```

9. Initialise la pile
```
void init_pile(t_pile * pile);
```

10. Vérifie si la pile est vide
```
int pile_vide(t_pile * pile);
```

11. Empile une tuile de la pile
```
void empiler(t_pile * pile,t_tuile * t);
```

12. Retire une tuile de la pile
```
void depiler(t_pile * pile);
```

13. Récupère la tuile du sommet de la pile
```
void sommet_pile(t_pile * pile,t_tuile ** c);
```

14. Compte le nombre d'élément d'une tuile
```
int compte_element(t_pile * pile);
```

15. Initialise un tableau de struture de tuile pour enregistrer les tuiles qui seront empilés
```
void init_enr_tuile(t_tuile * enr[],int taille);
```

16. Créer une tuile, lui affecte une valeur puis l'empile sur une pile
```
void empile_enr_tuile(t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pile,int taille,int numero);
```

17. Dépile toutes les piles de tuiles, utilisé pour finir la partie
```
void depiler_toutes_tuiles(t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4);
```
