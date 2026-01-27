#include "auxiliares.c"

void menuPrincipal(){
    int opcao;
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
        case 1:
            //colocar menuClientes
            break;
        case 2:
            //colocar menuProdutos
            break;
        case 3:
            //colocar menuCompra
            break;
        case 4:
            //colocar codigo de saida
            break;
    }
}

int main ()
{
    menuPrincipal();
}