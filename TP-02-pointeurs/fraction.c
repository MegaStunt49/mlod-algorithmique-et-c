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

int main(void) {
    Frac f;
    f.numerateur=420;
    f.denominateur=600;
    Frac simplef=simplifie(f);
    printf("%d\n%d\n",simplef.numerateur,simplef.denominateur);
    return EXIT_SUCCESS;
}