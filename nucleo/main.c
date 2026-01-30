#include "auxiliares.h"
#include "produtos.h"
#include "clientes.h"

int menuPrincipal(NodeProduto**, node_Cliente**);
void menuProdutos(NodeProduto**);
void menuClientes(node_Cliente**);
void encerrar(NodeProduto**, node_Cliente**);

int main ()
{
    NodeProduto* listaProdutos = NULL;
    node_Cliente* listaClientes = malloc(sizeof(node_Cliente));
    listaClientes->data = NULL;
    listaClientes->proximo = NULL;
    menuPrincipal(&listaProdutos, &listaClientes);
}

int menuPrincipal(NodeProduto** produtos, node_Cliente** clientes){
    while(1){
        limpaConsole();
        int opcao=-1;
        do{
            printf("\n====== MENU PRINCIPAL ======\n");
            printf("1 - Gerenciamento de clientes\n");
            printf("2 - Gerenciamento de produtos\n");
            printf("3 - Modo de compra\n");
            printf("4 - Sair\n");
            printf("Escolha uma opcao:\n");
            int controle = scanf("%d", &opcao);
            limpaBuffer();

            if(controle!=1 || opcao<1 || opcao>4){
                limpaConsole();
                printf("\nInput Invalido! Tente novamente.\n");
                opcao = -1;
            }
        }while(opcao<1 || opcao>4);

        switch(opcao){
            case 1: menuClientes(clientes); break;
            case 2: menuProdutos(produtos); break;
            case 4: encerrar(produtos, clientes);break;
        }
    }
}

void menuClientes(node_Cliente** head){
    int opcao = -1;
    do{
        printf("\n====== MENU CLIENTES ======\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Buscar cliente pelo CPF\n");
        printf("4 - Editar dados de um cliente\n");
        printf("5 - Remover um cliente\n");
        printf("6 - Voltar\n");
        printf("Escolha uma opcao:\n");
        int controle = scanf("%d", &opcao);
        limpaBuffer();

        if(controle!=1 || opcao<1 || opcao>6){
            limpaConsole();
            printf("\nInput Invalido! Tente novamente.\n");
            opcao = -1;
        }
    }while(opcao<1 || opcao>6);

    switch (opcao)
    {
    case 1: criarCliente((*head)); break;
    case 2: imprimirClientes(head); break;
    case 3:break;
    case 4: editarCliente((*head)); break;
    case 5: removerCliente(head);break;
    default:
        return;
        break;
    }
}

void menuProdutos(NodeProduto** lista){
    while(1){
        limpaConsole();
        int opcao=-1;
        do{
            printf("\n====== MENU PRODUTOS ======\n");
            printf("1 - Cadastrar produto\n");
            printf("2 - Listar produtos\n");
            printf("3 - Buscar produto pelo codigo\n");
            printf("4 - Editar dados de um produto\n");
            printf("5 - Remover um produto\n");
            printf("6 - Voltar\n");
            printf("Escolha uma opcao:\n");

            int controle = scanf("%d", &opcao);
            limpaConsole();
            limpaBuffer();
            if(controle!=1 || opcao>6 || opcao<1){
                opcao=-1;
                printf("Entrada invalida!\n");
            }
        }while(opcao<1 || opcao>6);
        switch (opcao)
        {
            case 1:adicionarProduto(lista);break;
            case 2:listarProdutos(*lista);break;
            case 3:imprimePorCodigo(lista);break;
            case 4:editarProduto(lista);break;
            case 5:removerProduto(lista);break;
            case 6:return;
        }
    }
}

void encerrar(NodeProduto** produtos, node_Cliente** clientes){
    limpaConsole();
    printf("Caso deseje sair, digite \"sair\"\n");
    char* resposta = lerString();
    if(!compararString(resposta, "sair")){
        free(resposta);
        printf("Saida cancelada!\n");
        continuar();
        return;
    }
    free(resposta);
    free_ListaClientes(clientes);
    freeProdutos(produtos);
    printf("Saindo...");
    exit(EXIT_SUCCESS);
}