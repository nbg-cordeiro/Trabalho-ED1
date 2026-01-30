#include "auxiliares.h"
#include "produtos.h"
#include "clientes.h"

int menuPrincipal(void);
void menuProdutos(NodeProduto**);
void menuClientes(void);
void menu_editaClientes();

int main ()
{
    node_Cliente* listaClientes = malloc(sizeof(node_Cliente)); // lerClientes(); tem que criar esse carinha
    listaClientes->data = NULL;
    listaClientes->proximo = NULL;
    NodeProduto* listaProdutos = NULL;
    
    //criarCliente(listaClientes); // isso é só pra testar o menu
    while(1){
        limpaConsole();
        int opcao = menuPrincipal();
        switch(opcao)
        {
            case 1: menuClientes(); break;
            case 2: menuProdutos(&listaProdutos); break;
            case 4: 
                free_ListaClientes(&listaClientes);
                freeProdutos(&listaProdutos);
                printf("Saindo...");
                exit(EXIT_SUCCESS);
            break;
        }
    }
}

int menuPrincipal(void){
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
    
    return opcao;
}

void menuClientes(){
    int opcao = -1;
    do{
        printf("\n====== MENU Clientes ======\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Buscar cliente pelo CPF\n");
        printf("4 - Editar dados de um cliente\n");
        printf("5 - Remover um cliente\n");
        printf("6 - Voltar\n");
        printf("Escolha uma opcao:\n");
        int controle = scanf("%d", &opcao);
        limpaBuffer();

        if(controle!=1 || opcao<1 || opcao>4){
            limpaConsole();
            printf("\nInput Invalido! Tente novamente.\n");
            opcao = -1;
        }
    }while(opcao<1 || opcao>4);

    switch (opcao)
    {
    case 1:
        // criarCliente();     // tem que lembrar que precisa jogar eles pra um node
        break;
    case 2:break;
    case 3:break;
    case 4: menu_editaClientes(); break;
    case 5:break;
    default:
        return;
        break;
    }
}

void menu_editaClientes(){
    return;
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