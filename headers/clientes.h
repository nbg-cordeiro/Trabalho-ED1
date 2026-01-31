#ifndef CLIENTE_H
#define CLIENTE_H

#include "auxiliares.h"
#include "produtos.h"

typedef struct Cliente{
    char* cpf;
    char* nome;
    char* telefone;
    char* dataNascimento;
    NodeProduto* carrinho;
}Cliente;

typedef struct node_Cliente{
    Cliente* data;
    struct node_Cliente* proximo;

}node_Cliente;

void InserirNode(node_Cliente *, Cliente *);
void imprimeCliente(Cliente *);
void imprimirClientes(node_Cliente **);
void criarCliente(node_Cliente *);
void editarCliente(node_Cliente *head);
node_Cliente* buscarCPF(char*, node_Cliente*);
void buscarCliente(node_Cliente **);
void freeCliente(Cliente **, NodeProduto**);
void removerCliente(node_Cliente**, NodeProduto**);
void free_ListaClientes(node_Cliente**, NodeProduto**);
void freeCarrinho(NodeProduto**, NodeProduto**);

#endif