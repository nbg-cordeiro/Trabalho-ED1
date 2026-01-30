#include "produtos.h"

void imprimirProduto(Produto* produto){
    printf("%s - %s - R$ %.2lf", produto->codigo, produto->nome, produto->preco);
}

void freeProduto(Produto** produto){
    free((*produto)->codigo);
    free((*produto)->nome);
    (*produto)=NULL;
}

Produto* criarProduto(){
    Produto* novoProduto = malloc(sizeof(Produto));

    printf("Novo produto:\nCodigo: ");
    char* codigo = lerString();
    novoProduto->codigo=codigo;

    printf("Nome: ");
    char* nome = lerString();
    novoProduto->nome=nome;

    double preco;
    do{
        printf("Preco: ");
        int control = scanf("%lf", &preco);
        limpaBuffer();
        if(control!=1){
            printf("Valor invalido!\n");
            preco = -1;
        }
    }while(preco<=0);

    novoProduto->preco = preco;
    printf("Produto (");
    imprimirProduto(novoProduto);
    printf(") cadastrado com sucesso!\n");
    return novoProduto;
}

void editarProduto(Produto* produto){
    if(produto==NULL){
        printf("Produto não existe!\n");
        return;
    }
    while(1){
        int opcao;
        do{
            printf("Qual informação gostaria de editar?\n");
            printf("1 - Codigo: %s\n", produto->codigo);
            printf("2 - Nome: %s\n", produto->nome);
            printf("3 - Preco: %.2lf\n", produto->preco);

            int controle = scanf("%d", &opcao);
            limpaBuffer();
            if(controle!=1 || opcao<1 || opcao>4){
                printf("Entrada invalida!\n");
                opcao=-1;
            }
        }while(opcao<1 || opcao>4);
        double preco;
        char* temp;
        switch (opcao)
        {
            case 1:printf("Digite o novo código: ");
                temp = lerString();
                free(produto->codigo);
                produto->codigo = temp;
                break;
            case 2:
                printf("Digite o novo Nome: ");
                temp = lerString();
                free(produto->nome);
                produto->nome = temp;
                break;
            case 3:
                do{
                    printf("Digite o novo Preco: ");
                    int control = scanf("%lf", &preco);
                    limpaBuffer();
                    if(control!=1){
                        printf("Valor invalido!\n");
                        preco = -1;
                    }
                }while(preco<=0);
                produto->preco=preco;
                break;
            default:
                return;
        }
    }
}