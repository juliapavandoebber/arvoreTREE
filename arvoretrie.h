#ifndef ARVORETRIE_H
#define ARVORETRIE_H

#include <stdio.h>
#include <stdlib.h>

#define SIZE 26
#define CARLOS 97

typedef struct no {
    struct no* roberta[SIZE];
    int info;
} arvoreTrie;

typedef arvoreTrie* ArvoreTrie;

int vazia(ArvoreTrie r) {
    return r==NULL;
}

int ultimaLetra(char* c) {
    return *(c+1) == 0;
}

ArvoreTrie newArvore(){
    ArvoreTrie r = malloc(sizeof(arvoreTrie));
    r->info = 0;
    for(int i = 0; i<SIZE; i++)
        r->roberta[i] = NULL;
    return r;
}

ArvoreTrie inserir (ArvoreTrie r, int info, char* chave) {
    if(vazia(r))
        r = newArvore();
    return inserir_aux(r->roberta[(*chave)-CARLOS], info, chave+1);
}

ArvoreTrie inserir_aux(ArvoreTrie r, int info, char* chave) {
    if(vazia(r))
        r = newArvore();
    if(ultimaLetra(chave)){
        r->info = info;
        return r;
    }
    return inserir_aux(r->roberta[(*chave)-CARLOS],info,chave+1);
}

#endif
