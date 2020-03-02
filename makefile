include makefile.compilation

all:
	@read -p "sdl ou terminal? " PARAM; \
	make $$PARAM;

SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include
AFF_DIR=./Affichage/
MENU_DIR=./Menu/
INIT_DIR=./Initialisation/

PARAM=${1}
INCLUDE_SDL=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image -I${SDLINC_DIR}
INCLUDE_NCURSES=-lncurses
INCLUDES=-I./ -lm -I${AFF_DIR} -I${MENU_DIR} -I${INIT_DIR}

BIN_SDL=fonctions_sdl.o affichages_sdl.o
BIN_TERMINAL=fonctions_terminal.o affichages_terminal.o
#objets indépendants des fichiers d'affichage
OBJ=init.o
#objets dépendants des fichiers d'affichage
OBJ_DEP_AFF=menu.o main.o



PROG=programme

sdl: clean $(OBJ) $(BIN_SDL) $(OBJ_DEP_AFF)
	$(CCLNK) $(CFLAGS) $(OBJ) ${BIN_SDL} $(OBJ_DEP_AFF) -o ${PROG} ${INCLUDES} ${INCLUDE_SDL}

terminal: clean $(OBJ) $(BIN_TERMINAL) $(OBJ_DEP_AFF)
	$(CCLNK) $(CFLAGS) $(OBJ) ${BIN_TERMINAL} $(OBJ_DEP_AFF) -o ${PROG} ${INCLUDES} ${INCLUDE_NCURSES}


#Affichage
fonctions_sdl.o:
	$(CCOBJ) $(CFLAGS) ${AFF_DIR}fonctions_sdl.c -o fonctions_sdl.o ${INCLUDES} ${INCLUDE_SDL}

fonctions_terminal.o:
	$(CCOBJ) $(CFLAGS) ${AFF_DIR}fonctions_terminal.c -o fonctions_terminal.o ${INCLUDES} ${INCLUDE_NCURSES}

affichages_sdl.o:
	$(CCOBJ) $(CFLAGS) ${AFF_DIR}affichages_sdl.c -o affichages_sdl.o ${INCLUDES} ${INCLUDE_SDL}

affichages_terminal.o:
	$(CCOBJ) $(CFLAGS) ${AFF_DIR}affichages_terminal.c -o affichages_terminal.o ${INCLUDES} ${INCLUDE_NCURSES}

#Fichiers indépendants de l'affichage
init.o:
	$(CCOBJ) $(CFLAGS) $(INCLUDES) $(INIT_DIR)init.c -o init.o




#Fichiers utilisants des fonctions d'affichage
main.o:
	$(CCOBJ) $(CFLAGS) $(INCLUDES) main.c -o main.o
menu.o:
	$(CCOBJ) $(CFLAGS) $(INCLUDES) ${MENU_DIR}menu.c -o menu.o


clean:
	rm -f ${PROG}
	rm -f *.o