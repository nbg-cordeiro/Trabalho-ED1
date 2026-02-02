#include "auxiliares.h"
#include "produtos.h"
#include "clientes.h"
#include "compras.h"
#include "testes.h"

int menuPrincipal(NodeProduto**, NodeCliente**);
void menuProdutos(NodeProduto**);
void menuClientes(NodeCliente**, NodeProduto**);
void modoCompra1(NodeProduto**, NodeCliente**);
void modoCompra2(NodeProduto**, NodeCliente*);
void encerrar(NodeProduto**, NodeCliente**);

int main (int argc, char *argv[])
{
    NodeProduto* listaProdutos = NULL;
    NodeCliente* listaClientes = NULL;
    if(argc>1 && compararString(argv[1],"testes"))
        objetosTeste(&listaProdutos,&listaClientes);
    menuPrincipal(&listaProdutos, &listaClientes);
}

int menuPrincipal(NodeProduto** produtos, NodeCliente** clientes){
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
            case 1: menuClientes(clientes, produtos); break;
            case 2: menuProdutos(produtos); break;
            case 3: modoCompra1(produtos, clientes);break;
            case 4: encerrar(produtos, clientes);break;
        }
    }
}

void menuClientes(NodeCliente** listaClientes, NodeProduto** estoque){
    while(1){
        limpaConsole();
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
            limpaConsole();
            limpaBuffer();
            if(controle!=1 || opcao<1 || opcao>6){
                printf("Entrada invalida! Tente novamente.\n");
                opcao = -1;
            }
        }while(opcao<1 || opcao>6);

        switch (opcao)
        {
            case 1: criarCliente(listaClientes); break;
            case 2: imprimirClientes((*listaClientes)); break;
            case 3: buscarCliente(listaClientes); break;
            case 4: editarCliente(listaClientes); break;
            case 5: removerCliente(listaClientes, estoque);break;
            case 6: return;
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
                printf("Entrada invalida! Tente novamente.\n");
            }
        }while(opcao<1 || opcao>6);
        switch (opcao)
        {
            case 1:adicionarProduto(lista);break;
            case 2:listarProdutos(*lista);continuar();break;
            case 3:imprimePorCodigo(lista);break;
            case 4:editarProduto(lista);break;
            case 5:removerProduto(lista);break;
            case 6:return;
        }
    }
}

void modoCompra1(NodeProduto** produtos, NodeCliente** clientes){
    while(1){
        limpaConsole();
        if(produtos == NULL || *produtos == NULL || clientes == NULL || *clientes == NULL){
            printf("Nao existe nenhum produto ou cliente cadastrado.\n");
            continuar();
            return;
        }
        char* temp = NULL;
        NodeCliente** cliente = NULL;
        do{
            printf("\n====== MODO COMPRA ======\n");
            printf("Para sair, digite \"sair\".\nPara continuar digite seu CPF.\n");
            temp = lerString();
            if(compararString(temp,"sair")){
                free(temp);
                temp=NULL;
                return;
            }   
            cliente = buscarCPF(clientes,temp);
            if(cliente==NULL || (*cliente) == NULL){
                limpaConsole();
                printf("Cliente com cpf \"%s\" nao encontrado!", temp);
                free(temp);
                temp=NULL;
            }
        }while(temp==NULL);
        free(temp);
        temp=NULL;

        modoCompra2(produtos,(*cliente));
        cliente=NULL;
    }
}

void modoCompra2(NodeProduto** produtos, NodeCliente* cliente){
    verificarCarrinho(produtos,&(cliente->data->carrinho));
    while(1){
        limpaConsole();
        int opcao=-1;
        do{
            printf("\n====== MODO COMPRA ======\n");
            printf("1 - Listar Produtos\n");
            printf("2 - Adicionar ao carrinho\n");
            printf("3 - Remover do carrinho\n");
            printf("4 - Listar Carrinho\n");
            printf("5 - Voltar\n");

            int controle = scanf("%d", &opcao);
            limpaConsole();
            limpaBuffer();

            if(controle!=1 || opcao<1 || opcao>5){
                opcao=-1;
                printf("Entrada invalida! Tente novamente.\n");
            }
        }while(opcao<1 || opcao>5);
        switch(opcao){
            case 1:listarProdutos(*produtos);break;
            case 2:adicionarCarrinho(produtos, &(cliente->data->carrinho));break;
            case 3:removerCarrinho(&(cliente->data->carrinho), produtos);break;
            case 4:listarCarrinho(cliente->data->carrinho);break;
            case 5:return;
        }
    }
}

void encerrar(NodeProduto** produtos, NodeCliente** clientes){
    limpaConsole();
    printf("Caso deseje sair, digite \"sair\"\n");
    char* resposta = lerString();
    if(!compararString(resposta, "sair")){
        free(resposta);
        limpaConsole();
        printf("Saida cancelada!\n");
        continuar();
        return;
    }
    free(resposta);
    free_ListaClientes(clientes, produtos);
    freeProdutos(produtos);
    printf("Saindo...");
    exit(EXIT_SUCCESS);
}
