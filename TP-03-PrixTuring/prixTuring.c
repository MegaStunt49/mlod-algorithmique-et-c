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

WinnerTabl readWinners(){
    int N = scanLineAsInt();
    WinnerPrix *d;
	WinnerTabl t;
    d=calloc(N,sizeof(WinnerPrix));
	for (int i = 0; i<N; i++){
		d[i].annee=scanLineAsInt();
		d[i].nom=scanLine();
		d[i].travaux=scanLine();
	}
	t.NbLign=N;
	t.Tabl=d;
    return t;
}

void printWinners(WinnerTabl T){
	WinnerPrix *d;
	d = T.Tabl;
	printf("%d",T.NbLign);
	for (int i = 0; i<T.NbLign; i++){
		printf("\n%d",d[i].annee);
		printf("\n%s",d[i].nom);
		printf("\n%s",d[i].travaux);
	}
}

void infosAnnee(WinnerTabl T,int an){
	WinnerPrix *d;
	d = T.Tabl;
	for (int i = 0; i<T.NbLign; i++){
		if (d[i].annee==an){
			printf("L'annee %d, le(s) gagnant(s) ont été : %s\n",an,d[i].nom);
			printf("Nature des travaux : %s\n",d[i].travaux);
		}
	}
}

int main(int argc, char* argv[]){
    WinnerTabl T;
    T = readWinners();
	if (argc==3){
		if (strcmp(argv[1],"infosAnnee")==0){
			int x;
    		sscanf(argv[2], "%d", &x);
			infosAnnee(T,x);
		}
	}

	// free
	WinnerPrix *d;
	d = T.Tabl;
	for (int i = 0; i<T.NbLign; i++){
		free(d[i].nom);
		free(d[i].travaux);
	}
	free(d);
	return EXIT_SUCCESS;
}