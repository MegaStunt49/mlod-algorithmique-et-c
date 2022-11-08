#include "linkedList.h"
#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
	Liste l;
	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

    Music* elem;
    elem = malloc(sizeof(Music));
    elem->artist = "bob";
    elem->album = "wow";
    elem->name = "lullaby";
    elem->genre = "hard rock";
    elem->diskNumber = 1;
    elem->trackNumber = 1;
    elem->year = 1969;


    l = ajoutTete(elem,l);

    afficheListe_r(l);

	detruire_i(l);

	return EXIT_SUCCESS;
}