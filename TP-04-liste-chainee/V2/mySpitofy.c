#include "linkedList.h"
#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

Liste read_csv(char* file){
    FILE* fr;
    fr = fopen(file,"r");
    char buffer[255];
    fgets(buffer, 255, fr);
    fgets(buffer, 255, fr);
    Liste l;
    l=NULL;
    while(buffer[0]!= EOF ){
        ajoutFin_r(creerElement(buffer));
        fgets(buffer, 255, fr);
    }
    fclose(fr);
}

int main(int argc, char* argv[]){
	Liste l;
	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

    l=read_csv(argv[1])


    afficheListe_r(l);

	detruire_r(l);

	return EXIT_SUCCESS;
}