#ifndef COMPRAS_H
#define COMPRAS_H
#include "clientes.h"
#include "produtos.h"
#include "auxiliares.h"

void listarCarrinho(NodeProduto*);
void adicionarCarrinho(NodeProduto**, NodeProduto**);
void removerCarrinho(NodeProduto**, NodeProduto**);
void freeCarrinho(NodeProduto**, NodeProduto**);

#endif