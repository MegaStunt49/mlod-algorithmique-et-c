#include "linkedListOfMusic.h"
#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>


void afficheElement(Element e){
    printf("%s from %s ;", e->name, e->artist);
}

void detruireElement(Element e){}

bool equalsElement(Element e1, Element e2){
    return (!strcmp(e1->name,e2->name) || !strcmp(e1->artist,e2->artist));
}
