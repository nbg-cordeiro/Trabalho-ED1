#ifndef CLIENTE_H
#define CLIENTE_H

#include "auxiliares.h"
#include "produtos.h"
#include <string.h>

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

void editarCliente(node_Cliente *head);
node_Cliente* buscarCPF(char*, node_Cliente*);
void removerCliente(node_Cliente**);
void imprimirClientes(node_Cliente **);
void criarCliente(node_Cliente *);
void criarCarrinho(Cliente*);
void free_ListaClientes(node_Cliente**);

#endif