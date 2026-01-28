#include "produtos.h"

void printarProduto(Produto produto){
    printf("%s - %s - %.2lf", produto.codigo, produto.nome, produto.preco);
}

void criarProduto(){
    Produto novoProduto;
    printf("Novo produto:\nCodigo: ");
    char* codigo = lerString();
    novoProduto.codigo=codigo;
    printf("Nome: ");
    char* nome = lerString();
    novoProduto.nome=nome;
    double preco;
    do{
        printf("Preco: ");
        int control = scanf("%lf", &preco);
        if(control!=1){
            perror("Valor invalido!");
            preco = -1;
        }
    }while(preco>=0);
    novoProduto.preco = preco;
    printarProduto(novoProduto);
}