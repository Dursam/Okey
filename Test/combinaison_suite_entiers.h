#ifndef _COMBISUITEENTIER_H_
#define _COMBISUITEENTIER_H_

#include <commun.h>

/**
* \file combinaison_suite_entiers.h
* \brief Fichier contenant la fonction de combinaison de suite d'entiers
* \author Samuel DURAN
* \version 1.0
* \date 12 avril 2020
*/

/**
* \fn void combinaison_suite(t_tuile * chev[])
* \brief Vérifie les ensembles de combinaisons à partir de 3 suites d'entiers
*/
extern void combinaison_suite(t_tuile * chev[]);

/**
* \fn int detection_rep_tuile(t_tuile * chev[])
* \brief Détecte si dans le chevalet il y a 3 ou 4 fois la même tuile, signifie que le chevalet possède des jokers
*/
extern int detection_rep_joker(t_tuile * chev[]);

#endif
