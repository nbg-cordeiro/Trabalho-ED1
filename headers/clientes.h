#ifndef CLIENTE_H
#define CLIENTE_H

#include "auxiliares.h"
#include <string.h>

typedef struct Cliente{
    char* cpf;
    char* nome;
    char* telefone;
    char* dataNascimento;
    Node* carrinho;
}Cliente;

typedef struct node_Cliente{
    Cliente *data;
    node_Cliente *proximo;

}node_Cliente;

void editarCliente(Cliente**);
Cliente buscarCPF(char*);
void removerCliente(Node*, Cliente);
Cliente* criarCliente();
void criarCarrinho(Cliente*);

#endif