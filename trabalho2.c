//Marlon Henrique Sanches

/*Para compila-lo utilize no terminal em mesmo diretório “gcc trabalho2.c”,
isso gerará um “a.out” que após a digitação no mesmo terminal de “./a.out” executará o programa.
*/

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

    return no;
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
                insereNo(&((*raiz)->esq), k);
            }
        }
        else{//A direita
            if ((*raiz)->dir == NULL){
                (*raiz)->dir = alocaNo(k);
            }
            else{
                insereNo(&((*raiz)->dir), k);
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

int folhasCount(TNoABP *raiz){
    if (raiz == NULL){
        return 0;
    }

    int count = 0;

    if (raiz->esq == NULL && raiz->dir == NULL){
        count++;
    }

    count = count + folhasCount(raiz->dir);
    count = count + folhasCount(raiz->esq);

    return count;

}

int menorValor(TNoABP *raiz){ //Percorre todos os valores, mas não é tão optimizada para uma arvore binária de pesquisa
    if (raiz == NULL){
        return NULL;
    }

    int menor = raiz->chave;

    if(menor > menorValor(raiz->esq) && menorValor(raiz->esq) != NULL){
        menor = menorValor(raiz->esq);
    }

    if(menor > menorValor(raiz->dir) && menorValor(raiz->dir) != NULL){
        menor = menorValor(raiz->dir);
    }

    return menor;
}

int menorValor2(TNoABP *raiz){ //Versão optimizada para uma arvore binária de pesquisa
    if (raiz == NULL){
        return NULL;
    }

    while (raiz->esq != NULL){
        raiz = raiz->esq;
    }

    return raiz->chave;   
}

int quantidadeNos(TNoABP *raiz){
    if (raiz == NULL){
        return 0;
    }

    int count = 1;

    count = count + quantidadeNos(raiz->dir);
    count = count + quantidadeNos(raiz->esq);

    return count;
}

int somaNos(TNoABP *raiz){
    if (raiz == NULL){
        return 0;
    }

    int soma = raiz->chave;

    soma = soma + somaNos(raiz->dir);
    soma = soma + somaNos(raiz->esq);

    return soma;
}

int mediaNos(TNoABP *raiz){
    if (raiz == NULL){
        return 0;
    }

    int soma = somaNos(raiz);
    int quantidade = quantidadeNos(raiz);

    return soma/quantidade;
}

void removeNo(TNoABP *pontParaNo){
    if (pontParaNo->esq == NULL && pontParaNo->dir == NULL){ //Se for uma folha (o que não será, mas assim o codigo fica completo)
        free(pontParaNo);
    }
    else if (pontParaNo->esq == NULL){ //Se só tiver filho a direita
        pontParaNo->chave = pontParaNo->dir->chave;
        pontParaNo->esq = pontParaNo->dir->esq;
        pontParaNo->dir = pontParaNo->dir->dir;
    }
    else if (pontParaNo->dir == NULL){ //Se só tiver filho a esquerda
        pontParaNo->chave = pontParaNo->esq->chave;
        pontParaNo->dir = pontParaNo->esq->dir;
        pontParaNo->esq = pontParaNo->esq->esq;
    }
    else{ //Se tiver os dois filhos
        TNoABP *aux = pontParaNo->dir; //Menor valor a direita

        while (aux->esq != NULL){
            aux = aux->esq;
        }

        pontParaNo->chave = aux->chave;
        removeNo(aux);
    }
}

void removeArvore(TNoABP **raiz){
    if (*raiz == NULL){
        return;
    }

    removeArvore(&((*raiz)->esq));
    removeArvore(&((*raiz)->dir));

    free(*raiz);
    *raiz = NULL;
}


int main(){
    TNoABP *raiz;

    insereNo(&raiz, 5);
    insereNo(&raiz, 10);
    insereNo(&raiz, 2);
    insereNo(&raiz, 12);

    // printf("%d\n", raiz->chave);
    // printf("%d\n", raiz->dir->chave);
    // printf("%d\n", raiz->esq->chave);
    // printf("%d\n", raiz->dir->dir->chave);

    imprimeArvore(raiz);

    printf("FOLHAS: %d\n",folhasCount(raiz));

    printf("MENOR: %d\n",menorValor(raiz));
    printf("MENOR: %d\n",menorValor2(raiz));

    printf("Quantidade de Nós: %d\n", quantidadeNos(raiz));

    printf("Soma dos Nós: %d\n", somaNos(raiz));

    printf("Media dos Nós: %d\n", mediaNos(raiz));

    removeNo(raiz->dir);

    imprimeArvore(raiz);

    removeArvore(&raiz);

    imprimeArvore(raiz);


    printf("++++++++++++++++++++=\n");

    insereNo(&raiz, 5);
    insereNo(&raiz, 10);
    insereNo(&raiz, 2);
    insereNo(&raiz, 12);

    imprimeArvore(raiz);

    removeArvore(&raiz);

    imprimeArvore(raiz);

    return 0;
}
