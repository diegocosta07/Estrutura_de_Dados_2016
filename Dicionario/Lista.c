#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

Lista* lst_cria(){
    return NULL;
}

void lst_insere(Lista** l, char* v, int linha, int qtd_repet){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    strcpy(v,novo->info);
    novo->linha = linha;
    novo->qtd_repet = qtd_repet;
    novo->prox = *l;
    *l = novo;
}

void lst_imprime(Lista* l){
    Lista* p;
    for(p=l; p != NULL; p=p->prox){
        printf("info = %s\n",p->info);
        //printf("Apareceu %d na linha %d \n",p->qtd_repet,p->linha);
    }
}

int lst_vazia(Lista* l){
    return (l==NULL);
}

void lst_libera(Lista* l){
    Lista* p = l;
    while (p!=NULL){
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}

void strcpy(char *orig, char *dest)
{
    int i;
    for (i=0;orig[i]!='\0';i++)
    {
        dest[i]=orig[i];
    }
    dest[i]='\0';
}
