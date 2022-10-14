#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "prixTuring.h"

WinnerTabl readWinners(char* file){
    FILE* fr;
    fr = fopen(file,"r");
    char buffer[255];
    fgets(buffer, 255, fr);
	int N;
    sscanf(buffer, "%d", &N);
    WinnerPrix *d;
	WinnerTabl t;
    d=calloc(N,sizeof(WinnerPrix));
	for (int i = 0; i<N; i++){
        char *c;
        fgets(buffer, 255, fr);
        int an;
        sscanf(buffer, "%d", &an);
		d[i].annee=an;
        c = calloc(256,sizeof(char));
        fgets(c, 255, fr);
		d[i].nom=c;
        c = calloc(256,sizeof(char));
        fgets(c, 255, fr);
		d[i].travaux=c;
	}
	t.NbLign=N;
	t.Tabl=d;
    fclose(fr);
    return t;
}

void printWinners(WinnerTabl T, FILE *f){
	WinnerPrix *d;
	d = T.Tabl;
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

WinnerTabl *sortTuringWinnersByYears(WinnerTabl *T){
    WinnerTabl *tf;
    tf = malloc(sizeof(WinnerTabl));
    int N = T->NbLign;
	WinnerPrix *d;
    d=T->Tabl;
	WinnerPrix *df;
    df=calloc(N,sizeof(WinnerPrix));
    int PrevAn = 0;
    int BestAn = 3000;
    int IdAn = -1;
	for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            int antest = d[j].annee;
            if (antest<BestAn && antest>PrevAn){
                IdAn = j;
                BestAn = antest;
            }
        }
        PrevAn = BestAn;
        BestAn = 3000;
        df[i].annee=d[IdAn].annee;
        df[i].nom=d[IdAn].nom;
        df[i].travaux=d[IdAn].travaux;
	}
	tf->NbLign=N;
	tf->Tabl=df;
    return tf;
}

int main(int argc, char* argv[]){
    WinnerTabl T;
    T = readWinners(argv[1]);
	WinnerPrix *d;
	d = T.Tabl;
    FILE* f;
    char *fileName;
    if (argc>2){
        fileName = argv[2];
    }
    else{
        fileName = "out.txt";
    }
    f = fopen(fileName,"w");
    if (argc>3){
        if (strcmp(argv[3],"sort")){
            WinnerTabl *a;
            a = sortTuringWinnersByYears(&T);
            printWinners(*a,f);
            WinnerPrix *d2;
            d2= a->Tabl;
            for (int i = 0; i<a->NbLign; i++){
                free(d2[i].nom);
                free(d2[i].travaux);
            }
            free(d2);
        }
    }
    else{
        printWinners(T,f);
    }

    
	for (int i = 0; i<T.NbLign; i++){
		free(d[i].nom);
		free(d[i].travaux);
	}
	free(d);
	return EXIT_SUCCESS;
}