/* L'objectif de ce fichier est de créer une partie en réseau */
/* La partie finie lorsque la pioche est vide */

#include <init_structure.h>
#include <init_pile.h>
#include <affichage_tuile.h>
#include <combinaison_couleur.h>
#include <combinaison_suite_entiers.h>
#include <selection_tuile.h>
#include <partie.h>
#include <partie_IA.h>
#include <reseau.h>

int main(void){

  /* Le joueur distant */
  t_tuile * joueur[N_CHEV];
  /* Les 4 sommet de piles */
  t_tuile * sommet_J1 = creer_tuile(),* sommet_J2 = creer_tuile(),* sommet_J3 = creer_tuile(),* sommet_J4 = creer_tuile();
  /* La tuile OKEY */
  t_tuile * okey = creer_tuile();
  /* Le numéro du joueur qui commence la partie */
  int num_joueur;
  /* Détermine lequel des joueurs est gagnant */
  int joueur_gagnant;
  /* Test si l'un des chevalets est gagnant au premier tour 1 (Situation très exceptionnel) */
  int issue_partie_tour_1;
  /* Entiers de conversion de donnée */
  int * val1,val2;
  /* Socket réseau*/
  SOCKET sock, csock;

  /* Tentative de connexion */
  if ((csock = client(sock)) == 0){
    printf("Vérifier que vous saissisez bien l'adresse IP du serveur\n");
    printf("Vérifier que votre adresse IP soit sur le même réseau que celui du serveur\n");
    return 0;
  }

  /* On initialise le joueur */
  creer_chevalet(joueur,N_CHEV);

  /* On reçoit le okey */
  recv(csock,val2,sizeof(val2),0);
  *val1 = val2;
  int_to_tuile(okey,val1);

  /* Reçoit le numéro du joueur auprès du serveur */
  recv(csock,num_joueur,sizeof(num_joueur),0);

  /* Déroulement du premier tour de la partie */
  debut_partie_client(csock,joueur,sommet_J1,sommet_J2,sommet_J3,sommet_J4,okey,num_joueur);

  /* Reçoit l'issue du premier tour auprès du serveur */
  recv(csock,issue_partie_tour_1,sizeof(issue_partie_tour_1),0);

  if(issue_partie_tour_1 != 0){
    issue_partie(issue_partie_tour_1);
    return 0;
  }
  /* Déroulement de la partie */
  //joueur_gagnant = partie_en_cours_client(jeu,joueur,sommet_J1,sommet_J2,sommet_J3,sommet_J4,okey,num_joueur);

  /* Annonce de l'issue de la partie, un vainqueur ou non */
  //issue_partie(joueur_gagnant);

  /* On détruit le jeu, la tuile okey, les enregistrements des piles, les chevalets et la copie d'un chevalet */
  detruire_tuile(&okey,taille_tuile(&okey,sizeof(okey)));

  detruire_tuile(&sommet_J1,taille_tuile(&sommet_J1,sizeof(sommet_J1)));
  detruire_tuile(&sommet_J2,taille_tuile(&sommet_J2,sizeof(sommet_J2)));
  detruire_tuile(&sommet_J3,taille_tuile(&sommet_J3,sizeof(sommet_J3)));
  detruire_tuile(&sommet_J4,taille_tuile(&sommet_J4,sizeof(sommet_J4)));

  detruire_tuile(joueur,taille_tuile(joueur,sizeof(joueur)));

  deconnexion(csock);

  return 0;
}
