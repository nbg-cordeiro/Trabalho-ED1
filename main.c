#include "auxiliares.h"

int menuPrincipal(void);

int main ()
{
    Node* listaClientes = NULL; // lerClientes(); tem que criar esse carinha
    Node* listaProdutos = NULL; // lerProdutos(); e esse aqui também
    
    int opcao = menuPrincipal();

    switch(opcao)
    {
        case 4:
            // salvarClientes(listaClientes); tem que colocar esse menininho
            // salvarLista(listaProdutos); esse menininho também
            freeLista(&listaClientes);
            freeLista(&listaProdutos);
        break;
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
            perror("\nInput Invalido! Tente novamente.\n");
            opcao = -1;
        }
    }while(opcao<1 || opcao>4);
    
    return opcao;
}