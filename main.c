#include <menu.h>

int main(void){

	init_affichage();
	while (showMenu() ==1);
	return 0;
}
