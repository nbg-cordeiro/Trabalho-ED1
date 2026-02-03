#ifndef CLIENTE_H
#define CLIENTE_H

#include "auxiliares.h"
#include "produtos.h"

typedef struct Cliente{
    char* cpf;
    char* nome;
    char* email;
    char* telefone;
    char* dataNascimento;
    NodeProduto* carrinho;
}Cliente;

typedef struct NodeCliente{
    Cliente* data;
    struct NodeCliente* proximo;

}NodeCliente;

void InserirNode(NodeCliente**, Cliente*);
void imprimeCliente(Cliente*);
void imprimirClientes(NodeCliente*);
void criarCliente(NodeCliente**);
void editarCliente(NodeCliente**);
NodeCliente** buscarCPF(NodeCliente**,char*);
void buscarCliente(NodeCliente**);
void freeCliente(Cliente**, NodeProduto**);
void removerCliente(NodeCliente**, NodeProduto**);
void free_ListaClientes(NodeCliente**, NodeProduto**);

#endif