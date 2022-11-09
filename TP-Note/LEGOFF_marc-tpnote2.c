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

unsigned int string_length(String str){
    unsigned int s = 0;
    String scop = str;
    while (scop!=NULL){
        s += scop->chunkSize;
        scop = scop->next;
    }
    return s;
}

void detruire_r(String str){
    if (str!=NULL){
        free(str->chunk);
        detruire_r(str->next);
        free(str);
    }
}

String add_fin(String str, String str2){
    if(str->next!=NULL){
        add_fin(str->next,str2);
    }
    else{
        str->next=str2;
    }
    return str;
}

String string_insert_at(String str, unsigned int pos, char* strAdd){
    if (str->chunkSize<pos){
        if(str->next!=NULL){
            str->next=string_insert_at(str->next, pos-(str->chunkSize), strAdd);
        }
        else {
            str->next=string_new(strAdd);
        }
        return str;
    }
    else{
        char* content = str->chunk;
        String strN = string_new(strAdd);
        free(str->chunk);
        for (int i = 0; i<(pos-1); i++){
            str->chunk[i]=content[i];
        }
        strN=string_insert_at(strN,string_length(strN)+1,&(content[pos-1]));
        strN = add_fin(strN,str->next);
        str->next=strN;
        return str;
    }
}

int main(void){
    String s = string_new("HELLO !");
    printf("%s%s\n",s->chunk,s->next->chunk);
    printf("%d\n",string_length(s));
    // s = string_insert_at(s,7,"les pros du C");
    // String s1=s;
    // while(s1!=NULL){
    //     printf("%s",s->chunk);
    //     s1=s1->next;
    // }
    // printf("\n");
    detruire_r(s);
	return EXIT_SUCCESS;
}