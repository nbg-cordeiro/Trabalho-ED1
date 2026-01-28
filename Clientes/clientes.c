#include <stdio.h>
#include <string.h>

// NAO ESQUECER DE APAGAR ESSES COMENTARIOS DPS!!!!!!!!!! (lam od odraude)

typedef struct cliente{
    char nome[100];     // Luis Daniel Dalpizzol Moretti da Nobrega Borges Brito
    char cpf[15];       // 123.456.789-00
    char telefone[20];  // +55 61 91234-5678
}modeloCliente;

void listarClientes(modeloCliente *clientes, int N){
    if (clientes != NULL){
        
        for (int index = 0; index < N; index++){
            printf("%d - %s\n", index+1, clientes[index].nome);
        }

    }else{  // ERRO

        printf("listarCliente: LISTA NAO EXISTE.\n");

    }
}

void buscarCPF(modeloCliente *clientes, int N, char *search_cpf){  // array de clientes | numero total de clientes | cpf q vamo procurar
    if (clientes != NULL){

        if (search_cpf != NULL){
            int res_busca = 0;

            for (int index = 0; index < N; index++){

                int comp = strcmp(clientes[index].cpf, search_cpf);

                if (comp == 0){
                    //printf("CPF encontrado.\n");
                    printf("Cliente: %s\nCPF: %s\nTelefone: %s\n", clientes[index].nome,clientes[index].cpf,clientes[index].telefone);
                    res_busca = 1;
                }

            }

            if (res_busca == 0){
                printf("buscarCPF: CPF NAO ESTA CADASTRADO.");
            }
        }

    }else{

        printf("buscarCPF: LISTA NAO EXISTE.\n");

    }
}

void editarCliente(){

}

void removerCliente(){

}


// TESTES 
int main(){
    int TAMN = 4;
    modeloCliente debug_listaCliente[TAMN];

    // cliente teste 1
    strcpy(debug_listaCliente[0].nome,"Eduardo do bem");
    strcpy(debug_listaCliente[0].cpf,"111.111.111-11");
    strcpy(debug_listaCliente[0].telefone,"+5561912345678");

    // cliente teste 2
    strcpy(debug_listaCliente[1].nome,"Eduardo do mal");
    strcpy(debug_listaCliente[1].cpf,"222.222.222-22");
    strcpy(debug_listaCliente[1].telefone,"+5561987654321");

    strcpy(debug_listaCliente[2].nome,"Joao do bem");
    strcpy(debug_listaCliente[2].cpf,"333.333.333-33");
    strcpy(debug_listaCliente[2].telefone,"+5561912345679");

    strcpy(debug_listaCliente[3].nome,"Joao do mal");
    strcpy(debug_listaCliente[3].cpf,"444.444.444-44");
    strcpy(debug_listaCliente[3].telefone,"+5561997654321");

    listarClientes(debug_listaCliente,TAMN);
    buscarCPF(debug_listaCliente,TAMN,debug_listaCliente[2].cpf);

}