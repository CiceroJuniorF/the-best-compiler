#include<stdio.h>

#ifndef SCAN_H
#define SCAN_H

// declaração de constantes
#define MAXNUM 9
#define MAXOP 2
#define MAXNAME 255
#define TAMSTR 50



// declaraçã de tipos

typedef struct tokens{
int id;
int linha;
int coluna;
char *nome;
struct tokens *prox;
}Tk;


typedef struct simbolos{
int n; // número
int id; // ponteiro=0, constante=1, variável=2
int linha;
char *nome;
int tipo; // int =0, char = 1, float = 2, double=3, struct =4
int bytes; //
}simbolos;


// declaração das funções globais
Tk *getTokens(char *nome);
void insereTk(Tk *TkList, Tk *elemento );
void exibeTk(Tk *TkList);
void removeTk(Tk *TkList, int chave);
void liberaTk(Tk *TkList);
void buscaTk(char *var);

#endif
