#ifndef PRODUTOS_H
#define PRODUTOS_H
#include "auxiliares.h"

typedef struct Produto{
    char* codigo;
    char* nome;
    double preco;
    int quantidade;
}Produto;

typedef struct NodeProduto{
    Produto* produto;
    struct NodeProduto* proximo;
}NodeProduto;


Produto* criarProduto(NodeProduto**);
void imprimirProduto(Produto*);
void editarProduto(NodeProduto**);
void removerProduto(NodeProduto**);
void listarProdutos(NodeProduto*);
NodeProduto** buscarProduto(NodeProduto**, char*);
void freeProdutos(NodeProduto**);
void adicionarProduto(NodeProduto**);
void imprimePorCodigo(NodeProduto**);
double somaProdutos(NodeProduto*);
void listarCarrinho(NodeProduto*);

#endif