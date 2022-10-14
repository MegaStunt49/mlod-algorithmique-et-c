#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "fraction.h"

int PGCD(int i1,int i2){
    return i2==0 ? i1 : PGCD(i2, i1%i2);
}

Frac simplifie(Frac fr){
    int i1 = fr.numerateur;
    int i2 = fr.denominateur;
    int p = PGCD(i1, i2);
    Frac frf;
    frf.numerateur=i1/p;
    frf.denominateur=i2/p;
    return frf;
}

Frac additionSimpl(Frac f1, Frac f2){
    Frac f;
    f.numerateur=f1.numerateur*f2.denominateur+f1.denominateur*f2.numerateur;
    f.denominateur=f1.denominateur*f2.denominateur;
    return simplifie(f);
}

Frac H(int N){
    Frac f;
    f.numerateur=1;
    f.denominateur=N;
    if (N<=1){
        return f;
    }
    return additionSimpl(f,H(N-1));
}

int main(void) {
    int N;
    printf("Saisir N :\n");
    scanf("%d",&N);
    Frac f=H(N);
    printf("La Somme vaux :\n%d\n%d\n",f.numerateur,f.denominateur);
    return EXIT_SUCCESS;
}