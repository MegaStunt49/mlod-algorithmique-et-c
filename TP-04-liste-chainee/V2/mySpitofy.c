// gcc -W -Wall -Wno-unused-parameter -std=c99 linkedList.c linkedListOfMusic.c mySpitofy.c -o mySpitofy

#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

Liste read_csv(char* file){
    FILE* fr;
    fr = fopen(file,"r");
    char dump[255];
    fgets(dump, 255, fr);
    char* buffer = calloc(256,sizeof(char));
    fgets(buffer, 255, fr);
    Liste l;
    l=creer(creerElement(buffer));
    buffer = calloc(256,sizeof(char));
    fgets(buffer, 255, fr);
    while(buffer[0]!= 0){
        ajoutFin_i(creerElement(buffer),l);
        buffer = calloc(256,sizeof(char));
        fgets(buffer, 255, fr);
    }
    free(buffer);
    fclose(fr);
    return l;
}

Liste trier(Liste l){
    if(l!=NULL){
        if(l->suiv==NULL){return l;}
        trier(l->suiv);
        int annee;
    }
    return l;
}

int main(){
	Liste l;
	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

    l=read_csv("music.csv");

    afficheListe_r(l);

	detruire_r(l);

	return EXIT_SUCCESS;
}