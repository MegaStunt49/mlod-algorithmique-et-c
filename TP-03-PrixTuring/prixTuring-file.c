#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "prixTuring.h"

WinnerTabl readWinners(char* file){
    FILE* f;
    f = fopen(file,"r");
    char buffer[255];
    fgets(buffer, 255, f);
	int N;
    sscanf(buffer, "%d", &N);
    WinnerPrix *d;
	WinnerTabl t;
    d=calloc(N,sizeof(WinnerPrix));
	for (int i = 0; i<N; i++){
        fgets(buffer, 255, f);
        int an;
        sscanf(buffer, "%d", &an);
		d[i].annee=an;
		d[i].nom=fgets(buffer, 255, f);
		d[i].travaux=fgets(buffer, 255, f);
	}
	t.NbLign=N;
	t.Tabl=d;
    fclose(f);
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
    T = readWinners(argv[1]);
	WinnerPrix *d;
	d = T.Tabl;
	free(d);
	return EXIT_SUCCESS;
}