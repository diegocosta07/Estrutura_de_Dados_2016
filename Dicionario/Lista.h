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
int compara(char str[], char str2[]);//fun��o para comparar strings
int strtam(char *str);//fun��o para saber o tamanho das strings
void strconcatena(char *str, char str2);//fun��o para concatenar strings
void lst_conta(Lista* l, Lista** dicionario);//fun��o para contar o numero de repeti��es de palavras em cada linha
int verifica_Insercao(Lista* l,char str[]);//fun��o para verificar a inser��o da palavra no  novo dicionario
void organiza_Dicionario(Lista** dic);//fun��o para organizar o dicion�rio, criando o encadeamento das palavras iguais
