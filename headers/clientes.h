#ifndef CLIENTE_H
#define CLIENTE_H
#include "auxiliares.h"

typedef struct Cliente{
    char* cpf;
    char* nome;
    char* telefone;
    Node* carrinho;
}Cliente;

void editarCliente(Cliente*);
Cliente buscarCPF(Node*);
void removerCliente(Node*, Cliente);
Cliente criarCliente(char*,char*,char*);
void criarCarrinho(Cliente*);

#endif