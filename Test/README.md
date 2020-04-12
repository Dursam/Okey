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
    <h3> Les fonctions ():</h3>
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
    <h4> combinaison_couleur () -></h4>
    <ul>
      <li> Vérifie les tuiles supprimer ou non</li>
      <p> void affiche_tuile(t_tuile * jeu[],int taille);</p>
      <li> Compte le nombre de couleur différente d'une tuile</li>
      <p> int compte_coul_diff(int tab_coul[4]);</p>
      <li> Vérifie les ensembles de combinaisons de 3 ou 4 couleurs</li>
      <p> void combinaison_coul(t_tuile * chev[]);</p>
      </ul>
    <h4></h4>
    <ul>
      <li></li>
      <p></p>
    </ul>
  </body>
</html>
