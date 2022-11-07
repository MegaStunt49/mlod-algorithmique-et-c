#include <stdio.h>

// Le Goff Marc

Tabl repeat(Tabl t1, Tabl t2){
    Tabl t3;
    int* val3;
    int s =0;
    for (int i = 0; i<t1.size; i++){
        s+=t1.valeurs[i];
    }
    val3 = calloc(s,sizeof(int));
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
    ;
    return EXIT_SUCCESS;
}