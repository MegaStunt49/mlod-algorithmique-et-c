#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

void matrix_mult(int64_t mR[][],int64_t m1[][],int64_t m2[][]){
    for (int i = 0; i<sizeof(m1); i++){
        for (int j = 0; j<sizeof(m1); j++){
            int s = 0;
            for (int k = 0; k<sizeof(m1);k++){
                s+=m1[i][k]*m2[k][j];
            }
            mR[i][j]=s;
        }
    }
}

int main(void) {
    ;
    return EXIT_SUCCESS;
}