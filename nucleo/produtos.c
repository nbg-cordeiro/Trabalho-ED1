#include "produtos.h"

NodeProduto** buscarProduto(NodeProduto** lista, char* codigo){
    while((*lista)!=NULL){
        if((compararString((*lista)->produto->codigo, codigo))){
            return lista;
        }
        lista = &((*lista)->proximo);
    }
    return NULL;
}

void imprimirProduto(Produto* produto){
    if(produto!=NULL)
        printf("Cod: %s - Nome: %s - R$ %.2lf - Qtd: %d", produto->codigo, produto->nome, produto->preco, produto->quantidade);
}

void imprimePorCodigo(NodeProduto** lista){
    if(lista == NULL || (*lista)==NULL){
        printf("Nenhum produto cadastrado.\n");
        continuar();
        return;
    }
    printf("Insira o codigo do produto: ");
    char* codigo1 = lerString();
    NodeProduto** produto1 = (buscarProduto(lista, codigo1));
    free(codigo1);
    if(produto1==NULL || (*produto1)==NULL){
        printf("Produto nao encontrado!\n");
        continuar();
        return;
    }
    printf("Produto:\n");
    imprimirProduto((*produto1)->produto);
    printf("\n");
    continuar();
}

void listarProdutos(NodeProduto* lista){
    if(lista == NULL){
        printf("Nenhum produto cadastrado.\n");
        continuar();
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
}

void adicionarProduto(NodeProduto** lista){
    NodeProduto* novoNode = malloc(sizeof(NodeProduto));
    if(novoNode==NULL){
        perror("Erro ao alocar memoria em adicionarProduto()");
        exit(EXIT_FAILURE);
    }
    novoNode->produto=criarProduto(lista);
    novoNode->proximo=(*lista);
    (*lista)=novoNode;
    printf("Produto adicionado com sucesso!\n");
    continuar();
}

Produto* criarProduto(NodeProduto** lista){
    Produto* novoProduto = malloc(sizeof(Produto));
    char* codigo=NULL;
    do{
        printf("Novo produto:\nCodigo: ");
        codigo = lerString();
        if(buscarProduto(lista,codigo)!=NULL){
            printf("Este codigo ja existe!\n");
            free(codigo);
            codigo=NULL;
        }
    }while(codigo==NULL);
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
        if(control!=1 || quantidade<1){
            printf("Entrada Invalida!\n");
            quantidade=-1;
        }
    }while(quantidade<1);
    novoProduto->quantidade=quantidade;
    return novoProduto;
}

void editarProduto(NodeProduto** lista){
    if(lista == NULL || (*lista)==NULL){
        printf("Nenhum produto cadastrado.\n");
        continuar();
        return;
    }
    printf("Insira o codigo do produto: ");
    char* codigo = lerString();
    NodeProduto** node = (buscarProduto(lista, codigo));
    free(codigo);
    if(node==NULL || (*node)==NULL){
        printf("Produto nao encontrado!\n");
        continuar();
        return;
    }
    while(1){
        int opcao;
        do{
            printf("Qual informacao gostaria de editar?\n");
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
            case 1:
                printf("Digite o novo codigo: ");
                do{
                    temp = lerString();
                    if(buscarProduto(lista,temp)!=NULL){
                        printf("Esse codigo ja existe!\n");
                        free(temp);
                        temp=NULL;
                    }
                }while(temp==NULL);
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
                    if(control!=1 || quantidade<1){
                        printf("Entrada invalida!\n");
                        quantidade=-1;
                    }
                }while(quantidade<1);
                (*node)->produto->quantidade=quantidade;
                break;
            default:
                return;
        }
        printf("Produto editado com sucesso!\n");
        imprimirProduto((*node)->produto);
        continuar();
    }
}

void removerProduto(NodeProduto** lista){
    if(lista == NULL || (*lista)==NULL){
        printf("Nenhum produto cadastrado.\n");
        continuar();
        return;
    }
    printf("Insira o codigo do produto: ");
    char* codigo = lerString();
    NodeProduto** node = (buscarProduto(lista, codigo));
    free(codigo);
    if(node==NULL || (*node)==NULL){
    printf("Produto nao encontrado!\n");
        continuar();
        return;
    }
    NodeProduto* aux = (*node)->proximo;

    free((*node)->produto->codigo);
    (*node)->produto->codigo=NULL;

    free((*node)->produto->nome);
    (*node)->produto->nome=NULL;

    free((*node)->produto);
    (*node)->produto=NULL;

    free(*node);
    (*node)=aux;

    printf("Produto removido com sucesso!\n");
    continuar();
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

double somaProdutos(NodeProduto* lista){
    double soma = 0;
    while(lista!=NULL){
        soma += lista->produto->preco * lista->produto->quantidade;
        lista = lista->proximo;
    }
    return soma;
}

void listarCarrinho(NodeProduto* carrinho){
    limpaConsole();
    if(carrinho==NULL){
        printf("Carrinho vazio!\n");
        continuar();
        return;
    }
    printf("\n====== Carrinho ======\n");
    listarProdutos(carrinho);
    printf("\nValor Total: R$ %.2lf\n",somaProdutos(carrinho));
    continuar();
}

void adicionarCarrinho(NodeProduto** produtos, NodeProduto** carrinho){
    if(produtos==NULL || (*produtos)==NULL){
        printf("Nenhum produto cadastrado.\n");
        continuar();
        return;
    }

    char* temp = NULL;
    NodeProduto** original = NULL;
    do{
        printf("Insira o codigo do produto: ");
        temp = lerString();
        limpaConsole();
        original = buscarProduto(produtos, temp);
        if(original==NULL || (*original)==NULL){
            printf("Produto com codigo \"%s\", nao encontrado.\n", temp);
            free(temp);
            temp=NULL;
        }
    }while(temp==NULL);

    NodeProduto** existente = buscarProduto(carrinho, temp);
    free(temp);
    temp=NULL;
    if(existente!=NULL){
        printf("Esse produto ja esta no seu carrinho.\n Para alterar a quantidade, digite \"alterar\".\nPara sair, pressione enter");
        char* resposta = lerString();
        int opcao;
        if(compararString(resposta, "alterar")){
            do{
                printf("Quantidade atual: %d\n", (*existente)->produto->quantidade);
                printf("Quantidade em estoque: %d\n", (*original)->produto->quantidade);
                printf("O que deseja fazer?\n");
                printf("1 - Alterar\n");
                printf("2 - Voltar\n");

                int control = scanf("%d", &opcao);
                limpaConsole();
                limpaBuffer();
                if(control!=1 || opcao<1 || opcao>2){
                    printf("Entrada invalida!\n");
                    opcao=-1;
                }
            }while(opcao<1 || opcao>2);
            if(opcao==2)
                return;
            (*original)->produto->quantidade+=(*existente)->produto->quantidade;
            (*existente)->produto->quantidade=0;
            int quantidade=-1;
            do{
                printf("Estoque disponivel: %d\n", (*original)->produto->quantidade);
                printf("Insira a nova quantidade: ");
                int control = scanf("%d", &quantidade);
                limpaBuffer();
                if(control!=1 || quantidade<1 || quantidade>(*original)->produto->quantidade){
                    printf("Quantidade invalida!\n");
                    quantidade=-1;
                }
            }while(quantidade<1);
            (*existente)->produto->quantidade = quantidade;
            (*original)->produto->quantidade -= quantidade;
            #warning temos que adicionar novamente ao remover o produto ou limpar o carrinho;
            limpaConsole();
            printf("Quantidade alterada com sucesso!\n");
            continuar();
            free(resposta);
        }
        return;
    }
    NodeProduto* novoProduto = malloc(sizeof(NodeProduto));
    novoProduto->produto = malloc(sizeof(Produto));
    novoProduto->produto->codigo = copiarString((*original)->produto->codigo);
    novoProduto->produto->nome = copiarString((*original)->produto->nome);
    novoProduto->produto->preco = (*original)->produto->preco;
    
    int quantidade = -1;

    do{
        printf("Insira a quantidade do produto: ");
        int control = scanf("%d",  &quantidade);
        limpaBuffer();
        if(control!=1 || quantidade<1){
            quantidade=-1;
            printf("Entrada invalida!\n");
        }
        if(quantidade>(*original)->produto->quantidade){
            quantidade=-1;
            printf("Nao existem tantos produtos em estoque!");
        }
    }while(quantidade<1);

    novoProduto->produto->quantidade = quantidade;
    (*original)->produto->quantidade -= quantidade;
    #warning temos que adicionar novamente ao remover o produto ou limpar o carrinho;

    novoProduto->proximo=(*carrinho);
    (*carrinho)=novoProduto;

    printf("Produto adicionado com sucesso!\n");
    continuar();
}