#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
int strlen(char *str)
{
    int i;
    for (i=0;str[i]!='\0';i++)
    {

    }
    return i;
}
void strcat(char *str, char str2)
{
    int i,tam=strlen(str);
    for (i=tam;i<tam+1;i++)
        str[i]=str2;
    str[i]='\0';
}
int main()
{
    FILE* arq = fopen("teste.txt","r");
    Lista* dicionario;
    dicionario = lst_cria();
    //Lista* l;
    //l = lst_cria();
    char frase[250];
    char palavra[20];
    int i,linha=0;
    if(arq == NULL){
        printf("Erro na abertura do arquivo.\n");
        system("pause");
        exit(1);
    }
    while(!feof(arq)){
        i = 0;
        fgets(frase,249,arq);
        palavra[0]='\0';
        //printf("%s\n",frase);
        while(frase[i] != '\0'){
            if(frase[i] != ' '){
                strcat(palavra,frase[i]);
                //printf("%c",frase[i]);
            }else{
                lst_insere(&dicionario,palavra,linha,1);
                //printf("%s\n",palavra);
                palavra[0]='\0';
            }
            i++;
            if (frase[i]=='\0')
                lst_insere(&dicionario,palavra,linha,1);
        }
        linha++;
        //printf("%s\n",palavra);
    }
    lst_imprime(dicionario);
    //lst_libera(l);
    lst_libera(dicionario);
    return 0;
}
