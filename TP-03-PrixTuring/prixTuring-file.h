#include <stdio.h>
#include <stdlib.h>

typedef struct WinnerPrix{int annee; char* nom; char* travaux;} WinnerPrix;

typedef struct WinnerTabl{int NbLign; WinnerPrix *Tabl;} WinnerTabl;

void infosAnnee(WinnerTabl T,int annee);