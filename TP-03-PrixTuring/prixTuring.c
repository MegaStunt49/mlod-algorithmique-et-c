#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "prixTuring.h"

char* scanLine(){
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n'){
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

int scanLineAsInt(){
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

WinnerPrix *readWinners(){
    int N = scanLineAsInt();
    WinnerPrix *d;
    d=malloc(sizeof(WinnerPrix[N]));
    (*d).annee = 42;
    return d;
}

int main(void){
    WinnerPrix *d;
    d = readWinners;
	return EXIT_SUCCESS;
}