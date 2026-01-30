#include "auxiliares.h"
#include "produtos.h"
#include "clientes.h"

int menuPrincipal(void);
void menuProdutos(void);
void menuClientes(void);
void menu_editaClientes();

int main ()
{
    node_Cliente* listaClientes = malloc(sizeof(node_Cliente)); // lerClientes(); tem que criar esse carinha
    listaClientes->data = NULL;
    listaClientes->proximo = NULL;
    //listaClientes = malloc(sizeof(node_Cliente));
    Node* listaProdutos = NULL; // lerProdutos(); e esse aqui também
    
    //criarCliente(listaClientes); // isso é só pra testar o menu
    while(1){
        int opcao = menuPrincipal();
        limpaConsole();
        switch(opcao)
        {
            case 1: menuClientes(); break;
            case 2: menuProdutos(); break;
            case 4:
                // salvarClientes(listaClientes); tem que colocar esse menininho
                // salvarLista(listaProdutos); esse menininho também
                free_ListaClientes(&listaClientes);
                freeLista(&listaProdutos);
                printf("Saindo...");
                exit(EXIT_SUCCESS);
            break;
        }
    }
}

void menuProdutos(){
    int opcao=-1;
    do{
        printf("\n====== MENU PRODUTOS ======\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto pelo codigo\n");
        printf("4 - Editar dados de um produto\n");
        printf("5 - Remover um produto\n");
        printf("6 - Voltar\n");

        int controle = scanf("%d", &opcao);
        limpaBuffer();
        limpaConsole();
        if(controle!=1 || opcao>6 || opcao<1){
            opcao=-1;
            printf("Entrada invalida!\n");
        }
    }while(opcao<1 || opcao>6);
    switch (opcao)
    {
    case 1:
        criarProduto();                   //quero fazer algo assim: adicionarProduto(lista, criarProduto()); "Ah mas isso é BURRO" eu também acho!
        break;
    default:
        return;
        break;
    }
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