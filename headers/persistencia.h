#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H
#include "compras.h"

void salvarProdutos(NodeProduto*);
void carregarProdutos(NodeProduto**);
void salvarClientes(NodeCliente*);
void carregarClientes(NodeCliente**);
void salvarCarrinhos(NodeCliente*);
void carregarCarrinhos(NodeCliente**, NodeProduto**);

#endif