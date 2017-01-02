#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

Lista* lst_cria(){
    return NULL;
}

void lst_insere(Lista** l, char* v, int linha, int qtd_repet){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    strcopia(v,novo->info);
    novo->linha = linha;
    novo->qtd_repet = qtd_repet;
    novo->prox = *l;
    *l = novo;
}

void lst_imprime(Lista* l){
    Lista* p;
    for(p=l; p != NULL; p=p->prox){
        printf("Palavra: %s\n%d vez(es)\nLinha %d \n",p->info,p->qtd_repet,p->linha);
        printf("---------------------------------------------------------------------\n");
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

void strcopia(char *orig, char *dest)
{
    int i;
    for (i=0;orig[i]!='\0';i++)
    {
        dest[i]=orig[i];
    }
    dest[i]='\0';
}

int strtam(char *str)
{
    int i;
    for (i=0;str[i]!='\0';i++)
    {

    }
    return i;
}
void strconcatena(char *str, char str2)
{
    int i,tam=strtam(str);
    for (i=tam;i<tam+1;i++){
        if (str2 != '\n')
            str[i]=str2;
    }
    str[i]='\0';
}

int compara(char str[], char str2[]){
    int i;
    for (i=0;str[i]!='\0' && str2!='\0';i++){
        if (str[i]>str2[i])
            return -1;
        else if(str[i]<str2[i])
            return 1;
    }
        return 0;
}

void lst_conta(Lista* l,Lista** dicionario){//função para contar as repetições das palavras em cada linha
    Lista* p;
    Lista* aux;
    int repet;
    for(p=l; p!=NULL; p=p->prox){
        repet = 1;
        for(aux=p->prox; aux!=NULL;aux=aux->prox){
            if(compara(p->info,aux->info)==0){
                if(p->linha==aux->linha){
                    repet++;
                    strcopia("vvisto",aux->info);//as palavras ja contabilizadas recebem "vvisto"
                }
            }
        }
        if(compara(p->info,"vvisto")!=0)//se for uma palavra ja contabilizada não adiciona a lista
            lst_insere(dicionario, p->info, p->linha, repet);
    }
}

void organiza_Dicionario(Lista** dic){
    Lista* novoDic;
    novoDic = lst_cria();
    Lista* p;
    Lista* q;
    Lista* verifica;
    int a;//variavel para saber se a palavra ja foi inserida no novoDci
    for(p=*dic; p!=NULL; p=p->prox){
        a = 0;
        for(verifica=novoDic;verifica!=NULL;verifica=verifica->prox){
            if(compara(verifica->info,p->info)==0)
                a = 1;
        }
        if(a==0) //se a=0 insere a palavra
            lst_insere(&novoDic,p->info,p->linha,p->qtd_repet);
        for(q=p->prox;q!=NULL;q=q->prox){
            if(compara(p->info,q->info)==0){
                lst_insere(&novoDic,q->info,q->linha,q->qtd_repet);
            }
        }
    }
    *dic = novoDic;
}
