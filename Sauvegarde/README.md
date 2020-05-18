# Fonctions de gestion de sauvegarde de fichier au format `ANNEE-MOIS-JOUR-MINUTES-SECONDES.txt` (7)
## Samuel DURAN (Dursam)


1. Créer une sauvegarde pour une partie
```
t_fichier * nom_fichier(void);
```

2. Récupère le numéro de partie
```
int numero_partie(t_fichier * fichier);
```

3. Ajoute les scores des joueurs de la partie
```
void ajout_score(t_fichier * fichier,int num_partie,int s_J1,int s_J2,int s_J3,int s_J4);
```

4. Charge une partie avec un fichier existant
```
void charger_partie(t_fichier * fichier);
```

5. Calcule le score d'un joueur à partir d'une sauvegarde de partie
```
int calcul_score(t_fichier * fichier,int num_partie,int num_joueur);
```

6. Affiche les scores des joueurs d'une partie
```
void afficher_scores(t_fichier * fichier,int num_partie);
```

7. Met à jour les scores d'une sauvegarde de partie
```
void maj_sauvegarde(t_fichier * fichier,int num_partie,int num_joueur);
```
