#ifndef AUXILIARES_H
#define AUXILIARES_H

typedef struct Node{
    void* conteudo;
    struct Node* proximo;
    struct Node* anterior;
} Node;

void limpaBuffer(void);
void limpaConsole(void);
void freeLista(Node** lista);
void salvarLista(Node** lista, char* nomeArquivo);

#endif