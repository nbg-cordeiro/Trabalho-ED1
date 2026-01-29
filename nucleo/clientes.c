#include "clientes.h"
#include "auxiliares.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu_editarCliente(void){
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
    
    return opcao;
}

void menu_modificarDado(const char * texto, char * dado){
    printf("\n====== GERENCIAMENTO DE CLIENTES | %s ======\n", texto);
    printf("Insira novo valor: ");

    // usar o fgets do joao :>
    // verificar se não mudou o dado para um espaço vazio (ex.: " ")

}

void editarCliente(Cliente * cliente){
    char opcao = menu_editarCliente();
    
    switch (opcao)
    {
    case 1:
        menu_modificarDado("EDITAR NOME DO CLIENTE",cliente->nome);
        break;
    case 2:
        menu_modificarDado("EDITAR CPF DO CLIENTE",cliente->cpf);
        break;
    case 3:
        menu_modificarDado("EDITAR TELEFONE DO CLIENTE",cliente->telefone);
        break;
    case 4:
        menu_modificarDado("EDITAR DATA DE NASCIMENTO DO CLIENTE",cliente->dataNascimento);
        break;
    case 5:
        // voltar pro gerenciamento de cliente
        break;
    }
        
}

Cliente criarCliente(char * nome, char * cpf, char * telefone){
    Cliente temp;
    strcpy(temp.nome,*nome);
    strcpy(temp.cpf,*cpf);
    strcpy(temp.telefone,*telefone);
    // TEM DATA DE NASCIMENTO TMB

    return temp;
}