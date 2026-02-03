#include "persistencia.h"

void salvarProdutos(NodeProduto* lista){
    FILE* escrita = fopen("dados/produtos.csv", "w");
    if (escrita == NULL)
        return;
    while (lista != NULL){
        fprintf(escrita, "%s;%s;%.2lf;%d\n", lista->produto->codigo, lista->produto->nome, lista->produto->preco, lista->produto->quantidade);
        lista = lista->proximo;
    }
    fclose(escrita);
}

void carregarProdutos(NodeProduto** lista){
    FILE* leitura = fopen("dados/produtos.csv", "r");
    if (leitura == NULL)
        return;

    char cod[201], nome[201];
    double preco;
    int qtd;

    while(fscanf(leitura, " %200[^;];%200[^;];%lf;%d\n", cod, nome, &preco, &qtd) == 4){
        Produto* produto = malloc(sizeof(Produto));
        produto->codigo = copiarString(cod);
        produto->nome = copiarString(nome);
        produto->preco = preco;
        produto->quantidade = qtd;

        NodeProduto* novo = malloc(sizeof(NodeProduto));
        if(novo==NULL){
            perror("Erro ao alocar memoria em carregarProdutos()");
            exit(EXIT_FAILURE);
        }
        novo->produto = produto;
        novo->proximo = *lista;
        *lista = novo;
    }
    fclose(leitura);
}

void salvarClientes(NodeCliente* lista){
    FILE* escrita = fopen("dados/clientes.csv", "w");
    if (escrita == NULL)
        return;

    while (lista != NULL){
        fprintf(escrita, "%s;%s;%s;%s;%s\n", lista->data->cpf, lista->data->nome, lista->data->email, lista->data->telefone, lista->data->dataNascimento);
        lista = lista->proximo;
    }
    fclose(escrita);
}

void carregarClientes(NodeCliente** lista){
    FILE* leitura = fopen("dados/clientes.csv", "r");
    if (leitura == NULL)
        return;

    char cpf[21], nome[201], email[201], tel[21], nasc[21];
    while (fscanf(leitura, " %20[^;];%200[^;];%200[^;];%20[^;];%20[^\n]\n", cpf, nome, email, tel, nasc) == 5){
        Cliente* cliente = malloc(sizeof(Cliente));
        if(cliente==NULL){
            perror("Erro ao alocar memoria em carregarClientes()");
            exit(EXIT_FAILURE);
        }
        cliente->cpf = copiarString(cpf);
        cliente->nome = copiarString(nome);
        cliente->email = copiarString(email);
        cliente->telefone = copiarString(tel);
        cliente->dataNascimento = copiarString(nasc);
        cliente->carrinho = NULL;

        InserirNode(lista, cliente);
    }
    fclose(leitura);
}

void salvarCarrinhos(NodeCliente* lista) {
    FILE* escrita = fopen("dados/carrinhos.csv", "w");
    if (escrita == NULL)
        return;

    while (lista != NULL){
        NodeProduto* item = lista->data->carrinho;

        while (item != NULL){
            fprintf(escrita, "%s;%s;%d\n", lista->data->cpf, item->produto->codigo, item->produto->quantidade);
            item = item->proximo;
        }

        lista = lista->proximo;
    }
    fclose(escrita);
}

void carregarCarrinhos(NodeCliente** listaClientes, NodeProduto** listaEstoque) {
    FILE* leitura = fopen("dados/carrinhos.csv", "r");
    if (leitura == NULL)
        return;

    char cpf[21], codProd[201];
    int qtd;

    while (fscanf(leitura, " %20[^;];%200[^;];%d\n", cpf, codProd, &qtd) == 3){
        NodeCliente** clienteNode = buscarCPF(listaClientes, cpf);
        NodeProduto** produtoEstoque = buscarProduto(listaEstoque, codProd);

        if (clienteNode && *clienteNode && produtoEstoque && *produtoEstoque){
            NodeProduto* novoItem = malloc(sizeof(NodeProduto));
            if(novoItem==NULL){
                perror("Erro ao alocar memoria em carregarCarrinho()");
                exit(EXIT_FAILURE);
            }
            novoItem->produto = malloc(sizeof(Produto));
            if(novoItem->produto==NULL){
                perror("Erro ao alocar memoria em carregarCarrinho()");
                exit(EXIT_FAILURE);
            }
            
            novoItem->produto->codigo = copiarString((*produtoEstoque)->produto->codigo);
            novoItem->produto->nome = copiarString((*produtoEstoque)->produto->nome);
            novoItem->produto->preco = (*produtoEstoque)->produto->preco;
            novoItem->produto->quantidade = qtd;

            novoItem->proximo = (*clienteNode)->data->carrinho;
            (*clienteNode)->data->carrinho = novoItem;
        }
    }
    fclose(leitura);
}