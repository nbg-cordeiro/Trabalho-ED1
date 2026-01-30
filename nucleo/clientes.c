#include "clientes.h"

/* checklist

cadastrar cliente:          ok
listar todos os clientes:   ok
buscar cliente pelo cpf:    precisa testar
editar dados de um cliente: pecisa testar
remover cliente:            precisa testar

*/

// ===== NODES CLIENTE ===== //

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

// ===== CRIAR CLIENTE ===== //

void imprimeCliente(Cliente * cliente){
    printf("%s\n", cliente->nome);
    printf("- CPF: %s\n", cliente->cpf);
    printf("- Telefone: %s\n", cliente->telefone);
    printf("- Data de Nascimento: %s", cliente->dataNascimento);

    printf("\n============================\n");
}

void criarCliente(node_Cliente *head){
    Cliente* novoCliente = malloc(sizeof(Cliente));
    if (novoCliente == NULL){
        perror("Erro ao alocar memória em criarCliente().");
        exit(EXIT_FAILURE);
    }

    printf("Novo cliente:\nNome:");
    char* nome = lerString();
    novoCliente->nome = nome;

    printf("Insira os dados a seguir sem pontuacao ('/', '-' e/ou '.') e sem espacamento.\n");

    printf("CPF: ");
    char* cpf = lerString();
    novoCliente->cpf = cpf;


    printf("Data de nascimento:");
    char* aniversaro = lerString();
    novoCliente->dataNascimento = aniversaro;

    printf("Telefone de contato:");
    char* telefone = lerString();
    novoCliente->telefone = telefone;

    printf("\nCliente cadastrado com exito.\n");

    imprimeCliente(novoCliente);

    InserirNode(head,novoCliente);
}

// ===== EDITAR CLIENTE ===== //

void menu_modificarDado(int * opcao, char * dado){
    free(dado); // limpar o que tinha antes

    switch (*opcao)
    {
    case 1:
        printf("Digite nome: ");
        break;
    case 2:
        printf("Insira o dado sem utilizar pontuacoes ('/' '.' '-') ou espaco.");
        printf("Digite CPF: ");
        break;
    case 3:
        printf("Insira o dado sem utilizar pontuacoes ('/' '.' '-') ou espaco.");
        printf("Digite numero de telefone: ");
        break;
    case 4:
        printf("Insira o dado sem utilizar pontuacoes ('/' '.' '-') ou espaco.");
        printf("Digite data de nascimento: ");
        break;
    }

    char* novo_dado = lerString();  // seria uma boa fazer um temp caso o usuario insira um nome invalido ou o lerstring() der null?
    dado = novo_dado;

    printf("\nDado atualizado com exito.\n");

}

void editarCliente(Cliente** cliente){
    if (cliente == NULL){
        printf("Cliente não existe.");
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
            // menu_modificarDado(opcao,cliente->nome);
            printf("Digite nome: ");
            temp = lerString();
            free((*cliente)->nome);
            (*cliente)->nome = temp;
            break;
        case 2:
            // menu_modificarDado(opcao,cliente->cpf);
            printf("Insira o dado sem utilizar pontuacoes ('/' '.' '-') ou espaco.");
            printf("Digite CPF: ");
            temp = lerString();
            free((*cliente)->cpf);
            (*cliente)->cpf = temp;
            break;
        case 3:
        // menu_modificarDado(opcao,cliente->telefone);
            printf("Insira o dado sem utilizar pontuacoes ('/' '.' '-') ou espaco.");
            printf("Digite numero de telefone: ");
            temp = lerString();
            free((*cliente)->telefone);
            (*cliente)->telefone = temp;
            break;
        case 4:
            // menu_modificarDado(opcao,cliente->dataNascimento);
            printf("Insira o dado sem utilizar pontuacoes ('/' '.' '-') ou espaco.");
            printf("Digite data de nascimento: ");
            temp = lerString();
            free((*cliente)->dataNascimento);
            (*cliente)->dataNascimento = temp;
            break;
        default:
            return;
        }
    
    // printf("\nDado atualizado com exito.\n");
    }
    
}


// ===== BUSCAR CLIENTE ===== //

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

// ===== IMPRIMIR CLIENTES ===== //

void imprimirClientes(node_Cliente **head){
    printf("\n====== LISTA CLIENTES ======\n");

    if (*head == NULL){
        printf("Nenhum cliente cadastrado.");
        printf("\n============================\n");
        return;
    }

    node_Cliente *p;
    for (p = (*head)->proximo; p != NULL; p = p->proximo){
        imprimeCliente(p->data);
    }

}

// ===== REMOVER CLIENTE ===== //

void freeCliente(Cliente** cliente){
    free((*cliente)->nome);
    free((*cliente)->cpf);
    free((*cliente)->dataNascimento);
    free((*cliente)->telefone);
    free(*cliente);
    (*cliente) = NULL;

    //free(carrinho);

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

void removerCliente(node_Cliente** head){
    if (head == NULL || (*head) == NULL){
        return;
    }

    printf("\nRemover Cliente:\n");
    printf("Nao utilize nenhuma acentuacao ('/', '-', '.') ou espacamento.");
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
}
