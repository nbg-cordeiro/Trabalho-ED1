#ifndef PRODUTOS_H
#define PRODUTOS_H
#include "auxiliares.h"

typedef struct Produto{
    char* codigo;
    char* nome;
    double preco;
    int quantidade;
}Produto;

typedef struct node_Produto{
    Produto* data;
    struct node_Produto* proximo;
    
}node_Produto;


Produto* criarProduto();
void imprimirProduto(Produto*);
void editarProduto(NodeProduto**);
void removerProduto(NodeProduto*, Produto*);
void listarProdutos(NodeProduto*);
NodeProduto** buscarProduto(NodeProduto**, char*);
void freeProdutos(NodeProduto**);
void adicionarProduto(NodeProduto**);

#endif