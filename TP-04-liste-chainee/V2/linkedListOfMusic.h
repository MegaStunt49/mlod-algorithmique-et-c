#pragma once

#include "linkedList.h"
#include <stdbool.h>

typedef struct music {
	char* name;
	char* artist;
	char* album;
	char* genre;
    int diskNumber;
    int trackNumber;
    int year;
} Music;

void afficheElement(Element e);

void detruireElement(Element e);

bool equalsElement(Element e1, Element e2);