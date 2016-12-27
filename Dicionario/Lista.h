struct lista{
    char info[20];
    int qtd_repet;
    int linha;
    struct lista* prox;
}; typedef struct lista Lista;

Lista* lst_cria();
void lst_insere(Lista** l, char* v,int linha, int qtd_repet);
void lst_imprime(Lista* l);
int lst_vazia(Lista* l);
void lst_libera(Lista* l);
void strcpy(char *orig, char *dest);


