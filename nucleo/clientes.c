#include "clientes.h"

void InserirNode(node_Cliente *head, Cliente * dado){
    node_Cliente *novo = malloc(sizeof(node_Cliente));
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

void imprimirClientes(node_Cliente **head){
    printf("\n====== LISTA CLIENTES ======\n");

    if ((*head)->proximo == NULL){
        printf("Nenhum cliente cadastrado.");
        printf("\n============================\n");
        continuar();
        return;
    }

    node_Cliente *p;
    for (p = (*head)->proximo; p != NULL; p = p->proximo){
        imprimeCliente(p->data);
    }

    continuar();
}

void criarCliente(node_Cliente *head){
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

void editarCliente(node_Cliente *head){

    printf("Nao utilize pontuacoes ('/' '.' '-') ou espaco.\n");
    printf("Digite o CPF do cliente: ");
    char *cpf = lerString();
    node_Cliente *cliente = buscarCPF(cpf,head);
    free(cpf);

    if (cliente == NULL){
        printf("Cliente nao cadastrado no sistema.");
        return;
    }
    
    while (1){
        int opcao=-1;
        do{
            printf("\n====== GERENCIAMENTO DE CLIENTES | EDITAR CLIENTE ======\n");
            printf("1 - Editar nome do cliete\n");
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

node_Cliente* buscarCPF(char* cpf, node_Cliente *head){
    if (cpf == NULL){
        perror("Entrada de dados invalidos em buscarCPF().");
        return NULL;
    }
    node_Cliente *atual;
    atual = head;

    while (atual != NULL ){
        if (atual->data != NULL){
            if (compararString(atual->data->cpf,cpf) == 1){
            return atual;
        }

        }
        
        atual = atual->proximo;
    }

    return NULL;
}


void buscarCliente(node_Cliente **head){
    printf("\nBuscar Cliente:\n");
    printf("Nao utilize nenhuma acentuacao ('/', '-', '.') ou espacamento.\n");
    printf("- Digite o CPF do cliente: ");

    char * temp = NULL;
    temp = lerString();
    if (temp == NULL){
        return;
    }
    node_Cliente *cliente = buscarCPF(temp, (*head));
    if (cliente == NULL){
        printf("Cliente não foi encontrado.");
        return;
    }

    printf("\n====== BUSCAR CLIENTE ======\n");
    imprimeCliente(cliente->data);
    free(temp);

    continuar();
}

void freeCliente(Cliente** cliente){
    free((*cliente)->nome);
    free((*cliente)->cpf);
    free((*cliente)->dataNascimento);
    free((*cliente)->telefone);
    freeProdutos(&((*cliente)->carrinho));
    free(*cliente);
    (*cliente) = NULL;
}

void removerCliente(node_Cliente** head){
    if (head == NULL || (*head) == NULL){
        return;
    }

    printf("\nRemover Cliente:\n");
    printf("Nao utilize nenhuma acentuacao ('/', '-', '.') ou espacamento.\n");
    printf("- Digite o CPF do cliente: ");

    char * temp = NULL;
    
    temp = lerString();
    if (temp == NULL){
        perror("Erro ao alocar memoria em removerCliente():lerString().");
        return;
    }

    node_Cliente * delete = NULL;

    
    delete = buscarCPF(temp, (*head));
    if (delete == NULL){
        perror("Erro ao alocar memoria em removerCliente():buscarCPF()");
        return;
    }

    if ((*head) == delete){
        (*head = delete->proximo);
    } else{
        node_Cliente *anterior;
        anterior = (*head);
        while (anterior != NULL && anterior->proximo != delete){
            anterior = anterior->proximo;
        }
        if (anterior != NULL){
        anterior->proximo = delete->proximo;
        }
    }
    
    freeCliente(&(delete->data));
    free(delete);
    free(temp);

    continuar();
}

void free_ListaClientes(node_Cliente** lista){
    if (lista == NULL || (*lista) == NULL){
        return;
    }

    node_Cliente* atual = (*lista);

    while (atual != NULL){
        node_Cliente* prox = atual->proximo;

        if (atual->data != NULL){
            freeCliente(&(atual->data));
        }
        free(atual);

        atual = prox;
    }
}
