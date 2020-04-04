include Makefile.compilation

#
# Objets
#

fich_obj_test_init_structure = test_init_structure.o init_structure.o
fich_obj_test_init_pile = test_init_pile.o init_pile.o init_structure.o
fich_obj_test_combinaison_couleur = test_combinaison_couleur.o combinaison_couleur.o init_pile.o init_structure.o
fich_obj_test_combinaison_suite_entiers = test_combinaison_suite_entiers.o combinaison_suite_entiers.o combinaison_couleur.o init_pile.o init_structure.o
fich_obj_test_affichage_tuile = test_affichage_tuile.o affichage_tuile.o init_pile.o init_structure.o
fich_obj_test_selection_tuile = test_selection_tuile.o selection_tuile.o affichage_tuile.o init_pile.o init_structure.o
#
# Tests (executables+objets)
#

BIN = prog_structure prog_pile prog_combinaison_couleur prog_combinaison_suite_entiers prog_affichage_tuile prog_selection_tuile

prog_structure : $(fich_obj_test_init_structure)
	$(CCLNK) $(CFLAGS) $(fich_obj_test_init_structure) -o prog_structure

test_init_structure.o : test_init_structure.c init_structure.h
	$(CCOBJ) $(CFLAGS) test_init_structure.c -o test_init_structure.o -I ./

prog_pile : $(fich_obj_test_init_pile)
	$(CCLNK) $(CFLAGS) $(fich_obj_test_init_pile) -o prog_pile

test_init_pile.o : test_init_pile.c init_pile.h
	$(CCOBJ) $(CFLAGS) test_init_pile.c -o test_init_pile.o -I ./

prog_combinaison_couleur : $(fich_obj_test_combinaison_couleur)
	$(CCLNK) $(CFLAGS) $(fich_obj_test_combinaison_couleur) -o prog_combinaison_couleur

test_combinaison_couleur.o : test_combinaison_couleur.c combinaison_couleur.h
	$(CCOBJ) $(CFLAGS) test_combinaison_couleur.c -o test_combinaison_couleur.o -I ./

prog_combinaison_suite_entiers : $(fich_obj_test_combinaison_suite_entiers)
	$(CCLNK) $(CFLAGS) $(fich_obj_test_combinaison_suite_entiers) -o prog_combinaison_suite_entiers

test_combinaison_suite_entiers.o : test_combinaison_suite_entiers.c combinaison_suite_entiers.h
	$(CCOBJ) $(CFLAGS) test_combinaison_suite_entiers.c -o test_combinaison_suite_entiers.o -I ./

prog_affichage_tuile : $(fich_obj_test_affichage_tuile)
	$(CCLNK) $(CFLAGS) $(fich_obj_test_affichage_tuile) -o prog_affichage_tuile

test_affichage_tuile.o : test_affichage_tuile.c affichage_tuile.h
	$(CCOBJ) $(CFLAGS) test_affichage_tuile.c -o test_affichage_tuile.o -I ./

prog_selection_tuile : $(fich_obj_test_selection_tuile)
	$(CCLNK) $(CFLAGS) $(fich_obj_test_selection_tuile) -o prog_selection_tuile

test_selection_tuile.o : test_selection_tuile.c selection_tuile.h
	$(CCOBJ) $(CFLAGS) test_selection_tuile.c -o test_selection_tuile.o -I ./

#
# Modules
#

OBJ = init_structure.o init_pile.o combinaison_couleur.o combinaison_suite_entiers.o affichage_tuile.o selection_tuile.o

init_structure.o : init_structure.c init_structure.h
	$(CCOBJ) $(CFLAGS) init_structure.c -o init_structure.o -I ./

init_pile.o : init_pile.c init_pile.h
	$(CCOBJ) $(CFLAGS) init_pile.c -o init_pile.o -I ./

combinaison_couleur.o : combinaison_couleur.c combinaison_couleur.h
	$(CCOBJ) $(CFLAGS) combinaison_couleur.c -o combinaison_couleur.o -I ./

combinaison_suite_entiers.o : combinaison_suite_entiers.c combinaison_suite_entiers.h init_structure.h
	$(CCOBJ) $(CFLAGS) combinaison_suite_entiers.c -o combinaison_suite_entiers.o -I ./

affichage_tuile.o : affichage_tuile.c affichage_tuile.h
	$(CCOBJ) $(CFLAGS) affichage_tuile.c -o affichage_tuile.o -I ./

selection_tuile.o : selection_tuile.c selection_tuile.h
		$(CCOBJ) $(CFLAGS) selection_tuile.c -o selection_tuile.o -I ./

all : $(BIN) $(OBJ)

clean :
	- rm  *.o
	- rm prog_structure
	- rm prog_pile
	- rm prog_combinaison_couleur
	- rm prog_combinaison_suite_entiers
	- rm prog_affichage_tuile
	- rm prog_selection_tuile

#tests :
#	./prog_structure
#	./prog_pile
# ./prog_combinaison_couleur
# ./prog_combinaison_suite_entiers
# ./prog_affichage_tuile
# ./prog_selection_tuile