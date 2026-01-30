#include "auxiliares.h"
#include "produtos.h"

int menuPrincipal(void);
void menuProdutos(NodeProduto**);

int main ()
{
    // Node* listaClientes = NULL;
    NodeProduto* listaProdutos = NULL;

    while(1){
        limpaConsole();
        int opcao = menuPrincipal();
        switch(opcao)
        {
            case 2: menuProdutos(&listaProdutos); break;
            case 4: 
                // freeLista(&listaClientes);
                freeProdutos(&listaProdutos);
                printf("Saindo...");
                exit(EXIT_SUCCESS);
            break;
        }
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
            case 3:
                printf("Insira o codigo do produto: ");
                char* codigo1 = lerString();
                NodeProduto** produto1 = (buscarProduto(lista, codigo1));
                free(codigo1);
                if(produto1==NULL || (*produto1)==NULL){
                    printf("Produto nao encontrado!\n");
                    printf("Pressione qualquer tecla para continuar.\n");
                    getchar();
                    break;
                }
                printf("Produto:\n");
                imprimirProduto((*produto1)->produto);
                printf("\n");
                break;
            case 4:
                printf("Insira o codigo do produto: ");
                char* codigo2 = lerString();
                NodeProduto** produto2 = (buscarProduto(lista, codigo2));
                free(codigo2);
                if(produto2==NULL || (*produto2)==NULL){
                    printf("Produto nao encontrado!\n");
                    printf("Pressione qualquer tecla para continuar.\n");
                    getchar();
                    break;
                }
                editarProduto(produto2);
                break;
            default:
                return;
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