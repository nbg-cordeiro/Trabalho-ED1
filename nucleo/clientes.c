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
    printf("%s", cliente->nome);
    printf("\n----------------------------\n");
    printf("- CPF: ");
    for (int k = 0; k < (tamanhoString(cliente->cpf)-1); k++){ //123.456.789-12
        if (k == 3 || k == 6){
            printf(".");
        }
        if (k == 9){
            printf("-");
        }
        printf("%c",cliente->cpf[k]);
    }
    printf("\n- Email: %s\n",cliente->email);
    printf("- Telefone: ");
    for (int i = 0; i < (tamanhoString(cliente->telefone)-1); i++){ //61 9 12345678
        if (i == 2 || i == 3){
            printf(" ");
        }
        printf("%c",cliente->telefone[i]);
    }
    printf("\n- Data de Nascimento: "); //25/25/2012
    for (int j = 0; j < (tamanhoString(cliente->dataNascimento)-1); j++){
        if (j==2 || j==4){
            printf("/");
        }
        printf("%c",cliente->dataNascimento[j]);
    }

    printf("\n============================\n");
}

void imprimirClientes(NodeCliente* listaClientes){
    printf("\n====== LISTA CLIENTES ======\n");

    if (listaClientes == NULL){
        printf("\nNenhum cliente cadastrado.\n");
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

    char* email = NULL;
    do
    {
        printf("email: ");
        email = lerString();

        if (email == NULL){
            perror("Nao foi possivel alocar memoria em criarCliente().");
            continue;
        }
        if (!validaEmail(email)){
            printf("Entrada invalida. Tente novamente.\n");
            free(email);
            email = NULL;
        }
        
    } while (email == NULL);
    novoCliente->email = email;

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
            printf("3 - Editar email do cliente\n");
            printf("4 - Editar telefone do cliente\n");
            printf("5 - Editar Data de Nascimento do cliente\n");
            printf("6 - Sair\n");
            printf("Escolha uma opcao:\n");
            int controle = scanf("%d", &opcao);
            limpaBuffer();

            if(controle!=1 || opcao<1 || opcao>6){
                limpaConsole();
                printf("\nInput Invalido! Tente novamente.\n");
                opcao = -1;
            }
        }while(opcao<1 || opcao>6);
    
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
                printf("Insira o dado a seguir sem pontuacao ('/', '-' e/ou '.') e sem espacamento.\n");
                printf("CPF: ");
                temp = lerString();

                if (temp == NULL){
                    perror("Nao foi possivel alocar memoria em criarCliente().");
                    continue;
                }
                if ((buscarCPF(listaClientes,temp) != NULL) && (!compararString(temp,(*cliente)->data->cpf))){
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
            do
            {
                printf("email: ");
                temp = lerString();

                if (temp == NULL){
                    perror("Nao foi possivel alocar memoria em criarCliente().");
                    continue;
                }
                if (!validaEmail(temp)){
                    printf("Entrada invalida. Tente novamente.\n");
                    free(temp);
                    temp = NULL;
                }
            } while (temp == NULL);

            free((*cliente)->data->email);
            (*cliente)->data->email = temp;

            break;
        case 4:
            do{
                printf("Insira o dado a seguir sem pontuacao ('/', '-' e/ou '.') e sem espacamento.\n");
                printf("Telefone de contato (DDD)9xxxx-xxxx: ");
                temp = lerString();
                if (temp == NULL){
                    printf("Nao foi possivel alocar memoria em criarCliente().");
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
        case 5:

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
        free(temp);
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
    free((*cliente)->email);
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
        continuar();
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