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

/*fun��o para contar as repeti��es das palavras em cada linha*/
void lst_conta(Lista* l,Lista** dicionario){
    Lista* p;
    Lista* aux;
    int repet; //varaiavel para contabilizar as repeti��es
    for(p=l; p!=NULL; p=p->prox){
        repet = 1;//inicializa�o das repeti��es com 1
        for(aux=p->prox; aux!=NULL;aux=aux->prox){
            /* se as palavras forem iguais e estiverem na mesma linha 'repet' incrementa 1*/
            if(compara(p->info,aux->info)==0){
                if(p->linha==aux->linha){
                    repet++;
                    strcopia("vvisto",aux->info);//as palavras ja contabilizadas recebem "vvisto"
                }
            }
        }
        /*se for uma palavra ja contabilizada ela n�o � adiciona a lista*/
        /* Se a alguma palavra for='vvisto' ela n�o � adicionada*/
        if(compara(p->info,"vvisto")!=0)
            lst_insere(dicionario, p->info, p->linha, repet);
    }
}
/*fun��o para verifica��o de inser��o no novoDic*/
int verifica_Insercao(Lista* l, char str[]){
    int a = 0;//funciona como um sinalizador para saber se a palvra ja foi inserida ou n�o
    Lista* verifica;
        for(verifica=l;verifica!=NULL;verifica=verifica->prox){
            /*se a palavra ja est� em novoDic ent�o a=1 para sinalizar que tal palavra j� est� inserida*/
            if(compara(verifica->info,str)==0)
                a = 1;
        }
    return a;//a=0 palavra n�o inserida, a=1 palavra j� inserida
}

/*Esta fun��o cria uma nova lista com o encadeamento acertado em as palavras*/
void organiza_Dicionario(Lista** dic){
    Lista* novoDic; //esse ser� o novo dicionario
    novoDic = lst_cria();
    Lista* p;
    Lista* q;
    for(p=*dic; p!=NULL; p=p->prox){
        if(verifica_Insercao(novoDic,p->info)==0) //se a palavra ainda n�o estiver em novoDic ela ser� adicionada agora
            lst_insere(&novoDic,p->info,p->linha,p->qtd_repet);
        for(q=p->prox;q!=NULL;q=q->prox){
            /*Se a palavra estiver em outras linhas ela � inserida no novoDic*/
            if(compara(p->info,q->info)==0){
                lst_insere(&novoDic,q->info,q->linha,q->qtd_repet);
            }
        }
    }
    lst_libera(*dic);//libera a mem�rio do dicionario antigo
    *dic = novoDic;//atualiza o Dicionario principal
}
