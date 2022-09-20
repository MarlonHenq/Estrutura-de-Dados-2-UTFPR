#include <stdio.h>
#include <stdlib.h>

typedef struct TNoABP{
    int chave;
    struct TNoABP *esq;
    struct TNoABP *dir;
}TNoABP;

//typedef struct TNoABP TNoABP;


//Busca - Retorna ponteiro tal que p->chave igual k ou nulo
TNoABP *bucaNo(TNoABP *raiz, int k){
    if (raiz == NULL){
        return NULL;
    }

    if (raiz->chave == k){
        return raiz;
    }

    if (k < raiz->chave){
        return bucaNo(raiz->esq, k);
    }
    else{
        return bucaNo(raiz->dir, k);
    }
}

/*
Recebe o ponteiro de ponteiro para o raiz de uma subarvore e uma chave de busca k
devolve o ponteiro de ponteiro para k ou null
obs como pp deriva de um &, assumimos que pp é não nulo
*/

TNoABP **buscaPP(TNoABP **pp, int k){
    if (*pp == NULL)
        return NULL;
    
    if ((*pp)->chave == k)
        return pp;
    
    if (k < (*pp)->chave)
        return buscaPP(&((*pp)->esq), k);
    else
        return buscaPP(&((*pp)->dir), k);
}

//dado o ponteiro de ponteiro para o no raiz de uma (sub)arvore, devolve o ponteiro de ponteiro para o maior no desata (sub)arvore
//ou NULL caso tal arvore seja vazia.
TNoABP **ppMaior(TNoABP **pp){
    if(*pp == NULL) //caso base, arvore vaiza
        return NULL;
    
    if ((*pp)->dir == NULL)
        return pp;
    
    return ppMaior(&((*pp)->dir));
}

removeNo(TNoABP **root, int k){
    TNoABP **noPai = buscaPP(root, k);
    TNoABP **noFilho = NULL;

    if (noPai == NULL)
        return NULL;
    
    if ((*noPai)->dir == k){
        *noFilho == &((*noPai)->dir);
    }
    else if ((*noPai)->esq == k){
        *noFilho == &((*noPai)->esq);
    }
    else{
        return NULL;
    }

    if ((*noFilho)->dir == NULL && (*noFilho)->esq == NULL){ //Folha
        free(noFilho);
        noFilho == NULL;
    }

    
}

isLeaf(TNoABP *p){ //Função "é folha?", recebe um ponteiro para nó
    if (p == NULL){ //Verifica se é nulo
        return 0;
    }

    if (p->esq == NULL && p->dir == NULL){ //Caso aponte para dois nulos
        return 1;
    }
    else{
        return 0;
    }
}

insereNo(TNoABP *raiz, int k){
    if (raiz == NULL){
        //Aloca em raiz
    }
    else{
        if (k < raiz->chave){ //a esquerda

        }
        else{//A direita

        }
    }
}

int main(){

    return 0;
}