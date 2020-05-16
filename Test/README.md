# Test et création de fonctions
## Samuel DURAN (Dursam) et Valentin GIROD (Guarmanda)

### Les programmes de test (10):

Pour vérifier que les fonctionnalités du jeu puissent se coordonner entre elles, il faut d'abord créer des programmes de test pour les tester unitairement.

1. Tests des structures d'éléments
Ce premier programme permet de tester la création des 106 tuiles du jeu et de les afficher.
Lors de la génération avec `make`, il est appelé `prog_structure`.

2. Tests de la pile
Ce programme permet de tester l'empilement et le dépilement d'une tuile, ainsi que la récupération du sommet de la pile et l'affichage de sa valeur.
Lors de la génération avec `make`, il est appelé `prog_pile`.

3. Tests d'affichage de la tuile
Ce programme permet l'affichage des 15 tuiles d'un tableau de tuiles.
Lors de la génération avec `make`, il est appelé `prog_affichage_tuile`.

4. Tests de la sélection de tuiles
Ce programme permet d'effectuer le déroulement d'un tour, c'est-à-dire le retrait d'une tuile et le choix d'une autre tuile à partir de la pioche ou d'une pile de tuiles.
Lors de la génération avec `make`, il est appelé `prog_selection_tuile`.

5. Tests de la combinaison de couleurs
Ce programme permet de tester une série de 3 ou 4 tuiles de couleurs différentes à partir d'un chevalet et de vérifier la suppression d'une tuile de la série.
Lors de la génération avec `make`, il est appelé `prog_combinaison_couleur`.

6. Tests de la combinaison de suites d'entiers
Ce programme permet de tester une suite de 3 entiers minimum d'une même couleur de tuile.
Lors de la génération avec `make`, il est appelé `prog_combinaison_suite_entiers`.

7. Tests de la partie du jeu
Ce programme permet de tester le déroulement d'une partie avec 4 joueurs à tour de rôle sur une même machine.
Lors de la génération avec `make`, il est appelé `prog_partie`.

8. Tests de la partie avec l'IA
Ce programme permet de tester le déroulement d'une partie avec un joueur et 3 autres joueurs IA sur une même machine à tour de rôle.
Lors de la génération avec `make`, il est appelé `prog_partie_IA`.

9. Tests de la sauvegarde du jeu
Ce programme permet de tester la création et le chargement d'une sauvegarde via un fichier local. Le nom du fichier est défini au format `ANNEE-MOIS-JOUR-MINUTES-SECONDES.txt`. Exemple : `2020-05-04-15-53.txt`.
Lors de la génération avec `make`, il est appelé `prog_sauvegarde`.

10. Tests de la connexion client-réseau (jeu en réseau)
Ce programme non fonctionnel devait tester le déroulement de la partie entre une machine cliente et serveur. A l'heure actuelle, seule la connexion entre le client et le serveur est opérationnelle.
Lors de la génération avec `make`, ils sont appelés `prog_client` et `prog_serveur`.

### Les constantes (5):

1. Nombre de tuiles du jeu
```
# define N_T 106
```

2. Nombre de tuiles d'un chevalet
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

5. Valeur tampon pour la vérification de combinaisons de tuiles
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

### Les fonctions (64)

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

15. Compte le nombre d'éléments d'une tuile
```
int compte_element(t_pile * pile);
```

#### Fichier affichage_tuile (5)
16. Affichage des 14/15 tuiles d'un chevalet
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
21. Affichage des tuiles supprimées ou non
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

#### Fichier combinaison_suite (2)
24. Détecte si dans le chevalet il y a 3 ou 4 fois la même tuile, signifie que le chevalet a de(s) joker(s)
```
int detection_rep_joker(t_tuile * chev[]);
```
25. Vérifie les ensembles de combinaisons à partir de 3 suites d'entiers
```
void combinaison_suite(t_tuile * chev[]);
```

#### Fichier selection_tuile (4)
26. Initialise un tableau de structure de tuile pour enregistrer les tuiles qui seront empilées
```
void init_enr_tuile(t_tuile * enr[],int taille);
```

27. Creer une tuile, lui affecte une valeur puis l'empile sur une pile
```
void test_enr_tuile(t_tuile * jeu[N_T],t_tuile * enr[],t_pile * pile,int taille);
```

28. Creer une tuile, lui affecte une valeur puis l'empile sur une pile
```
void empile_enr_tuile(t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pile,int taille,int numero);
```

29. Sélectionne une tuile, soit de la pioche ou de la pile à gauche du joueur et retire une tuile du chevalet, version avec affiche_pile
```
void selection_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd);
```

#### Fichier partie (13)
30. Donne une valeur + 1 de la tuile retournée (le okey) à la tuile joker rouge ou noire possédé(s) par le joueur
```
void valeur_okey(t_tuile * okey,t_tuile * joker);
```

31. Affichage du sommet des piles de tout les joueurs, ainsi que le okey et la pioche
```
void affiche_plateau(t_tuile * okey,t_pile * p1,t_pile * p2,t_pile * p3,t_pile * p4);
```

32. Commence le premier tour de la partie en fonction du joueur ayant reçu la tuile de démarrage
```
void premier_tour_partie(t_tuile * chevalet[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int dem);
```

33. Dépile toutes les piles de tuiles, utilisé pour finir la partie
```
void depiler_toutes_tuiles(t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4);
```

34. Vérifie si le chevalet est gagnant en utilisant les combinaisons de couleurs et de suite d'entier
```
int regle_combinaison(t_tuile * chevalet[N_CHEV],t_tuile * okey);
```

35. Laisse le choix au joueur de pouvoir faire un tri rapide, un tri manuel ou pas de tri
```
int choix_tri(t_tuile * chevalet[N_CHEV]);
```

36. Réalise le premier tour d'un joueur
```
int tour_1_joueur(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur);
```

37. Début de partie, réalise le premier tour complètement avec la tuile de démarrage et la tuile a retirée
```
void debut_partie(t_tuile * chevalet[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int dem);
```

38. Annonce de l'issue de la partie un vainqueur ou non
```
void issue_partie(int issue_joueur);
```

39. Sélectionne une tuile, soit de la pioche ou de la pile à gauche du joueur et retire une tuile du chevalet, version avec affiche_plateau
```
void selection_tuile_v2(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd);
```

40. Vérifie si le jeu ne possèdent plus aucune tuiles
```
int pioche_vide(t_tuile * jeu[N_T]);
```

41. Réalise le tour d'un joueur
```
int tour_joueur(t_tuile * jeu[N_T],t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int cpt_tour,int num_joueur);
```

42. Déroule la partie, après que le première joueur désigné commence
```
int partie_en_cours(t_tuile * jeu[N_T],t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int num_joueur);
```

#### Fichier partie_IA (7)
43. Vérifie si une tuile appartient à une combinaison
```
int nombre_combinaison_tuile(t_tuile * chevalet[N_CHEV],t_tuile * okey,int ind_tuile,int ind_dep);

```
44. L'IA retire une tuile de son chevalet
```
int IA_retire_tuile(t_tuile * chevalet[N_CHEV],t_tuile * okey);

```
45. L'IA ajoute une tuile à son chevalet soit en piochant ou soit en prenant la tuile de sa pile à gauche de l'IA
```
int IA_ajout_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * okey,t_pile * pile_tuile);

```
46. Réalise le premier tour d'une IA
```
int tour_1_IA(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur);

```
47. Débute le première tour de la partie en démarrant avec l'IA qui reçoit une 15 ème tuile
```
 int debut_partie_IA(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur);

```
48. Réalise le tour d'une IA
```
int tour_IA(t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur);

```
49. Déroule la partie, après que le première joueur IA désigné commence
```
 int partie_en_cours_IA(t_tuile * jeu[N_T], t_tuile * joueur1[N_CHEV], t_tuile * joueur2[N_CHEV], t_tuile * joueur3[N_CHEV], t_tuile * joueur4[N_CHEV], t_tuile * J1_p1[], t_tuile * J2_p2[], t_tuile * J3_p3[], t_tuile * J4_p4[], t_pile * pile_J1, t_pile * pile_J2, t_pile * pile_J3, t_pile * pile_J4, t_tuile * okey, int num_joueur);
```

#### Fichier reseau (15)
50. Ouverture d'un port, le serveur attends une demande de connexion
```
SOCKET serveur (SOCKET sock)
```

51. Connexion d'un client au près d'un serveur, entre son adresse IP
```
SOCKET client (SOCKET sock);
```

52. Déconnecte une socket réseau, client ou serveur
```
void deconnexion (SOCKET sock);
```

53. Affichage des 14/15 tuiles cachés du chevalet d'une IA
```
void affiche_chevalet_IA(t_tuile * jeu[],int taille);
```

54. Affichage de 14/15 tuiles factices
```
void affiche_chevalet_factice(int mode);
```

55. Affichage de la tuile du sommet d'une pile, la tuile provient du serveur
```
void affiche_sommet_reseau(t_tuile * tuile);
```

56. Affichage des sommets des piles et de la tuile Okey
```
void affiche_piles_reseau(t_tuile * okey,t_tuile * sommet_p1,t_tuile * sommet_p2,t_tuile * sommet_p3,t_tuile * sommet_p4)
```

57. Affichage des 14/15 tuiles cachés du chevalet d'une IA
```
void affiche_chevalet_IA(t_tuile * jeu[], int taille)
```

58. Convertit une tuile en une donnée sous forme d'entier
```
void tuile_to_int(t_tuile * tuile,int * entier)
```

59. Interprète et convertit un entier en tuile
```
void int_to_tuile(t_tuile * tuile,int * entier)
```

60. Affichage des sommets des piles et de la tuile Okey en fonction du numéro du joueur
```
void affiche_1_factice(t_tuile * okey,t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,int num_joueur)
```

61. Réalise le tour 1 côté client (Fonctionne pas)
```
void tour_1_client(SOCKET csock,t_tuile * joueur[N_CHEV],t_tuile * okey,t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,int num_joueur)
```

62. Réalise le tour 1 côté serveur (Fonctionne pas)
```
int tour_1_serveur(SOCKET ssock,t_tuile * joueur2[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J2_p2[N_CHEV],t_tuile * okey,int num_joueur)
```

63. Réalise le début de la partie côté serveur (Fonctionne pas)
```
int debut_partie_serveur(SOCKET ssock,t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * J1_p1[N_CHEV],t_tuile * J2_p2[N_CHEV],t_tuile * J3_p3[N_CHEV],t_tuile * J4_p4[N_CHEV],t_tuile * okey,int num_joueur)
```

64. Réalise le début de la partie côté client (Fonctionne pas)
```
int debut_partie_client(SOCKET csock,t_tuile * joueur[N_CHEV],t_tuile * sommet_J1,t_tuile * sommet_J2,t_tuile * sommet_J3,t_tuile * sommet_J4,t_tuile * okey,int num_joueur)
```
