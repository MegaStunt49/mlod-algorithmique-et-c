#include "linkedListOfMusic.h"
#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void afficheElement(Element e){
    printf("%s the %s music from %s in the album %s from year %d, disc %d track n°%d\n", ((Music*)e)->name, ((Music*)e)->genre, ((Music*)e)->artist, ((Music*)e)->album, ((Music*)e)->year, ((Music*)e)->diskNumber, ((Music*)e)->trackNumber);
}

void detruireElement(Element e){}

bool equalsElement(Element e1, Element e2){
    return (!strcmp(((Music*)e1)->name,((Music*)e2)->name) || !strcmp(((Music*)e1)->artist,((Music*)e2)->artist));
}
