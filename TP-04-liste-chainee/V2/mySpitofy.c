#include "linkedList.h"
#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
	Liste l;
	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

    Music music;
    music.artist = "bob";
    music.album = "wow";
    music.name = "lullaby";
    music.genre = "hard rock";
    music.diskNumber = 1;
    music.trackNumber = 1;
    music.year = 1969;

	l = creer(&music);

    afficheListe_r(l);

	detruire_r(l);

	return EXIT_SUCCESS;
}