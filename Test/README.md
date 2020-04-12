<doctype html>
  <head>
  <meta charset="utf-8">
  </head>
  <body>
    <h1> Test et création de fonctions </h2>
    <h2> Samuel DURAN (Dursam) et Valentin GIROD (Guarmanda)</h2>
    <h3> Les constantes :</h3>
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
    <h3> Les structures :</h3>
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
      <li> </li>
      <p> </p>
    </ul>
  </body>
</html>
