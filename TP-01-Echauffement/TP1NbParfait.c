#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

int nb_parfait(int N){
    for (int i = 2; i<=N; i++){
        int s=0;
        for (int j = 1; j<i/2+1; j++){
            if (i%j==0){
                s+=j;
            }
        }
        if (s==i){
            printf("%d est parfait \n",i);
        }
    }
    return 0;
}

int main(void) {
    int i;
    printf("Saisissez le nombre maximal :\n");
    scanf("%d", &i);
    char a = 'a';
    char b = 'A';
    printf("%d\n",a);
    printf("%d\n",b);
    nb_parfait(i);
    return EXIT_SUCCESS;
}