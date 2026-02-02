#include "clientes.h"
#include "compras.h"

void InserirNode(NodeCliente** listaClientes, Cliente* dado){
    NodeCliente *novoNode = malloc(sizeof(NodeCliente));
    if (novoNode == NULL){
        perror("Erro ao alocar memória em InserirNode().");
        exit(EXIT_FAILURE);
    }

    novoNode->data = dado;

    novoNode->proximo = (*listaClientes);
    (*listaClientes) = novoNode;
}

void imprimeCliente(Cliente* cliente){
    printf("%s\n", cliente->nome);
    printf("- CPF: %s\n", cliente->cpf);
    printf("- Telefone: %s\n", cliente->telefone);
    printf("- Data de Nascimento: %s", cliente->dataNascimento);

    printf("\n============================\n");
}

void imprimirClientes(NodeCliente* listaClientes){
    printf("\n====== LISTA CLIENTES ======\n");

    if (listaClientes == NULL){
        printf("Nenhum cliente cadastrado.");
        printf("\n============================\n");
        continuar();
        return;
    }

    while ((listaClientes) != NULL){
        imprimeCliente(listaClientes->data);
        listaClientes = listaClientes->proximo;
    }
    
    continuar();
}

void criarCliente(NodeCliente** listaClientes){
    Cliente* novoCliente = malloc(sizeof(Cliente));
    if (novoCliente == NULL){
        perror("Erro ao alocar memória em criarCliente().");
        exit(EXIT_FAILURE);
    }

    printf("\n====== CADASTRAR CLIENTE ======\n");

    char* nome = NULL;
    do{
        printf("Insira o dado a seguir sem pontuacao ('/', '-' e/ou '.') e sem numeros.\n");
        printf("Nome: ");
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

        if (!validaEntradaLetra(nome)){
            printf("Entrada invalida. Tente novamente.\n");
            free(nome);
            nome = NULL;
        }
    } while (nome == NULL);
    novoCliente->nome = nome;

    char* cpf = NULL;
    do
    {
        printf("Insira o dado a seguir sem pontuacao ('/', '-' e/ou '.') e sem espacamento.\n");
        printf("CPF: ");
        cpf = lerString();

        if (cpf == NULL){
            perror("Nao foi possivel alocar memoria em criarCliente().");
            continue;
        }
        if (buscarCPF(listaClientes,cpf) != NULL){
            printf("Esse CPF ja esta cadastrado!\n");
            free(cpf);
            cpf = NULL;
        }
        if (!validaEntradaNumero(cpf,11)){
            printf("Entrada invalida. Tente novamente.\n");
            free(cpf);
            cpf = NULL;
        }
        
    } while (cpf == NULL);
    novoCliente->cpf = cpf;

    char* telefone = NULL;
    do{
        printf("Insira o dado a seguir sem pontuacao ('/', '-' e/ou '.') e sem espacamento.\n");
        printf("Telefone de contato (DDD)9xxxx-xxxx: ");
        telefone = lerString();
        if (telefone == NULL){
            perror("Nao foi possivel alocar memoria em criarCliente().");
            continue;
        }
        if (!validaEntradaNumero(telefone,11)){
            printf("Entrada invalida. Tente novamente.\n");
            free(telefone);
            telefone = NULL;
        }
    } while (telefone == NULL);
    novoCliente->telefone = telefone;

    char* aniversario = NULL;
    do{
        printf("Insira o dado a seguir sem pontuacao ('/', '-' e/ou '.') e sem espacamento.\n");
        printf("Data de nascimento (DDMMAAAA): ");
        aniversario = lerString();
        if (aniversario == NULL){
            perror("Nao foi possivel alocar memoria em criarCliente().");
            continue;
        }
        if (!validaEntradaNumero(aniversario,8)){
            printf("Entrada invalida. Tente novamente.\n");
            free(aniversario);
            aniversario = NULL;
        }
    } while (aniversario == NULL);
    novoCliente->dataNascimento = aniversario;

    novoCliente->carrinho=NULL;

    InserirNode(listaClientes,novoCliente);
    
    printf("\nCliente cadastrado com exito.\n\n");
    imprimeCliente(novoCliente);

    continuar();
}

void editarCliente(NodeCliente** listaClientes){
    if (listaClientes == NULL || (*listaClientes) == NULL){
        return;
    }

    char *cpf = NULL;
    printf("Nao utilize pontuacoes ('/' '.' '-') ou espaco.\n");
    printf("Digite o CPF do cliente: ");
    cpf = lerString();
    NodeCliente **cliente = buscarCPF(listaClientes, cpf);
    free(cpf);

    if (cliente == NULL || (*cliente) == NULL){
        printf("Cliente nao cadastrado no sistema.");
        continuar();
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
            do{
                printf("Insira o dado a seguir sem pontuacao ('/', '-' e/ou '.') e sem numeros.\n");
                printf("Nome: ");
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

                if (!validaEntradaLetra(temp)){
                    printf("Entrada invalida. Tente novamente.\n");
                    free(temp);
                    temp = NULL;
                }
            } while (temp == NULL);

            free((*cliente)->data->nome);
            (*cliente)->data->nome = temp;

            break;
        case 2:
            do{
                #warning ainda preciso fazer um counter caso insira o mesmo cpf na hora de modificar o cliente
                printf("Insira o dado a seguir sem pontuacao ('/', '-' e/ou '.') e sem espacamento.\n");
                printf("CPF: ");
                temp = lerString();

                if (temp == NULL){
                    perror("Nao foi possivel alocar memoria em criarCliente().");
                    continue;
                }
                if (buscarCPF(listaClientes,temp) != NULL){
                    printf("Esse CPF ja esta cadastrado!\n");
                    free(temp);
                    temp = NULL;
                }
                if (!validaEntradaNumero(temp,11)){
                    printf("Entrada invalida. Tente novamente.\n");
                    free(temp);
                    temp = NULL;
                }
                
            } while (temp == NULL);
            
            free((*cliente)->data->cpf);
            (*cliente)->data->cpf = temp;

            break;
        case 3:
            do{
                printf("Insira o dado a seguir sem pontuacao ('/', '-' e/ou '.') e sem espacamento.\n");
                printf("Telefone de contato (DDD)9xxxx-xxxx: ");
                temp = lerString();
                if (temp == NULL){
                    perror("Nao foi possivel alocar memoria em criarCliente().");
                    continue;
                }
                if (!validaEntradaNumero(temp,11)){
                    printf("Entrada invalida. Tente novamente.\n");
                    free(temp);
                    temp = NULL;
                }
            } while (temp == NULL);

            free((*cliente)->data->telefone);
            (*cliente)->data->telefone = temp;

            break;
        case 4:

            do{
                printf("Insira o dado a seguir sem pontuacao ('/', '-' e/ou '.') e sem espacamento.\n");
                printf("Data de nascimento (DDMMAAAA): ");
                temp = lerString();
                if (temp == NULL){
                    perror("Nao foi possivel alocar memoria em criarCliente().");
                    continue;
                }
                if (!validaEntradaNumero(temp,8)){
                    printf("Entrada invalida. Tente novamente.\n");
                    free(temp);
                    temp = NULL;
                }
            } while (temp == NULL);

            free((*cliente)->data->dataNascimento);
            (*cliente)->data->dataNascimento = temp;

            break;
        default:
            return;
        }
    
    printf("\nDado atualizado com exito.\n\n");
    imprimeCliente((*cliente)->data);
    continuar();
    }
    
}

NodeCliente** buscarCPF(NodeCliente** listaCliente,char* cpf){
    if (listaCliente == NULL){
        return NULL;
    }

    while ((*listaCliente) != NULL ){
        if (compararString((*listaCliente)->data->cpf,cpf) == 1)
            return listaCliente;
        listaCliente = &((*listaCliente)->proximo);
    }
    return NULL;
}


void buscarCliente(NodeCliente** listaCliente){
    if (listaCliente == NULL || (*listaCliente) == NULL){
        printf("Nenhum cliente cadastrado.\n");
        continuar();
        return;
    }

    printf("\nBuscar Cliente:\n");
    printf("Nao utilize nenhuma acentuacao ('/', '-', '.') ou espacamento.\n");
    printf("- Digite o CPF do cliente: ");

    char * temp = lerString();
    if (temp == NULL){
        return;
    }
    NodeCliente** cliente = buscarCPF(listaCliente, temp);
    free(temp);
    if (cliente == NULL || (*cliente) == NULL){
        printf("Cliente não foi encontrado.");
        continuar();
        return;
    }

    printf("\n====== BUSCAR CLIENTE ======\n");
    imprimeCliente((*cliente)->data);

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

void removerCliente(NodeCliente** listaCliente, NodeProduto** estoque){
    if (listaCliente == NULL || (*listaCliente) == NULL){
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

    NodeCliente** nodeDelete = buscarCPF(listaCliente,temp);
    free(temp);

    if (nodeDelete == NULL || (*nodeDelete) == NULL){
        printf("CPF inserido nao esta cadastrado.");
        return;
    }

    NodeCliente* aux = (*nodeDelete)->proximo;

    freeCliente(&((*nodeDelete)->data),estoque);
    free(*nodeDelete);
    (*nodeDelete) = aux;

    continuar();
}

void free_ListaClientes(NodeCliente** listaClientes, NodeProduto** estoque){
    if (listaClientes == NULL){
        return;
    }

    while ((*listaClientes) != NULL){
        NodeCliente* aux = (*listaClientes)->proximo;

        if ((*listaClientes)->data != NULL){
            freeCliente(&(*listaClientes)->data,estoque);
        }
        free(*listaClientes);
        (*listaClientes) = NULL;

        (*listaClientes) = aux;
    }
}