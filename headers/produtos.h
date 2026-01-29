#ifndef PRODUTOS_H
#define PRODUTOS_H
#include "auxiliares.h"

typedef struct Produto{
    char* codigo;
    char* nome;
    double preco;
}Produto;

Produto* criarProduto();
void imprimirProduto(Produto*);
void editarProduto(Produto*);
void removerProduto(Node*, Produto*);
void listarProdutos(Node*);
void freeProduto(Produto**);

#endif