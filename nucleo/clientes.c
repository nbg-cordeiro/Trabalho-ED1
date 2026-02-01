#include "clientes.h"
#include "compras.h"

void InserirNode(NodeCliente *head, Cliente * dado){
    NodeCliente *novo = malloc(sizeof(NodeCliente));
    if (novo == NULL){
        perror("Erro ao alocar memória em InserirNode().");
        exit(EXIT_FAILURE);
    }

    novo->data = dado;

    novo->proximo = head->proximo;
    head->proximo = novo;
}

void imprimeCliente(Cliente * cliente){
    printf("%s\n", cliente->nome);
    printf("- CPF: %s\n", cliente->cpf);
    printf("- Telefone: %s\n", cliente->telefone);
    printf("- Data de Nascimento: %s", cliente->dataNascimento);

    printf("\n============================\n");
}

void imprimirClientes(NodeCliente **head){
    printf("\n====== LISTA CLIENTES ======\n");

    if ((*head)->proximo == NULL){
        printf("Nenhum cliente cadastrado.");
        printf("\n============================\n");
        continuar();
        return;
    }

    NodeCliente *p;
    for (p = (*head)->proximo; p != NULL; p = p->proximo){
        imprimeCliente(p->data);
    }

    continuar();
}

void criarCliente(NodeCliente *head){
    Cliente* novoCliente = malloc(sizeof(Cliente));
    if (novoCliente == NULL){
        perror("Erro ao alocar memória em criarCliente().");
        exit(EXIT_FAILURE);
    }

    char* nome = NULL;
    do{
        printf("Novo cliente:\nNome:");
        nome = lerString();

        if (nome == NULL){
            perror("Nao foi possivel alocar memoria em criarCliente().");
            continue;
        }
        
        if (*nome == '\0'){
            printf("Entrada invalida. Tente novamente.\n");
            free(nome);
            nome = NULL;
        }
    } while (nome == NULL);
    novoCliente->nome = nome;
   
    printf("Insira os dados a seguir sem pontuacao ('/', '-' e/ou '.') e sem espacamento.\n");

    char* cpf = NULL;
    do
    {
        printf("CPF: ");
        cpf = lerString();

        if (cpf == NULL){
            perror("Nao foi possivel alocar memoria em criarCliente().");
            continue;
        }
        if (*cpf == '\0'){
            printf("Entrada invalida. Tente novamente.\n");
            free(cpf);
            cpf = NULL;
        }
        if (buscarCPF(cpf,head) != NULL){
            printf("Esse CPF ja esta cadastrado!\n");
            free(cpf);
            cpf = NULL;
        }
        
    } while (cpf == NULL);
    novoCliente->cpf = cpf;


    printf("Data de nascimento:");
    char* aniversario = lerString();
    novoCliente->dataNascimento = aniversario;

    printf("Telefone de contato:");
    char* telefone = lerString();
    novoCliente->telefone = telefone;

    novoCliente->carrinho=NULL;
    
    printf("\nCliente cadastrado com exito.\n");

    imprimeCliente(novoCliente);

    InserirNode(head,novoCliente);

    continuar();
}

void editarCliente(NodeCliente *head){

    printf("Nao utilize pontuacoes ('/' '.' '-') ou espaco.\n");
    printf("Digite o CPF do cliente: ");
    char *cpf = lerString();
    NodeCliente *cliente = buscarCPF(cpf,head);
    free(cpf);

    if (cliente == NULL){
        printf("Cliente nao cadastrado no sistema.");
        return;
    }
    
    while (1){
        int opcao=-1;
        do{
            printf("\n====== GERENCIAMENTO DE CLIENTES | EDITAR CLIENTE ======\n");
            printf("1 - Editar nome do cliente\n");
            printf("2 - Editar CPF do cliente\n");
            printf("3 - Editar telefone do cliente\n");
            printf("4 - Editar Data de Nascimento do cliente\n");
            printf("5 - Sair\n");
            printf("Escolha uma opcao:\n");
            int controle = scanf("%d", &opcao);
            limpaBuffer();

            if(controle!=1 || opcao<1 || opcao>5){
                limpaConsole();
                perror("\nInput Invalido! Tente novamente.\n");
                opcao = -1;
            }
        }while(opcao<1 || opcao>5);
    
        char * temp = NULL;

        switch (opcao)
        {
        case 1:
            printf("Digite nome: ");

            temp = lerString();

            free((cliente)->data->nome);
            (cliente)->data->nome = temp;
            break;
        case 2:
            do{
                printf("Digite novo CPF: ");
                temp = lerString();

                if (temp == NULL){
                    perror("Nao foi possivel alocar memoria em criarCliente().");
                    continue;
                }
                if (*temp == '\0'){
                    printf("Entrada invalida. Tente novamente.\n");
                    free(temp);
                    temp = NULL;
                }
                if (buscarCPF(temp,head) != NULL){
                    printf("Esse CPF ja esta cadastrado!\n");
                    free(temp);
                    temp = NULL;
                }
            } while (temp == NULL);
            
            free((cliente)->data->cpf);
            (cliente)->data->cpf = temp;
            break;
        case 3:
            printf("Digite novo telefone: ");
            
            temp = lerString();

            free((cliente)->data->telefone);
            (cliente)->data->telefone = temp;
            break;
        case 4:
            printf("Digite nova Data de Nascimento: ");
            
            temp = lerString();

            free((cliente)->data->dataNascimento);
            (cliente)->data->dataNascimento = temp;
            break;
        default:
            return;
        }
    
    printf("\nDado atualizado com exito.\n\n");
    imprimeCliente(cliente->data);
    continuar();
    }
    
}

NodeCliente* buscarCPF(char* cpf, NodeCliente *head){
    if (cpf == NULL){
        perror("Entrada de dados invalidos em buscarCPF().");
        return NULL;
    }
    NodeCliente *atual;
    atual = head->proximo;

    while (atual != NULL ){
        if (compararString(atual->data->cpf,cpf) == 1)
            return atual;
        atual = atual->proximo;
    }
    return NULL;
}


void buscarCliente(NodeCliente **head){
    printf("\nBuscar Cliente:\n");
    printf("Nao utilize nenhuma acentuacao ('/', '-', '.') ou espacamento.\n");
    printf("- Digite o CPF do cliente: ");

    char * temp = lerString();
    if (temp == NULL){
        return;
    }
    NodeCliente *cliente = buscarCPF(temp, (*head));
    free(temp);
    if (cliente == NULL){
        printf("Cliente não foi encontrado.");
        return;
    }

    printf("\n====== BUSCAR CLIENTE ======\n");
    imprimeCliente(cliente->data);

    continuar();
}

void freeCliente(Cliente** cliente, NodeProduto** estoque){
    free((*cliente)->nome);
    free((*cliente)->cpf);
    free((*cliente)->dataNascimento);
    free((*cliente)->telefone);
    freeCarrinho(&((*cliente)->carrinho), estoque);
    free(*cliente);
    (*cliente) = NULL;
}

void removerCliente(NodeCliente** head, NodeProduto** estoque){
    if (head == NULL || (*head) == NULL){
        return;
    }

    printf("\nRemover Cliente:\n");
    printf("Nao utilize nenhuma acentuacao ('/', '-', '.') ou espacamento.\n");
    printf("- Digite o CPF do cliente: ");

    char * temp = lerString();

    if (temp == NULL){
        perror("Erro ao alocar memoria em removerCliente():lerString().");
        return;
    }

    NodeCliente * delete = buscarCPF(temp, (*head));
    free(temp);

    if (delete == NULL){
        printf("CPF inserido nao esta cadastrado.");
        return;
    }
    NodeCliente *anterior = (*head);

    while (anterior != NULL && anterior->proximo != delete)
        anterior = anterior->proximo;

    if (anterior != NULL)
        anterior->proximo = delete->proximo;
    
    freeCliente(&(delete->data), estoque);
    free(delete);

    continuar();
}

void free_ListaClientes(NodeCliente** lista, NodeProduto** estoque){
    if (lista == NULL || (*lista) == NULL){
        return;
    }

    NodeCliente* atual = (*lista);

    while (atual != NULL){
        NodeCliente* prox = atual->proximo;
        if (atual->data != NULL)
            freeCliente(&(atual->data), estoque);
        free(atual);
        atual = prox;
    }
    *lista = NULL;
}