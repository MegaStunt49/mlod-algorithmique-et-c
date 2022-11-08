#include "linkedListOfMusic.h"
#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void afficheElement(Element e){
    printf("%s from %s ;", ((Music*)e)->name, ((Music*)e)->artist);
}

void detruireElement(Element e){}

bool equalsElement(Element e1, Element e2){
    return (!strcmp(((Music*)e1)->name,((Music*)e2)->name) || !strcmp(((Music*)e1)->artist,((Music*)e2)->artist));
}
