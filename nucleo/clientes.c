#include "clientes.h"

// ===== REMOVER CLIENTE ===== //

void freeCliente(Cliente** cliente){
    free((*cliente)->cpf);
    free((*cliente)->nome);
    free((*cliente)->telefone);
    free((*cliente)->dataNascimento);
    (*cliente) = NULL;
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

// ===== CRIAR CLIENTE ===== //

Cliente* criarCliente(){
    Cliente* novoCliente = malloc(sizeof(Cliente));

    printf("Novo cliente:\nNome:");
    char* nome = lerString();
    novoCliente->nome = nome;

    printf("Insira os dados a seguir sem pontuacao ('/', '-' e/ou '.') e sem espacamento.\n");

    //fazer uma verificacao de tamanho de string nesses rapazes

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

    // imprimeCliente()?
    return novoCliente;
}

void node_inserirCliente(Cliente** clienteAtual, Cliente** clienteProximo, Cliente** clienteAnterior){ // (conteudo, proxima, anterior)
    // Node nodeCliente;
}