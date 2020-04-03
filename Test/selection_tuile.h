#ifndef _SELECTION_H_
#define _SELECTION_H_

#include <commun.h>

extern void init_enr_tuile(t_tuile * enr[],int taille);

extern void test_enr_tuile(t_tuile * jeu[N_T],t_tuile * enr[],t_pile * pile,int taille);

extern void empile_enr_tuile(t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pile,int taille,int numero);

extern void selection_tuile(t_tuile * jeu[N_T],t_tuile * chevalet[N_CHEV],t_tuile * enr[],t_pile * pfg,t_pile * pfd,t_pile * pg,t_pile * pd);

#endif
