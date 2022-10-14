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
        char *c;
        fgets(buffer, 255, f);
        int an;
        sscanf(buffer, "%d", &an);
		d[i].annee=an;
        c = calloc(256,sizeof(char));
        fgets(c, 255, f);
		d[i].nom=c;
        c = calloc(256,sizeof(char));
        fgets(c, 255, f);
		d[i].travaux=c;
	}
	t.NbLign=N;
	t.Tabl=d;
    fclose(f);
    return t;
}

void printWinners(WinnerTabl T){
	WinnerPrix *d;
	d = T.Tabl;
    FILE* f;
    f = fopen("out.txt","w");
	fprintf(f,"%d\n",T.NbLign);
	for (int i = 0; i<T.NbLign; i++){
		fprintf(f,"%d",d[i].annee);
		fprintf(f,"\n%s",d[i].nom);
		fprintf(f,"%s",d[i].travaux);
	}
    fclose(f);
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
    printWinners(T);
	WinnerPrix *d;
	d = T.Tabl;
	for (int i = 0; i<T.NbLign; i++){
		free(d[i].nom);
		free(d[i].travaux);
	}
	free(d);
	return EXIT_SUCCESS;
}