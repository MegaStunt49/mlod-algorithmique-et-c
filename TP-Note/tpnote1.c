#include <stdio.h>
#include <stdlib.h>
#include "tpnote1.h"

// Le Goff Marc

Tabl repeat(Tabl t1, Tabl t2){
    Tabl t3;
    int* val3;
    int s =0;
    for (int i = 0; i<t1.size; i++){
        s+=t1.valeurs[i];
    }
    val3 = calloc(s,sizeof(int));
    t3.size = s;
    t3.valeurs = val3;
    int s1 = 0;
    for (int i = 0; i<t1.size; i++){
        for (int j = 0; j<t1.valeurs[i]; j++){
            t3.valeurs[s1]=t2.valeurs[i];
            s1++;
        }
    }
    return t3;
}


int main(void) {
    Tabl t1;
    t1.size = 3;
    int val1[3] = {1,2,4};
    t1.valeurs = val1;
    Tabl t2;
    t2.size = 3;
    int val2[3] = {10,3,8};
    t2.valeurs = val2;
    Tabl t3 = repeat(t1,t2);
    for (int j = 0; j<t3.size; j++){
            printf(" %d ",t3.valeurs[j]);
        }
        printf("\n");
    free(t3.valeurs);
    return EXIT_SUCCESS;
}