#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
int main()
{
    FILE* arq = fopen("teste.txt","r");
    Lista* dicionario;
    dicionario = lst_cria();
    Lista* l;
    l = lst_cria();
    char frase[250];//recebe linha por linha do arquivo teste.txt
    char palavra[20];//recebe a concatena��o dos caracteres das frases do arquivo
    int i,linha=0;//posi��o do caractere no vetor de char e a linha do arquivo respectivamente
    if(arq == NULL){
        printf("Erro na abertura do arquivo.\n");
        system("pause");
        exit(1);
    }
    while(!feof(arq)){
        i = 0;
        fgets(frase,249,arq);//pega cada linha do arquivo teste.txt
        palavra[0]='\0';//atribui '/0' para uma string
        while(frase[i] != '\0'){
            if(frase[i] != ' '){
                /*enquanto n�o chegar a um espa�o as letras s�o concatenadas*/
                strconcatena(palavra,frase[i]);
            }else{
                /*ao chegar no espa�o a palavra � inserida na lista*/
                lst_insere(&l,palavra,linha,1);
                //printf("%s\n",palavra);
                palavra[0]='\0';//a palavra � resetada
            }
            i++;
        }
        lst_insere(&l,palavra,linha,1);//ao fim do arquivo a ultima palavra � inserida
        linha++;
    }
    lst_conta(l,&dicionario);//contabiliza a repeti��o das palavras em cada linha
    organiza_Dicionario(&dicionario);//� criada o dicionario final
    lst_imprime(dicionario);
    lst_libera(l);
    lst_libera(dicionario);
    fclose(arq);
    return 0;
}
