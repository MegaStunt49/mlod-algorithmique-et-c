#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

void EchangeContenu(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int a = 10;
    int b = 20;
    EchangeContenu(&a,&b);
    printf ("a est de valeur %d\n",a);
    printf ("b est de valeur %d\n",b);
    return EXIT_SUCCESS;
}