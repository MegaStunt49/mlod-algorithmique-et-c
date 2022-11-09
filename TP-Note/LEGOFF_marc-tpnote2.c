// gcc -o LEGOFF_marc-tpnote2 LEGOFF_marc-tpnote2.c -Wall -std=c99
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHUNK_SIZE_MAX 5

typedef struct globChunk {
    struct globChunk* next;
    int chunkSize;
    char* chunk;
} globChunk;

typedef globChunk* String;

String string_new(char* str){
    String newStr = malloc(sizeof(globChunk));
    newStr->chunkSize = 0;
    newStr->next = NULL;
    newStr->chunk = calloc(5,sizeof(char));
    for (int i = 0; ((str[i]!='\0' && str!=NULL) && i<5); i++){
        newStr->chunkSize = i+1;
        newStr->chunk[i] = str[i];
    }
    if (newStr->chunkSize == 5){
        newStr->next = string_new(&(str[5]));
    }
    return newStr;
}

void detruire_r(String str){
    if (str!=NULL){
        free(str->chunk);
        detruire_r(str->next);
        free(str);
    }
}

int main(void){
    String s = string_new("HELLO !");
    printf("%s%s\n",s->chunk,s->next->chunk);
    detruire_r(s);
	return EXIT_SUCCESS;
}