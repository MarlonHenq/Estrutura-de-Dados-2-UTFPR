#include <stdio.h>
#include <stdlib.h>

typedef struct TNoABP{
    int chave;
    struct TNoABP *esq;
    struct TNoABP *dir;
}TNoABP;

TNoABP *alocaNo(int k){
    TNoABP *no = (TNoABP *) malloc(sizeof(TNoABP));

    no->chave = k;
    no->dir = NULL;
    no->esq = NULL;

    return &no;
}

void insereNo(TNoABP **raiz, int k){
    if ((*raiz) == NULL){
        *raiz = alocaNo(k);
    }
    else{
        if (k < ((*raiz)->chave)){ //a esquerda
            if ((*raiz)->esq == NULL){
                (*raiz)->esq = alocaNo(k);
            }
            else{
                insereNo(((*raiz)->esq), k);
            }
        }
        else{//A direita
            if ((*raiz)->dir == NULL){
                (*raiz)->dir = alocaNo(k);
            }
            else{
                insereNo(((*raiz)->dir), k);
            }
        }
    }
}

void imprimeArvore(TNoABP *raiz){
    if (raiz == NULL){
        return;
    }
    
    printf("%d\n", raiz->chave);

    imprimeArvore(raiz->esq);
    imprimeArvore(raiz->dir);

}

int main(){

    TNoABP *raiz = NULL;

    insereNo(&raiz, 10);
    insereNo(&raiz, 15);
    //insereNo(&raiz, 5);

    imprimeArvore(raiz);
    

    return 0;
}