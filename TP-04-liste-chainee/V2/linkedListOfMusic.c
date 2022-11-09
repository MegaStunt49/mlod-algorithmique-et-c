#include "linkedListOfMusic.h"
#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void afficheElement(Element e){
    printf("%s the %s music from %s in the album %s from year %d, disc %d track n°%d\n", ((Music*)e)->name, ((Music*)e)->genre, ((Music*)e)->artist, ((Music*)e)->album, ((Music*)e)->year, ((Music*)e)->diskNumber, ((Music*)e)->trackNumber);
}

void detruireElement(Element e){
    free(((Music*)e)->name);
    free(e);
}

Element creerElement(char* ligne){
    Music* elem;
    elem = malloc(sizeof(Music));
    char delim[] = ",";
    char *ptr = strtok(ligne, delim);
    elem->name = ptr;
    ptr = strtok(NULL, delim);
    elem->artist = ptr;
    ptr = strtok(NULL, delim);
    elem->album = ptr;
    ptr = strtok(NULL, delim);
    elem->genre = ptr;
    ptr = strtok(NULL, delim);
    int dN;
    sscanf(ptr, "%d", &dN);
    elem->diskNumber = dN;
    ptr = strtok(NULL, delim);
    int tN;
    sscanf(ptr, "%d", &tN);
    elem->trackNumber = tN;
    ptr = strtok(NULL, delim);
    int y;
    sscanf(ptr, "%d", &y);
    elem->year = y;
    return elem;
}

bool equalsElement(Element e1, Element e2){
    return (!strcmp(((Music*)e1)->name,((Music*)e2)->name) || !strcmp(((Music*)e1)->artist,((Music*)e2)->artist));
}
