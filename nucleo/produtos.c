#include "produtos.h"

void imprimirProduto(Produto* produto){
    if(produto!=NULL)
        printf("Cod: %s - Nome: %s - R$ %.2lf - Qtd: %d", produto->codigo, produto->nome, produto->preco, produto->quantidade);
}

void freeProdutos(NodeProduto** produtos){
    if(produtos==NULL)
        return;
    while((*produtos)!=NULL){
        NodeProduto* aux = (*produtos)->proximo;

        if ((*produtos)->produto != NULL) {
            free((*produtos)->produto->codigo);
            (*produtos)->produto->codigo=NULL;

            free((*produtos)->produto->nome);
            (*produtos)->produto->nome=NULL;
            
            free((*produtos)->produto);
            (*produtos)->produto=NULL;
        }
        free(*produtos);
        (*produtos)=NULL;

        (*produtos)=aux;
    }
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
            printf("Entrada invalida!\n");
            preco = -1;
        }
    }while(preco<=0);
    novoProduto->preco = preco;

    int quantidade;
    do{
        printf("Quantidade: ");
        int control = scanf("%d", &quantidade);
        limpaBuffer();
        if(control!=1 || quantidade<0){
            printf("Entrada Invalida!\n");
            quantidade=-1;
        }
    }while(quantidade<0);
    novoProduto->quantidade=quantidade;
    return novoProduto;
}

void editarProduto(NodeProduto** node){
    if(node==NULL || (*node)==NULL){
        printf("Produto não existe!\n");
        return;
    }
    while(1){
        int opcao;
        do{
            printf("Qual informação gostaria de editar?\n");
            printf("1 - Codigo: %s\n", (*node)->produto->codigo);
            printf("2 - Nome: %s\n", (*node)->produto->nome);
            printf("3 - Preco: %.2lf\n", (*node)->produto->preco);
            printf("4 - Quantidade: %d\n", (*node)->produto->quantidade);
            printf("5 - Voltar\n");

            int controle = scanf("%d", &opcao);
            limpaBuffer();
            if(controle!=1 || opcao<1 || opcao>5){
                printf("Entrada invalida!\n");
                opcao=-1;
            }
        }while(opcao<1 || opcao>5);
        double preco;
        char* temp;
        int control, quantidade;
        switch (opcao)
        {
            case 1:printf("Digite o novo código: ");
                temp = lerString();
                free((*node)->produto->codigo);
                (*node)->produto->codigo = temp;
                break;
            case 2:
                printf("Digite o novo Nome: ");
                temp = lerString();
                free((*node)->produto->nome);
                (*node)->produto->nome = temp;
                break;
            case 3:
                do{
                    printf("Digite o novo Preco: ");
                    control = scanf("%lf", &preco);
                    limpaBuffer();
                    if(control!=1){
                        printf("Entrada invalida!\n");
                        preco = -1;
                    }
                }while(preco<=0);
                (*node)->produto->preco=preco;
                break;
            case 4:
                do{
                    printf("Digite a nova Quantidade: ");
                    control = scanf("%d", &quantidade);
                    limpaBuffer();
                    if(control!=1 || quantidade<0){
                        printf("Entrada invalida!\n");
                        quantidade=-1;
                    }
                }while(quantidade<0);
                (*node)->produto->quantidade=quantidade;
                break;
            default:
                return;
        }
    }
}

NodeProduto** buscarProduto(NodeProduto** lista, char* codigo){
    while((*lista)!=NULL){
        if((compararString((*lista)->produto->codigo, codigo))){
            return lista;
        }
        lista = &((*lista)->proximo);
    }
    return NULL;
}

void adicionarProduto(NodeProduto** lista){
    NodeProduto* novoNode = malloc(sizeof(NodeProduto));
    if(novoNode==NULL){
        perror("Erro ao alocar memoria em adicionarProduto()");
        exit(EXIT_FAILURE);
    }
    novoNode->produto=criarProduto();
    novoNode->proximo=(*lista);
    (*lista)=novoNode;
}

void listarProdutos(NodeProduto* lista){
    if(lista == NULL){
        printf("Nenhum produto cadastrado.\nPressione qualquer tecla para continuar.\n");
        getchar();
        return;
    }
    int i = 1;
    while(lista!=NULL){
        printf("%d- ",i);
        imprimirProduto(lista->produto);
        printf("\n");
        i++;
        lista=lista->proximo;
    }
    printf("Pressione qualquer tecla para continuar.\n");
    getchar();
}