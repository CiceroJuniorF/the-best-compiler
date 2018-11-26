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
    linha = 1;
    char *str;
    FILE *p;
    p = abreArq(nome);
    nextChar(p);
    ntoken =0;
    while(!feof(p)) // feof returna verdadeiro se p apontar para o final do arquivo.
    {
        scan(p);
        str = (char*) malloc (sizeof(char)*strlen(token));
        strcpy(str,token);
        elemento = (Tk*) malloc (sizeof(Tk));
        elemento->nome=str;
        elemento->linha=linha;
        elemento ->prox =NULL;

        if(TkList==NULL) // primeira posição
            TkList = elemento;
        else // demais posições
            insereTk(TkList,elemento);
        ntoken++;
      //  printf("token %d: %s\n",ntoken,token);

    }
    return TkList;
}

/*********************************
 * Nome: scan
 * desc:
 * returno:
 ********************************/
void scan(FILE *p)
{
    if(look == ' ')
        skipWhite(p);

    if(look == '/')
        skipComment(p);
//   printf("scan\n");
    while (look == '\n'|| look == 13) //19-11-14 ADICIONADO || look == 13, resolver problema com arquivos com "carriage return = 13"
    {
        newLine(p);

        if(look == ' ')
            skipWhite(p);

        if(look == '/')
            skipComment(p);
    }

    skipWhite(p);

    if (isalpha(look))      /*A função isalpha(c) retorna TRUE se c for uma letra ou retorna FALSE caso contrario. */
        getWord(p);

    else if (isdigit(look)) /*A função isalnum(c) retorna TRUE se c for letra ou digito ou retorna FALSE caso contrario */
        getNum(p);

    else if (isOp(look))
        getOp(p);

    else if(look == '/')
    {
        skipComment(p);
    }

    else
    {
        token[0] = look;
        token[1] = '\0';

        nextChar(p);
    }
    skipWhite(p);
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

    for(ptr=TkList; ptr->prox!=NULL; ptr=ptr->prox); //indo para o final do arquivo
    ptr->prox=TkElemento;

}

/*********************************
 * Nome: exibeTk
 * desc:
 * returno: void
 ********************************/
void exibeTk(Tk *TkList)
{
    Tk *ptr;
    int num=-1,caracter=0;
    int lin=0;

    for(ptr=TkList; ptr->prox!=NULL; ptr=ptr->prox) //indo para o final do arquivo
    {
        if( num != ptr->linha )
        {
            num = ptr->linha;
            printf("\nlinha %d:",num);
           lin++;
        }
        printf(" %s",ptr->nome);
        caracter++;

    }
    printf("\nTotal de Linhas: %d\n",lin);
    printf("Total de caracteres: %d\n",caracter);
}

/*********************************
 * Nome: removeTk
 * desc:
 * returno: void
 ********************************/
void liberaTk(Tk *TkList)
{
    Tk *T,*ptr;
    for(ptr=TkList; ptr->prox!=NULL; ptr=ptr->prox)
    {
        T = ptr->prox;
        free(ptr);
        ptr = T;
    }
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
    // aqui apresenta o tratamento de um arquivo cuja
    // a linha é finalizada no padrão windows ou linux
    if(look =='\n' )  // window
    {
        nextChar(p);
        //if( look !='\0' && look !=EOF)
        //{
         //   printf("erro na linha %d coluna %d\n",linha,coluna);

        //}
        if(look=='\0')
         nextChar(p);
        linha++;
    }
    else if(look=='\0')
    {
        nextChar(p);
        linha++;
    }
}

/*********************************
 * Nome: skipComment
 * desc:
 * returno:
 ********************************/
void skipComment(FILE *p)
{
    while (look != '\n' && look != 13)
        nextChar(p);
}

/*********************************
 * Nome: getNum
 * desc:
 * returno:
 ********************************/
void getNum(FILE *p)
{
    int i;

    // if (!isdigit(look))
    //     expected("Integer");

    for (i = 0; isdigit(look) && i < MAXNUM; i++)
    {

        token[i] = look;
        nextChar(p);

    }
    token[i] = '\0';
    skipWhite(p);

}

/*********************************
 * Nome: getWord
 * desc:
 * returno:
 ********************************/
void getWord(FILE *p)
{
    int i;
     for (i = 0; isalpha(look) && i < MAXNAME; i++)
    {

        token[i] = look;
        nextChar(p);

    }
    token[i] = '\0';
    skipWhite(p);
}

/*********************************
 * Nome: getOp
 * desc:
 * returno:
 ********************************/
void getOp(FILE *p)
{
    int i;

    //if (!isOp(look))
    //    expected("Operator");

    for (i = 0; isOp(look) && i < MAXOP; i++)
    {

        token[i] = look;
        nextChar(p);
        if( (token[i]=='/'&&look=='/') || (token[i]=='/'&&look=='*') )
         {
              skipComment(p);
              token[0] = '\0';
              return;
         }

    }
    token[i] = '\0';
    skipWhite(p);
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

