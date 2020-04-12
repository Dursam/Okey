<doctype html>
  <head>
  <meta charset="utf-8">
  </head>
  <body>
    <h1> Test et création de fonctions </h2>
    <h2> Samuel DURAN (Dursam) et Valentin GIROD (Guarmanda)</h2>
    <h3> Les constantes (4):</h3>
    <ul>
      <li> Nombre de tuiles du jeu</li>
      <p> #define N_T 106</p>
      <li> Nombre de tuile d'un chevalet</li>
      <p> #define N_CHEV 15</p>
      <li> Valeur d'une tuile de joker</li>
      <p> #define V_OKEY 13</p>
      <li> Valeur d'une tuile supprimée</li>
      <p> #define V_DEL 100</p>
      <li> Valeur tampon qui sert pour la fonction combinaison suite entier</li>
      <p> #define NO_VALUE 99</p>
    </ul>
    <h3> Les structures (4):</h3>
    <ul>
      <li> Définition de la couleur</li>
      <p>  typedef enum {jaune,rouge,noire,bleu} t_couleur;</p>
      <li> Definition d'une tuile</li>
      <p> typedef struct s_tuile {
        int nbr;
        t_couleur clr;
      } t_tuile;</p>
      <li> Définition d'un élément d'une pile soit une tuile</li>
      <p> typedef struct s_element { t_tuile * tuile; struct s_element * suivant;} t_element;</p>
      <li> Définition d'une pile de tuile</li>
      <p> typedef struct s_pile { t_element * premier ;} t_pile;</p>
    </ul>
    <h3> Les fonctions (37):</h3>
    <h4> init_structure (9) -></h4>
    <ul>
    <li> Initialise le jeu de 106 tuiles</li>
    <p> void init_tuile(t_tuile * jeu[N_T]);</p>
    <li> Alloue une mémoire dynamique à un chevalet</li>
    <p> void creer_chevalet(t_tuile * joueur[],int taille);</p>
    <li> Libère la mémoire d'une tuile ou de plusieurs tuiles d'un tableau de structure</li>
    <p> void detruire_tuile(t_tuile * jeu[],int taille);</p>
    <li> Affiche les tuiles une par une</li>
    <p> void affiche_chaque_tuile(t_tuile * jeu[],int taille);</p>
    <li> Donne une tuile au hasard à un des 4 joueurs</li>
    <p> demarrage(t_tuile * jeu[N_T], t_tuile * j1[N_CHEV],t_tuile * j2[N_CHEV],t_tuile * j3[N_CHEV],t_tuile * j4[N_CHEV]);</p>
    <li> Distribue 14 tuiles à un joueur</li>
    <p> void distribution_joueur(t_tuile * jeu[N_T], t_tuile * joueur[N_CHEV]);</p>
    <li> Distribue une tuile parmi le jeu des 106 tuiles, au hasard</li>
    <p> t_tuile distribution_pioche(t_tuile * jeu[N_T]);</p>
    <li> Alloue une mémoire dynamique à une tuile</li>
    <p> t_tuile * creer_tuile(void);</p>
    <li> Renvoie la taille des tuiles alloués</li>
    <p> int taille_tuile(t_tuile * jeu[],int taille_jeu);</p>
    </ul>
    <h4> init_pile (6) -></h4>
    <ul>
      <li> Initialise la pile</li>
      <p> void init_pile(t_pile * pile);</p>
      <li> Vérifie si la pile est vide</li>
      <p> int pile_vide(t_pile * pile);</p>
      <li> Empile une tuile de la pile</li>
      <p> void empiler(t_pile * pile,t_tuile * t);</p>
      <li> Retire une tuile de la pile</li>
      <p> void depiler(t_pile * pile);</p>
      <li> Récupère la tuile du sommet de la pile</li>
      <p> void sommet_pile(t_pile * pile,t_tuile ** c);</p>
      <li> Compte le nombre d'élément d'une tuile</li>
      <p> int compte_element(t_pile * pile);</p>
    </ul>
    <h4> affichage_tuile (5) -></h4>
    <ul>
      <li> Affichage des 14/15 tuiles du chevalet</li>
      <p> void affiche_chevalet(t_tuile * jeu[],int taille);</p>
      <li> Affichage du sommet d'une pile</li>
      <p> void affiche_sommet_pile(t_pile * pile);</p>
      <li> Affichage du sommet des piles de tout les joueurs</li>
      <p> void affiche_pile(t_pile * p1,t_pile * p2,t_pile * p3,t_pile * p4);</p>
      <li> Tri manuel d'un chevalet de tuiles</li>
      <p> void tri_manuel(t_tuile * chevalet[N_CHEV]);</p>
      <li> Tri rapide d'un chevalet de tuiles</li>
      <p> void tri_rapide(t_tuile * chevalet[],int i,int j);</p>
    </ul>
    <h4> combinaison_couleur (3) -></h4>
    <ul>
      <li> Vérifie les tuiles supprimer ou non</li>
      <p> void affiche_tuile(t_tuile * jeu[],int taille);</p>
      <li> Compte le nombre de couleur différente d'une tuile</li>
      <p> int compte_coul_diff(int tab_coul[4]);</p>
      <li> Vérifie les ensembles de combinaisons de 3 ou 4 couleurs</li>
      <p> void combinaison_coul(t_tuile * chev[]);</p>
      </ul>
    <h4> combinaison_suite (1) -></h4>
    <ul>
      <li> Vérifie les ensembles de combinaisons à partir de 3 suites d'entiers</li>
      <p> void combinaison_suite(t_tuile * chev[]);</p>
    </ul>
    <h4> selection_tuile (4) -></h4>
    <ul>
      <li> Initialise un tableau de struture de tuile pour enregistrer les tuiles qui seront empilés</li>
      <p> void init_enr_tuile(t_tuile * enr[],int taille);</p>
      <li> Creer une tuile, lui affecte une valeur puis l'empile sur une pile</li>
      <p> void test_enr_tuile(t_tuile * jeu[N_T],t_tuile * enr[],t_pile * pile,int taille);</p>
      <li> Creer une tuile, lui affecte une valeur puis l'empile sur une pile</li>
      <p> void empile_enr_tuile(t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pile,int taille,int numero);</p>
      <li> Permet de sélection une tuile soit de la pioche ou de la pile de gauche et retire une tuile du chevalet, version avec affiche_pile</li>
      <p> void selection_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd);</p>
    </ul>
    <h4> partie (9) -></h4>
    <ul>
      <li> Donne une valeur + 1 de la tuile retournée (le okey) à la tuile joker rouge ou noire posséder par le joueur</li>
      <p> void valeur_okey(t_tuile * okey,t_tuile * joker);</p>
      <li> Affichage du sommet des piles de tout les joueurs</li>
      <p> void affiche_plateau(t_tuile * okey,t_pile * p1,t_pile * p2,t_pile * p3,t_pile * p4);</p>
      <li> Début de partie en fonction de la tuile de démarrage</li>
      <p> void debut_partie(t_tuile * chevalet[N_CHEV],t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4,t_tuile * okey,int dem);</p>
      <li> Dépile toutes les piles de tuiles, utilisé pour finir la partie</li>
      <p> void depiler_toutes_tuiles(t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4);</p>
      <li> Vérifie si le chevalet est gagnant (return 1, 0 pour contraire) en utilisant les combinaisons de couleurs et de suite d'entier</li>
      <p> int regle_combinaison(t_tuile * chevalet[N_CHEV],t_tuile * okey);</p>
      <li> Laisse le choix au joueur de pouvoir faire un tri rapide, un tri manuel ou un pas de tri</li>
      <p> int choix_tri(t_tuile * chevalet[N_CHEV]);</p>
      <li> Permet de sélection une tuile soit de la pioche ou de la pile de gauche et retire une tuile du chevalet, version avec affiche plateau</li>
      <p> selection_tuile_v2(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd);</p>
      <li> Permet de vérifier si le jeu ne posséde plus aucune tuiles,return vrai (1) et faux (0)</li>
      <p> int pioche_vide(t_tuile * jeu[N_T]);</p>
      <li> Permet le déroulement de la partie, après que le première joueur commence. Retourne le numéro de joueur gagnant</li>
      <p> int  partie_en_cours(t_tuile * jeu[N_T]
                                             ,t_tuile * joueur1[N_CHEV],t_tuile * joueur2[N_CHEV],t_tuile * joueur3[N_CHEV],t_tuile * joueur4[N_CHEV]
                                             ,t_tuile * J1_p1[],t_tuile * J2_p2[],t_tuile * J3_p3[],t_tuile * J4_p4[]
                                             ,t_pile * pile_J1,t_pile * pile_J2,t_pile * pile_J3,t_pile * pile_J4
                                             ,int num_joueur
                                             ,t_tuile * okey
                                              );</p>
    </ul>
  </body>
</html>
