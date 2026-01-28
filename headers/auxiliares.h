#ifndef AUXILIARES_H
#define AUXILIARES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    void* conteudo;
    struct Node* proximo;
    struct Node* anterior;
} Node;

void limpaBuffer(void);
void limpaConsole(void);
char* lerString(void);
void freeLista(Node** lista);
void salvarLista(Node*);
Node* lerLista(char);

#endif