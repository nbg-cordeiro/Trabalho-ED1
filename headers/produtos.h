#ifndef PRODUTOS_H
#define PRODUTOS_H
#include "auxiliares.h"

typedef struct Produto{
    char* codigo;
    char* nome;
    double preco;
}Produto;

void criarProduto();
char* ProdToString(Produto*);
void editarProduto(Produto*);
void removerProduto(Node*, Produto*);
void listarProdutos(Node*);

#endif