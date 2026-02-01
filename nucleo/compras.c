#include "compras.h"

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
        printf("Digite \"sair\" para cancelar ou insira o codigo do produto: ");
        temp = lerString();
        if(compararString(temp, "sair")){
            free(temp);
            temp=NULL;
            return;
        }
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
        printf("Esse produto ja esta no seu carrinho.\nO que deseja fazer?\n1 - Alterar quantidade\n2 - Voltar\n");
        int opcao;
        do{
            int control = scanf("%d", &opcao);
            limpaBuffer();
            if(control!=1 || opcao<1 || opcao>2){
                printf("Entrada invalida!\n");
                opcao=-1;
        }   
        }while(opcao<1 || opcao>2);
        if(opcao==1){
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
            if(opcao==2){
                return;
            }
            int quantidade=-1;
            do{
                printf("Estoque disponivel: %d\n", (*original)->produto->quantidade + (*existente)->produto->quantidade);
                printf("Insira \"0\" para cancelar.\n");
                printf("Insira a nova quantidade: ");
                int control = scanf("%d", &quantidade);
                limpaBuffer();
                if(control!=1 || quantidade<0 || quantidade>(*original)->produto->quantidade + (*existente)->produto->quantidade){
                    limpaConsole();
                    printf("Quantidade invalida!\n");
                    quantidade=-1;
                }
            }while(quantidade<0);
            if(quantidade==0){
                printf("Alteracao cancelada!\n");
                continuar();
                return;
            }
            (*original)->produto->quantidade += (*existente)->produto->quantidade;
            (*existente)->produto->quantidade = (quantidade);
            (*original)->produto->quantidade -= quantidade;
            limpaConsole();
            printf("Quantidade alterada com sucesso!\n");
            continuar();
        }
        return;
    }
    NodeProduto* novoProduto = malloc(sizeof(NodeProduto));
    if(novoProduto==NULL){
        perror("Erro ao alocar memoria em adicionarCarrinho()");
        exit(EXIT_FAILURE);
    }

    novoProduto->produto = malloc(sizeof(Produto));
    if(novoProduto->produto==NULL){
        perror("Erro ao alocar memoria em adicionarCarrinho()");
        exit(EXIT_FAILURE);
    }
    
    novoProduto->produto->codigo = copiarString((*original)->produto->codigo);
    novoProduto->produto->nome = copiarString((*original)->produto->nome);
    novoProduto->produto->preco = (*original)->produto->preco;
    
    int quantidade = -1;

    do{
        printf("Insira \"0\" para cancelar.\n");
        printf("Insira a quantidade do produto: ");
        int control = scanf("%d",  &quantidade);
        limpaBuffer();
        if(control!=1 || quantidade<0){
            quantidade=-1;
            printf("Entrada invalida!\n");
        }
        if(quantidade>(*original)->produto->quantidade){
            quantidade=-1;
            printf("Nao existem produtos suficientes em estoque!");
        }
    }while(quantidade<0);

    if(quantidade==0){
        printf("Adicao ao carrinho cancelada!\n");
        free(novoProduto->produto->codigo);
        novoProduto->produto->codigo = NULL;
        free(novoProduto->produto->nome);
        novoProduto->produto->nome = NULL;
        free(novoProduto->produto);
        novoProduto->produto = NULL;
        free(novoProduto);
        novoProduto = NULL;
        continuar();
        return;
    }
    novoProduto->produto->quantidade = quantidade;
    (*original)->produto->quantidade -= quantidade;

    novoProduto->proximo=(*carrinho);
    (*carrinho)=novoProduto;

    printf("Produto adicionado com sucesso!\n");
    continuar();
}

void removerCarrinho(NodeProduto** carrinho, NodeProduto** estoque){
    if (carrinho == NULL || (*carrinho) == NULL){
        return;
    }

    char * temp = NULL;
    printf("Remover do carrinho\n");
    NodeProduto** original = NULL;
    do{
        printf("Digite o codigo do produto a ser removido: ");
        temp = lerString();
        limpaConsole();
        original = buscarProduto(estoque, temp);
        if(original==NULL || (*original)==NULL){
            printf("Produto com codigo \"%s\", nao encontrado.\n", temp);
            free(temp);
            temp=NULL;
        }
    }while(temp==NULL);

    NodeProduto** del_carrinho = NULL;
    del_carrinho = buscarProduto(carrinho,temp);

    free(temp);
    temp = NULL;

    if (del_carrinho != NULL){
        (*original)->produto->quantidade += (*del_carrinho)->produto->quantidade; // funfact: antes estava (*estoque)->produto->quantidade (xD)

        NodeProduto* aux = (*del_carrinho)->proximo;
        
        free((*del_carrinho)->produto->codigo);
        (*del_carrinho)->produto->codigo = NULL;

        free((*del_carrinho)->produto->nome);
        (*del_carrinho)->produto->nome = NULL;

        free((*del_carrinho)->produto);
        (*del_carrinho)->produto = NULL;

        free(*del_carrinho);
        *del_carrinho = aux;
        
        return;
    }    
}

void freeCarrinho (NodeProduto** carrinho, NodeProduto** estoque){
    if (carrinho == NULL || (*carrinho) == NULL){
        return;
    }


    while ((*carrinho) != NULL){
        NodeProduto* aux = (*carrinho)->proximo;

        if ((*carrinho)->produto != NULL){
            NodeProduto** original = NULL;
            original = buscarProduto(estoque, (*carrinho)->produto->codigo);

            if (original != NULL && *original != NULL){
                (*original)->produto->quantidade += (*carrinho)->produto->quantidade;
            }

            free((*carrinho)->produto->codigo);
            (*carrinho)->produto->codigo = NULL;

            free((*carrinho)->produto->nome);
            (*carrinho)->produto->nome = NULL;

            free((*carrinho)->produto);
            (*carrinho)->produto = NULL;
        }

        free(*carrinho);
        (*carrinho) = aux;
    }

    *carrinho = NULL;
}