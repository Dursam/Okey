# Fonctions de règles (6)
## Samuel DURAN (Dursam)


1. Compte le nombre de couleurs différentes d'une tuile
```
int compte_coul_diff(int tab_coul[4]);
```

2. Vérifie les ensembles de combinaisons de 3 ou 4 couleurs
```
void regle_coul(t_tuile * chev[]);
```

3. Vérifie les ensembles de combinaisons à partir de 3 suites d'entiers
```
void regle_suite(t_tuile * chev[]);
```

4. Vérifie les ensembles de combinaisons à partir de 3 suites d'entiers
```
void regle_suite(t_tuile * chev[]);
```

5. Donne une valeur + 1 de la tuile retournée (le okey) à la tuile joker rouge ou noire posséder par le joueur
```
void valeur_okey(t_tuile * okey,t_tuile * joker);
```

6. Vérifie si le chevalet est gagnant (return 1, 0 pour contraire) en utilisant les combinaisons de couleurs et de suite d'entier
```
int regle_combinaison(t_tuile * chevalet[N_CHEV],t_tuile * okey);
```
