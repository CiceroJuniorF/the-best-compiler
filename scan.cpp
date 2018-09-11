#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include "scan.h"

// variaveis globais
int linha;
int coluna;
char look;
char token[256];
int ntoken;


// funções locais
FILE *abreArq(char *nome);
void nextChar(FILE *p);
void scan(FILE *P);
void skipWhite(FILE *p);
void newLine(FILE *p);
void getWord(FILE *p);
void getNum(FILE *p);
void getOp(FILE *p);
void skipComment(FILE *p);
void getOp(FILE *p);
int isOp(char c);
void getNum(FILE *p);

/***********************************************
 * Nome: getTokens
 * desc: obtém todos os tokens do arquivo nome
 * returno: ponteiro para a lista de tokens
 ***********************************************/
Tk *getTokens(char *nome)
{
    Tk *TkList=NULL, *elemento=NULL;
    FILE *P;

    return TkList;
}

/*********************************
 * Nome: scan
 * desc:
 * returno:
 ********************************/
void scan(FILE *p)
{

}

/*********************************
 * Nome: abreArq
 * desc:
 * returno:
 ********************************/
FILE *abreArq(char *nome)
{
    char *var;
    FILE *in;

    // aqui tem um exemplo do uso da função strstr

    var = strstr(nome,".c");
    if(var ==NULL) // O ARQUIVO NÃO TEM EXTENÇÃO
    {
        printf("Arquivo : %s invalido!\n",nome);
        exit(1); // cada erro será tratado com uma saída diferente de 0.
    }
    in = fopen(nome,"r");
    if(in == NULL)
    {
        printf("Nao foi possivel abrir o arquivo %s \n",nome);
        exit(3);
    }
    return in;
}

/*********************************
 * Nome: insereTk
 * desc:
 * returno: void
 ********************************/
void insereTk(Tk *TkList, Tk *TkElemento)
{
    Tk *ptr;


}

/*********************************
 * Nome: exibeTk
 * desc:
 * returno: void
 ********************************/
void exibeTk(Tk *TkList)
{
    Tk *ptr;

}

/*********************************
 * Nome: removeTk
 * desc:
 * returno: void
 ********************************/
void liberaTk(Tk *TkList)
{
    Tk *T,*ptr;

}

/*********************************
 * Nome: buscaTk
 * desc:
 * returno: void
 ********************************/
void removeTk(Tk *TkList, int chave)
{

}

/*********************************
 * Nome: nextChar
 * desc:
 * returno:
 ********************************/
void nextChar(FILE *p)
{
    if(look !=EOF) // EOF(End Of File)
    {
        look = getc(p);
    }
}

/*********************************
 * Nome: removeSpace
 * desc:
 * returno:
 ********************************/
void skipWhite(FILE *p)
{
    while (look == ' ' || look == '\t')
        nextChar(p);
}

/*********************************
 * Nome: removeSpace
 * desc:
 * returno:
 ********************************/
void newLine(FILE *p)
{

}

/*********************************
 * Nome: skipComment
 * desc:
 * returno:
 ********************************/
void skipComment(FILE *p)
{

}

/*********************************
 * Nome: getNum
 * desc:
 * returno:
 ********************************/
void getNum(FILE *p)
{
    int i;

}

/*********************************
 * Nome: getWord
 * desc:
 * returno:
 ********************************/
void getWord(FILE *p)
{
    int i;

}

/*********************************
 * Nome: getOp
 * desc:
 * returno:
 ********************************/
void getOp(FILE *p)
{
    int i;


}

/*********************************
 * Nome: isOp
 * desc:
 * returno:
 ********************************/
int isOp(char c)
{
    return (strchr("#.+-*/<>:=!", c) != NULL); //Returns a pointer to the first occurrence of character in the C string str.
}
