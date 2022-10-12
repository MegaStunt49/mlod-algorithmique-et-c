#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "fraction.h"

int PGCD(int i1, int i2){
    if (i2==0){
        return i1;
    }
    else {
        return PGCD(i2, i1%i2);
    }
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

int main(void) {
    Frac f1;
    f1.numerateur=420;
    f1.denominateur=600;
    Frac f2;
    f2.numerateur=300;
    f2.denominateur=600;
    Frac f=additionSimpl(f1,f2);
    printf("%d\n%d\n",f.numerateur,f.denominateur);
    return EXIT_SUCCESS;
}