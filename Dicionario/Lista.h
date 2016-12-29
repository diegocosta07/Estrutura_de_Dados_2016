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
void strcopia(char *orig, char *dest);
int compara(char str[], char str2[]);
int strtam(char *str);
void strconcatena(char *str, char str2);
void lst_conta(Lista* l, Lista** dicionario);
void organiza_Dicionario(Lista** dic);
