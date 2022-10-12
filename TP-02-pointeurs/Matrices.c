#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define SIZE  5

void matrix_mult(int64_t mR[SIZE][SIZE],int64_t m1[SIZE][SIZE],int64_t m2[SIZE][SIZE]){
    for (int i = 0; i<SIZE; i++){
        for (int j = 0; j<SIZE; j++){
            int s = 0;
            for (int k = 0; k<SIZE;k++){
                s+=m1[i][k]*m2[k][j];
            }
            mR[i][j]=s;
        }
    }
}

void matrix_print(int64_t m[SIZE][SIZE]){
    for (int i = 0; i<SIZE; i++){
        for (int j = 0; j<SIZE; j++){
            printf(" %ld ",m[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int64_t ma1[SIZE][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t ma2[SIZE][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t mar[SIZE][SIZE];
    matrix_mult(mar,ma1,ma2);
    matrix_print(mar);
    return EXIT_SUCCESS;
}